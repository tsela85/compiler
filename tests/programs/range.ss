(define (range n)
    (let ((acc (cons n '())))
        (letrec (
            (iter (lambda ()
                (if (zero? (car acc))
                    acc
                    (begin (set-cdr! acc (cons (car acc) (cdr acc)))
                           (dec acc) 
                           (iter)))))
            (dec (lambda (y) (set-car! y (- (car y) 1)))))
            (iter))))
            
(range 15)