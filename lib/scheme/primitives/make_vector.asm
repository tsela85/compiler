/* make_vector.asm
*
*  basic make_vector
*
*      Programmer: Tom & Eitan, 2013
*/

MAKE_VECTOR:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(1))     ; //checks num of args = 1
        JUMP_NE(MAKE_VECTOR_NOT_VALID_ARGUMENTS);
        CMP(INDD(FPARG(IMM(2)),IMM(0)),T_INTEGER); //arg type is pair
        JUMP_NE(MAKE_VECTOR_NOT_A_INTEGER);
        MOV(R0,INDD(FPARG(2),IMM(1)));
MAKE_VECTOR_LOOP:
        CMP(R0, IMM(0));
        JUMP_EQ(MAKE_VECTOR_END);
        PUSH(IMM(SOB_NIL)) ; //initialize the vector with null
        DECR(R0)           ;
        JUMP(MAKE_VECTOR_LOOP);
MAKE_VECTOR_END:
        PUSH(INDD(FPARG(2),IMM(1)))  ;
        CALL(MAKE_SOB_VECTOR)           ;
        DROP(INDD(FPARG(2),IMM(1))+1) ;
        POP(FP);
        RETURN;

MAKE_VECTOR_NOT_VALID_ARGUMENTS:
        SHOW("MAKE_VECTOR -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
MAKE_VECTOR_NOT_A_INTEGER:
        SHOW("MAKE_VECTOR -arg 1 is not a integer type",INDD(FPARG(2),IMM(0))) ;
        STOP_MACHINE ;
        return 1;
