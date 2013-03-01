(list
(symbol? 7) (symbol? "bla") (symbol? (lambda (x) x)) (symbol? #f) (symbol? #\s) (symbol? '(#t 4)) (symbol? symbol?)
(vector? 7) (vector? "bla") (vector? (lambda (x) x)) (vector? #f) (vector? #\s) (vector? '(#t 4)) (vector? vector?)
(char? 7) 	(char? "bla")   (char? (lambda (x) x))   (char? #f)   (char? #\s)   (char? '(#t 4))   (char? char?)
(pair? 7) 	(pair? "bla")   (pair? (lambda (x) x))   (pair? #f)   (pair? #\s)   (pair? '(#t 4))   (pair? pair?))