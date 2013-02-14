#include <stdio.h>
#include <stdlib.h>
#include "cisc.h"
#define SHOW(msg, x) { printf("%s %s = %ld\n", (msg), (#x), (x)); } 


int main()
{
  START_MACHINE;
  int consts[]={937610, 722689, 741553, 0, 741553, 1};
  memcpy(&machine->mem[10],consts,sizeof(consts));
   MOV(ADDR(0), IMM(16));
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
PUSH(1);
CALL(MAKE_SOB_INTEGER);
DROP(IMM(1));
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