all: out

out: main.o lib.a
	gcc -o out main.o -L . lib.a

main.o: main.c
	gcc -c main.c -o main.o

library.o: library.c
	gcc -c library.c -o library.o

lib.a: library.o
	ar rcs lib.a library.o

clean: 
	rm -rf *.o *.a out

run:
	./out