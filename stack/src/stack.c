#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./stack.h"

/* ==========================================================
 * Helpers privados
 * ========================================================== */

static Cell *createCell(int value) {
    Cell *newCell = malloc(sizeof(Cell));

    if (newCell == NULL) {
        return NULL;
    }

    newCell->data = value;
    newCell->next = NULL;

    return newCell;
}

/* ==========================================================
 * Inicialização
 * ========================================================== */

Stack *createStack() {
    Stack *stack = malloc(sizeof(Stack));

    stack->top = NULL;
    stack->size = 0;

    return stack;
}

/* ==========================================================
 * Inserção
 * ========================================================== */

bool push(Stack *stack, int value) {
    if (stack == NULL) {
        return false;
    }

    Cell *newCell = createCell(value);

    if (!newCell) return false;

    newCell->next = stack->top;

    stack->top = newCell;
    stack->size++;

    return true;
}

/* ==========================================================
 * Remoção
 * ========================================================== */

bool pop(Stack *stack, int *value) {

    Cell *tmpCell = stack->top;

    if (tmpCell == NULL) {
        return false;
    }

    *value = stack->top->data;
    
    stack->top = tmpCell->next;

    stack->size--;
    
    free(tmpCell);

    return true;
}

/* ==========================================================
 * Consulta
 * ========================================================== */

const Cell *peek(const Stack *stack) {
    if (stack == NULL) {
        return NULL;
    }

    return stack->top;
}

bool isEmpty(const Stack *stack) {
    return stack == NULL || stack->top == NULL;
}

int size(Stack *stack) {
    if (stack == NULL) {
        return 0;
    }

    return stack->size;
}

/* ==========================================================
 * Impressão
 * ========================================================== */

void printStack(const Stack *stack) {
    printf("Top -> ");

    if (stack == NULL || isEmpty(stack)) {
        printf("NULL \n");
        printf("\nStack size: 0\n");

        return;
    }

    const Cell *current = stack->top;

    while (current != NULL) {
        printf("[%d]", current->data);

        if (current->next != NULL) {
            printf(" -> ");
        }

        current = current->next;
    }

    printf("\nStack size: %d\n", stack->size);
}

void printCell(const Cell *cell) {
    if (cell == NULL) {
        printf("cell: NULL\n");

        return;
    }

    printf("=============== cell ===============\n");
    printf("Address : %p\n", (void *)cell);
    printf("Data    : %d\n", cell->data);
    printf("Next    : %p\n", (void *)cell->next);
    printf("====================================\n");
}

/* ==========================================================
 * Limpeza
 * ========================================================== */

void freeStack(Stack *stack) {
    if (stack == NULL) {
        return;
    }

    Cell *current = stack->top;

    while (current != NULL){
        Cell *next = current->next;

        free(current);

        current = next;
    }

    stack->top = NULL;
    stack->size = 0;
}

void destroyStack(Stack *stack) {
    if (stack == NULL) {
        return;
    }

    freeStack(stack);

    free(stack);
}