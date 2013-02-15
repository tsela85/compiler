/* is_symbol.asm
*
*      Programmer: Tom & Eitan, 2013
*/

IS_SYMBOL:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(1))     ; //checks num of args = 1
        JUMP_NE(SYMBOL_NOT_VALID_ARGUMENTS);
        MOV(R0,IMM(SOB_BOOLEAN_TRUE))        ;
        CMP(INDD(FPARG(2),0),T_SYMBOL); //checks arg 1 is symbol
        JUMP_EQ(SYMBOL_IS_A_SYMBOL);
        MOV(R0,IMM(SOB_BOOLEAN_FALSE))        ;
SYMBOL_IS_A_SYMBOL:
        POP(FP);
        RETURN;
SYMBOL_NOT_VALID_ARGUMENTS:
        SHOW("IS_SYMBOL -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
