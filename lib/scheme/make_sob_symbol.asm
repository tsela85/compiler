/* scheme/make_sob_symbol.asm
 * Takes an symbol, and place the corresponding Scheme object in R0
 * 
 * Programmer: Tom & Eitan, 2013
 */

MAKE_SOB_SYMBOL:
  PUSH(FP);
  MOV(FP, SP);
  PUSH(IMM(2));
  CALL(MALLOC);
  DROP(1);
  MOV(IND(R0), T_SYMBOL);
  MOV(INDD(R0, 1), FPARG(0));
  POP(FP);
  RETURN;
