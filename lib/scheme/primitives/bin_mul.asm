/* bin_mul.asm
 *
 *  basic *
 *
 *      Programmer: Tom & Eitan, 2013
 */

BIN_MUL:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(2))     ; //checks num of args = 2
        JUMP_NE(MUL_NOT_VALID_ARGUMENTS) ;
        CMP(INDD(FPARG(2),0),T_INTEGER); //checks arg 1 is integer
        JUMP_NE(MUL_NOT_A_INTEGER) ;
        CMP(INDD(FPARG(3),0),T_INTEGER); //checks arg 2 is integer
        JUMP_NE(MUL_NOT_A_INTEGER) ;
        MOV(R0,INDD(FPARG(2),1));
        MUL(R0,INDD(FPARG(3),1));
        PUSH(R0);
        CALL(MAKE_SOB_INTEGER);
        DROP(IMM(1));
        POP(FP);
        RETURN;
MUL_NOT_VALID_ARGUMENTS:
        SHOW("BIN_MUL -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
MUL_NOT_A_INTEGER:
        SHOW("BIN_MUL - arg is not a integer type ",(long int)0);
        SHOW("BIN_MUL - arg 1 type ",INDD(FPARG(2),0)) ;
        SHOW("BIN_MUL - arg 2 type ",INDD(FPARG(3),0)) ;
        STOP_MACHINE ;
        return 1;
