;;; torture-test-for-compiler-005.scm
;;; Should return #t
;;;
;;; Programmer: Mayer Goldberg, 2010

(compile '(((((lambda (x) (x (x x)))
             (lambda (x)
               (lambda (y)
                 (x (x y)))))
            (lambda (p)
              (p (lambda (x)
                   (lambda (y)
                     (lambda (z)
                       ((z y) x)))))))
           (lambda (x)
             ((x #t) #f)))
          (lambda (x)
            (lambda (y)
              x))))

(compile '(let* ((a #t)
              (a (if a #f #t))
              (b #f))
            b))

(compile '(let* ((a #t)
              (a (if a #f #t))
              (b #f)
              (b (or b #t)))
         a))


(code-gen (test '((lambda (a c d h) ;;
            ((lambda (b e)          ;;
               b) #f #f))           ;;
                  #t #t #t #t)))    ;;
(compile '((lambda (a c d h)        ;;
             ((lambda (b e)         ;;
                b) #f #f))          ;;
           #t #t #t #t))            ;;

(compile '((lambda (a b c)
             ((lambda (b c)
                ((lambda (d) d)
                 ((lambda (g) #f) #t)))
              #f #f))
           #t #t #t))

(compile '((lambda (a c)
          ((lambda b
           ((lambda (d e) d)
            #t #t))
              ))
           #f #f))


(compile '((lambda (a c)
             ((lambda b
                ((lambda (d . e)
                 ((lambda (q w . r)
                    r)
                  #t #t #f #f #t #t #f))
                 #t #t #t))
              ))
           #f #f))


(compile '((lambda a a) #t #t #t #t))
(compile '((lambda (a b . d) d) #t #t #t #t #t #t))


(compile '(begin (define x (lambda (x y) y)) (x #t #f)))
(compile '(begin (define x (lambda (x y) x)) (x #t #f)))
