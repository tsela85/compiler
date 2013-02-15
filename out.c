#include <stdio.h>
#include <stdlib.h>
#include "cisc.h"
#define SHOW(msg, x) { printf("%s %s = %ld\n", (msg), (#x), (x)); }


int main()
{
  START_MACHINE;
  int consts[]={937610, 722689, 741553, 0, 741553, 1, 799345, 1, 43, 368031, 75, 799345, 1, 45, 368031, 77, 799345, 1, 42, 368031, 79, 799345, 1, 47, 368031, 81, 799345, 4, 99, 111, 110, 115, 368031, 83, 799345, 3, 99, 97, 114, 368031, 85, 799345, 3, 99, 100, 114, 368031, 87, 799345, 5, 97, 112, 112, 108, 121, 368031, 89, 799345, 1, 97, 368031, 91, 885397, 70, 11, 16, 0, 21, 0, 26, 0, 31, 0, 36, 0, 44, 0, 51, 0, 58, 0, 67, 0};
  memcpy(&machine->mem[10],consts,sizeof(consts));
   MOV(ADDR(0), IMM(93));
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
  #define SOB_VOID 10
  #define SOB_NIL 11
  #define SOB_BOOLEAN_FALSE 12
  #define SOB_BOOLEAN_TRUE 14

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
PUSH(LABEL(BIN_PLUS));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,75);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(BIN_MINUS));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,77);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(BIN_DIV));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,81);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(BIN_MUL));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,79);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(APPLY));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,89);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);


//applic pushing args to stack
MOV(R0,72);
PUSH(R0);
//extending the env by 1
//allocating space for the new env
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<0;++i,++j){
  MOV(INDD(R2,IMM(j)),INDD(R1,IMM(i)));
}
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
PUSH(LABEL(L_clos_code_1));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_1);
L_clos_code_1:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_1:

PUSH(R0);

//applic pushing number of args
PUSH(IMM(2));
//fvar: apply
MOV(R0,89);
MOV(R0,INDD(R0,IMM(1)));
CMP(R0,0);
JUMP_EQ(error);

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push clousre env
CALLA(INDD(R0,IMM(2)));
//applic drop number of args
MOV(R10,IMM(STARG(IMM(0)))) //TODO: TEMP move sp 
DROP(IMM(STARG(IMM(0))+IMM(2)));

  POP(FP);
//  print_stack("dd");
//  print_heap("dd");
  PUSH(R0);
  CALL(WRITE_SOB);
  DROP(IMM(1));

  STOP_MACHINE;

  return 0;
error:
  printf("ERROR\n");
  STOP_MACHINE;
  return 1;}