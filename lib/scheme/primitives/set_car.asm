/* set_car.asm
*
*  basic set-car
*
*      Programmer: Tom & Eitan, 2013
*/

SET_CAR:
        PUSH(FP);
        MOV(FP, SP);
        CMP(FPARG(IMM(1)),IMM(2))     ; //checks num of args = 2
        JUMP_NE(SET_CAR_NOT_VALID_ARGUMENTS);
        CMP(INDD(FPARG(IMM(2)),IMM(0)),T_PAIR); //arg type is pair
        JUMP_NE(SET_CAR_NOT_A_PAIR);
        MOV(INDD(FPARG(IMM(2)),IMM(1)),FPARG(IMM(3))); //move value to car of
        MOV(R0,SOB_VOID);
        POP(FP);
        RETURN;
SET_CAR_NOT_VALID_ARGUMENTS:
        SHOW("SET_CAR -not a valid number of args",FPARG(1)) ;
        STOP_MACHINE ;
        return 1;
SET_CAR_NOT_A_PAIR:
        SHOW("SET_CAR - arg is not a pair type ",INDD(FPARG(IMM(2)),IMM(0)));
        STOP_MACHINE ;
        return 1;
