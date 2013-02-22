/* system/malloc.asm
 * A stub for a more intelligent memory allocation code
 * that shall be re-written later...
 *
 * Programmer: Mayer Goldberg, 2010
 */

 MALLOC:
  PUSH(FP);
  MOV(FP, SP);
  PUSH(R1);
  MOV(R1, FPARG(0));
  MOV(R0, ADDR(0));
//  printf("the malloc number of r0 is: %ld in mem %ld\n",R0,machine->mem[0]) ;
// if (R0 == 170)
//        printf("this is the place \n");
//        if (ADDR(0) > 180)
//           printf("mem 182 \n");
  ADD(ADDR(0), R1);
  POP(R1);
  POP(FP);
  RETURN;
