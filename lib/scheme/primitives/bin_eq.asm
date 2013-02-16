/* bin_eq.asm
*
*  basic -
 *
 *      Programmer: Tom & Eitan, 2013
 */
BIN_EQ:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(2))     ; //checks num of args = 2
        JUMP_NE(BIN_EQ_NOT_VALID_ARGUMENTS) ;
        CMP(INDD(FPARG(2),0),T_INTEGER); //checks arg 1 is integer
        JUMP_NE(BIN_EQ_NOT_A_INTEGER) ;
        CMP(INDD(FPARG(3),0),T_INTEGER); //checks arg 2 is integer
        JUMP_NE(BIN_EQ_NOT_A_INTEGER) ;
        MOV(R0,IMM(SOB_BOOLEAN_TRUE));
        CMP(INDD(FPARG(2),1),INDD(FPARG(3),1));
        JUMP_EQ(BOOLEAN_IS_A_BOOLEAN);
        MOV(R0,IMM(SOB_BOOLEAN_FALSE))        ;
BIN_EQ_IS_A_EQ:
        POP(FP);
        RETURN;        RETURN;
BIN_EQ_NOT_VALID_ARGUMENTS:
        SHOW("BIN_EQ -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
BIN_EQ_NOT_A_INTEGER:
        SHOW("BIN_EQ - arg is not a integer type ",(long int)0);
        SHOW("BIN_EQ - arg 1 type ",INDD(FPARG(2),0)) ;
        SHOW("BIN_EQ - arg 2 type ",INDD(FPARG(3),0)) ;
        STOP_MACHINE ;
        return 1;
