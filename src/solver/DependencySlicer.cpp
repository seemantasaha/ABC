#include "DependencySlicer.h"

#include <glog/logging.h>
#include <glog/vlog_is_on.h>
#include <cstdbool>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>

#include "smt/ast.h"
#include "smt/Visitor.h"
#include "utils/List.h"

namespace Vlab {
namespace Solver {

using namespace SMT;
const int DependencySlicer::VLOG_LEVEL = 20;

DependencySlicer::DependencySlicer(Script_ptr script, SymbolTable_ptr symbol_table, ConstraintInformation_ptr constraint_information)
    : AstTraverser(script),
      symbol_table_(symbol_table),
      constraint_information_ (constraint_information),
      current_term_(nullptr) {
  setCallbacks();
}

DependencySlicer::~DependencySlicer() {
}

void DependencySlicer::start() {
  DVLOG(VLOG_LEVEL) << "Starting the Dependency Slicer";

  symbol_table_->push_scope(root);
  visitScript(root);
  symbol_table_->pop_scope();

  end();
}

void DependencySlicer::end() {
  if (VLOG_IS_ON(VLOG_LEVEL)) {

  }
}

void DependencySlicer::setCallbacks() {
  auto term_callback = [this] (Term_ptr term) -> bool {
    switch (term->type()) {
    case Term::Type::TERMCONSTANT: {
      return false;
    }
    default:
      return true;
    }
  };

  auto command_callback = [](Command_ptr command) -> bool {
    if (Command::Type::ASSERT == command->getType()) {
      return true;
    }
    return false;
  };

  setCommandPreCallback(command_callback);
  setTermPreCallback(term_callback);
}

void DependencySlicer::visitAssert(Assert_ptr assert_command) {
  if ((Term::Type::OR not_eq assert_command->term->type()) and (Term::Type::AND not_eq assert_command->term->type())) {
    //TODO There is only one constraint
  } else {
    visit_children_of(assert_command);
  }
}

void DependencySlicer::visitAnd(And_ptr and_term) {
  for (auto& term : *(and_term->term_list)) {
    current_term_ = term;
    visit(term);
    current_term_ = nullptr;
  }

  constraint_information_->add_component(and_term);

  auto components = GetComponentsFor(and_term->term_list);
  if (components.size() > 1) {
    and_term->term_list->clear();
    constraint_information_->remove_component(and_term);
    for (auto sub_term_list : components) {
      And_ptr and_component = new And(sub_term_list);
      constraint_information_->add_component(and_component);
      and_term->term_list->push_back(and_component);
    }
  } else if (components.size() == 1) {
    // deallocate term list to avoid memory leak
    components[0]->clear();
    delete components[0];
  }

  // reset data
  clear_mappings();
}

void DependencySlicer::visitOr(Or_ptr or_term) {
  for (auto& term : *(or_term->term_list)) {
    symbol_table_->push_scope(term);
    if (Term::Type::AND not_eq term->type()) {
      // TODO a single component, handle here
    } else {
      visit(term);
    }
    symbol_table_->pop_scope();
  }

  clear_mappings();
  // TODO handle components for a Or term at symbol table level (we use dnf form)
}

/**
 * TODO handle local scopes
 */
void DependencySlicer::visitQualIdentifier(QualIdentifier_ptr qi_term) {
  Variable_ptr variable = symbol_table_->getVariable(qi_term->getVarName());
  if (not variable->isLocalLetVar()) {
    add_variable_current_term_mapping(variable);
  }
}

void DependencySlicer::add_variable_current_term_mapping(Variable_ptr variable) {
  term_variable_map_[current_term_].insert(variable);
  variable_term_map_[variable].insert(current_term_);
}

void DependencySlicer::clear_mappings() {
  term_variable_map_.clear();
  variable_term_map_.clear();
}

/**
 * Creates a separate term list for each group of terms that are dependent to each other
 */
std::vector<TermList_ptr> DependencySlicer::GetComponentsFor(TermList_ptr term_list) {
  std::map<Term_ptr, bool> term_processed;
  std::map<Variable_ptr, bool> is_in_queue;
  std::vector<TermList_ptr> components;
  for (auto term : *term_list) {
    if (not term_processed[term]) {
      term_processed[term] = true;

      std::set<Term_ptr> dependent_terms;
      dependent_terms.insert(term);

      // Get initial work list
      std::queue<Variable_ptr> worklist;
      for (auto variable : term_variable_map_[term]) {
        if (not is_in_queue[variable]) {
          worklist.push(variable);
          is_in_queue[variable] = true;
        }
      }

      // Figure out all dependent terms
      while (not worklist.empty()) {
        auto variable = worklist.front(); worklist.pop();
        for (auto variable_term : variable_term_map_[variable]) {
          if (not term_processed[variable_term]) {
            term_processed[variable_term] = true;
            dependent_terms.insert(variable_term);
            for (auto next_variable : term_variable_map_[variable_term]) {
              if (not is_in_queue[next_variable]) {
                worklist.push(next_variable);
                is_in_queue[next_variable] = true;
              }
            }
          }
        }
      }

      TermList_ptr current_component = new TermList();
      current_component->insert(current_component->begin(), dependent_terms.begin(), dependent_terms.end());
      components.push_back(current_component);
    }
  }
  return components;
}

}  //Vlab
}  //Solver
