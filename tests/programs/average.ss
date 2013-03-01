(define (average ls)  (/ (foldr + 0 ls) (length ls)))
(average '(1 2 3 4 5 -1 7))