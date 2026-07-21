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

Stack *createStack();

bool push(Stack *stack, int value);

bool pop(Stack *stack, int *value);

const Cell *peek(const Stack *stack);

bool isEmpty(const Stack *stack);

int size(Stack *stack);

void printStack(const Stack *stack);

void printCell(const Cell *cell);

void freeStack(Stack *stack);

void destroyStack(Stack *stack);

#endif
