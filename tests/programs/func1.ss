(define (func1 x y z)
  (letrec ((r (lambda (m n)
                (+ y z m x n y)))
           (m (lambda (z)
                (* x z y))))
  (+ (r x y) (m 3) (gcd x y z))))
  
(func1 210 96 150)