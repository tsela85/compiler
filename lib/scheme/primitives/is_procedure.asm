/* is_procedure.asm
*
*      Programmer: Tom & Eitan, 2013
*/

IS_PROCEDURE:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(1))     ; //checks num of args = 1
        JUMP_NE(PROCEDURE_NOT_VALID_ARGUMENTS);
        MOV(R0,IMM(SOB_BOOLEAN_TRUE))        ;
        CMP(INDD(FPARG(2),0),T_CLOSURE); //checks arg 1 is procedure
        JUMP_EQ(PROCEDURE_IS_A_CLOUSRE);
        MOV(R0,IMM(SOB_BOOLEAN_FALSE))        ;
PROCEDURE_IS_A_CLOUSRE:
        POP(FP);
        RETURN;
PROCEDURE_NOT_VALID_ARGUMENTS:
        SHOW("IS_PROCEDURE -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
