/* vector_set.asm
*
*  basic vector_set
*
*      Programmer: Tom & Eitan, 2013
*/

VECTOR_SET:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(3))     ; //checks num of args = 3
        JUMP_NE(VECTOR_SET_NOT_VALID_ARGUMENTS);
        CMP(INDD(FPARG(IMM(2)),IMM(0)),T_VECTOR); //arg type is vector
        JUMP_NE(VECTOR_SET_NOT_A_VECTOR);
        CMP(INDD(FPARG(3),0),T_INTEGER); //checks arg 2 is integer
        JUMP_NE(VECTOR_SET_NOT_A_VECTOR);
        MOV(R0,	INDD(FPARG(IMM(3)),IMM(1))) ; //get the set
        CMP(R0,	INDD(FPARG(IMM(2)),IMM(1))) ;
        JUMP_GT	(VECTOR_SET_TOO_BIG); //set bigger then vector length
        MOV(INDD(FPARG(IMM(2)),R0+2),FPARG(4));
        MOV(R0,SOB_VOID)                    ;
        POP(FP);
        RETURN;
VECTOR_SET_NOT_VALID_ARGUMENTS:
        SHOW("VECTOR_SET -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
VECTOR_SET_NOT_A_VECTOR:
        SHOW("VECTOR_SET - type mismatch ",(long int)0);
        SHOW("VECTOR_SET - arg 1 type vector 335728 ",INDD(FPARG(2),0)) ;
        SHOW("VECTOR_SET - arg 2 type integer 945311",INDD(FPARG(3),0)) ;
        STOP_MACHINE ;
        return 1;
VECTOR_SET_TOO_BIG:
        SHOW("VECTOR_SET -set is bigger the vector length",	INDD(FPARG(IMM(3)),IMM(1))) ;
        STOP_MACHINE ;
        return 1;
