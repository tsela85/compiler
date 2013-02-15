/* cdr.asm
*
*  basic cdr
*
*      Programmer: Tom & Eitan, 2013
*/

CDR:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(1))     ; //checks num of args = 1
        JUMP_NE(CDR_NOT_VALID_ARGUMENTS);
        CMP(INDD(FPARG(IMM(2)),IMM(0)),T_PAIR); //arg type is pair
        JUMP_NE(CDR_NOT_A_PAIR);
        MOV(R0,INDD(FPARG(IMM(2)),IMM(2))); //move value to R0
        POP(FP);
        RETURN;
CDR_NOT_VALID_ARGUMENTS:
        SHOW("CDR -not a valid number of args\n",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
CDR_NOT_A_PAIR:
        SHOW("CDR - arg is not a pair type \n",INDD(FPARG(IMM(2)),IMM(0))      );
        STOP_MACHINE ;
        return 1;
