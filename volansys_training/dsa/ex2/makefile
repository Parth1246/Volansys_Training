all: out

out: app.o lib.a
	gcc -o out app.o -L . lib.a

app.o: app.c
	gcc -c app.c -o app.o

lib.o: lib.c
	gcc -c lib.c -o lib.o

lib.a: lib.o
	ar rcs lib.a lib.o

clean: 
	rm -rf *.o *.a out

run:
	./out