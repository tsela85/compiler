/* scheme/write_sob_no_void.asm
 * Take a pointer to a Scheme object, and
 * prints (to stdout) the character representation
 * of that object.
 *
 * Programmer: Mayer Goldberg, 2010
 * Edited: Eitan & TOM,2013
 */

WRITE_SOB_NO_VOID:
//        CALL(NEWLINE)                ;
  MOV(R0, STARG(0));
  MOV(R0, IND(R0));
  CMP(R0, IMM(T_VOID));
        JUMP_EQ(WRITE_SOB_NO_VOID_IS_VOID); //do not print
        PUSH(R0)                          ;
        CALL(NEWLINE)                     ;
        POP(R0)                           ;
  CMP(R0, IMM(T_NIL));
  JUMP_EQ(WRITE_SOB_NIL);
  CMP(R0, IMM(T_BOOL));
  JUMP_EQ(WRITE_SOB_BOOL);
  CMP(R0, IMM(T_CHAR));
  JUMP_EQ(WRITE_SOB_CHAR);
  CMP(R0, IMM(T_INTEGER));
  JUMP_EQ(WRITE_SOB_INTEGER);
  CMP(R0, IMM(T_STRING));
  JUMP_EQ(WRITE_SOB_STRING);
  CMP(R0, IMM(T_SYMBOL));
  JUMP_EQ(WRITE_SOB_SYMBOL);
  CMP(R0, IMM(T_PAIR));
  JUMP_EQ(WRITE_SOB_PAIR);
  CMP(R0, IMM(T_VECTOR));
  JUMP_EQ(WRITE_SOB_VECTOR);
  CMP(R0, IMM(T_CLOSURE));
  JUMP_EQ(WRITE_SOB_CLOSURE);
  PUSH(R0);
  PUSH(IMM('\n'));
  CALL(PUTCHAR);
  PUSH(IMM('F'));
  CALL(PUTCHAR);
  PUSH(IMM('a'));
  CALL(PUTCHAR);
  PUSH(IMM('t'));
  CALL(PUTCHAR);
  PUSH(IMM('a'));
  CALL(PUTCHAR);
  PUSH(IMM('l'));
  CALL(PUTCHAR);
  PUSH(IMM(' '));
  CALL(PUTCHAR);
  PUSH(IMM('e'));
  CALL(PUTCHAR);
  PUSH(IMM('r'));
  CALL(PUTCHAR);
  PUSH(IMM('r'));
  CALL(PUTCHAR);
  PUSH(IMM('o'));
  CALL(PUTCHAR);
  PUSH(IMM('r'));
  CALL(PUTCHAR);
  PUSH(IMM(':'));
  CALL(PUTCHAR);
  PUSH(IMM(' '));
  CALL(PUTCHAR);
  PUSH(IMM('C'));
  CALL(PUTCHAR);
  PUSH(IMM('o'));
  CALL(PUTCHAR);
  PUSH(IMM('r'));
  CALL(PUTCHAR);
  PUSH(IMM('r'));
  CALL(PUTCHAR);
  PUSH(IMM('u'));
  CALL(PUTCHAR);
  PUSH(IMM('p'));
  CALL(PUTCHAR);
  PUSH(IMM('t'));
  CALL(PUTCHAR);
  PUSH(IMM(' '));
  CALL(PUTCHAR);
  PUSH(IMM('s'));
  CALL(PUTCHAR);
  PUSH(IMM('e'));
  CALL(PUTCHAR);
  PUSH(IMM('x'));
  CALL(PUTCHAR);
  PUSH(IMM('p'));
  CALL(PUTCHAR);
  PUSH(IMM('r'));
  CALL(PUTCHAR);
  PUSH(IMM(' '));
  CALL(PUTCHAR);
  PUSH(IMM('t'));
  CALL(PUTCHAR);
  PUSH(IMM('y'));
  CALL(PUTCHAR);
  PUSH(IMM('p'));
  CALL(PUTCHAR);
  PUSH(IMM('e'));
  CALL(PUTCHAR);
  PUSH(IMM(':'));
  CALL(PUTCHAR);
  PUSH(IMM(' '));
  CALL(PUTCHAR);
  DROP(34);
  CALL(WRITE_INTEGER);
  DROP(1);
  CALL(NEWLINE);
  HALT;
WRITE_SOB_NO_VOID_IS_VOID:
        RETURN                        ;
