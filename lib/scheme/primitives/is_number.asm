/* is_number.asm
*
*      Programmer: Tom & Eitan, 2013
*/

IS_NUMBER:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(1))     ; //checks num of args = 1
        JUMP_NE(NUMBER_NOT_VALID_ARGUMENTS);
        MOV(R0,IMM(SOB_BOOLEAN_TRUE))        ;
        CMP(INDD(FPARG(2),0),T_INTEGER); //checks arg 1 is number
        JUMP_EQ(NUMBER_IS_A_NUMBER);
        MOV(R0,IMM(SOB_BOOLEAN_FALSE))        ;
NUMBER_IS_A_NUMBER:
        POP(FP);
        RETURN;
NUMBER_NOT_VALID_ARGUMENTS:
        SHOW("IS_NUMBER -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
