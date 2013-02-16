/* make_string.asm
*
*  basic make_string
*
*      Programmer: Tom & Eitan, 2013
*/

MAKE_STRING:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(1))     ; //checks num of args = 1
        JUMP_NE(MAKE_STRING_NOT_VALID_ARGUMENTS);
        CMP(INDD(FPARG(IMM(2)),IMM(0)),T_INTEGER); //arg type is pair
        JUMP_NE(MAKE_STRING_NOT_A_INTEGER);
        MOV(R0,INDD(FPARG(2),IMM(1)));
MAKE_STRING_LOOP:
        CMP(R0, IMM(0));
        JUMP_EQ(MAKE_STRING_END);
        PUSH(IMM(-1)) ; //initialize the string with 0
        DECR(R0)           ;
        JUMP(MAKE_STRING_LOOP);
MAKE_STRING_END:
        PUSH(INDD(FPARG(2),IMM(1)));
        CALL(MAKE_SOB_STRING)           ;
        DROP(INDD(FPARG(2),IMM(1))+1) ;
        POP(FP);
        RETURN;

MAKE_STRING_NOT_VALID_ARGUMENTS:
        SHOW("MAKE_STRING -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
MAKE_STRING_NOT_A_INTEGER:
        SHOW("MAKE_STRING- arg 1 is not a integer type",INDD(FPARG(2),IMM(0))) ;
        STOP_MACHINE ;
        return 1;
