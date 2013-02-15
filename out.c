#include <stdio.h>
#include <stdlib.h>
#include "cisc.h"
#define SHOW(msg, x) { printf("%s %s = %ld\n", (msg), (#x), (x)); }


int main()
{
  START_MACHINE;
  int consts[]={937610, 722689, 741553, 0, 741553, 1, 799345, 1, 43, 368031, 49, 799345, 1, 45, 368031, 51, 799345, 4, 99, 111, 110, 115, 368031, 53, 799345, 3, 99, 97, 114, 368031, 55, 945311, 2, 945311, 12, 945311, 7, 945311, 5, 16, 0, 21, 0, 26, 0, 34, 0};
  memcpy(&machine->mem[10],consts,sizeof(consts));
   MOV(ADDR(0), IMM(57));
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
MOV(R1,49);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

//applic pushing args to stack
MOV(R0,45);
PUSH(R0);
MOV(R0,47);
PUSH(R0);

//applic pushing number of args
PUSH(IMM(2));
//fvar: +
MOV(R0,49);
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

//applic pushing args to stack
MOV(R0,41);
PUSH(R0);
MOV(R0,43);
PUSH(R0);

//applic pushing number of args
PUSH(IMM(2));
//fvar: +
MOV(R0,49);
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