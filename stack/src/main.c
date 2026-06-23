#include <stdio.h>
#include <stdlib.h>

#include "./stack.h"


int main() {
    Stack *stack = createStack();

    push(stack, 5);
    push(stack, 25);

    printStack(stack);

    return 0;
}