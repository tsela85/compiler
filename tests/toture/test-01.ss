;;; torture-test-for-compiler-01.scm
;;; Tests the tail-call optimization. Assumes zeor?, - and #t
;;; The test should return #t
;;;
;;; Programmer: Mayer Goldberg, 2010

((lambda (x) (x x 200000))
 (lambda (x n)
   (if (zero? n) 13
       (x x (- n 1)))))