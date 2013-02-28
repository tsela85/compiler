/* string_to_symbol.asm
*
*      Programmer: Tom & Eitan, 2013
*/

STRING_TO_SYMBOL:
        PUSH(FP);
        MOV(FP, SP);
        PUSH(R1);
        PUSH(R2);

        CMP(FPARG(1),IMM(1)); //checks num of args = 1
        JUMP_NE(STRING_TO_SYMBOL_NOT_VALID_ARGUMENTS);
        CMP(INDD(FPARG(2),0),T_STRING); //checks arg 1 is string
        JUMP_NE(STRING_TO_SYMBOL_IS_NOT_STRING);

        MOV(R1,15);

STRING_TO_SYMBOL_SEARCH_STRING_LOOP:
        INCR(R1);
        CMP(R1,ADDR(0)-1);
        JUMP_EQ(STRING_TO_SYMBOL_SYM_NOT_FOUND);
        CMP(IND(R1),T_SYMBOL);
        JUMP_NE(STRING_TO_SYMBOL_SEARCH_STRING_LOOP);
        MOV(R2,INDD(R1,1));
        MOV(R2,INDD(R2,0));
        PUSH(R2);
        PUSH(FPARG(IMM(2)));
        CALL(STRING_COMPARE);
        DROP(2);
        CMP(R0,SOB_BOOLEAN_TRUE);
        JUMP_NE(STRING_TO_SYMBOL_SEARCH_STRING_LOOP);
        JUMP(STRING_TO_SYMBOL_END);
STRING_TO_SYMBOL_SYM_NOT_FOUND:
        PUSH(IMM(2));
        CALL(MALLOC);
        DROP(IMM(1));
        MOV(IND(R0),FPARG(2));
        MOV(INDD(R0,1),0);
        PUSH(R0);
        CALL(MAKE_SOB_SYMBOL);
        DROP(IMM(1));

STRING_TO_SYMBOL_END:
        MOV(R0,R1)              ;

        POP(R2);
        POP(R1);
        POP(FP);
        RETURN;
STRING_TO_SYMBOL_NOT_VALID_ARGUMENTS:
        SHOW("STRING_TO_SYMBOL -not a valid number of args",FPARG(1));
        STOP_MACHINE ;
        return 1;
STRING_TO_SYMBOL_IS_NOT_STRING:
        SHOW("STRING_TO_SYMBOL - not a string 799345",INDD(FPARG(2),0));
        STOP_MACHINE ;
        return 1;
