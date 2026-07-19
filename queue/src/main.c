#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

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
    printf("                    QUEUE DEMO\n");
    printf("=========================================================\n");
    printf(RESET);
}

void printMenu(void) {

    printf("\n");

    printf(" 1  - Enqueue\n");
    printf(" 2  - Dequeue\n");
    printf("-----------------------------------------\n");
    printf(" 3  - Front\n");
    printf(" 4  - Rear\n");
    printf("-----------------------------------------\n");
    printf(" 5  - Print Queue\n");
    printf(" 6  - Size\n");
    printf(" 7  - Is Empty\n");
    printf("-----------------------------------------\n");
    printf(" 8  - Clear Queue\n");
    printf("-----------------------------------------\n");
    printf(" 0  - Exit\n");

    printf("\nOption: ");
}

void printStatus(Queue *queue) {

    clearScreen();

    printTitle();

    printQueue(queue);
}

int askValue(void) {

    int value;

    printf("\nValue: ");

    scanf("%d", &value);

    return value;
}

void success(const char *msg, Queue *queue) {

    printStatus(queue);

    printf(GREEN "\n✔ %s\n" RESET, msg);

    pauseScreen();
}

void errorMsg(const char *msg, Queue *queue) {

    printStatus(queue);

    printf(RED "\n✖ %s\n" RESET, msg);

    pauseScreen();
}

int main(void) {

    Queue *queue = initQueue();

    if (queue == NULL) {

        printf("Failed to create queue.\n");

        return EXIT_FAILURE;
    }

    int option;

    do {

        printStatus(queue);

        printMenu();

        scanf("%d", &option);

        switch(option) {

            case 1: {

                int value = askValue();

                if (enqueue(queue, value))
                    success("Value inserted into queue.", queue);
                else
                    errorMsg("Failed to insert value.", queue);

                break;
            }

            case 2: {

                int value;

                if (dequeue(queue, &value)) {

                    char message[100];

                    sprintf(message, "Removed value: %d", value);

                    success(message, queue);

                } else {

                    errorMsg("Queue is empty.", queue);

                }

                break;
            }

            case 3: {

                printStatus(queue);

                const Node *node = front(queue);

                if (node) {

                    printf(GREEN "\nFront node:\n\n" RESET);

                    printNode(node);

                } else {

                    printf(RED "\nQueue is empty.\n" RESET);

                }

                pauseScreen();

                break;
            }

            case 4: {

                printStatus(queue);

                const Node *node = rear(queue);

                if (node) {

                    printf(GREEN "\nRear node:\n\n" RESET);

                    printNode(node);

                } else {

                    printf(RED "\nQueue is empty.\n" RESET);

                }

                pauseScreen();

                break;
            }
            case 5:

                printStatus(queue);

                pauseScreen();

                break;

            case 6:

                printStatus(queue);

                printf(YELLOW "\nQueue size: %d\n" RESET, size(queue));

                pauseScreen();

                break;

            case 7:

                printStatus(queue);

                if (isEmpty(queue))
                    printf(YELLOW "\nThe queue is empty.\n" RESET);
                else
                    printf(GREEN "\nThe queue is NOT empty.\n" RESET);

                pauseScreen();

                break;

            case 8:

                freeQueue(queue);

                success("Queue cleared successfully.", queue);

                break;

            case 0:

                break;

            default:

                errorMsg("Invalid option.", queue);

                break;
        }

    } while (option != 0);

    destroyQueue(queue);

    clearScreen();

    printf(GREEN);
    printf("=========================================================\n");
    printf("          Thanks for using Queue Demo!\n");
    printf("=========================================================\n");
    printf(RESET);

    return EXIT_SUCCESS;
}