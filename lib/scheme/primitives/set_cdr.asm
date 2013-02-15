/* set_cdr.asm
*
*  basic set-cdr
*
*      Programmer: Tom & Eitan, 2013
*/

SET_CDR:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(IMM(1)),IMM(2))     ; //checks num of args = 2
        JUMP_NE(SET_CDR_NOT_VALID_ARGUMENTS);
        CMP(INDD(FPARG(IMM(2)),IMM(0)),T_PAIR); //arg type is pair
        JUMP_NE(SET_CDR_NOT_A_PAIR);
        MOV(INDD(FPARG(IMM(2)),IMM(2)),FPARG(IMM(3))); //move value to car of
        MOV(R0,SOB_VOID);
        POP(FP);
        RETURN;
SET_CDR_NOT_VALID_ARGUMENTS:
        SHOW("SET_CDR -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
SET_CDR_NOT_A_PAIR:
        SHOW("SET_CDR - arg is not a pair type ",INDD(FPARG(IMM(2)),IMM(0)));
        STOP_MACHINE ;
        return 1;
