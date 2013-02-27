/* string_ref.asm
*
*  basic string_ref
*
*      Programmer: Tom & Eitan, 2013
*/

STRING_REF:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(2))     ; //checks num of args = 2
        JUMP_NE(STRING_REF_NOT_VALID_ARGUMENTS);
        CMP(INDD(FPARG(IMM(2)),IMM(0)),T_STRING); //arg type is string
        JUMP_NE(STRING_REF_NOT_A_STRING);
        CMP(INDD(FPARG(3),0),T_INTEGER); //checks arg 2 is integer
        JUMP_NE(STRING_REF_NOT_A_STRING);
        MOV(R0,	INDD(FPARG(IMM(3)),IMM(1))) ; //get the ref
        CMP(R0,	INDD(FPARG(IMM(2)),IMM(1))) ;
        JUMP_GT	(STRING_REF_TOO_BIG); //ref bigger then string length
        PUSH(INDD(FPARG(IMM(2)),R0+2));
        CALL(MAKE_SOB_CHAR)           ;
        DROP(1)                       ;
        POP(FP);
        RETURN;
STRING_REF_NOT_VALID_ARGUMENTS:
        SHOW("STRING_REF -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
STRING_REF_NOT_A_STRING:
        SHOW("STRING_REF - type mismatch ",(long int)0);
        SHOW("STRING_REF - arg 1 type ",INDD(FPARG(2),0)) ;
        SHOW("STRING_REF - arg 2 type ",INDD(FPARG(3),0)) ;
        STOP_MACHINE ;
        return 1;
STRING_REF_TOO_BIG:
        SHOW("STRING_REF -ref is bigger the string length",	INDD(FPARG(IMM(3)),IMM(1))) ;
        STOP_MACHINE ;
        return 1;
