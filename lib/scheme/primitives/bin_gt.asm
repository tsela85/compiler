/* bin_gt.asm
*
*  basic -
 *
 *      Programmer: Tom & Eitan, 2013
 */
BIN_GT:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(2))     ; //checks num of args = 2
        JUMP_NE(BIN_GT_NOT_VALID_ARGUMENTS) ;
        CMP(INDD(FPARG(2),0),T_INTEGER); //checks arg 1 is integer
        JUMP_NE(BIN_GT_NOT_A_INTEGER) ;
        CMP(INDD(FPARG(3),0),T_INTEGER); //checks arg 2 is integer
        JUMP_NE(BIN_GT_NOT_A_INTEGER) ;
        MOV(R0,IMM(SOB_BOOLEAN_TRUE));
        CMP(INDD(FPARG(3),1),INDD(FPARG(2),1));
        JUMP_GT(BOOLEAN_IS_A_BOOLEAN);
        MOV(R0,IMM(SOB_BOOLEAN_FALSE))        ;
BIN_GT_IS_A_GT:
        POP(FP);
        RETURN;        RETURN;
BIN_GT_NOT_VALID_ARGUMENTS:
        SHOW("BIN_GT -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
BIN_GT_NOT_A_INTEGER:
        SHOW("BIN_GT - arg is not a integer type ",(long int)0);
        SHOW("BIN_GT - arg 1 type ",INDD(FPARG(2),0)) ;
        SHOW("BIN_GT - arg 2 type ",INDD(FPARG(3),0)) ;
        STOP_MACHINE ;
        return 1;
