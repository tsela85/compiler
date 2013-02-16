/* is_zero.asm
*
*      Programmer: Tom & Eitan, 2013
*/
ZERO:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(1))     ; //checks num of args = 1
        JUMP_NE(ZERO_NOT_VALID_ARGUMENTS) ;
        CMP(INDD(FPARG(2),0),T_INTEGER); //checks arg 1 is integer
        JUMP_NE(ZERO_NOT_A_INTEGER) ;
        MOV(R0,IMM(SOB_BOOLEAN_TRUE));
        CMP(IMM(0),INDD(FPARG(2),1));
        JUMP_EQ(ZERO_IS_A_ZERO);
        MOV(R0,IMM(SOB_BOOLEAN_FALSE))        ;
ZERO_IS_A_ZERO:
        POP(FP);
        RETURN;
ZERO_NOT_VALID_ARGUMENTS:
        SHOW("ZERO -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
ZERO_NOT_A_INTEGER:
        SHOW("ZERO - arg is not a integer type ",INDD(FPARG(2),0));
        STOP_MACHINE ;
        return 1;
