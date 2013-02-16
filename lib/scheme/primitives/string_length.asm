/* string_length.asm
*
*  basic string_length
*
*      Programmer: Tom & Eitan, 2013
*/

STRING_LENGTH:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(1))     ; //checks num of args = 1
        JUMP_NE(STRING_LENGTH_NOT_VALID_ARGUMENTS);
        CMP(INDD(FPARG(IMM(2)),IMM(0)),T_STRING); //arg type is pair
        JUMP_NE(STRING_LENGTH_NOT_A_STRING);
        PUSH(INDD(FPARG(IMM(2)),IMM(1))); //make a sob_integer of the length
        CALL(MAKE_SOB_INTEGER)          ;
        DROP(IMM(1))                    ;
        POP(FP);
        RETURN;
STRING_LENGTH_NOT_VALID_ARGUMENTS:
        SHOW("STRING_LENGTH -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
STRING_LENGTH_NOT_A_STRING:
        SHOW("STRING_LENGTH - arg is not a string type ",INDD(FPARG(IMM(2)),IMM(0)));
        STOP_MACHINE ;
        return 1;
