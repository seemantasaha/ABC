(set-logic QF_S)

(declare-fun a () String)

(assert (not (ends (concat a "b") "a" )))

(check-sat)
