/* cons.asm
*
*  basic cons
*
*      Programmer: Tom & Eitan, 2013
*/

CONS:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(2))     ; //checks num of args = 2
        JUMP_NE(CONS_NOT_VALID_ARGUMENTS);
        PUSH(IMM(3))                     ;
        CALL(MALLOC)                     ;
        DROP(IMM(1))                     ;
        MOV(IND(R0),IMM(T_PAIR))  ;
        MOV(INDD(R0,IMM(1)),FPARG(IMM(2))) ;
        MOV(INDD(R0,IMM(2)),FPARG(IMM(3))) ;
        POP(FP);
        RETURN;
CONS_NOT_VALID_ARGUMENTS:
        SHOW("CONS -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
