#include <stdio.h>
#include <stdlib.h>

#include "./stack.h"

void printStack(Stack *stack) {
    Cell *current = stack->top;
    
    printf(" TOP\n  ↓ \n");

    if (current == NULL) {
        printf(" NULL \n");
        return;
    }
     
    printf(" %d \n ↓ \n", current->data);
    
    while (current != NULL){
        printf("+----+\n");
        printf("  %d  \n", current->data);
        printf("+----+\n");
        printf("  ↓ \n");
    }

    printf(" NULL \n");    
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
    printf("&next.......: %p\n", (void *)&cell->next);

    printf("\n");
}

Stack *createStack() {
    Stack *stack = malloc(sizeof(Stack));

    stack->top = NULL;
    stack->size = 0;

    return stack;
}