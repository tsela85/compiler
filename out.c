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
MOV(R0,SOB_BOOLEAN_FALSE);
PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
MOV(R0,SOB_BOOLEAN_TRUE);
PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//pushing args to stack
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
PUSH(LABEL(L_clos_code_161));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_161);
L_clos_code_161:
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
PUSH(LABEL(L_clos_code_162));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_162);
L_clos_code_162:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//pushing args to stack
//pushing args to stack
//pushing args to stack
//pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_162:

  POP(FP);
  RETURN;
L_clos_exit_161:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//pushing args to stack
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
PUSH(LABEL(L_clos_code_159));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_159);
L_clos_code_159:
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
PUSH(LABEL(L_clos_code_160));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_160);
L_clos_code_160:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//pushing args to stack
//pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_160:

  POP(FP);
  RETURN;
L_clos_exit_159:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//pushing args to stack
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
PUSH(LABEL(L_clos_code_157));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_157);
L_clos_code_157:
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
PUSH(LABEL(L_clos_code_158));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_158);
L_clos_code_158:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_158:

  POP(FP);
  RETURN;
L_clos_exit_157:

PUSH(R0);

//pushing number of args
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
PUSH(LABEL(L_clos_code_155));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_155);
L_clos_code_155:
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
PUSH(LABEL(L_clos_code_156));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_156);
L_clos_code_156:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//pushing args to stack
//pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_156:

  POP(FP);
  RETURN;
L_clos_exit_155:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
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
PUSH(LABEL(L_clos_code_146));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_146);
L_clos_code_146:
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
PUSH(LABEL(L_clos_code_147));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_147);
L_clos_code_147:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
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
PUSH(LABEL(L_clos_code_153));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_153);
L_clos_code_153:
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
PUSH(LABEL(L_clos_code_154));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_154);
L_clos_code_154:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_154:

  POP(FP);
  RETURN;
L_clos_exit_153:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//pushing args to stack
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
PUSH(LABEL(L_clos_code_148));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_148);
L_clos_code_148:
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
PUSH(LABEL(L_clos_code_149));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_149);
L_clos_code_149:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<4;++i,++j){
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
PUSH(LABEL(L_clos_code_150));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_150);
L_clos_code_150:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<5;++i,++j){
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
PUSH(LABEL(L_clos_code_151));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_151);
L_clos_code_151:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<6;++i,++j){
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
PUSH(LABEL(L_clos_code_152));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_152);
L_clos_code_152:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 1, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(1)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_152:

  POP(FP);
  RETURN;
L_clos_exit_151:

  POP(FP);
  RETURN;
L_clos_exit_150:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_149:

  POP(FP);
  RETURN;
L_clos_exit_148:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_147:

  POP(FP);
  RETURN;
L_clos_exit_146:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
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
PUSH(LABEL(L_clos_code_137));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_137);
L_clos_code_137:
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
PUSH(LABEL(L_clos_code_138));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_138);
L_clos_code_138:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
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
PUSH(LABEL(L_clos_code_144));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_144);
L_clos_code_144:
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
PUSH(LABEL(L_clos_code_145));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_145);
L_clos_code_145:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_145:

  POP(FP);
  RETURN;
L_clos_exit_144:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//pushing args to stack
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
PUSH(LABEL(L_clos_code_139));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_139);
L_clos_code_139:
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
PUSH(LABEL(L_clos_code_140));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_140);
L_clos_code_140:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<4;++i,++j){
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
PUSH(LABEL(L_clos_code_141));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_141);
L_clos_code_141:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<5;++i,++j){
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
PUSH(LABEL(L_clos_code_142));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_142);
L_clos_code_142:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<6;++i,++j){
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
PUSH(LABEL(L_clos_code_143));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_143);
L_clos_code_143:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 1, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(1)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_143:

  POP(FP);
  RETURN;
L_clos_exit_142:

  POP(FP);
  RETURN;
L_clos_exit_141:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_140:

  POP(FP);
  RETURN;
L_clos_exit_139:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_138:

  POP(FP);
  RETURN;
L_clos_exit_137:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//pushing args to stack
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
PUSH(LABEL(L_clos_code_135));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_135);
L_clos_code_135:
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
PUSH(LABEL(L_clos_code_136));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_136);
L_clos_code_136:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//pushing args to stack
//pushing args to stack
//pushing args to stack
//pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_136:

  POP(FP);
  RETURN;
L_clos_exit_135:

PUSH(R0);

//pushing number of args
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
PUSH(LABEL(L_clos_code_101));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_101);
L_clos_code_101:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//pushing args to stack
//pushing args to stack
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
PUSH(LABEL(L_clos_code_134));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_134);
L_clos_code_134:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_134:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
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
PUSH(LABEL(L_clos_code_133));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_133);
L_clos_code_133:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_133:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
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
PUSH(LABEL(L_clos_code_130));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_130);
L_clos_code_130:
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
PUSH(LABEL(L_clos_code_131));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_131);
L_clos_code_131:
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
PUSH(LABEL(L_clos_code_132));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_132);
L_clos_code_132:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//bvar: maj: 1, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(1)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_132:

  POP(FP);
  RETURN;
L_clos_exit_131:

  POP(FP);
  RETURN;
L_clos_exit_130:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
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
PUSH(LABEL(L_clos_code_105));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_105);
L_clos_code_105:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//pushing args to stack
//pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
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
PUSH(LABEL(L_clos_code_127));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_127);
L_clos_code_127:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
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
PUSH(LABEL(L_clos_code_128));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_128);
L_clos_code_128:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<4;++i,++j){
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
PUSH(LABEL(L_clos_code_129));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_129);
L_clos_code_129:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_129:

  POP(FP);
  RETURN;
L_clos_exit_128:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_127:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
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
PUSH(LABEL(L_clos_code_124));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_124);
L_clos_code_124:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
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
PUSH(LABEL(L_clos_code_125));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_125);
L_clos_code_125:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<4;++i,++j){
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
PUSH(LABEL(L_clos_code_126));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_126);
L_clos_code_126:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

  POP(FP);
  RETURN;
L_clos_exit_126:

  POP(FP);
  RETURN;
L_clos_exit_125:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_124:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
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
PUSH(LABEL(L_clos_code_115));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_115);
L_clos_code_115:
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
PUSH(LABEL(L_clos_code_116));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_116);
L_clos_code_116:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<4;++i,++j){
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
PUSH(LABEL(L_clos_code_122));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_122);
L_clos_code_122:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<5;++i,++j){
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
PUSH(LABEL(L_clos_code_123));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_123);
L_clos_code_123:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_123:

  POP(FP);
  RETURN;
L_clos_exit_122:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//pushing args to stack
//extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<4;++i,++j){
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
PUSH(LABEL(L_clos_code_117));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_117);
L_clos_code_117:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<5;++i,++j){
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
PUSH(LABEL(L_clos_code_118));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_118);
L_clos_code_118:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<6;++i,++j){
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
PUSH(LABEL(L_clos_code_119));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_119);
L_clos_code_119:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<7;++i,++j){
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
PUSH(LABEL(L_clos_code_120));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_120);
L_clos_code_120:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(9));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<8;++i,++j){
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
PUSH(LABEL(L_clos_code_121));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_121);
L_clos_code_121:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 1, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(1)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_121:

  POP(FP);
  RETURN;
L_clos_exit_120:

  POP(FP);
  RETURN;
L_clos_exit_119:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_118:

  POP(FP);
  RETURN;
L_clos_exit_117:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_116:

  POP(FP);
  RETURN;
L_clos_exit_115:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//pushing args to stack
//pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
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
PUSH(LABEL(L_clos_code_112));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_112);
L_clos_code_112:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
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
PUSH(LABEL(L_clos_code_113));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_113);
L_clos_code_113:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<4;++i,++j){
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
PUSH(LABEL(L_clos_code_114));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_114);
L_clos_code_114:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

  POP(FP);
  RETURN;
L_clos_exit_114:

  POP(FP);
  RETURN;
L_clos_exit_113:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_112:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
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
PUSH(LABEL(L_clos_code_109));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_109);
L_clos_code_109:
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
PUSH(LABEL(L_clos_code_110));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_110);
L_clos_code_110:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<4;++i,++j){
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
PUSH(LABEL(L_clos_code_111));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_111);
L_clos_code_111:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 1, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(1)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_111:

  POP(FP);
  RETURN;
L_clos_exit_110:

  POP(FP);
  RETURN;
L_clos_exit_109:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
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
PUSH(LABEL(L_clos_code_106));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_106);
L_clos_code_106:
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
PUSH(LABEL(L_clos_code_107));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_107);
L_clos_code_107:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<4;++i,++j){
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
PUSH(LABEL(L_clos_code_108));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_108);
L_clos_code_108:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//bvar: maj: 1, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(1)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_108:

  POP(FP);
  RETURN;
L_clos_exit_107:

  POP(FP);
  RETURN;
L_clos_exit_106:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_105:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
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
PUSH(LABEL(L_clos_code_102));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_102);
L_clos_code_102:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
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
PUSH(LABEL(L_clos_code_103));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_103);
L_clos_code_103:
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
PUSH(LABEL(L_clos_code_104));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_104);
L_clos_code_104:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_104:

  POP(FP);
  RETURN;
L_clos_exit_103:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_102:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_101:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
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
PUSH(LABEL(L_clos_code_31));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_31);
L_clos_code_31:
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
PUSH(LABEL(L_clos_code_32));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_32);
L_clos_code_32:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//pushing args to stack
//pushing args to stack
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
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
PUSH(LABEL(L_clos_code_75));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_75);
L_clos_code_75:
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
PUSH(LABEL(L_clos_code_76));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_76);
L_clos_code_76:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<4;++i,++j){
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
PUSH(LABEL(L_clos_code_77));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_77);
L_clos_code_77:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//pushing args to stack
//pushing args to stack
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<5;++i,++j){
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
PUSH(LABEL(L_clos_code_99));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_99);
L_clos_code_99:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<6;++i,++j){
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
PUSH(LABEL(L_clos_code_100));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_100);
L_clos_code_100:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_100:

  POP(FP);
  RETURN;
L_clos_exit_99:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<5;++i,++j){
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
PUSH(LABEL(L_clos_code_97));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_97);
L_clos_code_97:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<6;++i,++j){
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
PUSH(LABEL(L_clos_code_98));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_98);
L_clos_code_98:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_98:

  POP(FP);
  RETURN;
L_clos_exit_97:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<5;++i,++j){
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
PUSH(LABEL(L_clos_code_94));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_94);
L_clos_code_94:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<6;++i,++j){
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
PUSH(LABEL(L_clos_code_95));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_95);
L_clos_code_95:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<7;++i,++j){
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
PUSH(LABEL(L_clos_code_96));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_96);
L_clos_code_96:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//bvar: maj: 1, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(1)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_96:

  POP(FP);
  RETURN;
L_clos_exit_95:

  POP(FP);
  RETURN;
L_clos_exit_94:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<5;++i,++j){
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
PUSH(LABEL(L_clos_code_81));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_81);
L_clos_code_81:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<6;++i,++j){
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
PUSH(LABEL(L_clos_code_91));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_91);
L_clos_code_91:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<7;++i,++j){
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
PUSH(LABEL(L_clos_code_92));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_92);
L_clos_code_92:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(9));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<8;++i,++j){
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
PUSH(LABEL(L_clos_code_93));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_93);
L_clos_code_93:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

  POP(FP);
  RETURN;
L_clos_exit_93:

  POP(FP);
  RETURN;
L_clos_exit_92:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_91:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//pushing args to stack
//pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<6;++i,++j){
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
PUSH(LABEL(L_clos_code_88));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_88);
L_clos_code_88:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<7;++i,++j){
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
PUSH(LABEL(L_clos_code_89));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_89);
L_clos_code_89:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(9));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<8;++i,++j){
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
PUSH(LABEL(L_clos_code_90));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_90);
L_clos_code_90:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

  POP(FP);
  RETURN;
L_clos_exit_90:

  POP(FP);
  RETURN;
L_clos_exit_89:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_88:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<6;++i,++j){
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
PUSH(LABEL(L_clos_code_85));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_85);
L_clos_code_85:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<7;++i,++j){
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
PUSH(LABEL(L_clos_code_86));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_86);
L_clos_code_86:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(9));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<8;++i,++j){
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
PUSH(LABEL(L_clos_code_87));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_87);
L_clos_code_87:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 1, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(1)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_87:

  POP(FP);
  RETURN;
L_clos_exit_86:

  POP(FP);
  RETURN;
L_clos_exit_85:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<6;++i,++j){
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
PUSH(LABEL(L_clos_code_82));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_82);
L_clos_code_82:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<7;++i,++j){
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
PUSH(LABEL(L_clos_code_83));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_83);
L_clos_code_83:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(9));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<8;++i,++j){
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
PUSH(LABEL(L_clos_code_84));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_84);
L_clos_code_84:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//bvar: maj: 1, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(1)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_84:

  POP(FP);
  RETURN;
L_clos_exit_83:

  POP(FP);
  RETURN;
L_clos_exit_82:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_81:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<5;++i,++j){
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
PUSH(LABEL(L_clos_code_78));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_78);
L_clos_code_78:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<6;++i,++j){
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
PUSH(LABEL(L_clos_code_79));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_79);
L_clos_code_79:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<7;++i,++j){
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
PUSH(LABEL(L_clos_code_80));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_80);
L_clos_code_80:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_80:

  POP(FP);
  RETURN;
L_clos_exit_79:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_78:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_77:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_76:

  POP(FP);
  RETURN;
L_clos_exit_75:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
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
PUSH(LABEL(L_clos_code_69));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_69);
L_clos_code_69:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
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
PUSH(LABEL(L_clos_code_73));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_73);
L_clos_code_73:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<4;++i,++j){
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
PUSH(LABEL(L_clos_code_74));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_74);
L_clos_code_74:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

  POP(FP);
  RETURN;
L_clos_exit_74:

  POP(FP);
  RETURN;
L_clos_exit_73:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
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
PUSH(LABEL(L_clos_code_70));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_70);
L_clos_code_70:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<4;++i,++j){
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
PUSH(LABEL(L_clos_code_71));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_71);
L_clos_code_71:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<5;++i,++j){
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
PUSH(LABEL(L_clos_code_72));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_72);
L_clos_code_72:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_72:

  POP(FP);
  RETURN;
L_clos_exit_71:

  POP(FP);
  RETURN;
L_clos_exit_70:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_69:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//pushing args to stack
//pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
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
PUSH(LABEL(L_clos_code_43));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_43);
L_clos_code_43:
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
PUSH(LABEL(L_clos_code_44));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_44);
L_clos_code_44:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<4;++i,++j){
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
PUSH(LABEL(L_clos_code_45));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_45);
L_clos_code_45:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//pushing args to stack
//pushing args to stack
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<5;++i,++j){
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
PUSH(LABEL(L_clos_code_67));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_67);
L_clos_code_67:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<6;++i,++j){
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
PUSH(LABEL(L_clos_code_68));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_68);
L_clos_code_68:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_68:

  POP(FP);
  RETURN;
L_clos_exit_67:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<5;++i,++j){
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
PUSH(LABEL(L_clos_code_65));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_65);
L_clos_code_65:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<6;++i,++j){
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
PUSH(LABEL(L_clos_code_66));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_66);
L_clos_code_66:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_66:

  POP(FP);
  RETURN;
L_clos_exit_65:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<5;++i,++j){
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
PUSH(LABEL(L_clos_code_62));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_62);
L_clos_code_62:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<6;++i,++j){
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
PUSH(LABEL(L_clos_code_63));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_63);
L_clos_code_63:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<7;++i,++j){
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
PUSH(LABEL(L_clos_code_64));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_64);
L_clos_code_64:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//bvar: maj: 1, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(1)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_64:

  POP(FP);
  RETURN;
L_clos_exit_63:

  POP(FP);
  RETURN;
L_clos_exit_62:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<5;++i,++j){
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
PUSH(LABEL(L_clos_code_49));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_49);
L_clos_code_49:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<6;++i,++j){
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
PUSH(LABEL(L_clos_code_59));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_59);
L_clos_code_59:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<7;++i,++j){
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
PUSH(LABEL(L_clos_code_60));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_60);
L_clos_code_60:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(9));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<8;++i,++j){
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
PUSH(LABEL(L_clos_code_61));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_61);
L_clos_code_61:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

  POP(FP);
  RETURN;
L_clos_exit_61:

  POP(FP);
  RETURN;
L_clos_exit_60:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_59:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//pushing args to stack
//pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<6;++i,++j){
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
PUSH(LABEL(L_clos_code_56));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_56);
L_clos_code_56:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<7;++i,++j){
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
PUSH(LABEL(L_clos_code_57));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_57);
L_clos_code_57:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(9));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<8;++i,++j){
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
PUSH(LABEL(L_clos_code_58));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_58);
L_clos_code_58:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

  POP(FP);
  RETURN;
L_clos_exit_58:

  POP(FP);
  RETURN;
L_clos_exit_57:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_56:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<6;++i,++j){
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
PUSH(LABEL(L_clos_code_53));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_53);
L_clos_code_53:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<7;++i,++j){
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
PUSH(LABEL(L_clos_code_54));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_54);
L_clos_code_54:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(9));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<8;++i,++j){
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
PUSH(LABEL(L_clos_code_55));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_55);
L_clos_code_55:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 1, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(1)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_55:

  POP(FP);
  RETURN;
L_clos_exit_54:

  POP(FP);
  RETURN;
L_clos_exit_53:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<6;++i,++j){
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
PUSH(LABEL(L_clos_code_50));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_50);
L_clos_code_50:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<7;++i,++j){
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
PUSH(LABEL(L_clos_code_51));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_51);
L_clos_code_51:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(9));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<8;++i,++j){
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
PUSH(LABEL(L_clos_code_52));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_52);
L_clos_code_52:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//bvar: maj: 1, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(1)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_52:

  POP(FP);
  RETURN;
L_clos_exit_51:

  POP(FP);
  RETURN;
L_clos_exit_50:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_49:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<5;++i,++j){
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
PUSH(LABEL(L_clos_code_46));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_46);
L_clos_code_46:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<6;++i,++j){
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
PUSH(LABEL(L_clos_code_47));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_47);
L_clos_code_47:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<7;++i,++j){
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
PUSH(LABEL(L_clos_code_48));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_48);
L_clos_code_48:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_48:

  POP(FP);
  RETURN;
L_clos_exit_47:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_46:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_45:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_44:

  POP(FP);
  RETURN;
L_clos_exit_43:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
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
PUSH(LABEL(L_clos_code_37));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_37);
L_clos_code_37:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
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
PUSH(LABEL(L_clos_code_41));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_41);
L_clos_code_41:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<4;++i,++j){
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
PUSH(LABEL(L_clos_code_42));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_42);
L_clos_code_42:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

  POP(FP);
  RETURN;
L_clos_exit_42:

  POP(FP);
  RETURN;
L_clos_exit_41:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
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
PUSH(LABEL(L_clos_code_38));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_38);
L_clos_code_38:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<4;++i,++j){
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
PUSH(LABEL(L_clos_code_39));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_39);
L_clos_code_39:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<5;++i,++j){
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
PUSH(LABEL(L_clos_code_40));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_40);
L_clos_code_40:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_40:

  POP(FP);
  RETURN;
L_clos_exit_39:

  POP(FP);
  RETURN;
L_clos_exit_38:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_37:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
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
PUSH(LABEL(L_clos_code_33));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_33);
L_clos_code_33:
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
PUSH(LABEL(L_clos_code_34));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_34);
L_clos_code_34:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<4;++i,++j){
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
PUSH(LABEL(L_clos_code_35));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_35);
L_clos_code_35:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
for(i=0,j=1;i<5;++i,++j){
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
PUSH(LABEL(L_clos_code_36));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_36);
L_clos_code_36:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_36:

  POP(FP);
  RETURN;
L_clos_exit_35:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_34:

  POP(FP);
  RETURN;
L_clos_exit_33:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
//tc-applic changes
//push old ret
PUSH(FPARG(IMM(-1)));
MOV(R15,FPARG(IMM(-2)))
MOV(R2,FPARG(IMM(1)));
//copy stack to old stack
for(i=0; i < 1+3;i++) {
  MOV(FPARG(R2 + 1 -i),LOCAL(i));
}
//NOT SURE THAT IT IS TRUE - update sp
//update sp to sizw of frameMOV(SP,R15 + 3+1);
//get old fp inorder to runover the old stack
MOV(FP,R15)
JUMPA(INDD(R0,2));

  POP(FP);
  RETURN;
L_clos_exit_32:

  POP(FP);
  RETURN;
L_clos_exit_31:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

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