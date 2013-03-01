/* system/malloc.asm
 * A stub for a more intelligent memory allocation code
 * that shall be re-written later...
 *
 * Programmer: Mayer Goldberg, 2010
 */

 MALLOC:
        PUSH(FP);
        MOV(FP, SP);
        CMP(ADDR(0),RAM_SIZE)   ;
//        if(ADDR(0) == 206192)   ;
//                printf("malloc is: %d\n",ADDR(0)) ;
        JUMP_GE(MALLOC_HEAP_TOO_SMALL)               ;
        PUSH(R1);
        MOV(R1, FPARG(0));
        MOV(R0, ADDR(0));
        ADD(ADDR(0), R1);
        POP(R1);
        POP(FP);
        RETURN;
MALLOC_HEAP_TOO_SMALL:
        SHOW("MALLOC - trying to allocate memory outsize of memory size",ADDR(0)) ;
        STOP_MACHINE            ;
        return                  ;
