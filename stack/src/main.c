#include <stdio.h>
#include <stdlib.h>

#include "./stack.h"


int main() {
    Stack *stack = createStack();

    printStack(stack);

    return 0;
}