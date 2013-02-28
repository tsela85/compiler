;;; compiler.scm
;;;
;;; Programmer: ???

;;; general support routines

(define with (lambda (s f) (apply f s)))

(define member?
  (lambda (a s)
    (ormap
     (lambda (b) (eq? a b))
     s)))

(define file->list
  (lambda (filename)
    (let ((port (open-input-file filename)))
      (letrec ((loop
                (lambda ()
                  (let ((ch (read-char port)))
                    (if (eof-object? ch) '()
                        (cons ch (loop)))))))
        (let ((s (loop)))
          (close-input-port port)
          s)))))

(define make-char-between?
  (lambda (char<=?)
    (lambda (char-from char-to)
      (lambda (char)
        (and (char<=? char-from char)
             (char<=? char char-to))))))

;;; The scanner recognizes parenthesis and single quote.
;;; It knows to ignore comments up to the end of the current input line,
;;; as well as whitespaces.

(define list->tokens
  (letrec ((st-init
            (lambda (s)
              (cond
               ((null? s) '())
               ((char=? (car s) #\;) (st-comment s))
               ((char=? (car s) #\.) `((dot) ,@(st-init (cdr s))))
               ((char=? (car s) #\') `((single-quote) ,@(st-init (cdr s))))
               ((char=? (car s) #\`) `((quasiquote) ,@(st-init (cdr s))))
               ((char=? (car s) #\,) (st-unquote (cdr s)))
               ((char=? (car s) #\() `((lparen) ,@(st-init (cdr s))))
               ((char=? (car s) #\)) `((rparen) ,@(st-init (cdr s))))
               ((char=? (car s) #\#) (st-hash (cdr s)))
               ((char=? (car s) #\") (st-string (cdr s) '()))
               ((char-whitespace? (car s)) (st-init (cdr s)))
               ((char-symbol? (car s))
                (st-symbol/number (cdr s) (list (car s))))
               (else (scanner-error "What's this" s)))))
           (st-unquote
            (lambda (s)
              (cond ((null? s) `((unquote) ,@(st-init '())))
                    ((char=? (car s) #\@)
                     `((,'unquote-splicing) ,@(st-init (cdr s))))
                    (else `((,'unquote) ,@(st-init s))))))
           (st-symbol/number
            (lambda (s chars)
              (cond ((null? s)
                     `(,(make-symbol/number-token chars) ,@(st-init '())))
                    ((char-symbol? (car s))
                     (st-symbol/number (cdr s) (cons (car s) chars)))
                    ((char-delimiter? (car s))
                     `(,(make-symbol/number-token chars) ,@(st-init s)))
                    (else (scanner-error "At the end of a symbol: " s)))))
           (st-string
            (lambda (s chars)
              (cond ((null? s)
                     (scanner-error "Expecting a \" char to close the string"))
                    ((char=? (car s) #\")
                     `((string ,(list->string (reverse chars)))
                       ,@(st-init (cdr s))))
                    ((char=? (car s) #\\) (st-meta-char (cdr s) chars))
                    (else (st-string (cdr s) (cons (car s) chars))))))
           (st-meta-char
            (lambda (s chars)
              (cond ((null? s)
                     (scanner-error
                      "Expecting a string meta-char; reached EOF"))
                    ((char=? (car s) #\\) (st-string (cdr s) (cons #\\ chars)))
                    ((char=? (car s) #\") (st-string (cdr s) (cons #\" chars)))
                    ((char-ci=? (car s) #\n)
                     (st-string (cdr s) (cons #\newline chars)))
                    ((char-ci=? (car s) #\r)
                     (st-string (cdr s) (cons #\return chars)))
                    ((char-ci=? (car s) #\t)
                     (st-string (cdr s) (cons #\tab chars)))
                    ((char-ci=? (car s) #\f)
                     (st-string (cdr s) (cons #\page chars)))
                    (else (scanner-error "What kind of a meta-char is " s)))))
           (st-hash
            (lambda (s)
              (cond ((null? s)
                     (scanner-error
                      "Expecting something after #, but reached end"))
                    ((char=? (car s) #\() `((vector) ,@(st-init (cdr s))))
                    ((char=? (car s) #\\) (st-char-1 (cdr s)))
                    ((char-ci=? (car s) #\f)
                     `((boolean #f) ,@(st-init (cdr s))))
                    ((char-ci=? (car s) #\t)
                     `((boolean #t) ,@(st-init (cdr s))))
                    ((char=? (car s) #\;) `((comment) ,@(st-init (cdr s))))
                    (else (scanner-error
                           "Expecting t, f, \\, ( after #, but found" s)))))
           (st-char-1
            (lambda (s)
              (cond ((null? s) (error 'scanner "Must be one char after #\\"))
                    (else (st-char (cdr s) (list (car s)))))))
           (st-char
            (lambda (s chars)
              (cond ((null? s) `((char ,(make-char chars)) ,@(st-init '())))
                    ((char-delimiter? (car s))
                     `((char ,(make-char chars)) ,@(st-init s)))
                    (else (st-char (cdr s) (cons (car s) chars))))))
           (st-comment
            (lambda (s)
              (cond ((null? s) (st-init '()))
                    ((char=? (car s) #\newline) (st-init (cdr s)))
                    (else (st-comment (cdr s)))))))
    (lambda (s)
      (st-init s))))

(define make-symbol/number-token
  (lambda (chars)
    (let* ((string (list->string (reverse chars)))
           (maybe-number (string->number string)))
      (if (number? maybe-number)
          `(number ,maybe-number)
          `(symbol ,(string->symbol (string-downcase string)))))))

(define make-char
  (lambda (chars)
    (cond ((null? chars) (scanner-error "Found #\\ without any char"))
          ((null? (cdr chars)) (car chars))
          (else (let* ((string (list->string (reverse chars)))
                       (maybe-number (string->number string 8)))
                  (if (number? maybe-number)
                      (integer->char maybe-number)
                      (cond ((string-ci=? string "return") #\return)
                            ((string-ci=? string "newline") #\newline)
                            ((string-ci=? string "space") #\space)
                            ((string-ci=? string "tab") #\tab)
                            ((string-ci=? string "page") #\page)
                            (else (scanner-error
                                   "Can't recognize the following character: "
                                   (format "#\\~s" string))))))))))

(define char-alphabetic? ((make-char-between? char-ci<=?) #\a #\z))
(define char-decimal? ((make-char-between? char<=?) #\0 #\9))

(define char-symbol?
  (let ((punc-chars (string->list "!@$%^*-_=+<>./?:")))
    (lambda (char)
      (or (char-alphabetic? char)
          (char-decimal? char)
          (ormap
           (lambda (punc-char) (char=? punc-char char))
           punc-chars)))))

(define char-whitespace?
  (lambda (char)
    (char<=? char #\space)))

(define char-delimiter?
  (lambda (char)
    (or (char-whitespace? char)
        (not (char-symbol? char)))))

(define scanner-error
  (lambda (message s)
    (if (null? s)
        (error 'list-tokens message)
        (error 'list-tokens
               (format "~a: [~s]~a"
                       message
                       (car s)
                       (list->string (cdr s)))))))

(define file->tokens
  (lambda (filename)
    (list->tokens
     (file->list filename))))

(define string->tokens
  (lambda (string)
    (list->tokens
     (string->list string))))

;;;
;;; TASK 1
;;;

(define tokens->sexprs
  (letrec ((get-sexpr
            (lambda (toks ret-sexpr+toks ret-none)
              (cond ((or (null? toks)
                         (eq? (caar toks) 'rparen)
                         (eq? (caar toks) 'dot))
                     (ret-none))
;simple form
                    ((ormap (lambda (tag) (eq? (caar toks) tag))
                            '(boolean char number string symbol))
                     (ret-sexpr+toks (cadar toks) (cdr toks)))
;simple quote form
                    ((eq? (caar toks) 'single-quote)
                     (get-sexpr (cdr toks)
                                (lambda (sexpr2 tok2)
                                  (ret-sexpr+toks  (list 'quote sexpr2) tok2))
                                (lambda () 'Expected_an_sexpr_after_qoute)))
;other qoute form
                    ((ormap (lambda (tag) (eq? (caar toks) tag))
                            '(quasiquote unquote unquote-splicing))
                     (get-sexpr (cdr toks)
                                (lambda (sexpr2 tok2)
                                  (ret-sexpr+toks  (list (caar toks) sexpr2) tok2))
                                (lambda () 'Expected_an_sexpr_after_qouteType)))
;list type
                    ((eq? (caar toks) 'lparen)
                     (get-sexprs (cdr toks)
                                 (lambda (sexpr2 tok2)
                                   (cond  ((null? tok2) ;missing rparen/dot
                                           (error 'tokens->sexprs
                                                  (format "List type is missing rparen/dot ~s" toks)))
                                        ;list
                                          ((eq? (caar tok2) 'rparen)
                                           (ret-sexpr+toks sexpr2 (cdr tok2)))
                                        ;ImproperList
                                          ((eq? (caar tok2) 'dot)
                                           (get-sexpr (cdr tok2)
                                                      (lambda (sexpr3 tok3)
                                                        (if (eq? (caar toks) 'lparen)
                                                            (ret-sexpr+toks `(,@sexpr2 . ,sexpr3) (cdr tok3))
                                                            (error 'tokens->sexprs
                                                                   (format "ImproperList  missing rparen ~s" toks))))
                                                        (lambda () 'ImproperList missing rparen))
                                           )))))
;vector
                    ((eq? (caar toks) 'vector)
                     (get-sexprs (cdr toks)
                                 (lambda (sexpr2 tok2)
                                   (cond  ((null? tok2) ;missing rparen
                                           (error 'tokens->sexprs
                                                  (format "vector is missing rparen ~s" toks)))
                                          ((eq? (caar tok2) 'rparen)
                                           (ret-sexpr+toks (list->vector sexpr2) (cdr tok2)))
                                          (else (error 'tokens->sexprs
                                                       (format "vector is missing rparen ~s" toks)))))))
;unreconized form
                    (else (error 'tokens->sexprs
                                (format "I can't recognize an sexpr in ~s" toks))))))

           (get-sexprs
            (lambda (toks ret-sexprs+toks)
              (get-sexpr toks
               (lambda (sexpr toks)
                 (get-sexprs toks
                  (lambda (sexprs toks)
                    (ret-sexprs+toks (cons sexpr sexprs) toks))))
               (lambda () (ret-sexprs+toks '() toks))))))

    (lambda (toks)
      (get-sexprs toks
       (lambda (sexprs toks)
         (if (null? toks)
             sexprs
             'error))))
    ))

;;;
;;; TASK 2
;;;

;;; const

(define const?
  (lambda (sexpr)
    (or (number? sexpr) (boolean? sexpr) (char? sexpr) (string? sexpr) (vector? sexpr))
    ))

(define parse-const
  (lambda (sexpr)
    (list 'const sexpr)))

;;; quote

(define quote?
  (lambda (sexpr)
    (and (pair? sexpr) (equal? (car sexpr) 'quote))
    ))

(define parse-quote
  (lambda (sexpr)
    (list 'const (cadr sexpr))))

;;; var

(define parse-var
  (lambda (sexpr)
    (list 'var sexpr)))

(define reserved '(if lambda cond define begin or and let let* letrec quasiquote))

(define non-reserved
  (lambda (sexpr reserved-list)
    (if (null? reserved-list)
        #t
        (if (equal? sexpr (car reserved-list))
            #f
            (non-reserved sexpr (cdr reserved-list))))
    ))

(define var?
  (lambda (sexpr)
    (and (not (vector? sexpr))(not (list? sexpr)) (non-reserved sexpr reserved))))

;;;if

(define if-3?
  (lambda (sexpr)
    (and (pair? sexpr) (equal? (car sexpr) 'if) (not (null? (cdr sexpr)))(not (null? (cddr sexpr)))(not (null? (cdddr sexpr)))(null? (cddddr sexpr)))
    ))

(define parse-if-3
  (lambda (sexpr)
    (list 'if-3 (parse (cadr sexpr)) (parse (caddr sexpr)) (parse (cadddr sexpr)) )))

(define if-2?
  (lambda (sexpr)
    (and (pair? sexpr) (equal? (car sexpr) 'if) (not (null? (cdr sexpr)))(not (null? (cddr sexpr)))(null? (cdddr sexpr)))
    ))

(define parse-if-2
  (lambda (sexpr)
    (list 'if-3 (parse (cadr sexpr)) (parse (caddr sexpr)) `(const ,void-object))))

;;;lambda

(define not-dup?
(lambda (e)
(cond ((list? e) (= (length (dedupe e)) (length e)))
(else #t))))

(define lambda?
  (lambda (sexpr)
    (and (pair? sexpr) (equal? (car sexpr) 'lambda)(pair? (cdr sexpr))(pair? (cddr sexpr)) (not-dup? (cadr sexpr)))))

(define parse-lambda-helper
  (lambda (sexpr ret-pro ret-imp ret-sym)
    (cond ((pair? sexpr)
           (parse-lambda-helper (cdr sexpr)
                                ret-pro
                                (lambda (s a) (ret-imp (cons (car sexpr) s) a))
                                (lambda () (ret-imp (list (car sexpr)) (cdr sexpr)))))
          ((null? sexpr) (ret-pro))
          (else (ret-sym)))))

(define parse-lambda
  (lambda (sexpr)
    (let ((arg1 (cadr sexpr))
          ;(body (parse (caddr sexpr))))
          (body (parse (beginify (cddr sexpr)))))
      (parse-lambda-helper arg1
                           (lambda () `(lambda-simple ,arg1 ,body))
                           (lambda (s a) `(lambda-opt ,s ,a ,body))
                           (lambda () `(lambda-variadic ,arg1 ,body))))))

;;; define

(define define?
  (lambda (sexpr)
    (and (pair? sexpr)(equal? (car sexpr) 'define)(pair? (cdr sexpr))(pair? (cddr sexpr)) (or (and (var? (cadr sexpr)) (null? (cdddr sexpr)))
                                                                                              (and (list? (cadr sexpr)) (var? (caadr sexpr)) (null? (cdddr sexpr)))))))

(define parse-define
  (lambda (sexpr)
    (cond ((pair? (cadr sexpr)) (list 'define (parse (caadr sexpr))(parse-lambda (list 'lambda (cdadr sexpr) (caddr sexpr)))))
          (else (list 'define (parse (cadr sexpr)) (parse (caddr sexpr)))))))

;;; applic

(define applic?
  (lambda (sexpr)
    (and (list? sexpr) (not (null? sexpr)) (or (list? (car sexpr)) (var? (car sexpr))))))

(define parse-applic
  (lambda (sexpr)
    (list 'applic (parse (car sexpr)) (parse-applic-args (cdr sexpr)))))

(define parse-applic-args
  (lambda (sexpr)
    (if (null? sexpr)
        sexpr
        (cons (parse (car sexpr)) (parse-applic-args (cdr sexpr))))))

;;;begin

(define begin?
  (lambda (sexpr)
    (and (pair? sexpr)(equal? (car sexpr) 'begin)(not (null? (cdr sexpr))))))

(define parse-begin
  (lambda (sexpr)
    (list 'seq (parse-applic-args (cdr sexpr)))))

(define beginify
  (lambda (sexpr)
    (cond ((null? sexpr) void-object)
          ((null? (cdr sexpr)) (car sexpr))
          (else `(begin ,@sexpr) ))))

;;; or

(define or?
  (lambda (sexpr)
    (and (pair? sexpr)(equal? (car sexpr) 'or))))

(define parse-or
 (lambda (sexpr)
   (cond ((null? (cdr sexpr)) (parse '#f))
         ((null? (cddr sexpr)) (parse (cadr sexpr)))
         (else (list 'or (map parse (cdr sexpr)))))))

;;; and

(define and?
  (lambda (sexpr)
    (and (pair? sexpr)(equal? (car sexpr) 'and))))

(define expand-and
 (lambda (sexpr)
   (cond ((null? (cdr sexpr)) '#t)
         ((null? (cddr sexpr)) (cadr sexpr))
         (else (expand-and-helper (cdr sexpr))))))

(define expand-and-helper
  (lambda (sexpr)
    (cond ((null? (cddr sexpr)) `(if ,(car sexpr) ,(cadr sexpr) #f))
           (else `(if ,(car sexpr) ,(expand-and-helper (cdr sexpr)) #f)
           ))))

;;; cond

(define cond?
  (lambda (sexpr)
    (and (pair? sexpr) (equal? (car sexpr) 'cond) (pair? (cdr sexpr)) (not (null? (cdr sexpr))) (cond?-helper (cdr sexpr)))))

(define cond?-helper
  (lambda (sexpr)
    (and (pair? sexpr) (not (null? sexpr)) (pair? (car sexpr)) (not (null? (car sexpr)))
         (or (and (equal? (caar sexpr) 'else) (pair? (cdar sexpr)) (not (null? (cdar sexpr))) (null? (cdr sexpr)))
             (not (equal? (caar sexpr) 'else)))
         (or (null? (cdr sexpr)) (cond?-helper (cdr sexpr))))))

(define expand-cond-helper
  (lambda (sexpr)
    (cond ((null? (cdr sexpr))
           (if (equal? (caar sexpr) 'else)
               (beginify (cdar sexpr))
               `(if ,(caar sexpr) ,(beginify (cdar sexpr)))))
          (else `(if ,(caar sexpr) ,(beginify (cdar sexpr)) ,(expand-cond-helper (cdr sexpr)))))
     ))

(define expand-cond
  (lambda (sexpr)
    (expand-cond-helper (cdr sexpr))))

;;; let

(define let?
  (lambda (sexpr)
    (and (pair? sexpr) (equal? (car sexpr) 'let) (pair? (cdr sexpr))(pair? (cddr sexpr))(or (null? (cadr sexpr)) (and (pair? (cadr sexpr)) (andmap (lambda(x)
                                                                                                                       (and (pair? x)
                                                                                                                            (= (length x) 2)))
                                                                                                                     (cadr sexpr)))))))
(define expand-let
 (lambda (sexpr)
   (let ((args (map car (cadr sexpr)))
         (vals (map cadr (cadr sexpr)))
         (body (cddr sexpr)))
     (cond ((and (null? args) (null? vals)) `((lambda ,args ,@body) ))
           ((and (not (null? args)) (not (null? vals))) `((lambda ,args ,@body) ,@vals ))
           (else "error")))))

;;; let*

(define let*?
  (lambda (sexpr)
    (and (pair? sexpr) (equal? (car sexpr) 'let*) (pair? (cdr sexpr))(pair? (cddr sexpr))(or (null? (cadr sexpr)) (pair? (cadr sexpr)) (andmap (lambda(x)
                                                                                                                       (and (pair? x)
                                                                                                                            (= (length x) 2)))
                                                                                                                     (cadr sexpr))))))

(define expand-let*
 (lambda (sexpr)
   (let ((args (map car (cadr sexpr)))
         (vals (map cadr (cadr sexpr)))
         (body (cddr sexpr)))
     (expand-let*-helper args vals body))))

(define expand-let*-helper
 (lambda (args vals body)
   (cond ((and (null? args) (null? vals)) `((lambda () ,@body)))
         ((and (null? (cdr args)) (null? (cdr vals))) `((lambda (,(car args)) ,@body) ,(car vals)))
         (else `((lambda (,(car args)) ,(expand-let*-helper (cdr args) (cdr vals) body)) ,(car vals))))))

;;; quasiquote

(define expand-qq
  (lambda (e)
    (cond ((unquote? e) (cadr e))
          ((unquote-splicing? e) (error 'expand-qq "unquote-splicing here makes no sense!"))
          ((pair? e)
           (let ((a (car e))
                 (b (cdr e)))
             (cond ((unquote-splicing? a) `(append ,(cadr a) ,(expand-qq b)))
                   ((unquote-splicing? b) `(cons ,(expand-qq a) ,(cadr b)))
                   (else `(cons ,(expand-qq a) ,(expand-qq b))))))
          ((vector? e) `(list->vector ,(expand-qq (vector->list e))))
          ((or (null? e) (symbol? e)) `',e)
          (else e))))

(define ^quote?
  (lambda (tag)
    (lambda (e)
      (and (pair? e)
           (eq? (car e) tag)
           (pair? (cdr e))
           (null? (cddr e))))))

(define qq? (^quote? 'quasiquote))

(define unquote? (^quote? 'unquote))
(define unquote-splicing? (^quote? 'unquote-splicing))

;;;letrec

(define letrec?
  (lambda (sexpr)
    (and (pair? sexpr) (equal? (car sexpr) 'letrec) (pair? (cdr sexpr))(pair? (cddr sexpr))(pair? (cadr sexpr)) (andmap (lambda(x)
                                                                                                                       (and (pair? x)
                                                                                                                            (= (length x) 2)
                                                                                                                                                                                                                                                        (lambda? (cadr x))))
                                                                                                                     (cadr sexpr)))))

(define with (lambda (s f) (apply f s)))

(define Yn
  (lambda fs
    (let ((ms (map
                  (lambda (fi)
                    (lambda ms
                      (apply fi
                             (map (lambda (mi)
                                    (lambda args
                                      (apply (apply mi ms) args)))
                               ms))))
                fs)))
      (apply (car ms) ms))))

(define expand-letrec
  (lambda (e)
    (with e
      (lambda (_letrec ribs . exprs)
        (let* ((names `(,(gensym) ,@(map car ribs)))
               (fs `((lambda ,names ,@exprs)
                     ,@(map (lambda (rib) `(lambda ,names ,(cadr rib)))
                         ribs))))
          `(Yn ,@fs))))))

(define (dedupe e)
  (if (null? e) '()
      (cons (car e) (dedupe (filter (lambda (x) (not (equal? x (car e))))
          (cdr e))))))

(define void-object (if #f #t))

(define parse
  (lambda (sexpr)
    (cond ((const? sexpr) (parse-const sexpr))
          ((quote? sexpr) (parse-quote sexpr))
          ((var? sexpr) (parse-var sexpr))
          ((if-3? sexpr) (parse-if-3 sexpr))
          ((if-2? sexpr) (parse-if-2 sexpr))
          ((lambda? sexpr) (parse-lambda sexpr))
          ((define? sexpr) (parse-define sexpr))
          ((applic? sexpr) (parse-applic sexpr))
          ((begin? sexpr) (parse-begin sexpr))
          ((or? sexpr) (parse-or sexpr))
          ((cond? sexpr) (parse (expand-cond sexpr)))
          ((and? sexpr) (parse (expand-and sexpr)))
          ((let? sexpr) (parse (expand-let sexpr)))
          ((let*? sexpr) (parse (expand-let* sexpr)))
                  ((qq? sexpr) (parse (expand-qq (cadr sexpr))))
                  ((letrec? sexpr) (parse (expand-letrec sexpr)))
                  (else (error 'parse (format "~s is not legal expression" sexpr)))
      )))



;;;
;;; ASSIGNMENT 3
;;;


(define tag?
  (lambda (tag exp)
    (if (pair? exp)
        (eq? tag (car exp))
        #f)))

;;;task1

(define search-in-rib
        (lambda (a s ret-min ret-nf)
                (cond ((null? s) (ret-nf))
                        ((eq? (car s) a) (ret-min 0))
                        (else (search-in-rib a (cdr s)
                                        (lambda (min)
                                                        (ret-min (+ 1 min)))
                                        ret-nf)))))

(define search-in-ribs
        (lambda (a env ret-maj+min ret-nf)
                (if (null? env)
                        (ret-nf)
                        (search-in-rib a (car env)
                                (lambda (min)
                                                (ret-maj+min 0 min))
                                (lambda ()
                                                (search-in-ribs a (cdr env)
                                                        (lambda (maj min)
                                                                (ret-maj+min (+ 1 maj) min))
                                                        ret-nf))))))

(define run
        (lambda (pe params env)
                (cond   ((tag? 'const pe) pe)
                                ((tag? 'var pe)
                                        (with pe
                                                (lambda (_ v)
                                                        (search-in-rib v params
                                                                (lambda (min) `(pvar ,v ,min))
                                                                (lambda() (search-in-ribs v env
                                                                        (lambda (min maj) `(bvar ,v ,min ,maj))
                                                                        (lambda () `(fvar ,v)) ))))))
                                ((tag? 'if-3 pe)
                                        (with pe
                                                (lambda (_ test dit dif)
                                                        `(if-3 ,(run test params env) ,(run dit params env) ,(run dif params env)))))
                                ((tag? 'lambda-simple pe)
                                        (with pe
                                                (lambda (_ args body)
                                                        `(lambda-simple ,args ,(run body args (cons params env))))))

                                ((tag? 'lambda-opt pe)
                                        (with pe
                                                (lambda (_ args opt body)
                                                        (let ((args2 `(,@args ,opt)))
                                                        `(lambda-opt ,args ,opt ,(run body args2 (cons params env)))))))

                                ((tag? 'lambda-variadic pe)
                                        (with pe
                                                (lambda (_ args body)
                                                        `(lambda-variadic ,args ,(run body (list args) (cons params env))))))

                                ((tag? 'define pe)
                                        (with pe
                                                (lambda (_ var exp)
                                                        `(define ,(run var params env) ,(run exp params env)))))
                                ((or (tag? 'applic pe) )
                                        (with pe
                                                (lambda (tag proc args)
                                                        `(,tag ,(run proc params env) ,(map (lambda (ex)
                                                                                                                                        (run ex params env)) args)))))
                                ((tag? 'seq pe)
                                        (with pe
                                                (lambda (_ exps)
                                                        `(seq ,(map (lambda (ex)
                                                                                (run ex params env)) exps)))))
                                ((tag? 'or pe)
                                        (with pe
                                                (lambda (_ exps)
                                                        `(or ,(map (lambda (ex)
                                                                                (run ex params env)) exps)))))

                                (else pe) )))

(define pe->lex-pe
        (letrec ((run
                        (lambda (pe params env)
                                (cond   ((tag? 'const pe) pe)
                                                ((tag? 'var pe)
                                                        (with pe
                                                                (lambda (_ v)
                                                                        (search-in-rib v params
                                                                                (lambda (min) `(pvar ,v ,min))
                                                                                (lambda() (search-in-ribs v env
                                                                                        (lambda (min maj) `(bvar ,v ,min ,maj))
                                                                                        (lambda () `(fvar ,v)) ))))))
                                                ((tag? 'if-3 pe)
                                                        (with pe
                                                                (lambda (_ test dit dif)
                                                                        `(if-3 ,(run test params env) ,(run dit params env) ,(run dif params env)))))
                                                ((tag? 'lambda-simple pe)
                                                        (with pe
                                                                (lambda (_ args body)
                                                                        `(lambda-simple ,args ,(run body args (cons params env))))))

                                                ((tag? 'lambda-opt pe)
                                                        (with pe
                                                                (lambda (_ args opt body)
                                                                        (let ((args2 `(,@args ,opt)))
                                                                        `(lambda-opt ,args ,opt ,(run body args2 (cons params env)))))))

                                                ((tag? 'lambda-variadic pe)
                                                        (with pe
                                                                (lambda (_ args body)
                                                                        `(lambda-variadic ,args ,(run body (list args) (cons params env))))))

                                                ((tag? 'define pe)
                                                        (with pe
                                                                (lambda (_ var exp)
                                                                        `(define ,(run var params env) ,(run exp params env)))))
                                                ((or (tag? 'applic pe) )
                                                        (with pe
                                                                (lambda (tag proc args)
                                                                        `(,tag ,(run proc params env) ,(map (lambda (ex)
                                                                                                                                                        (run ex params env)) args)))))
                                                ((tag? 'seq pe)
                                                        (with pe
                                                                (lambda (_ exps)
                                                                        `(seq ,(map (lambda (ex)
                                                                                                (run ex params env)) exps)))))
                                                ((tag? 'or pe)
                                                        (with pe
                                                                (lambda (_ exps)
                                                                        `(or ,(map (lambda (ex)
                                                                                                (run ex params env)) exps)))))

                                                (else (error 'pe->lex-pe (format "~s is not legal parsed expression" pe)))) )))

        (lambda (pe)
                (run pe '() '()))))

;;;Task2


(define annotate-tc
  (letrec ((divide-tc
            (lambda (pe new-tc?)
              `(,@(map (lambda (x)
                         (run x #f))
                       (list-head (cadr pe) (- (length (cadr pe)) 1))) ,(run (car (reverse (cadr pe))) new-tc?))))

           (all-but-last
            (lambda (pe func tc?)
              (if (null? (cdr pe))
                  (func (car pe) tc?)
                  (cons (func (car pe) #f) (all-but-last (cdr pe) func tc?)))))
           (run
            (lambda (pe tc?)
              (cond ((tag? 'const pe) pe)
                    ((tag? 'fvar pe) pe)
                    ((tag? 'pvar pe) pe)
                    ((tag? 'bvar pe) pe)
                    ((tag? 'if-3 pe)
                     (with pe
                           (lambda (_ test dit dif)
                             `(if-3 ,(run test #f)
                                    ,(run dit tc?)
                                    ,(run dif tc?)))))
                    ((tag? 'lambda-simple pe)
                     (with pe
                           (lambda (tag param body)
                             `(,tag ,param ,(run body #t)))))
                    ((tag? 'lambda-opt pe)
                     (with pe
                           (lambda (tag param opt body)
                             `(,tag ,param ,opt ,(run body #t)))))
                    ((tag? 'lambda-variadic pe)
                     (with pe
                           (lambda (tag param body)
                             `(,tag ,param ,(run body #t)))))
                    ((tag? 'define pe)
                     (with pe
                           (lambda (tag var dpe)
                             `(,tag ,var ,(run dpe #f)))))
                    ((tag? 'applic pe)
                     (if (eq? tc? #f)
                         (with pe
                               (lambda (_ proc expList)
                                 `(applic ,(run proc #f)
                                          ,(map (lambda (exp)
                                                  (run exp #f)) expList))))
                         (with pe
                               (lambda (_ proc expList)
                                 `(tc-applic ,(run proc #f)
                                             ,(map (lambda (exp)
                                                     (run exp #f)) expList))))))
                    ((tag? 'seq pe)  `(seq ,(divide-tc pe tc?)))
                    ((tag? 'or pe) `(or ,(divide-tc pe tc?)))
                    (else (error 'annotate-tc (format "~s is not legal parsed expression" pe)))))))
    (lambda (pe)
      (run pe #f)))) ;we changed it to #f on 12.2.13

;;;;

(define test
        (lambda (e)
                (annotate-tc
                        (pe->lex-pe (parse e)))))
