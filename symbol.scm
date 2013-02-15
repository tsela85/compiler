(load "compiler.scm")

(define symbols '())
(define buckets '())
(define prims '(+ - * / cons car cdr set-car! set-cdr! apply))

(define const-list
 `((10 ,void-object (937610))
 (11 () (722689))
 (12 #f (741553 0))
 (14 #t (741553 1))))
(define next-mem 16)
(define next-sym 0)
;(set! const-list (cons '(const 3) const-list))

(define list->c-array 
  (lambda (consts) 
    (string-append "{" 
	(apply string-append (cdr (apply append (map (lambda (v) (list ", " (number->string v))) (apply append (map caddr consts)))))) "}")))

(define lookup
  (lambda (con consts)
    (cond
	  ((null? consts) #f)
	  ((equal? con (cadr (car consts))) (caar consts))
	  (else (lookup con (cdr consts))))))

(define add-const
  (lambda (pe consts)
    (if (lookup pe const-list)
       (lookup pe const-list)
	   (begin    
    (cond
	  ((null? pe) 11)
	  ((pair? pe) (add-const-pair pe consts))
	  ((symbol? pe) (add-const-sym pe consts))
	  ((number? pe) (add-const-num pe consts))
	  ((string? pe) (add-const-string pe consts))
	  (else 'error)
	  )))
	  ))
	  
(define add-const-pair
  (lambda (pe consts)
	  (let* ((car-addr (add-const (car pe) consts))
		    (cdr-addr (add-const (cdr pe) consts))
		    (addr next-mem))
		    (set! const-list (append const-list (list (list next-mem pe (list 885397 car-addr cdr-addr)))))
		    (set! next-mem (+ next-mem 3))		 
		 addr)))
	
	;))
	  
(define add-const-string
  (lambda (pe consts)
    (let ((chars (map char->integer (string->list pe)))
	      (str-addr next-mem))
	(set! const-list (append const-list (list (list next-mem pe (cons 799345 (cons (length chars) chars))))))
	(set! next-mem (+ next-mem 2 (length chars)))
	str-addr)))
	  
(define add-const-sym
  (lambda (pe consts)
    (let ((chars (map char->integer (string->list (symbol->string pe)))))
	(set! const-list (append const-list (list (list next-mem (symbol->string pe) (cons 799345 (cons (length chars) chars))))))
	(set! next-mem (+ next-mem 2 (length chars)))
	(set! symbols (append symbols (list pe)))
	(let ((sym-addr next-mem))
		(set! const-list (append const-list (list (list next-mem pe (list 368031 0)))))
		(set! next-mem (+ next-mem 2))
		sym-addr))))
		
(define add-const-num
  (lambda (pe consts)
    ;(let ((chars (map char->integer (string->list (symbol->string pe)))))
	(let ((num-addr next-mem))
		(set! const-list (append const-list (list (list next-mem pe (list 945311 pe)))))
		(set! next-mem (+ next-mem 2))
		num-addr)))

(define find-consts
	(lambda (pe)
		(cond
			((tag? 'const pe) (add-const (cadr pe) const-list))
			((or (tag? 'tc-applic pe) (tag? 'applic pe)) 
				(with pe
					(lambda (tag proc args)
						(find-consts proc)
						(map find-consts args))))
									                  
			((tag? 'fvar pe) (add-const (cadr pe) const-list))
            ((tag? 'pvar pe) pe)
            ((tag? 'bvar pe) pe)
			((tag? 'if-3 pe)
                (with pe
                    (lambda (_ test dit dif)
						(find-consts dif)
						(find-consts dit)
						(find-consts test)
						)))
			((or (tag? 'lambda-simple pe) (tag? 'lambda-variadic pe))
                   (with pe
                        (lambda (tag param body)
                          (find-consts body))))
			((tag? 'lambda-opt pe)
				(with pe
                    (lambda (tag param opt body)
                          (find-consts body))))
						  
			((or (tag? 'seq pe) (tag? 'or pe))
				(with pe
					(lambda (_ exps)
						(map find-consts exps))))
						
			((tag? 'define pe)
			    (with pe
				   (lambda (_ val var)
				      (find-consts val)
					  (find-consts var))))
			(else 'error)
			)
			const-list))
			
(define create-buckets
  (lambda (syms)
    (if (null? syms)
	    (update-consts const-list)
		(begin
		  (if (lookup (car syms) buckets) 
		  'bucket-exists
		  (begin
		    (set! buckets (append buckets (list (list next-mem (car syms) (list (lookup (symbol->string (car syms)) const-list) 0)))))
		    (set! next-mem (+ next-mem 2))))
		  (create-buckets (cdr syms))))))
		  
(define update-consts
  (lambda (consts)
    (cond 
	  ((null? consts) 'finished-update-consts)
	  ((symbol? (cadr (car consts))) (set-car! (cdr (caddr (car consts))) (lookup (cadr (car consts)) buckets)) (update-consts (cdr consts)))
	  (else (update-consts (cdr consts)))
	  )))
	  
(define add-primitives
  (lambda (prim-list)
    (if (null? prim-list)
	    'finished
		(begin (add-const (car prim-list) const-list)
		       (add-primitives (cdr prim-list))))))
			   
(define initialize
  (lambda ()
    (set! const-list `((10 ,void-object (937610)) (11 () (722689)) (12 #f (741553 0)) (14 #t (741553 1))))
	(set! buckets '())
	(set! symbols '())
	(set! next-mem 16)))
		
