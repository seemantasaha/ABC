(set-logic QF_S)
(declare-fun a () String)
(declare-fun b () String)


(assert (not (= (concat "a" a) (concat "a" a))))
	

(check-sat)

