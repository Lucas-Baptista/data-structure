CC=gcc

CFLAGS=-Wall -Wextra -Wpedantic -g

SRC=src/main.c src/linked_list.c

TARGET=linked-list

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)