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
L_clos_loop_141:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(0));
JUMP_LT(L_clos_loop_141);
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
PUSH(LABEL(L_clos_code_141));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_141);
L_clos_code_141:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_142:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(1));
JUMP_LT(L_clos_loop_142);
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
PUSH(LABEL(L_clos_code_142));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_142);
L_clos_code_142:
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
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_142:

  POP(FP);
  RETURN;
L_clos_exit_141:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//pushing args to stack
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
L_clos_loop_139:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(0));
JUMP_LT(L_clos_loop_139);
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
PUSH(LABEL(L_clos_code_139));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_139);
L_clos_code_139:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_140:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(1));
JUMP_LT(L_clos_loop_140);
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

  POP(FP);
  RETURN;
L_clos_exit_140:

  POP(FP);
  RETURN;
L_clos_exit_139:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//pushing args to stack
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
L_clos_loop_137:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(0));
JUMP_LT(L_clos_loop_137);
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
PUSH(LABEL(L_clos_code_137));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_137);
L_clos_code_137:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_138:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(1));
JUMP_LT(L_clos_loop_138);
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

  POP(FP);
  RETURN;
L_clos_exit_138:

  POP(FP);
  RETURN;
L_clos_exit_137:

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
L_clos_loop_135:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(0));
JUMP_LT(L_clos_loop_135);
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
PUSH(LABEL(L_clos_code_135));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_135);
L_clos_code_135:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_136:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(1));
JUMP_LT(L_clos_loop_136);
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

  POP(FP);
  RETURN;
L_clos_exit_136:

  POP(FP);
  RETURN;
L_clos_exit_135:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

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
L_clos_loop_126:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(0));
JUMP_LT(L_clos_loop_126);
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
PUSH(LABEL(L_clos_code_126));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_126);
L_clos_code_126:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_127:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(1));
JUMP_LT(L_clos_loop_127);
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
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_133:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(2));
JUMP_LT(L_clos_loop_133);
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
PUSH(LABEL(L_clos_code_133));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_133);
L_clos_code_133:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_134:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(3));
JUMP_LT(L_clos_loop_134);
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

  POP(FP);
  RETURN;
L_clos_exit_133:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_128:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(2));
JUMP_LT(L_clos_loop_128);
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
PUSH(LABEL(L_clos_code_128));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_128);
L_clos_code_128:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_129:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(3));
JUMP_LT(L_clos_loop_129);
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
PUSH(LABEL(L_clos_code_129));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_129);
L_clos_code_129:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_130:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(4));
JUMP_LT(L_clos_loop_130);
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
PUSH(LABEL(L_clos_code_130));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_130);
L_clos_code_130:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_131:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(5));
JUMP_LT(L_clos_loop_131);
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
PUSH(LABEL(L_clos_code_131));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_131);
L_clos_code_131:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_132:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(6));
JUMP_LT(L_clos_loop_132);
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
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_132:

  POP(FP);
  RETURN;
L_clos_exit_131:

  POP(FP);
  RETURN;
L_clos_exit_130:

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
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_129:

  POP(FP);
  RETURN;
L_clos_exit_128:

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
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_127:

  POP(FP);
  RETURN;
L_clos_exit_126:

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
L_clos_loop_117:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(0));
JUMP_LT(L_clos_loop_117);
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
PUSH(LABEL(L_clos_code_117));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_117);
L_clos_code_117:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_118:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(1));
JUMP_LT(L_clos_loop_118);
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
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_124:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(2));
JUMP_LT(L_clos_loop_124);
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
PUSH(LABEL(L_clos_code_124));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_124);
L_clos_code_124:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_125:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(3));
JUMP_LT(L_clos_loop_125);
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
PUSH(LABEL(L_clos_code_125));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_125);
L_clos_code_125:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_125:

  POP(FP);
  RETURN;
L_clos_exit_124:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_119:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(2));
JUMP_LT(L_clos_loop_119);
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
PUSH(LABEL(L_clos_code_119));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_119);
L_clos_code_119:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_120:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(3));
JUMP_LT(L_clos_loop_120);
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
PUSH(LABEL(L_clos_code_120));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_120);
L_clos_code_120:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_121:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(4));
JUMP_LT(L_clos_loop_121);
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
PUSH(LABEL(L_clos_code_121));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_121);
L_clos_code_121:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_122:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(5));
JUMP_LT(L_clos_loop_122);
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
PUSH(LABEL(L_clos_code_122));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_122);
L_clos_code_122:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_123:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(6));
JUMP_LT(L_clos_loop_123);
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
PUSH(LABEL(L_clos_code_123));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_123);
L_clos_code_123:
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
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_123:

  POP(FP);
  RETURN;
L_clos_exit_122:

  POP(FP);
  RETURN;
L_clos_exit_121:

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
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

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

  POP(FP);
  RETURN;
L_clos_exit_118:

  POP(FP);
  RETURN;
L_clos_exit_117:

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
L_clos_loop_115:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(0));
JUMP_LT(L_clos_loop_115);
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
PUSH(LABEL(L_clos_code_115));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_115);
L_clos_code_115:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_116:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(1));
JUMP_LT(L_clos_loop_116);
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
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_116:

  POP(FP);
  RETURN;
L_clos_exit_115:

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
L_clos_loop_81:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(0));
JUMP_LT(L_clos_loop_81);
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
//pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_114:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(1));
JUMP_LT(L_clos_loop_114);
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
PUSH(LABEL(L_clos_code_114));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_114);
L_clos_code_114:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_114:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_113:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(1));
JUMP_LT(L_clos_loop_113);
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
PUSH(LABEL(L_clos_code_113));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_113);
L_clos_code_113:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_113:

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
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_110:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(1));
JUMP_LT(L_clos_loop_110);
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
PUSH(LABEL(L_clos_code_110));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_110);
L_clos_code_110:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_111:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(2));
JUMP_LT(L_clos_loop_111);
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
PUSH(LABEL(L_clos_code_111));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_111);
L_clos_code_111:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_112:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(3));
JUMP_LT(L_clos_loop_112);
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
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_112:

  POP(FP);
  RETURN;
L_clos_exit_111:

  POP(FP);
  RETURN;
L_clos_exit_110:

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
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_85:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(1));
JUMP_LT(L_clos_loop_85);
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
PUSH(LABEL(L_clos_code_85));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_85);
L_clos_code_85:
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
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_107:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(2));
JUMP_LT(L_clos_loop_107);
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
PUSH(LABEL(L_clos_code_107));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_107);
L_clos_code_107:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_108:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(3));
JUMP_LT(L_clos_loop_108);
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
PUSH(LABEL(L_clos_code_108));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_108);
L_clos_code_108:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_109:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(4));
JUMP_LT(L_clos_loop_109);
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
PUSH(LABEL(L_clos_code_109));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_109);
L_clos_code_109:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_109:

  POP(FP);
  RETURN;
L_clos_exit_108:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_107:

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
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_104:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(2));
JUMP_LT(L_clos_loop_104);
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
PUSH(LABEL(L_clos_code_104));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_104);
L_clos_code_104:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_105:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(3));
JUMP_LT(L_clos_loop_105);
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
PUSH(LABEL(L_clos_code_105));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_105);
L_clos_code_105:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_106:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(4));
JUMP_LT(L_clos_loop_106);
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
PUSH(LABEL(L_clos_code_106));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_106);
L_clos_code_106:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

  POP(FP);
  RETURN;
L_clos_exit_106:

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

  POP(FP);
  RETURN;
L_clos_exit_104:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

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
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_95:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(2));
JUMP_LT(L_clos_loop_95);
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
PUSH(LABEL(L_clos_code_95));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_95);
L_clos_code_95:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_96:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(3));
JUMP_LT(L_clos_loop_96);
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
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_102:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(4));
JUMP_LT(L_clos_loop_102);
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
PUSH(LABEL(L_clos_code_102));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_102);
L_clos_code_102:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_103:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(5));
JUMP_LT(L_clos_loop_103);
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
PUSH(LABEL(L_clos_code_103));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_103);
L_clos_code_103:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_103:

  POP(FP);
  RETURN;
L_clos_exit_102:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_97:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(4));
JUMP_LT(L_clos_loop_97);
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
PUSH(LABEL(L_clos_code_97));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_97);
L_clos_code_97:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_98:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(5));
JUMP_LT(L_clos_loop_98);
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
PUSH(LABEL(L_clos_code_98));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_98);
L_clos_code_98:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_99:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(6));
JUMP_LT(L_clos_loop_99);
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
PUSH(LABEL(L_clos_code_99));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_99);
L_clos_code_99:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_100:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(7));
JUMP_LT(L_clos_loop_100);
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
PUSH(LABEL(L_clos_code_100));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_100);
L_clos_code_100:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(9));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_101:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(8));
JUMP_LT(L_clos_loop_101);
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
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_101:

  POP(FP);
  RETURN;
L_clos_exit_100:

  POP(FP);
  RETURN;
L_clos_exit_99:

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
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_98:

  POP(FP);
  RETURN;
L_clos_exit_97:

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
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_96:

  POP(FP);
  RETURN;
L_clos_exit_95:

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
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_92:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(2));
JUMP_LT(L_clos_loop_92);
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
PUSH(LABEL(L_clos_code_92));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_92);
L_clos_code_92:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_93:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(3));
JUMP_LT(L_clos_loop_93);
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
PUSH(LABEL(L_clos_code_93));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_93);
L_clos_code_93:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_94:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(4));
JUMP_LT(L_clos_loop_94);
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
PUSH(LABEL(L_clos_code_94));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_94);
L_clos_code_94:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

  POP(FP);
  RETURN;
L_clos_exit_94:

  POP(FP);
  RETURN;
L_clos_exit_93:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_92:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

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
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_89:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(2));
JUMP_LT(L_clos_loop_89);
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
PUSH(LABEL(L_clos_code_89));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_89);
L_clos_code_89:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_90:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(3));
JUMP_LT(L_clos_loop_90);
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
PUSH(LABEL(L_clos_code_90));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_90);
L_clos_code_90:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_91:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(4));
JUMP_LT(L_clos_loop_91);
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
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_91:

  POP(FP);
  RETURN;
L_clos_exit_90:

  POP(FP);
  RETURN;
L_clos_exit_89:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

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
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_86:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(2));
JUMP_LT(L_clos_loop_86);
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
PUSH(LABEL(L_clos_code_86));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_86);
L_clos_code_86:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_87:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(3));
JUMP_LT(L_clos_loop_87);
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
PUSH(LABEL(L_clos_code_87));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_87);
L_clos_code_87:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_88:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(4));
JUMP_LT(L_clos_loop_88);
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
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_88:

  POP(FP);
  RETURN;
L_clos_exit_87:

  POP(FP);
  RETURN;
L_clos_exit_86:

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
  RETURN;
L_clos_exit_85:

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
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_82:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(1));
JUMP_LT(L_clos_loop_82);
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
PUSH(LABEL(L_clos_code_82));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_82);
L_clos_code_82:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_83:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(2));
JUMP_LT(L_clos_loop_83);
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
PUSH(LABEL(L_clos_code_83));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_83);
L_clos_code_83:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_84:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(3));
JUMP_LT(L_clos_loop_84);
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
PUSH(LABEL(L_clos_code_84));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_84);
L_clos_code_84:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_84:

  POP(FP);
  RETURN;
L_clos_exit_83:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_82:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_81:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

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
L_clos_loop_11:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(0));
JUMP_LT(L_clos_loop_11);
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
PUSH(LABEL(L_clos_code_11));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_11);
L_clos_code_11:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_12:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(1));
JUMP_LT(L_clos_loop_12);
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
PUSH(LABEL(L_clos_code_12));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_12);
L_clos_code_12:
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
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_55:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(2));
JUMP_LT(L_clos_loop_55);
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
PUSH(LABEL(L_clos_code_55));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_55);
L_clos_code_55:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_56:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(3));
JUMP_LT(L_clos_loop_56);
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
//bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_57:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(4));
JUMP_LT(L_clos_loop_57);
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
PUSH(LABEL(L_clos_code_57));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_57);
L_clos_code_57:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//pushing args to stack
//pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_79:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(5));
JUMP_LT(L_clos_loop_79);
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
PUSH(LABEL(L_clos_code_79));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_79);
L_clos_code_79:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_80:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(6));
JUMP_LT(L_clos_loop_80);
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
//pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_77:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(5));
JUMP_LT(L_clos_loop_77);
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
PUSH(LABEL(L_clos_code_77));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_77);
L_clos_code_77:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_78:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(6));
JUMP_LT(L_clos_loop_78);
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
PUSH(LABEL(L_clos_code_78));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_78);
L_clos_code_78:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_78:

  POP(FP);
  RETURN;
L_clos_exit_77:

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
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_74:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(5));
JUMP_LT(L_clos_loop_74);
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
PUSH(LABEL(L_clos_code_74));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_74);
L_clos_code_74:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_75:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(6));
JUMP_LT(L_clos_loop_75);
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
PUSH(LABEL(L_clos_code_75));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_75);
L_clos_code_75:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_76:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(7));
JUMP_LT(L_clos_loop_76);
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
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_76:

  POP(FP);
  RETURN;
L_clos_exit_75:

  POP(FP);
  RETURN;
L_clos_exit_74:

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
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_61:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(5));
JUMP_LT(L_clos_loop_61);
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
PUSH(LABEL(L_clos_code_61));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_61);
L_clos_code_61:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

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
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_71:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(6));
JUMP_LT(L_clos_loop_71);
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
PUSH(LABEL(L_clos_code_71));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_71);
L_clos_code_71:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_72:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(7));
JUMP_LT(L_clos_loop_72);
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
PUSH(LABEL(L_clos_code_72));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_72);
L_clos_code_72:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(9));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_73:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(8));
JUMP_LT(L_clos_loop_73);
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
PUSH(LABEL(L_clos_code_73));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_73);
L_clos_code_73:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

  POP(FP);
  RETURN;
L_clos_exit_73:

  POP(FP);
  RETURN;
L_clos_exit_72:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_71:

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
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_68:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(6));
JUMP_LT(L_clos_loop_68);
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
PUSH(LABEL(L_clos_code_68));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_68);
L_clos_code_68:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_69:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(7));
JUMP_LT(L_clos_loop_69);
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
PUSH(LABEL(L_clos_code_69));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_69);
L_clos_code_69:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(9));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_70:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(8));
JUMP_LT(L_clos_loop_70);
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
PUSH(LABEL(L_clos_code_70));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_70);
L_clos_code_70:
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

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_68:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

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
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_65:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(6));
JUMP_LT(L_clos_loop_65);
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
PUSH(LABEL(L_clos_code_65));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_65);
L_clos_code_65:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_66:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(7));
JUMP_LT(L_clos_loop_66);
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
PUSH(LABEL(L_clos_code_66));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_66);
L_clos_code_66:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(9));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_67:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(8));
JUMP_LT(L_clos_loop_67);
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
PUSH(LABEL(L_clos_code_67));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_67);
L_clos_code_67:
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
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_67:

  POP(FP);
  RETURN;
L_clos_exit_66:

  POP(FP);
  RETURN;
L_clos_exit_65:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

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
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_62:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(6));
JUMP_LT(L_clos_loop_62);
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
PUSH(LABEL(L_clos_code_62));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_62);
L_clos_code_62:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_63:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(7));
JUMP_LT(L_clos_loop_63);
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
PUSH(LABEL(L_clos_code_63));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_63);
L_clos_code_63:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(9));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_64:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(8));
JUMP_LT(L_clos_loop_64);
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
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

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

  POP(FP);
  RETURN;
L_clos_exit_61:

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
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_58:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(5));
JUMP_LT(L_clos_loop_58);
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
PUSH(LABEL(L_clos_code_58));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_58);
L_clos_code_58:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_59:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(6));
JUMP_LT(L_clos_loop_59);
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
PUSH(LABEL(L_clos_code_59));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_59);
L_clos_code_59:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_60:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(7));
JUMP_LT(L_clos_loop_60);
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
PUSH(LABEL(L_clos_code_60));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_60);
L_clos_code_60:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_60:

  POP(FP);
  RETURN;
L_clos_exit_59:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_58:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

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
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_56:

  POP(FP);
  RETURN;
L_clos_exit_55:

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
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_49:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(2));
JUMP_LT(L_clos_loop_49);
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
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_53:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(3));
JUMP_LT(L_clos_loop_53);
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
PUSH(LABEL(L_clos_code_53));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_53);
L_clos_code_53:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_54:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(4));
JUMP_LT(L_clos_loop_54);
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
PUSH(LABEL(L_clos_code_54));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_54);
L_clos_code_54:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

  POP(FP);
  RETURN;
L_clos_exit_54:

  POP(FP);
  RETURN;
L_clos_exit_53:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_50:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(3));
JUMP_LT(L_clos_loop_50);
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
PUSH(LABEL(L_clos_code_50));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_50);
L_clos_code_50:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_51:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(4));
JUMP_LT(L_clos_loop_51);
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
PUSH(LABEL(L_clos_code_51));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_51);
L_clos_code_51:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_52:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(5));
JUMP_LT(L_clos_loop_52);
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
PUSH(LABEL(L_clos_code_52));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_52);
L_clos_code_52:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_52:

  POP(FP);
  RETURN;
L_clos_exit_51:

  POP(FP);
  RETURN;
L_clos_exit_50:

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

  POP(FP);
  RETURN;
L_clos_exit_49:

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
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_23:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(2));
JUMP_LT(L_clos_loop_23);
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
PUSH(LABEL(L_clos_code_23));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_23);
L_clos_code_23:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_24:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(3));
JUMP_LT(L_clos_loop_24);
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
PUSH(LABEL(L_clos_code_24));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_24);
L_clos_code_24:
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
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_25:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(4));
JUMP_LT(L_clos_loop_25);
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
PUSH(LABEL(L_clos_code_25));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_25);
L_clos_code_25:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//pushing args to stack
//pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_47:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(5));
JUMP_LT(L_clos_loop_47);
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
PUSH(LABEL(L_clos_code_47));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_47);
L_clos_code_47:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_48:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(6));
JUMP_LT(L_clos_loop_48);
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
//pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_45:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(5));
JUMP_LT(L_clos_loop_45);
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
PUSH(LABEL(L_clos_code_45));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_45);
L_clos_code_45:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_46:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(6));
JUMP_LT(L_clos_loop_46);
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
PUSH(LABEL(L_clos_code_46));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_46);
L_clos_code_46:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_46:

  POP(FP);
  RETURN;
L_clos_exit_45:

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
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_42:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(5));
JUMP_LT(L_clos_loop_42);
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
PUSH(LABEL(L_clos_code_42));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_42);
L_clos_code_42:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_43:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(6));
JUMP_LT(L_clos_loop_43);
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
PUSH(LABEL(L_clos_code_43));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_43);
L_clos_code_43:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_44:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(7));
JUMP_LT(L_clos_loop_44);
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
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_44:

  POP(FP);
  RETURN;
L_clos_exit_43:

  POP(FP);
  RETURN;
L_clos_exit_42:

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
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_29:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(5));
JUMP_LT(L_clos_loop_29);
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
PUSH(LABEL(L_clos_code_29));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_29);
L_clos_code_29:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//pushing args to stack
MOV(R0,FPARG(IMM(2+0)));

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
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_39:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(6));
JUMP_LT(L_clos_loop_39);
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
PUSH(LABEL(L_clos_code_39));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_39);
L_clos_code_39:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_40:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(7));
JUMP_LT(L_clos_loop_40);
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
PUSH(LABEL(L_clos_code_40));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_40);
L_clos_code_40:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(9));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_41:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(8));
JUMP_LT(L_clos_loop_41);
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
PUSH(LABEL(L_clos_code_41));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_41);
L_clos_code_41:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

  POP(FP);
  RETURN;
L_clos_exit_41:

  POP(FP);
  RETURN;
L_clos_exit_40:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_39:

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
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_36:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(6));
JUMP_LT(L_clos_loop_36);
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
PUSH(LABEL(L_clos_code_36));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_36);
L_clos_code_36:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_37:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(7));
JUMP_LT(L_clos_loop_37);
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
PUSH(LABEL(L_clos_code_37));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_37);
L_clos_code_37:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(9));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_38:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(8));
JUMP_LT(L_clos_loop_38);
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
PUSH(LABEL(L_clos_code_38));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_38);
L_clos_code_38:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

  POP(FP);
  RETURN;
L_clos_exit_38:

  POP(FP);
  RETURN;
L_clos_exit_37:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_36:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

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
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_33:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(6));
JUMP_LT(L_clos_loop_33);
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
PUSH(LABEL(L_clos_code_33));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_33);
L_clos_code_33:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_34:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(7));
JUMP_LT(L_clos_loop_34);
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
PUSH(LABEL(L_clos_code_34));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_34);
L_clos_code_34:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(9));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_35:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(8));
JUMP_LT(L_clos_loop_35);
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
PUSH(LABEL(L_clos_code_35));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_35);
L_clos_code_35:
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
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_35:

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
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_30:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(6));
JUMP_LT(L_clos_loop_30);
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
PUSH(LABEL(L_clos_code_30));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_30);
L_clos_code_30:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_31:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(7));
JUMP_LT(L_clos_loop_31);
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
PUSH(LABEL(L_clos_code_31));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_31);
L_clos_code_31:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(9));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_32:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(8));
JUMP_LT(L_clos_loop_32);
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
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_32:

  POP(FP);
  RETURN;
L_clos_exit_31:

  POP(FP);
  RETURN;
L_clos_exit_30:

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
  RETURN;
L_clos_exit_29:

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
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_26:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(5));
JUMP_LT(L_clos_loop_26);
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
PUSH(LABEL(L_clos_code_26));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_26);
L_clos_code_26:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(7));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_27:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(6));
JUMP_LT(L_clos_loop_27);
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
PUSH(LABEL(L_clos_code_27));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_27);
L_clos_code_27:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(8));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_28:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(7));
JUMP_LT(L_clos_loop_28);
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
PUSH(LABEL(L_clos_code_28));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_28);
L_clos_code_28:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_28:

  POP(FP);
  RETURN;
L_clos_exit_27:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
MOV(R0,FPARG(IMM(2+0)));

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_26:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_25:

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

  POP(FP);
  RETURN;
L_clos_exit_24:

  POP(FP);
  RETURN;
L_clos_exit_23:

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
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_17:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(2));
JUMP_LT(L_clos_loop_17);
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
PUSH(LABEL(L_clos_code_17));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_17);
L_clos_code_17:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_21:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(3));
JUMP_LT(L_clos_loop_21);
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
PUSH(LABEL(L_clos_code_21));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_21);
L_clos_code_21:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_22:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(4));
JUMP_LT(L_clos_loop_22);
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
PUSH(LABEL(L_clos_code_22));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_22);
L_clos_code_22:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //bvar: maj: 0, min: 0
MOV(R0,FPARG(IMM(0)));
MOV(R0,INDD(R0,IMM(0)));
MOV(R0,INDD(R0,IMM(0)));

  POP(FP);
  RETURN;
L_clos_exit_22:

  POP(FP);
  RETURN;
L_clos_exit_21:

PUSH(R0);

//pushing number of args
PUSH(IMM(1));
//pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_18:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(3));
JUMP_LT(L_clos_loop_18);
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
PUSH(LABEL(L_clos_code_18));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_18);
L_clos_code_18:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_19:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(4));
JUMP_LT(L_clos_loop_19);
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
PUSH(LABEL(L_clos_code_19));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_19);
L_clos_code_19:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_20:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(5));
JUMP_LT(L_clos_loop_20);
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
PUSH(LABEL(L_clos_code_20));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_20);
L_clos_code_20:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_20:

  POP(FP);
  RETURN;
L_clos_exit_19:

  POP(FP);
  RETURN;
L_clos_exit_18:

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

  POP(FP);
  RETURN;
L_clos_exit_17:

CMP(INDD(R0,0),T_CLOSURE);
JUMP_NE(error);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

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
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_13:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(2));
JUMP_LT(L_clos_loop_13);
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
PUSH(LABEL(L_clos_code_13));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_13);
L_clos_code_13:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(4));
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
CMP(R15,IMM(3));
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
  //pushing args to stack
//creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(5));
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
CMP(R15,IMM(4));
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
  //creating sob of size 3 and put 'T_CLOSURE' in the 0th place
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
MOV(INDD(R0,0),T_CLOSURE);
MOV(R1,R0); //r1 holds a pointer to the closure struct
//extending the env by 1
//allocating space for the new env
PUSH(IMM(6));
CALL(MALLOC);
DROP(IMM(1));
MOV(R2,R0); //R2 <- new env
//shifting the old enviroment
MOV(R1,FPARG(IMM(0))); //R1 <- env
//R2[j] <- R1[i]
PUSH(R15);
MOV(R15,IMM(0));
L_clos_loop_16:
MOV(INDD(R2,R15 + 1),INDD(R1,R15));
INCR(R15);
CMP(R15,IMM(5));
JUMP_LT(L_clos_loop_16);
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
PUSH(LABEL(L_clos_code_16));
PUSH(R2);
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
JUMP(L_clos_exit_16);
L_clos_code_16:
  PUSH(FP);
  MOV(FP,SP);
  //lambda-body
  MOV(R0,FPARG(IMM(2+0)));

  POP(FP);
  RETURN;
L_clos_exit_16:

  POP(FP);
  RETURN;
L_clos_exit_15:

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
CALLA(INDD(R0,IMM(2)));
DROP(IMM(1+2));

  POP(FP);
  RETURN;
L_clos_exit_14:

  POP(FP);
  RETURN;
L_clos_exit_13:

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
  RETURN;
L_clos_exit_12:

  POP(FP);
  RETURN;
L_clos_exit_11:

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