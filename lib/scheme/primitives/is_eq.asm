/* is_eq.asm
*
*      Programmer: Tom & Eitan, 2013
*/

IS_EQ:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(2))     ; //checks num of args = 2
        JUMP_NE(EQ_NOT_VALID_ARGUMENTS);
        MOV(R0,IMM(SOB_BOOLEAN_TRUE))        ;
        CMP(FPARG(2),FPARG(3)); //checks arg 1 is eq arg 2
        JUMP_EQ(EQ_IS_A_EQ);
        MOV(R0,IMM(SOB_BOOLEAN_FALSE))        ;
EQ_IS_A_EQ:
        POP(FP);
        RETURN;
EQ_NOT_VALID_ARGUMENTS:
        SHOW("IS_EQ -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
