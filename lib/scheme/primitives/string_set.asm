/* string_set.asm
*
*  basic string_set
*
*      Programmer: Tom & Eitan, 2013
*/

STRING_SET:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(3))     ; //checks num of args = 3
        JUMP_NE(STRING_SET_NOT_VALID_ARGUMENTS);
        CMP(INDD(FPARG(IMM(2)),IMM(0)),T_STRING); //arg type is string
        JUMP_NE(STRING_SET_NOT_A_STRING);
        CMP(INDD(FPARG(3),0),T_INTEGER); //checks arg 2 is integer
        JUMP_NE(STRING_SET_NOT_A_STRING);
        CMP(INDD(FPARG(4),0),T_CHAR); //checks arg 3 is char
        JUMP_NE(STRING_SET_NOT_A_STRING);
        MOV(R0,	INDD(FPARG(IMM(3)),IMM(1))) ; //get the set
        CMP(R0,	INDD(FPARG(IMM(2)),IMM(1))) ;
        JUMP_GT	(STRING_SET_TOO_BIG); //set bigger then string length
        MOV(INDD(FPARG(IMM(2)),R0+2),INDD(FPARG(4),1));
        MOV(R0,SOB_VOID)                    ;
        POP(FP);
        RETURN;
STRING_SET_NOT_VALID_ARGUMENTS:
        SHOW("STRING_SET -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
STRING_SET_NOT_A_STRING:
        SHOW("STRING_SET - type mismatch ",(long int)0);
        SHOW("STRING_SET - arg 1 should be string type 799345 ",INDD(FPARG(2),0)) ;
        SHOW("STRING_SET - arg 2 should be integer type	945311 ",INDD(FPARG(3),0)) ;
        SHOW("STRING_SET - arg 3 should be char type 181048",INDD(FPARG(4),0)) ;
        STOP_MACHINE ;
        return 1;
STRING_SET_TOO_BIG:
        SHOW("STRING_SET -set is bigger the string length",	INDD(FPARG(IMM(3)),IMM(1))) ;
        STOP_MACHINE ;
        return 1;
