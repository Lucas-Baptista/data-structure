#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./stack.h"


int main() {
    Stack *stack = createStack();

    push(stack, 5);
    push(stack, 25);
    push(stack, 15);
    push(stack, 89);

    pop(stack);

    peek(stack);

    isEmpty(stack);

    size(stack);

    return 0;
}