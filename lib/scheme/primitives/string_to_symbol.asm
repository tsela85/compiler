/* string_to_symbol.asm
*
*      Programmer: Tom & Eitan, 2013
*/

STRING_TO_SYMBOL:
        PUSH(FP);
        MOV(FP, SP);
        PUSH(R15);
        PUSH(R14);

        CMP(FPARG(1),IMM(1)); //checks num of args = 1
        JUMP_NE(STRING_TO_SYMBOL_NOT_VALID_ARGUMENTS);
        CMP(INDD(FPARG(2),0),T_STRING); //checks arg 1 is string
        JUMP_NE(STRING_TO_SYMBOL_IS_NOT_STRING);

        MOV(R15,15);

STRING_TO_SYMBOL_SEARCH_STRING_LOOP:
                INCR(R15);
                CMP(R15,ADDR(0)-1);
                JUMP_EQ(STRING_TO_SYMBOL_SYM_NOT_FOUND);
                CMP(IND(R15),T_SYMBOL);
                JUMP_NE(STRING_TO_SYMBOL_SEARCH_STRING_LOOP);
        MOV(R0,R15);
        //TODO: string deep compare
                MOV(R14,INDD(R15,1));
                MOV(R14,INDD(R14,0));
                CMP(R14,FPARG(IMM(2)));
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

        POP(R14);
        POP(R15);
        POP(FP);
        RETURN;
STRING_TO_SYMBOL_NOT_VALID_ARGUMENTS:
        SHOW("STRING_TO_SYMBOL -not a valid number of args",FPARG(1));
        STOP_MACHINE ;
        return 1;
STRING_TO_SYMBOL_IS_NOT_STRING:
        SHOW("TRING_TO_SYMBOL - not a string",INDD(FPARG(2),0));
        STOP_MACHINE ;
        return 1;
