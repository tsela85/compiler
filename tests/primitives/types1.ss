(list 
(boolean? 7)   (boolean? "bla")   (boolean? (lambda (x) x))   (boolean? #f)   (boolean? #\s)   (boolean? '(#t 4))   (boolean? boolean?)
(integer? 7)   (integer? "bla")   (integer? (lambda (x) x))   (integer? #f)   (integer? #\s)   (integer? '(#t 4))   (integer? integer?)
(procedure? 7) (procedure? "bla") (procedure? (lambda (x) x)) (procedure? #f) (procedure? #\s) (procedure? '(#t 4)) (procedure? integer?)
(string? 7)  (string? "bla")  (string? (lambda (x) x))  (string? #f)  (string? #\s)  (string? '(#t 4))  (string? string?))