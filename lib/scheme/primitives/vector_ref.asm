/* vector_ref.asm
*
*  basic vector_ref
*
*      Programmer: Tom & Eitan, 2013
*/

VECTOR_REF:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(2))     ; //checks num of args = 2
        JUMP_NE(VECTOR_REF_NOT_VALID_ARGUMENTS);
        CMP(INDD(FPARG(IMM(2)),IMM(0)),T_VECTOR); //arg type is pair
        JUMP_NE(VECTOR_REF_NOT_A_VECTOR);
        CMP(INDD(FPARG(3),0),T_INTEGER); //checks arg 2 is integer
        JUMP_NE(VECTOR_REF_NOT_A_VECTOR);
        MOV(R0,	INDD(FPARG(IMM(3)),IMM(1))) ; //get the ref
        CMP(R0,	INDD(FPARG(IMM(2)),IMM(1))) ;
        JUMP_GT	(VECTOR_REF_TOO_BIG); //ref bigger then vector length
        MOV(R0,INDD(FPARG(IMM(2)),R0+2));
        POP(FP);
        RETURN;
VECTOR_REF_NOT_VALID_ARGUMENTS:
        SHOW("VECTOR_REF -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
VECTOR_REF_NOT_A_VECTOR:
        SHOW("VECTOR_REF - type mismatch ",(long int)0);
        SHOW("VECTOR_REF - arg 1 type ",INDD(FPARG(2),0)) ;
        SHOW("VECTOR_REF - arg 2 type ",INDD(FPARG(3),0)) ;
        STOP_MACHINE ;
        return 1;
VECTOR_REF_TOO_BIG:
        SHOW("VECTOR_REF -ref is bigger the vector length",	INDD(FPARG(IMM(3)),IMM(1))) ;
        STOP_MACHINE ;
        return 1;
