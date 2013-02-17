/* is_pair.asm
*
*      Programmer: Tom & Eitan, 2013
*/

IS_PAIR:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(1))     ; //checks num of args = 1
        JUMP_NE(PAIR_NOT_VALID_ARGUMENTS);
        MOV(R0,IMM(SOB_BOOLEAN_TRUE))        ;
        CMP(INDD(FPARG(2),0),T_PAIR); //checks arg 1 is pair
        JUMP_EQ(PAIR_IS_A_PAIR);
        MOV(R0,IMM(SOB_BOOLEAN_FALSE))        ;
PAIR_IS_A_PAIR:
        POP(FP);
        RETURN;
PAIR_NOT_VALID_ARGUMENTS:
        SHOW("IS_PAIR -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
