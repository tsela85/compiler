
; stress test for applic

(define range '(0 1 2))

(define (from-rows rows)
  (lambda (i j)
    (list-ref (list-ref rows i) j)))
    
(define (to-rows m)
  (map (lambda (i) (map (lambda (j) (m i j)) range)) range))    

(define (mul a b)
  (lambda (i j)
    (apply + (map (lambda (k) (* (a i k) (b k j))) range))))

(define (Id i j)
	(if (eq? i j) 1 0))
   
(define (pow m p)
  (if (eq? p 0) Id
    (mul m (pow m (- p 1)))))
  
(define A (from-rows '((1 2 1) (2 -1 0) (-1 2 -1))))

(to-rows (pow A 7))