all: out

out: main.o lib.a
	gcc -o out main.o -L . lib.a

main.o: main.c
	gcc -c main.c -o main.o

lib.o: lib.c
	gcc -c lib.c -o lib.o

lib.a: lib.o
	ar rcs lib.a lib.o

clean: 
	rm -rf *.o *.a out

run:
	./out