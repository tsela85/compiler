(define str (list->string '(#\h #\e #\l #\l #\o)))
(string-set! str 3 #\a)
(string-set! str 0 #\b)

(cons (string-ref "brown" 1) 
(cons (string-ref "orange" 4)
(cons (make-string 0)
(cons (make-string 6 #\6)
(cons (list->string '(#\1 #\2 #\3 #\4 #\5))
(cons (string->list "yellow")
(cons (string-length "123")
(cons str 
 '()))))))))