(define plus
  (lambda args
    (if (null? args)
        0
        (+ (car args) (apply plus (cdr args))))))
(plus 1 2 3 4 5 6 7 8 9 10)