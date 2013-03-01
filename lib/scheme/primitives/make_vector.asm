/* make_vector.asm
*
*  basic make_vector
*
*      Programmer: Tom & Eitan, 2013
*/

MAKE_VECTOR:
        PUSH(FP);
        MOV(FP, SP);
        PUSH(R1)   ;
        PUSH(0)    ;
        CALL(MAKE_SOB_INTEGER)       ;
        DROP(1)                      ;
        MOV(R1,R0) ;
        CMP(FPARG(1),IMM(2))     ; //checks num of args = 2
        JUMP_NE(MAKE_VECTOR_ONE_ARG);
        MOV(R1,FPARG(IMM(3)))           ;
        JUMP(MAKE_VECTOR_BODY)         ;
MAKE_VECTOR_ONE_ARG:
        CMP(FPARG(1),IMM(1))     ; //checks num of args = 1
        JUMP_NE(MAKE_VECTOR_NOT_VALID_ARGUMENTS);
        CMP(INDD(FPARG(IMM(2)),IMM(0)),T_INTEGER); //arg type is integer
        JUMP_NE(MAKE_VECTOR_NOT_A_INTEGER);
MAKE_VECTOR_BODY:
        MOV(R0,INDD(FPARG(2),IMM(1)));
MAKE_VECTOR_LOOP:
        CMP(R0, IMM(0));
        JUMP_EQ(MAKE_VECTOR_END);
        PUSH(R1) ; //initialize the vector with 0
        DECR(R0)           ;
        JUMP(MAKE_VECTOR_LOOP);
MAKE_VECTOR_END:
        PUSH(INDD(FPARG(2),IMM(1)));
        CALL(MAKE_SOB_VECTOR)           ;
        DROP(INDD(FPARG(2),IMM(1))+1) ;
        POP(R1)                       ;
        POP(FP);
        RETURN;

MAKE_VECTOR_NOT_VALID_ARGUMENTS:
        SHOW("MAKE_VECTOR -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
MAKE_VECTOR_NOT_A_INTEGER:
        SHOW("MAKE_VECTOR- arg 1 is not a integer type",INDD(FPARG(2),IMM(0))) ;
        STOP_MACHINE ;
        return 1;
