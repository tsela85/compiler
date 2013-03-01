/* make_string.asm
*
*  basic make_string
*
*      Programmer: Tom & Eitan, 2013
*/

MAKE_STRING:
        PUSH(FP);
        MOV(FP, SP);
        PUSH(R1)   ;
        MOV(R1,-1) ;
        CMP(FPARG(1),IMM(2))     ; //checks num of args = 2
        JUMP_NE(MAKE_STRING_ONE_ARG);
        CMP(INDD(FPARG(IMM(3)),IMM(0)),T_CHAR); //arg type is CHAR
        JUMP_NE(MAKE_STRING_NOT_A_CHAR);
        MOV(R1,INDD(FPARG(IMM(3)),1))           ;
        JUMP(MAKE_STRING_BODY)         ;
MAKE_STRING_ONE_ARG:
        CMP(FPARG(1),IMM(1))     ; //checks num of args = 1
        JUMP_NE(MAKE_STRING_NOT_VALID_ARGUMENTS);
        CMP(INDD(FPARG(IMM(2)),IMM(0)),T_INTEGER); //arg type is integer
        JUMP_NE(MAKE_STRING_NOT_A_INTEGER);
MAKE_STRING_BODY:
        MOV(R0,INDD(FPARG(2),IMM(1)));
MAKE_STRING_LOOP:
        CMP(R0, IMM(0));
        JUMP_EQ(MAKE_STRING_END);
        PUSH(R1) ; //initialize the string with 0
        DECR(R0)           ;
        JUMP(MAKE_STRING_LOOP);
MAKE_STRING_END:
        PUSH(INDD(FPARG(2),IMM(1)));
        CALL(MAKE_SOB_STRING)           ;
        DROP(INDD(FPARG(2),IMM(1))+1) ;
        POP(R1)                       ;
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

MAKE_STRING_NOT_A_CHAR:
        SHOW("MAKE_STRING- arg 2 is not a CHAR type",INDD(FPARG(3),IMM(0))) ;
        STOP_MACHINE ;
        return 1;
