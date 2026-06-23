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
    printf("stack size: %d\n", stack->size);
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
    printf("&next.......: %p\n", (void *)&cell->next);

    printf("---------------------------------------\n\n");
}

Stack *createStack() {
    Stack *stack = malloc(sizeof(Stack));

    stack->top = NULL;
    stack->size = 0;

    return stack;
}

void push(Stack *stack, int value) {
    
    printf("\nEmpilhando a céula: %d\n", value);

    Cell *newCell = malloc(sizeof(Cell));

    newCell->data = value;
    
    newCell->next = stack->top;

    stack->top = newCell;
    stack->size++;

    printStack(stack);
}

int pop(Stack *stack) {

    Cell *tmpCell = stack->top;
    
    printf("Desempilhando a célula: %d\n", tempCell->data);

    int cellData = tmpCell->data;

    stack->top = tmpCell->next;

    stack->size--;
    
    printCell(tmpCell);
    
    printStack(stack); 

    free(tmpCell);

    return cellData;
}