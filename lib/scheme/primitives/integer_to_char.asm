/* integer_to_char_gt.asm
*
*  basic -
 *
 *      Programmer: Tom & Eitan, 2013
 */
INTEGER_TO_CHAR:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(1))     ; //checks num of args = 1
        JUMP_NE(INTEGER_TO_CHAR_NOT_VALID_ARGUMENTS) ;
        CMP(INDD(FPARG(2),0),T_INTEGER); //checks arg 1 is integer
        JUMP_NE(INTEGER_TO_CHAR_NOT_A_INTEGER) ;
        PUSH(INDD(FPARG(2),1));
        CALL(MAKE_SOB_CHAR)   ;
        DROP(IMM(1))          ;
        POP(FP);
        RETURN;
INTEGER_TO_CHAR_NOT_VALID_ARGUMENTS:
        SHOW("INTEGER_TO_CHAR_GT -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
INTEGER_TO_CHAR_NOT_A_INTEGER:
        SHOW("INTEGER_TO_CHAR - arg is not a integer type ",	INDD(FPARG(2),0));
        STOP_MACHINE ;
        return 1;
