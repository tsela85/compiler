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

((lambda (a b . c) a) #t #f #f) ; #t
((lambda (a b . c) c) #t #f) ; ()
((lambda ( . c) c)) ; ()

(compile '((
    (lambda (a b . c)
      (lambda (d e f . g)
        c))
    #t #t ) #f #f #f) ; ()
  )

(compile '((
  (lambda (a b . c)
    (lambda (d e f . g)
      f))
  #t #t ) #f #f #f) ; #f
         )

(compile '((
  (lambda (a b . c)
    (lambda (d e f . g)
      g))
  #t #t ) #f #f #f)) ;()

(compile '(((
   (lambda (a b . c)
     (lambda (d e f . g)
       (lambda (h i j k . l)
         c)))
   #t #t ) #f #f #f) #t #t #t #t) ; ()
         )
(compile '(((
   (lambda (a b . c)
     (lambda (d e f . g)
       (lambda (h i j k . l)
         j
         )))
   #f #f) #f #f #f) #f #f #t #f) ; #t
         )

(compile '(boolean? (zero? (bin* 8 (bin+ 1 2)))))

(compile '(;;; the following should be re-implemented in cisc assembly:

;;; rename ++ to +

           (define ++
             (letrec ((loop
                       (lambda (s)
                         (if (null? s)
                             0
                           (bin+ (car s)
                                 (loop (cdr s)))))))
               (lambda s (loop s))))

;;; rename ** to *

           (define **
             (letrec ((loop
                       (lambda (s)
                         (if (null? s)
                             1
                           (bin* (car s)
                                 (loop (cdr s)))))))
               (lambda s (loop s))))

;;; rename -- to -

           (define --
             (lambda (a . s)
               (if (null? s)
                   (bin- 0 a)
                 (bin- a (apply ++ s)))))

;;; rename // to /

           (define //
             (lambda (a . s)
               (if (null? s)
                   (bin/ 1 a)
                 (bin/ a (apply ** s)))))

;;;
))


(compile '(apply bin+ '(1 2 3)))
(test '(apply bin+ (1 2 3)))

(compile '((lambda (a b c d) (bin+ a b))
           ((lambda () (bin+ 1 2)))
           ((lambda () (bin+ 1 2)))))
(compile '(begin
          (define testOP (lambda (x . y) (if (null? y) x (bin+ x (apply testOP y)) )))
          (apply testOP '(1 1 1))))
