all: out

out: out.o
	gcc -g -m32 -Wall -o out out.o

out.o: out.c
	gcc -m32 -g -Wall -ansi -c -o out.o out.c 

.PHONY: clean

clean: 
	rm -f *.o out