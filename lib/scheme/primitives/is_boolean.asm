/* is_boolean.asm
*
*      Programmer: Tom & Eitan, 2013
*/

IS_BOOLEAN:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(1))     ; //checks num of args = 1
        JUMP_NE(BOOLEAN_NOT_VALID_ARGUMENTS);
        MOV(R0,IMM(SOB_BOOLEAN_TRUE))        ;
        CMP(INDD(FPARG(2),0),T_BOOL); //checks arg 1 is boolean
        JUMP_EQ(BOOLEAN_IS_A_BOOLEAN);
        MOV(R0,IMM(SOB_BOOLEAN_FALSE))        ;
BOOLEAN_IS_A_BOOLEAN:
        POP(FP);
        RETURN;
BOOLEAN_NOT_VALID_ARGUMENTS:
        SHOW("IS_BOOLEAN -not a valid boolean of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
