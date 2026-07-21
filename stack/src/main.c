#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"

void clearScreen(void) {
    system(CLEAR);
}

void pauseScreen(void) {
    printf("\nPress ENTER to continue...");
    getchar();
    getchar();
}

void printTitle(void) {
    printf(CYAN);
    printf("=========================================================\n");
    printf("                    STACK DEMO\n");
    printf("=========================================================\n");
    printf(RESET);
}

void printMenu(void) {

    printf("\n");

    printf(" 1  - Push\n");
    printf(" 2  - Pop\n");
    printf("-----------------------------------------\n");
    printf(" 3  - Peek\n");
    printf("-----------------------------------------\n");
    printf(" 4  - Print Stack\n");
    printf(" 5  - Size\n");
    printf(" 6  - Is Empty\n");
    printf("-----------------------------------------\n");
    printf(" 7  - Clear Stack\n");
    printf("-----------------------------------------\n");
    printf(" 0  - Exit\n");

    printf("\nOption: ");
}

void printStatus(Stack *stack) {

    clearScreen();

    printTitle();

    printStack(stack);
}

int askValue(void) {

    int value;

    printf("\nValue: ");

    scanf("%d", &value);

    return value;
}

void success(const char *msg, Stack *stack) {

    printStatus(stack);

    printf(GREEN "\n✔ %s\n" RESET, msg);

    pauseScreen();
}

void errorMsg(const char *msg, Stack *stack) {

    printStatus(stack);

    printf(RED "\n✖ %s\n" RESET, msg);

    pauseScreen();
}

int main(void) {

    Stack *stack = createStack();

    if (stack == NULL) {

        printf("Failed to create stack.\n");

        return EXIT_FAILURE;
    }

    int option;

    do {

        printStatus(stack);

        printMenu();

        scanf("%d", &option);

        switch(option) {

            case 1: {

                int value = askValue();

                if (push(stack, value))
                    success("Value inserted into stack.", stack);
                else
                    errorMsg("Failed to insert value.", stack);

                break;
            }

            case 2: {

                int value;

                if (pop(stack, &value)) {

                    char message[100];

                    sprintf(message, "Removed value: %d", value);

                    success(message, stack);

                } else {

                    errorMsg("Stack is empty.", stack);

                }

                break;
            }

            case 3: {

                printStatus(stack);

                const Cell *cell = peek(stack);

                if (cell) {

                    printf(GREEN "\nPeek cell:\n\n" RESET);

                    printCell(cell);

                } else {

                    printf(RED "\nStack is empty.\n" RESET);

                }

                pauseScreen();

                break;
            }

            
            case 4:

                printStatus(stack);

                pauseScreen();

                break;

            case 5:

                printStatus(stack);

                printf(YELLOW "\nStack size: %d\n" RESET, size(stack));

                pauseScreen();

                break;

            case 6:

                printStatus(stack);

                if (isEmpty(stack))
                    printf(YELLOW "\nThe stack is empty.\n" RESET);
                else
                    printf(GREEN "\nThe stack is NOT empty.\n" RESET);

                pauseScreen();

                break;

            case 7:

                freeStack(stack);

                success("Stack cleared successfully.", stack);

                break;

            case 0:

                break;

            default:

                errorMsg("Invalid option.", stack);

                break;
        }

    } while (option != 0);

    destroyStack(stack);

    clearScreen();

    printf(GREEN);
    printf("=========================================================\n");
    printf("          Thanks for using Stack Demo!\n");
    printf("=========================================================\n");
    printf(RESET);

    return EXIT_SUCCESS;
}