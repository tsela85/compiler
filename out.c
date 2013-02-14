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
//applic pushing args to stack
MOV(R0,SOB_BOOLEAN_FALSE);
PUSH(R0);
MOV(R0,SOB_BOOLEAN_FALSE);
PUSH(R0);

//applic pushing number of args
PUSH(IMM(2));
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
PUSH(LABEL(L_clos_code_20));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_20);
L_clos_code_20:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //applic pushing args to stack

//applic pushing number of args
PUSH(IMM(0));
//extending the env by 1
//allocating space for the new env
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<1;++i,++j){
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
PUSH(LABEL(L_clos_code_21));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_21);
L_clos_code_21:
  PUSH(FP);
  MOV(FP,SP);
//converting args to list
MOV(R3,FPARG(IMM(1))); //R3<-amount of args
CMP(IMM(0),R3); //check if args count = 0
JUMP_EQ(L_clos_nil_9);
MOV(R4,FPARG(IMM(R3 + 1))); //R4<- last arg
PUSH(SOB_NIL); //last element is nil
PUSH(R4); //last arg
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
for(i = R3; i > 1;i--) {
   PUSH(R0); //previous pair
   PUSH(FPARG(i)); // next element
   CALL(MAKE_SOB_PAIR);
   DROP(IMM(2));
}
//fixing stack to conatin the list
MOV(FPARG(IMM(1)),IMM(1));//change amount of a to  1
MOV(FPARG(IMM(2)),R0);//change the first element to the list we made
//push down the stack
for(i=0; i < 5 ; i++) {
   MOV(FPARG(IMM(R3 + 1-i)),FPARG(IMM(2-i)));
}
DROP(R3-1); //update SP
MOV(FP,SP); //update FP
JUMP(L_clos_body_9);
L_clos_nil_9:
for(i = -2;i < 2;i++) {
   MOV(FPARG(i-1),FPARG(i));
}
INCR(FP);
INCR(SP);
MOV(FPARG(IMM(1)),IMM(1));//change amount of a to  1
MOV(FPARG(IMM(2)),SOB_NIL);//change the first element to the list we made
L_clos_body_9:
  //lambda-body
  //applic pushing args to stack
MOV(R0,SOB_BOOLEAN_TRUE);
PUSH(R0);
MOV(R0,SOB_BOOLEAN_TRUE);
PUSH(R0);
MOV(R0,SOB_BOOLEAN_TRUE);
PUSH(R0);

//applic pushing number of args
PUSH(IMM(3));
//extending the env by 1
//allocating space for the new env
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<2;++i,++j){
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
PUSH(LABEL(L_clos_code_22));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_22);
L_clos_code_22:
  PUSH(FP);
  MOV(FP,SP);
MOV(R3,FPARG(IMM(1))); //R3<-amount of args
CMP(IMM(0),R3 - 1); //check if opt count = 0
JUMP_EQ(L_clos_nil_10);
//converting OPT args to list args: 1
MOV(R4,FPARG(IMM(R3 + 1))); //R4<- last arg
PUSH(SOB_NIL); //last element is nil
PUSH(R4); //last arg
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
for(i = R3; i >  1 + 1;i--) {
   PUSH(R0); //previous pair
   PUSH(FPARG(i)); // next element
   CALL(MAKE_SOB_PAIR);
   DROP(IMM(2));
}
//lambda-opt fixing stack to conatin the list
MOV(FPARG(IMM(1)),2);//change amount of a to arg: 1 +1
MOV(FPARG(IMM(3)),R0);//change the first opt to the list we made
//lambda-opt push down the stack
for(i=0; i <= R3-1+2 ; i++) {
   MOV(FPARG(IMM(R3 + 1-i)),FPARG(IMM(3-i)));
}
DROP(R3-1-1); //update SP
MOV(FP,SP); //update FP
JUMP(L_clos_body_10);
L_clos_nil_10:
for(i = -2;i < 3;i++) {
   MOV(FPARG(i-1),FPARG(i));}
INCR(FP);
INCR(SP);
MOV(FPARG(IMM(1)),2);//change amount of a to arg: 1 +1
MOV(FPARG(IMM(3)),SOB_NIL);//change the first element to the list we made
L_clos_body_10:
  //lambda-body
  //applic pushing args to stack
MOV(R0,SOB_BOOLEAN_FALSE);
PUSH(R0);
MOV(R0,SOB_BOOLEAN_TRUE);
PUSH(R0);
MOV(R0,SOB_BOOLEAN_TRUE);
PUSH(R0);
MOV(R0,SOB_BOOLEAN_FALSE);
PUSH(R0);
MOV(R0,SOB_BOOLEAN_FALSE);
PUSH(R0);
MOV(R0,SOB_BOOLEAN_TRUE);
PUSH(R0);
MOV(R0,SOB_BOOLEAN_TRUE);
PUSH(R0);

//applic pushing number of args
PUSH(IMM(7));
//extending the env by 1
//allocating space for the new env
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<3;++i,++j){
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
PUSH(LABEL(L_clos_code_23));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_23);
L_clos_code_23:
  PUSH(FP);
  MOV(FP,SP);
MOV(R3,FPARG(IMM(1))); //R3<-amount of args
CMP(IMM(0),R3 - 2); //check if opt count = 0
JUMP_EQ(L_clos_nil_11);
//converting OPT args to list args: 2
MOV(R4,FPARG(IMM(R3 + 1))); //R4<- last arg
PUSH(SOB_NIL); //last element is nil
PUSH(R4); //last arg
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
for(i = R3; i >  2 + 1;i--) {
   PUSH(R0); //previous pair
   PUSH(FPARG(i)); // next element
   CALL(MAKE_SOB_PAIR);
   DROP(IMM(2));
}
//lambda-opt fixing stack to conatin the list
MOV(FPARG(IMM(1)),3);//change amount of a to arg: 2 +1
MOV(FPARG(IMM(4)),R0);//change the first opt to the list we made
//lambda-opt push down the stack
for(i=0; i <= R3-2+2 ; i++) {
   MOV(FPARG(IMM(R3 + 1-i)),FPARG(IMM(4-i)));
}
DROP(R3-2-1); //update SP
MOV(FP,SP); //update FP
JUMP(L_clos_body_11);
L_clos_nil_11:
for(i = -2;i < 4;i++) {
   MOV(FPARG(i-1),FPARG(i));}
INCR(FP);
INCR(SP);
MOV(FPARG(IMM(1)),3);//change amount of a to arg: 2 +1
MOV(FPARG(IMM(4)),SOB_NIL);//change the first element to the list we made
L_clos_body_11:
  //lambda-body
  MOV(R0,FPARG(IMM(2+2)));

  POP(FP);
  RETURN;
L_clos_exit_23:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push clousre env
CALLA(INDD(R0,IMM(2)));
//applic drop number of args
MOV(R10,IMM(STARG(IMM(0)))) //TODO: TEMP move sp 
DROP(IMM(STARG(IMM(0))+IMM(2)));

  POP(FP);
  RETURN;
L_clos_exit_22:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push clousre env
CALLA(INDD(R0,IMM(2)));
//applic drop number of args
MOV(R10,IMM(STARG(IMM(0)))) //TODO: TEMP move sp 
DROP(IMM(STARG(IMM(0))+IMM(2)));

  POP(FP);
  RETURN;
L_clos_exit_21:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push clousre env
CALLA(INDD(R0,IMM(2)));
//applic drop number of args
MOV(R10,IMM(STARG(IMM(0)))) //TODO: TEMP move sp 
DROP(IMM(STARG(IMM(0))+IMM(2)));

  POP(FP);
  RETURN;
L_clos_exit_20:

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