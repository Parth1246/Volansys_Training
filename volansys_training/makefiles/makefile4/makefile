
out.exe: app.o power.o
	gcc app.o power.o -o out

app.o:app.c
	gcc -c app.c -o app.o

power.o: power.c
	gcc -c power.c -o power.o

clean:
	rm -rf *.0 out
