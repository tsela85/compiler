/* is_string.asm
*
*      Programmer: Tom & Eitan, 2013
*/

IS_STRING:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(1))     ; //checks num of args = 1
        JUMP_NE(STRING_NOT_VALID_ARGUMENTS);
        MOV(R0,IMM(SOB_BOOLEAN_TRUE))        ;
        CMP(INDD(FPARG(2),0),T_STRING); //checks arg 1 is string
        JUMP_EQ(STRING_IS_A_STRING);
        MOV(R0,IMM(SOB_BOOLEAN_FALSE))        ;
STRING_IS_A_STRING:
        POP(FP);
        RETURN;
STRING_NOT_VALID_ARGUMENTS:
        SHOW("IS_STRING -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
