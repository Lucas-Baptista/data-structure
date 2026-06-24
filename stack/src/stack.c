#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./stack.h"

void printStack(Stack *stack) {
    Cell *current = stack->top;
    
    printf(" TOP\n  ↓ \n");

    if (current == NULL) {
        printf(" NULL \n");
        return;
    }
     
    printf("+----+\n");
    printf("  %d  \n", current->data);
    printf("+----+\n");
    printf("  ↓ \n");

    current = current->next;
    
    while (current != NULL){
        printf("+----+\n");
        printf("  %d  \n", current->data);
        printf("+----+\n");
        printf("  ↓ \n");

        current = current->next;
    }

    printf(" NULL \n\n");
    printf("stack size: %d\n\n", stack->size);
    printf("---------------------------------------\n\n");
}

void printCell (Cell *cell) {

    printf("cell........: %p\n", (void *)cell);

    if (cell == NULL) {
        printf("NULL\n\n");
        return;
    }

    printf("data........: %d\n", cell->data);
    printf("next........: %p\n", (void *)cell->next);
    printf("&data.......: %p\n", (void *)&cell->data);
    printf("&next.......: %p\n\n", (void *)&cell->next);

    printf("---------------------------------------\n\n");
}

Stack *createStack() {
    Stack *stack = malloc(sizeof(Stack));

    stack->top = NULL;
    stack->size = 0;

    return stack;
}

void push(Stack *stack, int value) {
    
    printf("Empilhando a céula: %d\n\n", value);

    Cell *newCell = malloc(sizeof(Cell));

    newCell->data = value;
    
    newCell->next = stack->top;

    stack->top = newCell;
    stack->size++;

    printStack(stack);
}

int pop(Stack *stack) {

    Cell *tmpCell = stack->top;

    if (tmpCell == NULL) {
        printf("Pilha Vazia!\n");

        exit(EXIT_FAILURE);
    }
    
    printf("Desempilhando a célula: %d\n\n", tmpCell->data);

    int cellData = tmpCell->data;

    stack->top = tmpCell->next;

    stack->size--;
    
    printCell(tmpCell);
    
    printStack(stack); 

    free(tmpCell);

    return cellData;
}

int peek(Stack *stack) {
    Cell *peek = stack->top;

    if (peek == NULL) {
        printf("Pilha Vazia!\n");
        
        exit(EXIT_FAILURE);
    }

    printf("Topo da pilha: %d\n\n", peek->data);

    printCell(peek);

    return peek->data;
}

bool isEmpty(Stack *stack) {
    printf(stack->size > 0 
        ? "A pilha não esta vazia\n\n" 
        : "A pilha esta vazia\n\n"
    );

    return stack->size > 0;
}

int size(Stack *stack) {
    printf("A Pilha contem %d elementos\n\n", stack->size);

    return stack->size;
}