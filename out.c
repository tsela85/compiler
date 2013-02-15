#include <stdio.h>
#include <stdlib.h>
#include "cisc.h"
#define SHOW(msg, x) { printf("%s %s = %ld\n", (msg), (#x), (x)); }


int main()
{
  START_MACHINE;
  int consts[]={937610, 722689, 741553, 0, 741553, 1, 799345, 1, 43, 368031, 98, 799345, 1, 45, 368031, 100, 799345, 1, 42, 368031, 102, 799345, 1, 47, 368031, 104, 799345, 4, 99, 111, 110, 115, 368031, 106, 799345, 3, 99, 97, 114, 368031, 108, 799345, 3, 99, 100, 114, 368031, 110, 799345, 8, 115, 101, 116, 45, 99, 97, 114, 33, 368031, 112, 799345, 8, 115, 101, 116, 45, 99, 100, 114, 33, 368031, 114, 799345, 5, 97, 112, 112, 108, 121, 368031, 116, 799345, 5, 117, 118, 97, 115, 97, 16, 0, 21, 0, 26, 0, 31, 0, 36, 0, 44, 0, 51, 0, 58, 0, 70, 0, 82, 0};
  memcpy(&machine->mem[10],consts,sizeof(consts));
   MOV(ADDR(0), IMM(118));
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
MOV(R1,98);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(BIN_MINUS));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,100);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(BIN_DIV));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,104);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(BIN_MUL));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,102);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(CONS));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,106);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(CAR));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,108);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(CDR));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,110);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(SET_CAR));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,112);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(SET_CDR));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,114);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(APPLY));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,116);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);


MOV(R0,91);
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