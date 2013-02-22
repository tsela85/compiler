/* is_eq.asm
*
*      Programmer: Tom & Eitan, 2013
*/

IS_EQ:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(2))     ; //checks num of args = 2
        JUMP_NE(IS_EQ_NOT_VALID_ARGUMENTS);
        MOV(R0,IMM(SOB_BOOLEAN_TRUE))  ;
        CMP(IND(FPARG(2)),IND(FPARG(3)))	; //checks if same type
        JUMP_NE(IS_EQ_NOT_EQ);
        CMP(IND(FPARG(2)),T_INTEGER) ;
        JUMP_EQ(IS_EQ_SIMPLE_TYPE);
        CMP(IND(FPARG(2)),T_CHAR) ;
        JUMP_EQ(IS_EQ_SIMPLE_TYPE);
        CMP(IND(FPARG(2)),T_SYMBOL) ;
        JUMP_NE(IS_EQ_COMPLEX_TYPE);
IS_EQ_SIMPLE_TYPE:
        CMP(INDD(FPARG(2),1),INDD(FPARG(3),1))	; //checks if same type
        JUMP_NE(IS_EQ_NOT_EQ);
        JUMP(IS_EQ_A_EQ) ;
IS_EQ_COMPLEX_TYPE:
        CMP(FPARG(2),FPARG(3)); //checks arg 1 is eq arg 2
        JUMP_EQ(IS_EQ_A_EQ);
IS_EQ_NOT_EQ:
        MOV(R0,IMM(SOB_BOOLEAN_FALSE))        ;
IS_EQ_A_EQ:
        POP(FP);
        RETURN;
IS_EQ_NOT_VALID_ARGUMENTS:
        SHOW("IS_EQ -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
