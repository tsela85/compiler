/* vector_length.asm
*
*  basic vector_length
*
*      Programmer: Tom & Eitan, 2013
*/

VECTOR_LENGTH:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(1))     ; //checks num of args = 1
        JUMP_NE(VECTOR_LENGTH_NOT_VALID_ARGUMENTS);
        CMP(INDD(FPARG(IMM(2)),IMM(0)),T_VECTOR); //arg type is pair
        JUMP_NE(VECTOR_LENGTH_NOT_A_VECTOR);
        PUSH(INDD(FPARG(IMM(2)),IMM(1))); //make a sob_integer of the length
        CALL(MAKE_SOB_INTEGER)          ;
        DROP(IMM(1))                    ;
        POP(FP);
        RETURN;
VECTOR_LENGTH_NOT_VALID_ARGUMENTS:
        SHOW("VECTOR_LENGTH -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
VECTOR_LENGTH_NOT_A_VECTOR:
        SHOW("VECTOR_LENGTH - arg is not a vector type ",INDD(FPARG(IMM(2)),IMM(0)));
        STOP_MACHINE ;
        return 1;
