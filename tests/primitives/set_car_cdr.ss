(define ls '(1 2 3 4))
(set-car! ls 8)
(set-cdr! (cdr ls) '(3 4 5))
(set-car! (cdr ls) 10)

(list (car '(1 2)) (cadr '(1 2)) ls)