(letrec 
   ((f (lambda (x y) x))
    (g (lambda (x y) y)))
   ((((lambda (x y) (x g f)) f g) g f) 'blip 'blop))