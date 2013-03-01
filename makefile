all: out

out: out.c
	gcc -g -m32 -o out out.c 
clean: 
	rm -f out
