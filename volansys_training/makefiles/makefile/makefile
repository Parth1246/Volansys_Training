DECORATE = -DDECORATE
CC = gcc
CFLAGS = -c 

out.exe: app.o sampleMul.o sampleAdd.o
	$(CC) -o out/$@ build/*.o

app.o : app.c
	$(CC) $(CFLAGS) app.c -o build/app.o

sampleMul.o : sampleMul.c
	$(CC) $(CFLAGS) sampleMul.c -o build/sampleMul.o

sampleAdd.o : sampleAdd.c
	$(CC) $(CFLAGS) sampleAdd.c -o build/sampleAdd.o

clean : 
	rm -rf build/*.o out/*.exe
