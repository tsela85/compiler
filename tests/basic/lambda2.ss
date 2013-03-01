(define x (lambda (x y) x))
(define y (lambda (x y) y))
((((lambda (x y) (x x x)) x y) y x) 'x 'y)