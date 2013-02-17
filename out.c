#include <stdio.h>
#include <stdlib.h>
#include "cisc.h"
#define SHOW(msg, x) { printf("%s %s = %ld\n", (msg), (#x), (x)); }


int main()
{
  START_MACHINE;
  int consts[]={937610, 722689, 741553, 0, 741553, 1, 799345, 4, 98, 105, 110, 43, 368031, 402, 799345, 4, 98, 105, 110, 45, 368031, 404, 799345, 4, 98, 105, 110, 42, 368031, 406, 799345, 4, 98, 105, 110, 47, 368031, 408, 799345, 5, 98, 105, 110, 61, 63, 368031, 410, 799345, 5, 98, 105, 110, 60, 63, 368031, 412, 799345, 8, 114, 101, 109, 105, 110, 100, 101, 114, 368031, 414, 799345, 4, 99, 111, 110, 115, 368031, 416, 799345, 3, 99, 97, 114, 368031, 418, 799345, 3, 99, 100, 114, 368031, 420, 799345, 8, 115, 101, 116, 45, 99, 97, 114, 33, 368031, 422, 799345, 8, 115, 101, 116, 45, 99, 100, 114, 33, 368031, 424, 799345, 10, 112, 114, 111, 99, 101, 100, 117, 114, 101, 63, 368031, 426, 799345, 7, 118, 101, 99, 116, 111, 114, 63, 368031, 428, 799345, 7, 115, 121, 109, 98, 111, 108, 63, 368031, 430, 799345, 7, 115, 116, 114, 105, 110, 103, 63, 368031, 432, 799345, 5, 99, 104, 97, 114, 63, 368031, 434, 799345, 7, 110, 117, 109, 98, 101, 114, 63, 368031, 436, 799345, 8, 98, 111, 111, 108, 101, 97, 110, 63, 368031, 438, 799345, 5, 112, 97, 105, 114, 63, 368031, 440, 799345, 5, 110, 117, 108, 108, 63, 368031, 442, 799345, 3, 101, 113, 63, 368031, 444, 799345, 5, 122, 101, 114, 111, 63, 368031, 446, 799345, 13, 105, 110, 116, 101, 103, 101, 114, 45, 62, 99, 104, 97, 114, 368031, 448, 799345, 13, 99, 104, 97, 114, 45, 62, 105, 110, 116, 101, 103, 101, 114, 368031, 450, 799345, 11, 109, 97, 107, 101, 45, 115, 116, 114, 105, 110, 103, 368031, 452, 799345, 11, 109, 97, 107, 101, 45, 118, 101, 99, 116, 111, 114, 368031, 454, 799345, 13, 115, 116, 114, 105, 110, 103, 45, 108, 101, 110, 103, 116, 104, 368031, 456, 799345, 10, 115, 116, 114, 105, 110, 103, 45, 114, 101, 102, 368031, 458, 799345, 11, 115, 116, 114, 105, 110, 103, 45, 115, 101, 116, 33, 368031, 460, 799345, 13, 118, 101, 99, 116, 111, 114, 45, 108, 101, 110, 103, 116, 104, 368031, 462, 799345, 10, 118, 101, 99, 116, 111, 114, 45, 114, 101, 102, 368031, 464, 799345, 11, 118, 101, 99, 116, 111, 114, 45, 115, 101, 116, 33, 368031, 466, 799345, 5, 97, 112, 112, 108, 121, 368031, 468, 16, 0, 24, 0, 32, 0, 40, 0, 48, 0, 57, 0, 66, 0, 78, 0, 86, 0, 93, 0, 100, 0, 112, 0, 124, 0, 138, 0, 149, 0, 160, 0, 171, 0, 180, 0, 191, 0, 203, 0, 212, 0, 221, 0, 228, 0, 237, 0, 254, 0, 271, 0, 286, 0, 301, 0, 318, 0, 332, 0, 347, 0, 364, 0, 378, 0, 393, 0};
  memcpy(&machine->mem[10],consts,sizeof(consts));
   MOV(ADDR(0), IMM(470));
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
MOV(R1,402);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(BIN_MINUS));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,404);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(BIN_DIV));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,408);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(BIN_MUL));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,406);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(BIN_EQ));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,410);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(BIN_GT));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,412);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(REMINDER));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,414);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(CONS));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,416);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(CAR));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,418);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(CDR));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,420);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(SET_CAR));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,422);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(SET_CDR));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,424);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(IS_PROCEDURE));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,426);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(IS_VECTOR));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,428);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(IS_SYMBOL));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,430);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(IS_STRING));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,432);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(IS_CHAR));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,434);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(IS_NUMBER));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,436);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(IS_BOOLEAN));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,438);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(IS_PAIR));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,440);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(IS_NULL));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,442);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(IS_EQ));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,444);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(ZERO));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,446);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(INTEGER_TO_CHAR));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,448);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(CHAR_TO_INTEGER));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,450);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(MAKE_STRING));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,452);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(MAKE_VECTOR));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,454);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(STRING_LENGTH));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,456);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(VECTOR_LENGTH));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,462);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(STRING_REF));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,458);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(VECTOR_REF));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,464);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(STRING_SET));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,460);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);

PUSH(LABEL(VECTOR_SET));
PUSH(0);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(R1,466);
MOV(INDD(R1,IMM(1)),R0);
MOV(R0,SOB_VOID);


//applic pushing args to stack
//lambda-s extending the env by 1
//lambda-s allocating space for the new env
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
//lambda-s moving params from the stack to the first list in env
//lambda-s allocating space
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
printf("push(FP):%ld \n",FP); //TODO: remove
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //lambda-s extending the env by 1
//lambda-s allocating space for the new env
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
//lambda-s moving params from the stack to the first list in env
//lambda-s allocating space
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
printf("push(FP):%ld \n",FP); //TODO: remove
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

  POP(FP);
  RETURN;
L_clos_exit_70:

  POP(FP);
  RETURN;
L_clos_exit_69:

PUSH(R0);

//applic pushing number of args
PUSH(IMM(1));
//applic pushing args to stack
//lambda-s extending the env by 1
//lambda-s allocating space for the new env
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
//lambda-s moving params from the stack to the first list in env
//lambda-s allocating space
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
printf("push(FP):%ld \n",FP); //TODO: remove
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //tc-applic pushing args to stack
MOV(R0,12);
PUSH(R0);

//tc-applic pushing number of args
PUSH(IMM(1));
//applic pushing args to stack
MOV(R0,14);
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
DROP(IMM(STARG(IMM(0))+IMM(2)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push closure env
//tc-applic changes
PUSH(FPARG(IMM(-1))); //pushing to the top of the frame  the ret of the old frame
MOV(R1,FPARG(-2)); //R1<-prev frame fp
printf("old FP %ld \n",R1); //TODO: remove
MOV(R2,STARG(1)); //R2<- amount of current args
//copy current frame to old frame
for(i=0; i < R2 + 3; i++) {
   MOV(STACK(R1 + i),LOCAL(i));
}
MOV(FP,R1); //update fp
MOV(SP,FP + R2 + 3); //SP<- old fp + args count + 3
JUMPA(INDD(R0,2)); //tc-applic jump to closure code

  POP(FP);
  RETURN;
L_clos_exit_68:

PUSH(R0);

//applic pushing number of args
PUSH(IMM(1));
//applic pushing args to stack
//lambda-s extending the env by 1
//lambda-s allocating space for the new env
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
//lambda-s moving params from the stack to the first list in env
//lambda-s allocating space
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
printf("push(FP):%ld \n",FP); //TODO: remove
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //tc-applic pushing args to stack
//lambda-s extending the env by 1
//lambda-s allocating space for the new env
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
//lambda-s moving params from the stack to the first list in env
//lambda-s allocating space
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
printf("push(FP):%ld \n",FP); //TODO: remove
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //lambda-s extending the env by 1
//lambda-s allocating space for the new env
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
//lambda-s moving params from the stack to the first list in env
//lambda-s allocating space
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
printf("push(FP):%ld \n",FP); //TODO: remove
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //lambda-s extending the env by 1
//lambda-s allocating space for the new env
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
//lambda-s moving params from the stack to the first list in env
//lambda-s allocating space
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
printf("push(FP):%ld \n",FP); //TODO: remove
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //tc-applic pushing args to stack
//bvar: maj: 1, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(1)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//tc-applic pushing number of args
PUSH(IMM(1));
//applic pushing args to stack
//bvar: maj: 0, min: 0
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
DROP(IMM(STARG(IMM(0))+IMM(2)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push closure env
//tc-applic changes
PUSH(FPARG(IMM(-1))); //pushing to the top of the frame  the ret of the old frame
MOV(R1,FPARG(-2)); //R1<-prev frame fp
printf("old FP %ld \n",R1); //TODO: remove
MOV(R2,STARG(1)); //R2<- amount of current args
//copy current frame to old frame
for(i=0; i < R2 + 3; i++) {
   MOV(STACK(R1 + i),LOCAL(i));
}
MOV(FP,R1); //update fp
MOV(SP,FP + R2 + 3); //SP<- old fp + args count + 3
JUMPA(INDD(R0,2)); //tc-applic jump to closure code

  POP(FP);
  RETURN;
L_clos_exit_67:

  POP(FP);
  RETURN;
L_clos_exit_66:

  POP(FP);
  RETURN;
L_clos_exit_65:

PUSH(R0);

//tc-applic pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push closure env
//tc-applic changes
PUSH(FPARG(IMM(-1))); //pushing to the top of the frame  the ret of the old frame
MOV(R1,FPARG(-2)); //R1<-prev frame fp
printf("old FP %ld \n",R1); //TODO: remove
MOV(R2,STARG(1)); //R2<- amount of current args
//copy current frame to old frame
for(i=0; i < R2 + 3; i++) {
   MOV(STACK(R1 + i),LOCAL(i));
}
MOV(FP,R1); //update fp
MOV(SP,FP + R2 + 3); //SP<- old fp + args count + 3
JUMPA(INDD(R0,2)); //tc-applic jump to closure code

  POP(FP);
  RETURN;
L_clos_exit_64:

PUSH(R0);

//applic pushing number of args
PUSH(IMM(1));
//applic pushing args to stack
//lambda-s extending the env by 1
//lambda-s allocating space for the new env
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
//lambda-s moving params from the stack to the first list in env
//lambda-s allocating space
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
printf("push(FP):%ld \n",FP); //TODO: remove
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //lambda-s extending the env by 1
//lambda-s allocating space for the new env
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
//lambda-s moving params from the stack to the first list in env
//lambda-s allocating space
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
printf("push(FP):%ld \n",FP); //TODO: remove
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //tc-applic pushing args to stack
//applic pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//applic pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push clousre env
CALLA(INDD(R0,IMM(2)));
//applic drop number of args
MOV(R10,IMM(STARG(IMM(0)))) //TODO: TEMP move sp 
DROP(IMM(STARG(IMM(0))+IMM(2)));

PUSH(R0);

//tc-applic pushing number of args
PUSH(IMM(1));
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push closure env
//tc-applic changes
PUSH(FPARG(IMM(-1))); //pushing to the top of the frame  the ret of the old frame
MOV(R1,FPARG(-2)); //R1<-prev frame fp
printf("old FP %ld \n",R1); //TODO: remove
MOV(R2,STARG(1)); //R2<- amount of current args
//copy current frame to old frame
for(i=0; i < R2 + 3; i++) {
   MOV(STACK(R1 + i),LOCAL(i));
}
MOV(FP,R1); //update fp
MOV(SP,FP + R2 + 3); //SP<- old fp + args count + 3
JUMPA(INDD(R0,2)); //tc-applic jump to closure code

  POP(FP);
  RETURN;
L_clos_exit_63:

  POP(FP);
  RETURN;
L_clos_exit_62:

PUSH(R0);

//applic pushing number of args
PUSH(IMM(1));
//lambda-s extending the env by 1
//lambda-s allocating space for the new env
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
//lambda-s moving params from the stack to the first list in env
//lambda-s allocating space
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
printf("push(FP):%ld \n",FP); //TODO: remove
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //tc-applic pushing args to stack
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
DROP(IMM(STARG(IMM(0))+IMM(2)));

PUSH(R0);

//tc-applic pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push closure env
//tc-applic changes
PUSH(FPARG(IMM(-1))); //pushing to the top of the frame  the ret of the old frame
MOV(R1,FPARG(-2)); //R1<-prev frame fp
printf("old FP %ld \n",R1); //TODO: remove
MOV(R2,STARG(1)); //R2<- amount of current args
//copy current frame to old frame
for(i=0; i < R2 + 3; i++) {
   MOV(STACK(R1 + i),LOCAL(i));
}
MOV(FP,R1); //update fp
MOV(SP,FP + R2 + 3); //SP<- old fp + args count + 3
JUMPA(INDD(R0,2)); //tc-applic jump to closure code

  POP(FP);
  RETURN;
L_clos_exit_61:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push clousre env
CALLA(INDD(R0,IMM(2)));
//applic drop number of args
MOV(R10,IMM(STARG(IMM(0)))) //TODO: TEMP move sp 
DROP(IMM(STARG(IMM(0))+IMM(2)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push clousre env
CALLA(INDD(R0,IMM(2)));
//applic drop number of args
MOV(R10,IMM(STARG(IMM(0)))) //TODO: TEMP move sp 
DROP(IMM(STARG(IMM(0))+IMM(2)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));//push clousre env
CALLA(INDD(R0,IMM(2)));
//applic drop number of args
MOV(R10,IMM(STARG(IMM(0)))) //TODO: TEMP move sp 
DROP(IMM(STARG(IMM(0))+IMM(2)));

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