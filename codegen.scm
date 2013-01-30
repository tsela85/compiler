(load "compiler.scm")

(define ^^label
(lambda (name)
(let ((n 0))
(lambda ()
(set! n (+ n 1))
(string-append name
(number->string n))))))
(define ^label-if3else (^^label "L_if3_else_"))
(define ^label-if3exit (^^label "L_if3_exit_"))
(define ^label-or-exit (^^label "L_or_exit_"))
(define ^label-clos-code (^^label "L_clos_code_"))
(define ^label-clos-exit (^^label "L_clos_exit_"))
(define ^label-loop (^^label "L_loop_"))
(define ^label-applic-err (^^label "L_applic_err_"))

(define nl (list->string (list #\newline)))

(define code-gen
  (lambda (pe)
    (cond
          ((tag? 'const pe) (code-gen-const pe))
          ((tag? 'if-3 pe) (code-gen-if3 pe))
          ((tag? 'seq pe) (code-gen-seq pe))
          ((tag? 'or pe) (code-gen-or pe))
          ((tag? 'pvar pe) (code-gen-pvar pe))
          ((tag? 'bvar pe) (code-gen-bvar pe))
          ((or (tag? 'tc-applic pe) (tag? 'applic pe)) (code-gen-applic pe))
          ((tag? 'lambda-simple pe) (code-gen-lambda-s pe))
          (else "not implemented")
          )))

(define create-code
  (lambda (pe)
    (if (file-exists? "out.c")
            (delete-file "out.c"))
    (let* ((out (open-output-file "out.c"))
               (body (code-gen pe))
               (code (string-append
"#include <stdio.h>
#include <stdlib.h>
#include \"cisc.h\"
#define SHOW(msg, x) { printf(\"%s %s = %ld\\n\", (msg), (#x), (x)); }


int main()
{
  START_MACHINE;
  void print_stack(char* comment){
        int i;
        printf(\"printing stack, FP: %d SP: %d %\\n\", (int)(FP), (int)(SP), comment);
        for(i=SP+5; i>=0; --i){
        if(SP == i){
                printf(\"SP\");
        }
        if(FP == i){
                printf(\"FP\");
        }
        printf(\"\\t element %d: \", i);
        SHOW(\" \", STACK(i));
        }
}
void print_heap(){
        int i;
        printf(\"printing heap\\n\");
        for (i=ADDR(0); i>=0; i--){
                printf(\"\\t element %d: \", i);
        SHOW(\" \",ADDR(i));
        }
}
  #define SOB_VOID 1
  #define SOB_NIL 2
  #define SOB_BOOLEAN_FALSE 3
  #define SOB_BOOLEAN_TRUE 5
  CALL(MAKE_SOB_VOID);
  CALL(MAKE_SOB_NIL);
  PUSH(IMM(0));
  CALL(MAKE_SOB_BOOL);
  DROP(1);
  PUSH(IMM(1));
  CALL(MAKE_SOB_BOOL);
  DROP(1);
  JUMP(CONTINUE);
  #include \"char.lib\"
  #include \"io.lib\"
  #include \"math.lib\"
  #include \"string.lib\"
  #include \"system.lib\"
  #include \"scheme.lib\"

  CONTINUE:" nl
  "PUSH(IMM(4));" nl
  "PUSH(IMM(5));" nl
  "PUSH(IMM(2));" nl
  "PUSH(0);" nl
  "PUSH(0);" nl
  ;"PUSH(0);" nl
  "PUSH(FP);" nl
  "MOV(FP,SP);" nl
  ;"MOV(FP,SP);" nl
  body nl

"  POP(FP);
  print_stack(\"dd\");
  print_heap(\"dd\");
  PUSH(R0);
  CALL(WRITE_SOB);
  DROP(IMM(1));

  STOP_MACHINE;

  return 0;
error:
  printf(\"ERROR\\n\");
  STOP_MACHINE;
  return 1;}"))
                   )
                   (display code out)
                   (close-output-port out))))

(define compile
  (lambda (e)
    (create-code (test e))))

(define code-gen-if3
  (lambda (e)
    (with e
          (lambda (if3 test do-if-true do-if-false)
            (let ((code-test (code-gen test))
                      (code-dit (code-gen do-if-true))
                          (code-dif (code-gen do-if-false))
                          (label-else (^label-if3else))
                          (label-exit (^label-if3exit)))
                        (string-append
                        code-test nl ; when run, the result of the test will be in R0
                        "CMP(R0, SOB_BOOLEAN_FALSE);" nl
                        "JUMP_EQ(" label-else ");" nl
                        code-dit nl
                        "JUMP(" label-exit ");" nl
                        label-else ":" nl
                        code-dif nl
                        label-exit ":" nl))))))

(define code-gen-const
  (lambda (e)
    (cond
          ((boolean? (cadr e)) (code-gen-boolean (cadr e)))
          ((number? (cadr e)) (code-gen-int (cadr e)))
          (else e))))

(define code-gen-boolean
  (lambda (e)
    (if e
        "MOV(R0,SOB_BOOLEAN_TRUE);"
                "MOV(R0,SOB_BOOLEAN_FALSE);")))

(define code-gen-int
  (lambda (e)
    (string-append
          "PUSH("(number->string e)");" nl
          "CALL(MAKE_SOB_INTEGER);" nl
          "DROP(IMM(1));")))

(define code-gen-seq
  (lambda (e)
    (with e
          (lambda (_ ex-list)
            (code-gen-seq-helper ex-list)))))

(define code-gen-seq-helper
  (lambda (e)
    (if (null? e)
            ""
                (string-append (code-gen (car e)) nl (code-gen-seq-helper (cdr e))))))

(define code-gen-or
  (lambda (e)
    (with e
          (lambda (_ ex-list)
            (let ((label-exit (^label-or-exit)))
                  (string-append (code-gen-or-helper ex-list label-exit)
                                 label-exit ":" nl))))))

(define code-gen-or-helper
  (lambda (e label-exit)
    (if (null? e)
            "";(string-append label-exit ":")
                (string-append (code-gen (car e)) nl
                "CMP(R0, SOB_BOOLEAN_FALSE);" nl
                "JUMP_NE(" label-exit ");" nl
                (code-gen-or-helper (cdr e) label-exit)))))

(define code-gen-pvar
  (lambda (e)
    (with e
          (lambda (_ v mi)
            (string-append
                "MOV(R0,FPARG(IMM(2+"(number->string mi)")));" nl)
                ))))

(define code-gen-bvar
  (lambda (e)
    (with e
          (lambda (_ v maj mi)
            (string-append
                "//bvar: maj: "(number->string maj)", min: "(number->string mi) nl
                "MOV(R0,FPARG(IMM(0)));" nl
                "MOV(R0,INDD(R0,IMM("(number->string maj)")));" nl
                "MOV(R0,INDD(R0,IMM("(number->string mi)")));" nl)
                ))))


(define env-size 0)

(define code-gen-lambda-s
  (lambda (e)
    (with e
          (lambda (_ args body)
              (set! env-size (+ env-size 1))
                  (let* ((label-clos (^label-clos-code))
                         (label-clos-exit (^label-clos-exit))
;                         (label-clos-loop (^label-clos-loop))
                         (lambda-code
                          (string-append
                           "//creating sob of size 3 and put 'T_CLOSURE' in the 0th place" nl
                           "PUSH(IMM(3));" nl
                           "CALL(MALLOC);" nl
                           "DROP(IMM(1));" nl
                           "MOV(INDD(R0,0),T_CLOSURE);" nl
                           "MOV(R1,R0); //r1 holds a pointer to the closure struct" nl
                           "//extending the env by 1" nl
                           "//allocating space for the new env" nl
                           "PUSH(IMM("(number->string env-size)"));" nl
                           "CALL(MALLOC);" nl
                           "DROP(IMM(1));" nl
                           "MOV(R2,R0); //R2 <- new env" nl
                           "//shifting the old enviroment" nl
                           "MOV(R1,FPARG(IMM(0))); //R1 <- env" nl

                           "//LOOP" nl
                           (generate-loop (string-append "MOV(INDD(R2,R15 + 1),INDD(R1,R15));" nl) "0"
                                          (number->string (- env-size 1)) " 1")

                           "//moving params from the stack to the first list in env" nl
                           "//allocating space" nl
                           "PUSH(FPARG(IMM(1)));" nl
                           "CALL(MALLOC);" nl
                           "DROP(IMM(1));" nl
                           "MOV(R3,R0); // R3 <- new env[0]" nl

                           (generate-loop (string-append "MOV(INDD(R3,R15),FPARG((IMM(2+R15)))); //R3[R15] <- param[R15]" nl) "0"
                                          "FPARG(IMM(1))"   " 1")
;                           "for (i=0;i<FPARG(IMM(1));++i) { " nl
;                           "  MOV(INDD(R3,i),FPARG((IMM(2+i)))); //R3[i] <- param[i]" nl
;                           "}" nl
                           "MOV(INDD(R2,0),R3); // new env[0] <- R3" nl
                                        ;"MOV(INDD(R1,1),R3); // R1[1] <- R3" nl
                           "PUSH(LABEL("label-clos"));" nl
                           "PUSH(R2);" nl
                           "CALL(MAKE_SOB_CLOSURE);" nl
                           "DROP(IMM(2));" nl
                           "JUMP("label-clos-exit");" nl
                           label-clos":" nl
                           "  PUSH(FP);" nl
                           "  MOV(FP,SP);" nl
                           "  //lambda-body" nl
                           "  "(code-gen body) nl
                           "  POP(FP);" nl
                           "  RETURN;" nl
                           label-clos-exit":" nl


                           )))
                    (set! env-size (- env-size 1))
                    lambda-code

                    )))))

(define code-gen-applic
  (lambda (e)
    (with e
          (lambda (_ proc ex-list)
            (let ((label-err (^label-applic-err))
                      (m (number->string (length ex-list))))
                (string-append
                "//pushing args to stack" nl
            (code-gen-applic-helper (reverse ex-list)) nl
                "//pushing number of args" nl
                "PUSH(IMM("m"));" nl
                (code-gen proc) nl
                "CMP(INDD(R0,0),T_CLOSURE);" nl
                "JUMP_NE(error);" nl
                "PUSH(INDD(R0,IMM(1)));" nl
                "CALLA(INDD(R0,IMM(2)));" nl
                "DROP(IMM("m"+2));" nl ; //TODO: m+2
                ))))))

(define code-gen-applic-helper
  (lambda (e)
    (if (null? e)
            ""
                (string-append
                (code-gen (car e)) nl
                "PUSH(R0);" nl
                (code-gen-applic-helper (cdr e))))))


(define generate-loop
  (lambda (body startval endval step)
    (let ((label-loop (^label-loop)))
      (string-append
       "PUSH(R15);" nl
       "MOV(R15,IMM(" startval "));" nl
       label-loop":" nl
       body
       "ADD(R15,IMM" step ");" nl
       "CMP(R15,IMM(" endval "));" nl
       "JUMP_LT("label-loop ");" nl
       "POP(R15);" nl
       ))))


(compile '((lambda (x y z) (if x y z)) #t ((lambda (i) i) 7) 8))
(trace generate-loop)
(untrace)
(compile '((lambda (x) (if x 9 6)) #f))
(compile '((lambda (x y z) (if x y z)) #f 7 8))
(compile '((lambda (x y z) (if x y z)) #t ((lambda (i) i) 7) 8))
(compile '((lambda (x y z) (if x y z)) #t ((lambda (i) i) 7) 8))
(compile '((lambda (x y z) (if x y z)) ((lambda (m n) n) #t #f) ((lambda (i) i) 7) 8))
(compile '((lambda (x y z) (if x y z)) ((lambda (m n) m) #t #f) ((lambda (i) i) 7) 8))
(compile '((lambda (x y z) (if x y z)) ((lambda (m n) m) ((lambda(x) x) #t) #f) ((lambda (i) i) 7) 8))
(compile '((lambda (x y z) (if x y z)) ((lambda (m n) m) ((lambda(x) x) (if 3 4 5)) #f) ((lambda (i) i) 7) 8))
