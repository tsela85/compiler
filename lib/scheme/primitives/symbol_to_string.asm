/* symbol_to_string.asm
*
*      Programmer: Tom & Eitan, 2013
*/

SYMBOL_TO_STRING:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(1))     ; //checks num of args = 1
        JUMP_NE(SYMBOL_TO_STRING_NOT_VALID_ARGUMENTS);
        CMP(INDD(FPARG(2),0),T_SYMBOL); //checks arg 1 is symbol
        JUMP_NE(SYMBOL_TO_STRING_IS_NOT_SYMBOL);
        MOV(R0,INDD(FPARG(2),1));
		MOV(R0,INDD(R0,0));
		CMP(INDD(R0,0),T_STRING); //checks resault is string
		JUMP_NE(SYMBOL_TO_STRING_IS_NOT_STRING);
		
        POP(FP);
        RETURN;
SYMBOL_TO_STRING_NOT_VALID_ARGUMENTS:
        SHOW("SYMBOL_TO_STRING -not a valid number of args",FPARG(1));
        STOP_MACHINE ;
        return 1;
SYMBOL_TO_STRING_IS_NOT_SYMBOL:
        SHOW("SYMBOL_TO_STRING - not a symbol",INDD(FPARG(2),0));
        STOP_MACHINE ;
        return 1;
SYMBOL_TO_STRING_IS_NOT_STRING:
        SHOW("SYMBOL_TO_STRING - not a string",INDD(R0,0));
        STOP_MACHINE ;
        return 1;
