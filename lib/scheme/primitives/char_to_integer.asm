/* char_to_integer_gt.asm
*
*  basic -
 *
 *      Programmer: Tom & Eitan, 2013
 */
CHAR_TO_INTEGER:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(1))     ; //checks num of args = 1
        JUMP_NE(CHAR_TO_INTEGER_NOT_VALID_ARGUMENTS) ;
        CMP(INDD(FPARG(2),0),T_CHAR); //checks arg 1 is char
        JUMP_NE(CHAR_TO_INTEGER_NOT_A_CHAR) ;
        PUSH(INDD(FPARG(2),1));
        CALL(MAKE_SOB_INTEGER)   ;
        DROP(IMM(1))          ;
        POP(FP);
        RETURN;
CHAR_TO_INTEGER_NOT_VALID_ARGUMENTS:
        SHOW("CHAR_TO_INTEGER -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
CHAR_TO_INTEGER_NOT_A_CHAR:
        SHOW("CHAR_TO_INTEGER - arg is not a char type ",INDD(FPARG(2),0));
        STOP_MACHINE ;
        return 1;
