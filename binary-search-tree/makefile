CC=gcc

CFLAGS=-Wall -Wextra -Wpedantic -g

SRC=src/main.c src/binary_search_tree.c

TARGET=binary_search_tree

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)