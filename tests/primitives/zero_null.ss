(cons (zero? 0)
(cons (zero? 45)
(cons (zero? -700)

(cons (null? '())
(cons (null? (cdr '(1)))
(cons (null? '(4 5))
(cons (null? '(4 . 5))
      '())))))))

(+ 1 2)
(make-vector 10)
(make-vector 10 999)
(make-vector 10 (if #f #f))
