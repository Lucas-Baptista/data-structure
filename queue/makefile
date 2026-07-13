CC=gcc

CFLAGS=-Wall -Wextra -Wpedantic -g

SRC=src/main.c src/queue.c

TARGET=queue

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)