#include <stdio.h>
#include <stdlib.h>
#include "cisc.h"
#define SHOW(msg, x) { printf("%s %s = %ld\n", (msg), (#x), (x)); }


int main()
{
  START_MACHINE;
  void print_stack(char* comment){
        int i;
        printf("printing stack, FP: %d SP: %d %\n", (int)(FP), (int)(SP), comment);
        for(i=SP+5; i>=0; --i){
        if(SP == i){
                printf("SP");
        }
        if(FP == i){
                printf("FP");
        }
        printf("\t element %d: ", i);
        SHOW(" ", STACK(i));
        }
}
void print_heap(){
        int i;
        printf("printing heap\n");
        for (i=ADDR(0); i>=0; i--){
                printf("\t element %d: ", i);
        SHOW(" ",ADDR(i));
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
  #include "char.lib"
  #include "io.lib"
  #include "math.lib"
  #include "string.lib"
  #include "system.lib"
  #include "scheme.lib"

  CONTINUE:
PUSH(IMM(4));
PUSH(IMM(5));
PUSH(IMM(2));
PUSH(0);
PUSH(0);
PUSH(FP);
MOV(FP,SP);
int i,j;
//pushing args to stack
PUSH(8);
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));
PUSH(R0);
//pushing args to stack
PUSH(1234);
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));
PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_15:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(0));
JUMP_LT(L_clos_loop_15);
POP(R15);
//moving params from the stack to the first list in env
//allocating space
PUSH(FPARG(IMM(1)));
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0); // R3 <- new env[0]
for (i=0;i<FPARG(IMM(1));++i) { 
  MOV(INDD(R3,i),FPARG((IMM(2+i)))); //R3[i] <- param[i]
}
MOV(INDD(R2,0),R3); // new env[0] <- R3
PUSH(LABEL(L_clos_code_15));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_15);
L_clos_code_15:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_15:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);
MOV(R0,SOB_BOOLEAN_FALSE);
PUSH(R0);

//pushing number of args
PUSH(IMM(3));
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_14:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(0));
JUMP_LT(L_clos_loop_14);
POP(R15);
//moving params from the stack to the first list in env
//allocating space
PUSH(FPARG(IMM(1)));
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0); // R3 <- new env[0]
for (i=0;i<FPARG(IMM(1));++i) { 
  MOV(INDD(R3,i),FPARG((IMM(2+i)))); //R3[i] <- param[i]
}
MOV(INDD(R2,0),R3); // new env[0] <- R3
PUSH(LABEL(L_clos_code_14));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_14);
L_clos_code_14:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

CMP(R0, SOB_BOOLEAN_FALSE);
JUMP_EQ(L_if3_else_7);
MOV(R0,FPARG(IMM(2+1)));

JUMP(L_if3_exit_7);
L_if3_else_7:
MOV(R0,FPARG(IMM(2+2)));

L_if3_exit_7:

  POP(FP);
  RETURN;
L_clos_exit_14:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(3+2));

  POP(FP);
  print_stack("dd");
  print_heap("dd");
  PUSH(R0);
  CALL(WRITE_SOB);
  DROP(IMM(1));

  STOP_MACHINE;

  return 0;
error:
  printf("ERROR\n");
  STOP_MACHINE;
  return 1;}