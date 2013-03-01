(define drlm1st
  (lambda (a b s)
    (letrec ((drlm1st
              (lambda (s ret-f ret-nf)
                (cond ((pair? s)
                       (drlm1st (car s)
                         (lambda (new-car)
                           (ret-f (cons new-car (cdr s))))
                         (lambda ()
                           (drlm1st (cdr s)
                             (lambda (new-cdr)
                               (ret-f (cons (car s) new-cdr)))
                 ret-nf))))
                      ((equal? s a) (ret-f b))
                      (else (ret-nf))))))
      (drlm1st s (lambda (s) s) (lambda () s)))))

(drlm1st 'a 'b '(((a b c)) (a b c) a b))