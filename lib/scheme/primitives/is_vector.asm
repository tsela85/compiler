/* is_vector.asm
*
*      Programmer: Tom & Eitan, 2013
*/

IS_VECTOR:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(1))     ; //checks num of args = 1
        JUMP_NE(VECTOR_NOT_VALID_ARGUMENTS);
        MOV(R0,IMM(SOB_BOOLEAN_TRUE))        ;
        CMP(INDD(FPARG(2),0),T_VECTOR); //checks arg 1 is vector
        JUMP_EQ(VECTOR_IS_A_VECTOR);
        MOV(R0,IMM(SOB_BOOLEAN_FALSE))        ;
VECTOR_IS_A_VECTOR:
        POP(FP);
        RETURN;
VECTOR_NOT_VALID_ARGUMENTS:
        SHOW("IS_VECTOR -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
