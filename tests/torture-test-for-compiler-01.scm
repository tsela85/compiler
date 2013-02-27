;;; torture-test-for-compiler-01.scm
;;; Tests the tail-call optimization. Assumes zeor?, - and #t
;;; The test should return #t
;;;
;;; Programmer: Mayer Goldberg, 2010

(compile '( (lambda (x) (x x 1000000))
            (lambda (x n)
              (if (zero? n)
                  #t
                  (x x (bin- n 1))))))
