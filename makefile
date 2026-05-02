CC=gcc
CFLAGS=-Wall -g

all:h

h: main.o  game.o
	$(CC) $(CFLAGS) -o h main.o game.o

main.o: main.c game.h
	$(CC) $(CFLAGS) -c main.c

game.o: game.c game.h
	$(CC) $(CFLAGS) -c game.c

clean:
	rm -f *.o h
