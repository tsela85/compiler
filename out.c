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
PUSH(LABEL(L_clos_code_18));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_18);
L_clos_code_18:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
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
PUSH(LABEL(L_clos_code_19));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_19);
L_clos_code_19:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //bvar: maj: 0, min: 0
//the var name is: x
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

  POP(FP);
  RETURN;
L_clos_exit_19:

  POP(FP);
  RETURN;
L_clos_exit_18:

PUSH(R0);

//applic pushing number of args
PUSH(IMM(1));
//applic pushing args to stack
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
PUSH(LABEL(L_clos_code_17));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_17);
L_clos_code_17:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //applic pushing args to stack
MOV(R0,SOB_BOOLEAN_FALSE);
PUSH(R0);

//applic pushing number of args
PUSH(IMM(1));
//applic pushing args to stack
MOV(R0,SOB_BOOLEAN_TRUE);
PUSH(R0);

//applic pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push clousre env
CALLA(INDD(R0,IMM(2)));
//applic drop number of args
MOV(R10,IMM(STARG(IMM(0)))) //TODO: TEMP move sp 
printf("drop: %d fp: %d\n",(int)(SP-IMM(STARG(IMM(0))+IMM(2))),(int)FP );
DROP(IMM(STARG(IMM(0))+IMM(2)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push clousre env
CALLA(INDD(R0,IMM(2)));
//applic drop number of args
MOV(R10,IMM(STARG(IMM(0)))) //TODO: TEMP move sp 
printf("drop: %d fp: %d\n",(int)(SP-IMM(STARG(IMM(0))+IMM(2))),(int)FP );
DROP(IMM(STARG(IMM(0))+IMM(2)));

  POP(FP);
  RETURN;
L_clos_exit_17:

PUSH(R0);

//applic pushing number of args
PUSH(IMM(1));
//applic pushing args to stack
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
PUSH(LABEL(L_clos_code_13));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_13);
L_clos_code_13:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //applic pushing args to stack
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
PUSH(LABEL(L_clos_code_14));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_14);
L_clos_code_14:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
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
PUSH(LABEL(L_clos_code_15));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_15);
L_clos_code_15:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
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
PUSH(LABEL(L_clos_code_16));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_16);
L_clos_code_16:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //applic pushing args to stack
//bvar: maj: 1, min: 0
//the var name is: x
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(1)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//applic pushing number of args
PUSH(IMM(1));
//applic pushing args to stack
//bvar: maj: 0, min: 0
//the var name is: y
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//applic pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push clousre env
CALLA(INDD(R0,IMM(2)));
//applic drop number of args
MOV(R10,IMM(STARG(IMM(0)))) //TODO: TEMP move sp 
printf("drop: %d fp: %d\n",(int)(SP-IMM(STARG(IMM(0))+IMM(2))),(int)FP );
DROP(IMM(STARG(IMM(0))+IMM(2)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push clousre env
CALLA(INDD(R0,IMM(2)));
//applic drop number of args
MOV(R10,IMM(STARG(IMM(0)))) //TODO: TEMP move sp 
printf("drop: %d fp: %d\n",(int)(SP-IMM(STARG(IMM(0))+IMM(2))),(int)FP );
DROP(IMM(STARG(IMM(0))+IMM(2)));

  POP(FP);
  RETURN;
L_clos_exit_16:

  POP(FP);
  RETURN;
L_clos_exit_15:

  POP(FP);
  RETURN;
L_clos_exit_14:

PUSH(R0);

//applic pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push clousre env
CALLA(INDD(R0,IMM(2)));
//applic drop number of args
MOV(R10,IMM(STARG(IMM(0)))) //TODO: TEMP move sp 
printf("drop: %d fp: %d\n",(int)(SP-IMM(STARG(IMM(0))+IMM(2))),(int)FP );
DROP(IMM(STARG(IMM(0))+IMM(2)));

  POP(FP);
  RETURN;
L_clos_exit_13:

PUSH(R0);

//applic pushing number of args
PUSH(IMM(1));
//applic pushing args to stack
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
PUSH(LABEL(L_clos_code_11));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_11);
L_clos_code_11:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
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
PUSH(LABEL(L_clos_code_12));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_12);
L_clos_code_12:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //applic pushing args to stack
//applic pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//applic pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
//the var name is: x
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push clousre env
CALLA(INDD(R0,IMM(2)));
//applic drop number of args
MOV(R10,IMM(STARG(IMM(0)))) //TODO: TEMP move sp 
printf("drop: %d fp: %d\n",(int)(SP-IMM(STARG(IMM(0))+IMM(2))),(int)FP );
DROP(IMM(STARG(IMM(0))+IMM(2)));

PUSH(R0);

//applic pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
//the var name is: x
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push clousre env
CALLA(INDD(R0,IMM(2)));
//applic drop number of args
MOV(R10,IMM(STARG(IMM(0)))) //TODO: TEMP move sp 
printf("drop: %d fp: %d\n",(int)(SP-IMM(STARG(IMM(0))+IMM(2))),(int)FP );
DROP(IMM(STARG(IMM(0))+IMM(2)));

  POP(FP);
  RETURN;
L_clos_exit_12:

  POP(FP);
  RETURN;
L_clos_exit_11:

PUSH(R0);

//applic pushing number of args
PUSH(IMM(1));
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
PUSH(LABEL(L_clos_code_10));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_10);
L_clos_code_10:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //applic pushing args to stack
//applic pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//applic pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push clousre env
CALLA(INDD(R0,IMM(2)));
//applic drop number of args
MOV(R10,IMM(STARG(IMM(0)))) //TODO: TEMP move sp 
printf("drop: %d fp: %d\n",(int)(SP-IMM(STARG(IMM(0))+IMM(2))),(int)FP );
DROP(IMM(STARG(IMM(0))+IMM(2)));

PUSH(R0);

//applic pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push clousre env
CALLA(INDD(R0,IMM(2)));
//applic drop number of args
MOV(R10,IMM(STARG(IMM(0)))) //TODO: TEMP move sp 
printf("drop: %d fp: %d\n",(int)(SP-IMM(STARG(IMM(0))+IMM(2))),(int)FP );
DROP(IMM(STARG(IMM(0))+IMM(2)));

  POP(FP);
  RETURN;
L_clos_exit_10:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push clousre env
CALLA(INDD(R0,IMM(2)));
//applic drop number of args
MOV(R10,IMM(STARG(IMM(0)))) //TODO: TEMP move sp 
printf("drop: %d fp: %d\n",(int)(SP-IMM(STARG(IMM(0))+IMM(2))),(int)FP );
DROP(IMM(STARG(IMM(0))+IMM(2)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push clousre env
CALLA(INDD(R0,IMM(2)));
//applic drop number of args
MOV(R10,IMM(STARG(IMM(0)))) //TODO: TEMP move sp 
printf("drop: %d fp: %d\n",(int)(SP-IMM(STARG(IMM(0))+IMM(2))),(int)FP );
DROP(IMM(STARG(IMM(0))+IMM(2)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push clousre env
CALLA(INDD(R0,IMM(2)));
//applic drop number of args
MOV(R10,IMM(STARG(IMM(0)))) //TODO: TEMP move sp 
printf("drop: %d fp: %d\n",(int)(SP-IMM(STARG(IMM(0))+IMM(2))),(int)FP );
DROP(IMM(STARG(IMM(0))+IMM(2)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push clousre env
CALLA(INDD(R0,IMM(2)));
//applic drop number of args
MOV(R10,IMM(STARG(IMM(0)))) //TODO: TEMP move sp 
printf("drop: %d fp: %d\n",(int)(SP-IMM(STARG(IMM(0))+IMM(2))),(int)FP );
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