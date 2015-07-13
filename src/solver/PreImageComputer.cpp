/*
 * PreImageComputer.cpp
 *
 *  Created on: Jun 24, 2015
 *      Author: baki
 */

#include "PreImageComputer.h"

namespace Vlab {
namespace Solver {

using namespace SMT;

const int PreImageComputer::VLOG_LEVEL = 12;

PreImageComputer::PreImageComputer(SymbolTable_ptr symbol_table, VariablePathTable& variable_path_table, const TermValueMap& post_images)
        : symbol_table(symbol_table), variable_path_table (variable_path_table),
          post_images (post_images) {
}

PreImageComputer::~PreImageComputer() {
  for (auto& entry : pre_images) {
    delete entry.second;
  }

  pre_images.clear();
}

void PreImageComputer::start() {
  Value_ptr initial_value = nullptr;
  Term_ptr root_term = nullptr;
  DVLOG(VLOG_LEVEL) << "Pre image computation start";
  for (auto& path_entry : variable_path_table) {
    current_path = path_entry.second;
    root_term = current_path.back();
    initial_value = getTermPostImage(root_term);
    setTermPreImage(root_term, initial_value->clone());
    visit(root_term);
  }
  end();
}

void PreImageComputer::end() {
}

void PreImageComputer::visitScript(Script_ptr script) {
}

void PreImageComputer::visitCommand(Command_ptr command) {
}

void PreImageComputer::visitTerm(Term_ptr term) {
}

void PreImageComputer::visitExclamation(Exclamation_ptr exclamation_term) {
}

void PreImageComputer::visitExists(Exists_ptr exists_term) {
}

void PreImageComputer::visitForAll(ForAll_ptr for_all_term) {
}

void PreImageComputer::visitLet(Let_ptr let_term) {
}

void PreImageComputer::visitAnd(And_ptr and_term) {
  LOG(FATAL) << "implement me";
}

void PreImageComputer::visitOr(Or_ptr or_term) {
  LOG(FATAL) << "implement me";
}

void PreImageComputer::visitNot(Not_ptr not_term) {
  LOG(FATAL) << "implement me";
  visit_children_of(not_term);
}

void PreImageComputer::visitUMinus(UMinus_ptr u_minus_term) {
  LOG(FATAL) << "implement me";
  visit_children_of(u_minus_term);
}

void PreImageComputer::visitMinus(Minus_ptr minus_term) {
  LOG(FATAL) << "implement me";
  visit_children_of(minus_term);
}

void PreImageComputer::visitPlus(Plus_ptr plus_term) {
  LOG(FATAL) << "implement me";
  visit_children_of(plus_term);
}

void PreImageComputer::visitEq(Eq_ptr eq_term) {
  DVLOG(VLOG_LEVEL) << "pop: " << *eq_term;
  popTerm(eq_term);
  Term_ptr child_term = current_path.back();
  Value_ptr child_value = getTermPreImage(child_term);
  if (child_value not_eq nullptr) {
    visit(child_term);
    return;
  }

  Value_ptr term_value = getTermPreImage(eq_term);
  child_value = term_value->clone();
  setTermPreImage(child_term, child_value);
  visit(child_term);
}

void PreImageComputer::visitGt(Gt_ptr gt_term) {
  LOG(FATAL) << "implement me";
  visit_children_of(gt_term);
}

void PreImageComputer::visitGe(Ge_ptr ge_term) {
  LOG(FATAL) << "implement me";
  visit_children_of(ge_term);
}

void PreImageComputer::visitLt(Lt_ptr lt_term) {
  visit_children_of(lt_term);
}

void PreImageComputer::visitLe(Le_ptr le_term) {
  LOG(FATAL) << "implement me";
  visit_children_of(le_term);
}

void PreImageComputer::visitConcat(Concat_ptr concat_term) {
  LOG(FATAL) << "implement me";
  visit_children_of(concat_term);
}

void PreImageComputer::visitIn(In_ptr in_term) {
  LOG(FATAL) << "implement me";
  visit_children_of(in_term);
}

void PreImageComputer::visitLen(Len_ptr len_term) {
  LOG(FATAL) << "implement me";
  visit_children_of(len_term);
}

void PreImageComputer::visitContains(Contains_ptr contains_term) {
  LOG(FATAL) << "implement me";
  visit_children_of(contains_term);
}

void PreImageComputer::visitBegins(Begins_ptr begins_term) {
  LOG(FATAL) << "implement me";
  visit_children_of(begins_term);
}

void PreImageComputer::visitEnds(Ends_ptr ends_term) {
  LOG(FATAL) << "implement me";
  visit_children_of(ends_term);
}

void PreImageComputer::visitIndexOf(IndexOf_ptr index_of_term) {
  LOG(FATAL) << "implement me";
  visit_children_of(index_of_term);
}

void PreImageComputer::visitLastIndexOf(SMT::LastIndexOf_ptr last_index_of_term) {
  LOG(FATAL) << "implement me";
  visit_children_of(last_index_of_term);
}

void PreImageComputer::visitCharAt(SMT::CharAt_ptr char_at_term) {
  LOG(FATAL) << "implement me";
  visit_children_of(char_at_term);
}

void PreImageComputer::visitSubString(SMT::SubString_ptr sub_string_term) {
  LOG(FATAL) << "implement me";
  visit_children_of(sub_string_term);
}

void PreImageComputer::visitToUpper(SMT::ToUpper_ptr to_upper_term) {
  LOG(FATAL) << "implement me";
  visit_children_of(to_upper_term);
}

void PreImageComputer::visitToLower(SMT::ToLower_ptr to_lower_term) {
  LOG(FATAL) << "implement me";
  visit_children_of(to_lower_term);
}

void PreImageComputer::visitTrim(SMT::Trim_ptr trim_term) {
  LOG(FATAL) << "implement me";
  visit_children_of(trim_term);
}

void PreImageComputer::visitReplace(Replace_ptr replace_term) {
  LOG(FATAL) << "implement me";
  visit_children_of(replace_term);
}

void PreImageComputer::visitCount(Count_ptr count_term) {
  LOG(FATAL) << "implement me";
  visit_children_of(count_term);
}

void PreImageComputer::visitIte(Ite_ptr ite_term) {
}

void PreImageComputer::visitReConcat(ReConcat_ptr re_concat_term) {
}

void PreImageComputer::visitToRegex(ToRegex_ptr to_regex_term) {
}

void PreImageComputer::visitUnknownTerm(Unknown_ptr unknown_term) {
}

void PreImageComputer::visitAsQualIdentifier(AsQualIdentifier_ptr as_qid_term) {
}

void PreImageComputer::visitQualIdentifier(QualIdentifier_ptr qi_term) {
  DVLOG(VLOG_LEVEL) << "pop: " << *qi_term;
  popTerm(qi_term);

  Value_ptr term_pre_value = getTermPreImage(qi_term);
  Value_ptr variable_old_value = symbol_table->getValue(qi_term->getVarName());
  Value_ptr variable_new_value = variable_old_value->intersect(term_pre_value);

  symbol_table->setValue(qi_term->getVarName(), variable_new_value);
  delete variable_old_value;

}

void PreImageComputer::visitTermConstant(TermConstant_ptr term_constant) {
}

void PreImageComputer::visitIdentifier(Identifier_ptr identifier) {
}

void PreImageComputer::visitPrimitive(Primitive_ptr primitive) {
}

void PreImageComputer::visitTVariable(TVariable_ptr t_variable) {
}

void PreImageComputer::visitTBool(TBool_ptr t_bool) {
}

void PreImageComputer::visitTInt(TInt_ptr t_int) {
}

void PreImageComputer::visitTString(TString_ptr t_string) {
}

void PreImageComputer::visitVariable(Variable_ptr variable) {
}

void PreImageComputer::visitSort(Sort_ptr sort) {
}

void PreImageComputer::visitAttribute(Attribute_ptr attribute) {
}

void PreImageComputer::visitSortedVar(SortedVar_ptr sorted_var) {
}

void PreImageComputer::visitVarBinding(VarBinding_ptr var_binding) {
}

Value_ptr PreImageComputer::getTermPostImage(SMT::Term_ptr term) {
  auto iter = post_images.find(term);
  if (iter == post_images.end()) {
    LOG(FATAL)<< "post image value is not computed for term: " << *term;
  }
  return iter->second;
}

Value_ptr PreImageComputer::getTermPreImage(SMT::Term_ptr term) {
  auto iter = pre_images.find(term);
  if (iter == pre_images.end()) {
    return nullptr;
  }
  return iter->second;
}

bool PreImageComputer::setTermPreImage(SMT::Term_ptr term, Value_ptr value) {
  auto result = pre_images.insert(std::make_pair(term, value));
  if (result.second == false) {
    LOG(FATAL)<< "value is already computed for term: " << *term;
  }
  return result.second;
}

void PreImageComputer::popTerm(SMT::Term_ptr term) {
  if (current_path.back() == term) {
    current_path.pop_back();
  } else {
    LOG(FATAL) << "expected '" << *term << "', but found '" << *current_path.back() << "'";
  }
}

} /* namespace Solver */
} /* namespace Vlab */