/* string_compare.asm
*
*      Programmer: Tom & Eitan, 2013
*/

STRING_COMPARE:
        PUSH(FP);
        MOV(FP, SP);
        PUSH(R1)   ;
        CMP(INDD(FPARG(0),0),T_STRING); //checks arg 1 is string
        JUMP_NE(STRING_COMPARE_IS_NOT_STRING);
        CMP(INDD(FPARG(1),0),T_STRING); //checks arg 2 is string
        JUMP_NE(STRING_COMPARE_IS_NOT_STRING);
        MOV(R0,IMM(SOB_BOOLEAN_TRUE))        ;
        CMP(INDD(FPARG(0),1),INDD(FPARG(1),1)) ;
        JUMP_NE(STRING_COMPARE_FALSE)         ;
        MOV(R1,INDD(FPARG(0),1))              ;
STRING_COMPARE_LOOP:
        CMP(R1,0)               ;
        JUMP_EQ(STRING_COMPARE_END) ;
        CMP(INDD(FPARG(0),R1 + 1),INDD(FPARG(1),R1 + 1)) ;
        JUMP_NE(STRING_COMPARE_FALSE)         ;
        DECR(R1)                              ;
        JUMP(STRING_COMPARE_LOOP);
STRING_COMPARE_FALSE:
        MOV(R0,IMM(SOB_BOOLEAN_FALSE))        ;
STRING_COMPARE_END:
        POP(R1)                 ;
        POP(FP);
        RETURN;

STRING_COMPARE_IS_NOT_STRING:
        SHOW("STRING_COMPARE - arg 1 not a string 799345",INDD(FPARG(1),0));
        SHOW("STRING_COMPARE - arg 2 not a string 799345",INDD(FPARG(1),0));
        STOP_MACHINE ;
        return 1;
