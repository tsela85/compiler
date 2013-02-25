/* apply.asm
*
*  basic -
 *
 *      Programmer: Tom & Eitan, 2013
 */

APPLY:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(1),IMM(2))     ; //checks num of args = 2
        JUMP_NE(APPLY_NOT_VALID_ARGUMENTS) ;
        CMP(INDD(FPARG(2),0),T_CLOSURE); //checks arg 1 is closure
        JUMP_NE(APPLY_INVALID_ARG_1) ;
        PUSH(R1)                     ;
        PUSH(R2)                     ;
        PUSH(R3)                     ;
        MOV(R0,FPARG(3))             ; //R3<-argument list
        MOV(R1,IMM(-1))              ;
        MOV(R2,IMM(-1))              ;//R2<-length of list
APPLY_PARAMS_LOOP:
        CMP(R0,SOB_NIL)         ;
        JUMP_EQ(APPLAY_REVERSE_LOOP)     ;
        CMP(INDD(R0,0),T_PAIR); //checks arg 2 is Pair
        JUMP_NE(APPLY_INVALID_ARG_2) ;
        PUSH(INDD(R0,IMM(1)))        ;
        MOV(R0,INDD(R0,IMM(2)))      ;
        INCR(R2)                     ;
        JUMP(APPLY_PARAMS_LOOP)             ;
APPLAY_REVERSE_LOOP:
        CMP(R1,R2)              ;
        JUMP_GE(APPLAY_END_REVERSE) ;
        MOV(R3,STARG(R1))                       ;
        MOV(STARG(R1),STARG(R2-1))                ;
        MOV(STARG(R2-1),R3)                       ;
        DECR(R2)                                ;
        INCR(R1)                                ;
        JUMP(APPLAY_REVERSE_LOOP)               ;
APPLAY_END_REVERSE:
        MOV(R1,SP)              ;
        SUB(R1,FP)              ;
        SUB(R1,IMM(3))          ; //R1<-amount of args
        PUSH(R1)                ;
        MOV(R2,FPARG(IMM(2)))   ;
        PUSH(INDD(R2,IMM(1)))   ; //pushing the env
        CALLA(INDD(R2,IMM(2)))   ;
        DROP(IMM(2))            ;
        MOV(R1,SP)              ;
        SUB(R1,FP)              ;
        SUB(R1,IMM(3))          ; //R1<-amount of args
        DROP(R1)                ;
        POP(R3)                 ;
        POP(R2)                 ;
        POP(R1)                 ;
        POP(FP);
        RETURN;

APPLY_NOT_VALID_ARGUMENTS:
        SHOW("APPLY -not a valid number of args",FPARG(1)) ;
        JUMP(APPLY_ERROR_END)                              ;
APPLY_INVALID_ARG_1:
        SHOW("APPLY - invalid arg",FPARG(2)) ;
        JUMP(APPLY_ERROR_END)                              ;
APPLY_INVALID_ARG_2:
        SHOW("APPLY - not a PAIR in param list ",R0) ;
        JUMP(APPLY_ERROR_END);


APPLY_ERROR_END:
        STOP_MACHINE ;
        return 1;
