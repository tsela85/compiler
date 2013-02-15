/* is_char.asm
*
*      Programmer: Tom & Eitan, 2013
*/

IS_CHAR:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(1))     ; //checks num of args = 1
        JUMP_NE(CHAR_NOT_VALID_ARGUMENTS);
        MOV(R0,IMM(SOB_BOOLEAN_TRUE))        ;
        CMP(INDD(FPARG(2),0),T_CHAR); //checks arg 1 is char
        JUMP_EQ(CHAR_IS_A_CHAR);
        MOV(R0,IMM(SOB_BOOLEAN_FALSE))        ;
CHAR_IS_A_CHAR:
        POP(FP);
        RETURN;
CHAR_NOT_VALID_ARGUMENTS:
        SHOW("IS_CHAR -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
