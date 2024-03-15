CC = gcc
CFLAGS = -c
DECORATE = -DDECORATE

out.exe: sampleMul.o sampleSub.o sampleAdd.o sampleDivide.o app.o
	$(CC) -o out/$@  build/*.o

app.o : app.c
	$(CC) $(CFLAGS) app.c $(DECORATE) -o build/app.o

%.o:./commonMod1/%.c
	$(CC) $(CFLAGS) $^ -o build/$@

%.o:./commonMod2/%.c
	$(CC) $(CFLAGS) $^ -o build/$@

clean:
	rm -rf build/*.o out/*.exe


