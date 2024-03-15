DECORATE = -DDECORATE
CC = gcc
CFLAGS = -c -Wall $(INCLUDES)
SOURCE = app.c sampleLib.c sampleAdd.c
INCLUDES = -I ./ExtHeader
TARGET = out/out.exe


all: out.exe

out.exe: app.o sampleLib.o sampleAdd.o
	$(CC) build/*.o -l./ExtLib/ -o out/out.exe

app.o : app.c
	$(CC) $(CFLAGS) app.c -o build/app.o

sampleLib.o : sampleLib.c
	$(CC) $(CFLAGS) sampleLib.c -o build/sampleLib.o

sampleAdd.o : sampleAdd.c
	$(CC) $(CFLAGS) sampleAdd.c -o build/sampleAdd.o

clean :
	rm -rf $(TARGET) build/*.o

