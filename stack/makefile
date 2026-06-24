CC=gcc

CFLAGS=-Wall -Wextra -Wpedantic -g

SRC=src/main.c src/stack.c

TARGET=stack

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)