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
(define ^label-clos-nil (^^label "L_clos_nil_"))
(define ^label-clos-body (^^label "L_clos_body_"))
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
          ((or (tag? 'tc-applic pe) (tag? 'applic pe))
           (code-gen-applic pe))
;          ((tag? 'applic pe) (code-gen-applic pe))
;          ((tag? 'tc-applic pe) (code-gen-tc-applic2 pe))
          ((tag? 'lambda-simple pe) (code-gen-lambda-s pe))
          ((tag? 'lambda-variadic pe) (code-gen-lambda-var pe))
          ((tag? 'lambda-opt pe) (code-gen-lambda-opt pe))
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
  "int i,j;" nl
  body nl

"  POP(FP);
//  print_stack(\"dd\");
//  print_heap(\"dd\");
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
             "//the var name is: " ( symbol->string v) nl
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
                  (lambda-code
                  (string-append
                  "//extending the env by 1" nl
                  "//allocating space for the new env" nl
                  "PUSH(IMM("(number->string env-size)"));" nl
                  "CALL(MALLOC);" nl
                  "DROP(IMM(1));" nl
                  "MOV(R2,R0); //R2 <- new env" nl
                  "//shifting the old enviroment" nl
                  "MOV(R1,FPARG(IMM(0))); //R1 <- env" nl

                  "//R2[j] <- R1[i]" nl
                  "for(i=0,j=1;i<"(number->string (- env-size 1))";++i,++j){" nl

                  "  MOV(INDD(R2,IMM(j)),INDD(R1,IMM(i)));" nl
                  "}" nl

                  "//moving params from the stack to the first list in env" nl
                  "//allocating space" nl
                  "PUSH(FPARG(IMM(1)));" nl
                  "CALL(MALLOC);" nl
                  "DROP(IMM(1));" nl
                  "MOV(R3,R0); // R3 <- new env[0]" nl

                  "for (i=0;i<FPARG(IMM(1));++i) { " nl
                  "  MOV(INDD(R3,i),FPARG((IMM(2+i)))); //R3[i] <- param[i]" nl
                  "}" nl
                  "MOV(INDD(R2,0),R3); // new env[0] <- R3" nl

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

(define code-gen-lambda-var
  (lambda (e)
    (with e
          (lambda (_ args body)
            (set! env-size (+ env-size 1))
            (let* ((label-clos (^label-clos-code))
                   (label-clos-exit (^label-clos-exit))
                   (label-clos-nil (^label-clos-nil))
                   (label-clos-body (^label-clos-body))
                   (lambda-code
                    (string-append
                  "//extending the env by 1" nl
                  "//allocating space for the new env" nl
                  "PUSH(IMM("(number->string env-size)"));" nl
                  "CALL(MALLOC);" nl
                  "DROP(IMM(1));" nl
                  "MOV(R2,R0); //R2 <- new env" nl
                  "//shifting the old enviroment" nl
                  "MOV(R1,FPARG(IMM(0))); //R1 <- env" nl
                  "//R2[j] <- R1[i]" nl
                  "for(i=0,j=1;i<"(number->string (- env-size 1))";++i,++j){" nl
                  "  MOV(INDD(R2,IMM(j)),INDD(R1,IMM(i)));" nl
                  "}" nl
                  "//moving params from the stack to the first list in env" nl
                  "//allocating space" nl
                  "PUSH(FPARG(IMM(1)));" nl
                  "CALL(MALLOC);" nl
                  "DROP(IMM(1));" nl
                  "MOV(R3,R0); // R3 <- new env[0]" nl
                  "for (i=0;i<FPARG(IMM(1));++i) { " nl
                  "  MOV(INDD(R3,i),FPARG((IMM(2+i)))); //R3[i] <- param[i]" nl
                  "}" nl
                  "MOV(INDD(R2,0),R3); // new env[0] <- R3" nl
                  "PUSH(LABEL("label-clos"));" nl
                  "PUSH(R2);" nl
                  "CALL(MAKE_SOB_CLOSURE);" nl
                  "DROP(IMM(2));" nl
                  "JUMP("label-clos-exit");" nl
                  label-clos":" nl
                  "  PUSH(FP);" nl
                  "  MOV(FP,SP);" nl
                  "//converting args to list" nl
                  "MOV(R3,FPARG(IMM(1))); //R3<-amount of args" nl
                  "CMP(IMM(0),R3); //check if args count = 0" nl
                  "JUMP_EQ("label-clos-nil");" nl
                  "MOV(R4,FPARG(IMM(R3 + 1))); //R4<- last arg" nl
                  "PUSH(SOB_NIL); //last element is nil" nl
                  "PUSH(R4); //last arg" nl
                  "CALL(MAKE_SOB_PAIR);" nl
                  "DROP(IMM(2));" nl
                  "for(i = R3; i > 1;i--) {" nl
                  "   PUSH(R0); //previous pair" nl
                  "   PUSH(FPARG(i)); // next element" nl
                  "   CALL(MAKE_SOB_PAIR);" nl
                  "   DROP(IMM(2));" nl
                  "}" nl

                  "//fixing stack to conatin the list" nl
                  "MOV(FPARG(IMM(1)),IMM(1));//change amount of a to  1" nl
                  "MOV(FPARG(IMM(2)),R0);//change the first element to the list we made" nl
                  "//push down the stack" nl
                  "for(i=0; i < 5 ; i++) {" nl
                  "   MOV(FPARG(IMM(R3 + 1-i)),FPARG(IMM(2-i)));" nl
                  "}" nl
                  "DROP(R3-1); //update SP" nl
                  "MOV(FP,SP); //update FP" nl
                  "JUMP("label-clos-body");" nl
                  label-clos-nil ":" nl
                  "for(i = -2;i < 2;i++) {" nl
                  "   MOV(FPARG(i-1),FPARG(i));" nl
                  "}" nl
                  "INCR(FP);" nl
                  "INCR(SP);" nl
                  "MOV(FPARG(IMM(1)),IMM(1));//change amount of a to  1" nl
                  "MOV(FPARG(IMM(2)),SOB_NIL);//change the first element to the list we made" nl
                  label-clos-body ":" nl
                  "  //lambda-body" nl
                  "  "(code-gen body) nl
                  "  POP(FP);" nl
                  "  RETURN;" nl
                  label-clos-exit":" nl


                  )))
                  (set! env-size (- env-size 1))
                  lambda-code)))))


(define code-gen-lambda-opt
  (lambda (e)
    (with e
          (lambda (_ args opt body)
            (set! env-size (+ env-size 1))
            (let* ((label-clos (^label-clos-code))
                   (label-clos-exit (^label-clos-exit))
                   (label-clos-nil (^label-clos-nil))
                   (label-clos-body (^label-clos-body))
                   (args-size (number->string (length args)))
                   (lambda-code
                    (string-append
                  "//extending the env by 1" nl
                  "//allocating space for the new env" nl
                  "PUSH(IMM("(number->string env-size)"));" nl
                  "CALL(MALLOC);" nl
                  "DROP(IMM(1));" nl
                  "MOV(R2,R0); //R2 <- new env" nl
                  "//shifting the old enviroment" nl
                  "MOV(R1,FPARG(IMM(0))); //R1 <- env" nl
                  "//R2[j] <- R1[i]" nl
                  "for(i=0,j=1;i<"(number->string (- env-size 1))";++i,++j){" nl
                  "  MOV(INDD(R2,IMM(j)),INDD(R1,IMM(i)));" nl
                  "}" nl
                  "//moving params from the stack to the first list in env" nl
                  "//allocating space" nl
                  "PUSH(FPARG(IMM(1)));" nl
                  "CALL(MALLOC);" nl
                  "DROP(IMM(1));" nl
                  "MOV(R3,R0); // R3 <- new env[0]" nl
                  "for (i=0;i<FPARG(IMM(1));++i) { " nl
                  "  MOV(INDD(R3,i),FPARG((IMM(2+i)))); //R3[i] <- param[i]" nl
                  "}" nl
                  "MOV(INDD(R2,0),R3); // new env[0] <- R3" nl
                  "PUSH(LABEL("label-clos"));" nl
                  "PUSH(R2);" nl
                  "CALL(MAKE_SOB_CLOSURE);" nl
                  "DROP(IMM(2));" nl
                  "JUMP("label-clos-exit");" nl
                  label-clos":" nl
                  "  PUSH(FP);" nl
                  "  MOV(FP,SP);" nl
                  "MOV(R3,FPARG(IMM(1))); //R3<-amount of args" nl
                  "CMP(IMM(0),R3 - "args-size"); //check if opt count = 0" nl
                  "JUMP_EQ("label-clos-nil");" nl
                  "//converting OPT args to list args: " args-size  nl
                  "MOV(R4,FPARG(IMM(R3 + 1))); //R4<- last arg" nl
                  "PUSH(SOB_NIL); //last element is nil" nl
                  "PUSH(R4); //last arg" nl
                  "CALL(MAKE_SOB_PAIR);" nl
                  "DROP(IMM(2));" nl
                  "for(i = R3; i >  "args-size" + 1;i--) {" nl
                  "   PUSH(R0); //previous pair" nl
                  "   PUSH(FPARG(i)); // next element" nl
                  "   CALL(MAKE_SOB_PAIR);" nl
                  "   DROP(IMM(2));" nl
                  "}" nl

                  "//lambda-opt fixing stack to conatin the list" nl
                  "MOV(FPARG(IMM(1)),"(number->string (+ (string->number args-size)   1))  ");//change amount of a to arg: " args-size " +1" nl
                  "MOV(FPARG(IMM("(number->string (+ 2 (string->number args-size) )) ")),R0);//change the first opt to the list we made" nl

                  "//lambda-opt push down the stack" nl
                  "for(i=0; i <= R3-"args-size"+2 ; i++) {" nl
                  "   MOV(FPARG(IMM(R3 + 1-i)),FPARG(IMM("(number->string (+ 2 (string->number args-size) ))"-i)));" nl
                  "}" nl
                  "DROP(R3-"args-size"-1); //update SP" nl
                  "MOV(FP,SP); //update FP" nl
                  "JUMP("label-clos-body");" nl
                  label-clos-nil ":" nl
                  "for(i = -2;i < "(number->string (+ 2 (string->number args-size) )) ";i++) {" nl
                  "   MOV(FPARG(i-1),FPARG(i));"
                  "}" nl
                  "INCR(FP);" nl
                  "INCR(SP);" nl
                  "MOV(FPARG(IMM(1)),"(number->string (+ (string->number args-size)  1))  ");//change amount of a to arg: " args-size " +1" nl
                  "MOV(FPARG(IMM("(number->string (+ 2 (string->number args-size) )) ")),SOB_NIL);//change the first element to the list we made" nl
                  label-clos-body ":" nl
                  "  //lambda-body" nl
                  "  "(code-gen body) nl
                  "  POP(FP);" nl
                  "  RETURN;" nl
                  label-clos-exit":" nl

                  )))
                  (set! env-size (- env-size 1))
                  lambda-code)))))


(define code-gen-applic
  (lambda (e)
    (with e
          (lambda (_ proc ex-list)
            (let ((label-err (^label-applic-err))
                      (m (number->string (length ex-list))))
              (string-append
                "//applic pushing args to stack" nl
            (code-gen-applic-helper (reverse ex-list)) nl
                "//applic pushing number of args" nl
                "PUSH(IMM("m"));" nl
                (code-gen proc) nl
                "CMP(INDD(R0,0),T_CLOSURE);" nl
                "JUMP_NE(error);" nl
                "PUSH(INDD(R0,IMM(1)));//push clousre env" nl
                "CALLA(INDD(R0,IMM(2)));" nl
                "//applic drop number of args" nl
;                "DROP(IMM("m"+2));" nl ; //TODO: m+2
                "MOV(R10,IMM(STARG(IMM(0)))) //TODO: TEMP move sp " nl
;                "printf(\"drop: %d fp: %d\\n\",(int)(SP-IMM(STARG(IMM(0))+IMM(2))),(int)FP );" nl
                 "DROP(IMM(STARG(IMM(0))+IMM(2)));" nl
;                "MOV(SP,FP); //TODO: remove" nl

                ))))))

(define code-gen-tc-applic
  (lambda (e)
    (with e
          (lambda (_ proc ex-list)
            (let ((label-err (^label-applic-err))
                  (m (number->string (length ex-list))))
              (string-append
               "//tc-applic pushing args to stack" nl
               (code-gen-applic-helper (reverse ex-list)) nl
               "//tc-applic pushing number of args" nl
               "PUSH(IMM("m"));" nl
;               "PUSH(IMM(FPARG(1)));" nl
               (code-gen proc) nl
               "CMP(INDD(R0,0),T_CLOSURE);" nl

               "JUMP_NE(error);" nl
               "PUSH(INDD(R0,IMM(1)));" nl
               "//tc-applic changes" nl
     "printf(\"OLD FP: %d\\n\",FP); printf(\"OLD SP: %d\\n\",SP);" nl
               "//tc-applic push old ret" nl
               "PUSH(FPARG(IMM(-1)));" nl
               ; "MOV(R1,FP)" nl ;current frame fp
               "MOV(R15,FPARG(-2)) //saving old fp" nl
               "MOV(R2,FPARG(IMM(1))); //saving old number of n" nl
               "//copy stack to old stack" nl
               "for(i=0; i < IMM(STARG(IMM(0)))+3;i++) {" nl
;               "for(i=0; i < "m"+3;i++) {" nl
               "  MOV(FPARG(R2 + 1 -i),LOCAL(i));" nl
               "}" nl
               "//NOT SURE THAT IT IS TRUE - update sp" nl
               "//update sp to size of frame" nl
;               "MOV(SP,R15 + 3 +" m ");" nl
;               "MOV(SP,R15 + 3 + IMM(FPARG(1)));" nl
               "MOV(SP,R15 + 3 + IMM(STARG(IMM(0))));" nl
               "//tc-applic  get old fp to run over the old stack" nl
               "MOV(FP,R15)" nl
  "printf(\"NEW FP: %d\\n \",FP); printf(\"NEW SP: %d\\n\",SP);" nl
               "JUMPA(INDD(R0,2));"nl
               ))))))

(define code-gen-tc-applic2
  (lambda (e)
    (with e
          (lambda (_ proc ex-list)
            (let ((label-err (^label-applic-err))
                  (m (number->string (length ex-list))))
              (string-append
               "//tc-applic pushing args to stack" nl
               (code-gen-applic-helper (reverse ex-list)) nl
               "//tc-applic pushing number of args" nl
               "PUSH(IMM("m"));" nl
               (code-gen proc) nl
               "CMP(INDD(R0,0),T_CLOSURE);" nl
               "JUMP_NE(error);" nl
               "PUSH(INDD(R0,IMM(1)));//push closure env" nl
               "//tc-applic changes" nl
               "PUSH(FPARG(IMM(-1))); //pushing to the top of the frame  the ret of the old frame" nl
               "MOV(R1,FPARG(-2)); //R1<-prev frame fp" nl
               "MOV(R2,STARG(1)); //R2<- amount of current args" nl
               "//copy current frame to old frame" nl
               "for(i=0; i < R2 + 3; i++) {" nl
               "   MOV(STACK(R1 + i),LOCAL(i));" nl
               "}" nl
               "MOV(FP,R1); //update fp" nl
               "MOV(SP,FP + R2 + 3); //SP<- old fp + args count + 3" nl
               "JUMPA(INDD(R0,2)); //tc-applic jumpint to cluser code"nl
               ))))))


(define code-gen-applic-helper
  (lambda (e)
    (if (null? e)
            ""
                (string-append
                (code-gen (car e)) nl
                "PUSH(R0);" nl
                (code-gen-applic-helper (cdr e))))))
