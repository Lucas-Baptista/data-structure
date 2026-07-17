CC=gcc

CFLAGS=-Wall -Wextra -Wpedantic -g

SRC=src/main.c src/doubly_linked_list.c

TARGET=doubly_linked_list

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)