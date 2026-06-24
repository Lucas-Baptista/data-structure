#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct Cell {
    int data;
    struct Cell *next;    
} Cell;

typedef struct Stack {
    struct Cell *top;
    int size;
} Stack;

void printStack(Stack *stack);

void printCell(Cell *cell);

Stack *createStack();

void push(Stack *stack, int value);

int pop(Stack* stack);

int peek(Stack *stack);

#endif