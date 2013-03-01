; an application in the middle of evaluating arguments
(define f (lambda x x))
(f
  'a
  (((lambda (a b)
     (lambda (f g) (list a b f g))) 1 2) 3 4)
  'c)