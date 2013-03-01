;;; torture-test-for-compiler-04.scm
;;; Testing the support-code.scm routines
;;; Should return #t
;;;
;;; Programmer: Mayer Goldberg, 2010


(string-reverse "abc")
(string-reverse (string-reverse "abc"))
(string=? "abc" "cvs")
                                        ;(and
 (= 4 (sub1 5))
 (= -5 (sub1 -4))
 (= 5 (add1 4))
 (= -4 (add1 -5))
 (not #f)
 (not (not 34))
 (not (not 'a))
 (zero? ((compose add1 sub1) 0))
 (eq? 'd (cadddr '(a b c d)))
 (char=? #\a #\a)
 (char-ci=? #\a #\A)
 (char-lowercase? #\a)
 (not (char-lowercase? #\A))
 (char=? #\a (char-downcase #\A))
 (even? 4)
 (odd? 5)
 (not (even? 5))
 (not (odd? 4))
 (= 4 (length '(a b c d)))
 (equal? '(a b c d) (list 'a 'b 'c 'd))
 (eq? 'd (list-ref '(a b c d) 3))
 (list? '())
 (list? '(a b c))
 (not (list? 'a))
 (not (list? '(a . b)))
 (not (list? #f))
 (equal? '(2 3 4) (map add1 '(1 2 3)))
 (equal? '(5 7 9) (map + '(1 2 3) '(4 5 6)))
 (member? 'do '(a b c do re mi 1 2 3))
 (not (member? 'x '()))
 (not (member? 'foo! '(1 2 3 4 5 6)))
 (negative? -4)
 (not (negative? 0))
 (positive? 5)
 (not (positive? 0))
 (not (positive? -5))
 (equal? '#(4 9 6 3 5 1) (vector 4 9 6 3 5 1))
 (ormap even? '(1 3 5 7 9 0 -25))
 (andmap even? '())
; (string=? "Hello World!" (list->string (string->list "Hello
                                        ; World!")))

 (string<=? "abc" "abc")
 (string<=? "" "abc")
 (not (string<=? "def" "abc"))
 (equal? '(4 9 6 3 5 1) (vector->list (list->vector '(4 9 6 3 5 1))))
; (equal? '(a b c) (member 'a '(x y z a b c)))
 (equal? '(a 1) (assoc 'a '((x 23) (b 2) (c 3) (a 1) (d 4))))
 (not (assoc 'a '((x 1) (y 2) (z 3))))
 (equal? '(a b c d) (append '(a b) '(c d)))
 (equal? '(3 2 1) (reverse '(1 2 3)))
 (null? (reverse '()))
 (string=? "abc" (string-reverse (string-reverse "abc")))
 (eq? 'a (list-ref '(x y z a b c) 3))
 (= 10 (max 4 3 2 1 6 7 8 10))
(zero? (min 4 5 6 0 7 8 9))


                                        ; )
