/* bin_plus.asm
 * Computes the sum value of its arguments      :
 *   R0 <- | ARG[0] +    ARG[1] |
 *
 *      Programmer: Tom & Eitan, 2013
 */

BIN_PLUS:
        PUSH(FP);
        MOV(FP, SP);
        MOV(R2, FPARG(IMM(2)));
        MOV(R2,	INDD(R2, 1)); //R0<-val of first arg
		MOV(R3, FPARG(IMM(3)));
        MOV(R3,	INDD(R3, 1)); //R0<-val of first arg
        ADD(R2,R3);
        PUSH(R2);
        CALL(MAKE_SOB_INTEGER);
        DROP(IMM(1));
        POP(FP);
		
        RETURN;
