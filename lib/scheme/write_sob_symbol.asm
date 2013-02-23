/* scheme/write_sob_symbol.asm
 * Take a pointer to a Scheme string object, and 
 * prints (to stdout) the character representation
 * of that object.
 * 
 * Programmer: Tom & Eitan, 2013
 */

 WRITE_SOB_SYMBOL:
  PUSH(FP);
  MOV(FP, SP);
  PUSH(R1);
  PUSH(R2);
  PUSH(R3);
  MOV(R0, FPARG(0));
  MOV(R0,INDD(R0,1));
  MOV(R0,INDD(R0,0));
  MOV(R1, INDD(R0,1));
  MOV(R2, R0);
  ADD(R2, IMM(2));
 L_WSS_LOOP_SYM:
  CMP(R1, IMM(0));
  JUMP_EQ(L_WSS_EXIT_SYM);
  CMP(IND(R2), '\n');
  JUMP_EQ(L_WSS_NEWLINE_SYM);
  CMP(IND(R2), '\t');
  JUMP_EQ(L_WSS_TAB_SYM);
  CMP(IND(R2), '\f');
  JUMP_EQ(L_WSS_PAGE_SYM);
  CMP(IND(R2), '\r');
  JUMP_EQ(L_WSS_RETURN_SYM);
  CMP(IND(R2), '\\');
  JUMP_EQ(L_WSS_BACKSLASH_SYM);
  CMP(IND(R2), '\"');
  JUMP_EQ(L_WSS_DQUOTE_SYM);
  CMP(IND(R2), ' ');
  JUMP_LT(L_WSS_OCT_CHAR_SYM);
  PUSH(IND(R2));
  CALL(PUTCHAR);
  DROP(1);
  JUMP(L_WSS_LOOP_CONT_SYM);
 L_WSS_DQUOTE_SYM:
  PUSH(IMM('\\'));
  CALL(PUTCHAR);
  PUSH(IMM('\"'));
  CALL(PUTCHAR);
  DROP(2);
  JUMP(L_WSS_LOOP_CONT_SYM);
 L_WSS_BACKSLASH_SYM:
  PUSH(IMM('\\'));
  CALL(PUTCHAR);
  PUSH(IMM('\\'));
  CALL(PUTCHAR);
  DROP(2);
  JUMP(L_WSS_LOOP_CONT_SYM);
 L_WSS_RETURN_SYM:
  PUSH(IMM('\\'));
  CALL(PUTCHAR);
  PUSH(IMM('r'));
  CALL(PUTCHAR);
  DROP(2);
  JUMP(L_WSS_LOOP_CONT_SYM);
 L_WSS_PAGE_SYM:
  PUSH(IMM('\\'));
  CALL(PUTCHAR);
  PUSH(IMM('f'));
  CALL(PUTCHAR);
  DROP(2);
  JUMP(L_WSS_LOOP_CONT_SYM);
 L_WSS_TAB_SYM:
  PUSH(IMM('\\'));
  CALL(PUTCHAR);
  PUSH(IMM('t'));
  CALL(PUTCHAR);
  DROP(2);
  JUMP(L_WSS_LOOP_CONT_SYM);  
 L_WSS_NEWLINE_SYM:
  PUSH(IMM('\\'));
  CALL(PUTCHAR);
  PUSH(IMM('n'));
  CALL(PUTCHAR);
  DROP(2);
  JUMP(L_WSS_LOOP_CONT_SYM);
 L_WSS_OCT_CHAR_SYM:
  MOV(R0, IND(R2));
  MOV(R3, R0);
  REM(R3, IMM(8));
  PUSH(R3);
  DIV(R0, IMM(8));
  MOV(R3, R0);
  REM(R3, IMM(8));
  PUSH(R3);
  DIV(R0, IMM(8));
  REM(R0, IMM(8));
  PUSH(R0);
  PUSH(IMM('\\'));
  CALL(PUTCHAR);
  DROP(1);
  CALL(WRITE_INTEGER);
  DROP(1);
  CALL(WRITE_INTEGER);
  DROP(1);
  CALL(WRITE_INTEGER);
  DROP(1);
 L_WSS_LOOP_CONT_SYM:
  INCR(R2);
  DECR(R1);
  JUMP(L_WSS_LOOP_SYM);
 L_WSS_EXIT_SYM:
  POP(R3);
  POP(R2);
  POP(R1);
  POP(FP);
  RETURN;

