/* bin_minus.asm
*
*  basic -
 *
 *      Programmer: Tom & Eitan, 2013
 */
 
APPLY:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(2))     ; //checks num of args = 2
        JUMP_NE(APPLY_NOT_VALID_ARGUMENTS) ;
        CMP(INDD(FPARG(2),0),T_CLOSURE); //checks arg 1 is closure
        JUMP_NE(APPLY_INVALID_ARG) ;
        CMP(INDD(FPARG(3),0),T_PAIR); //checks arg 2 is integer
        JUMP_NE(APPLY_INVALID_ARG) ;
        MOV(R0,IMM(6));
        PUSH(R0);
        CALL(MAKE_SOB_INTEGER);
        DROP(IMM(1));
        POP(FP);
        RETURN;
APPLY_NOT_VALID_ARGUMENTS:
        SHOW("APPLY -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
APPLY_INVALID_ARG:
		SHOW("APPLY - invalid args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;

