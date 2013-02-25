/* is_null.asm
*
*      Programmer: Tom & Eitan, 2013
*/

IS_NULL:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(1))     ; //checks num of args = 1
        JUMP_NE(NULL_NOT_VALID_ARGUMENTS);
        MOV(R0,IMM(SOB_BOOLEAN_TRUE))        ;
        CMP(FPARG(2),SOB_NIL); //checks arg 1 is null TODO: INDD
        JUMP_EQ(NULL_IS_A_NULL);
        MOV(R0,IMM(SOB_BOOLEAN_FALSE))        ;
NULL_IS_A_NULL:
        POP(FP);
        RETURN;
NULL_NOT_VALID_ARGUMENTS:
        SHOW("IS_NULL -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
