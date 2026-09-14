#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "binary_search_tree.h"

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


void clearScreen(void)
{
    system(CLEAR);
}


void pauseScreen(void)
{
    printf("\nPress ENTER to continue...");
    getchar();
    getchar();
}


void printTitle(void)
{
    printf(CYAN);
    printf("=========================================================\n");
    printf("            BINARY SEARCH TREE DEMO\n");
    printf("=========================================================\n");
    printf(RESET);
}


void printMenu(void)
{
    printf("\n");

    printf(" 1  - Insert Value\n");

    printf("-----------------------------------------\n");

    printf(" 2  - Remove Value\n");

    printf("-----------------------------------------\n");

    printf(" 3  - Search\n");

    printf("-----------------------------------------\n");

    printf(" 4  - Print InOrder\n");
    printf(" 5  - Print PreOrder\n");
    printf(" 6  - Print PostOrder\n");
    printf(" 7  - Print Tree\n");

    printf("-----------------------------------------\n");

    printf(" 8  - Find Minimum\n");
    printf(" 9  - Find Maximum\n");
    printf("10  - Height\n");
    printf("11  - Number of Nodes\n");
    printf("12  - Number of Leaves\n");

    printf("-----------------------------------------\n");

    printf("13  - Clear Tree\n");

    printf("-----------------------------------------\n");

    printf(" 0  - Exit\n");

    printf("\nOption: ");
}


void printStatus(BinarySearchTree *tree)
{
    clearScreen();

    printTitle();

    printf("\n");

    printTree(tree);
}


int askValue(void)
{
    int value;

    printf("\nValue: ");
    scanf("%d", &value);

    return value;
}


void success(const char *msg, BinarySearchTree *tree)
{
    printStatus(tree);

    printf(GREEN "\n✔ %s\n" RESET, msg);

    pauseScreen();
}


void errorMsg(const char *msg, BinarySearchTree *tree)
{
    printStatus(tree);

    printf(RED "\n✖ %s\n" RESET, msg);

    pauseScreen();
}


int main(void)
{
    BinarySearchTree *tree = initBinarySearchTree();

    if (tree == NULL) {
        printf("Failed to create tree.\n");
        return EXIT_FAILURE;
    }

    int option;

    do {

        printStatus(tree);

        printMenu();

        scanf("%d", &option);

        switch (option) {

            /*
             * ================================================
             * INSERT
             * ================================================
             */

            case 1: {

                int value = askValue();

                if (insert(tree, value)) {
                    success("Value inserted.", tree);
                } else {
                    errorMsg(
                        "Value already exists or insertion failed.",
                        tree
                    );
                }

                break;
            }


            /*
             * ================================================
             * REMOVE
             * ================================================
             */

            case 2: {

                int value = askValue();

                if (removeValue(tree, value)) {
                    success("Value removed.", tree);
                } else {
                    errorMsg("Value not found.", tree);
                }

                break;
            }


            /*
             * ================================================
             * SEARCH
             * ================================================
             */

            case 3: {

                int value = askValue();

                SearchNode *result = search(tree, value);

                printStatus(tree);

                if (result != NULL) {

                    printf(
                        GREEN "\nNode found:\n\n" RESET
                    );

                    printf(
                        "Value : %d\n",
                        result->target->data
                    );

                    if (result->parent != NULL) {

                        printf(
                            "Parent: %d\n",
                            result->parent->data
                        );

                    } else {

                        printf(
                            "Parent: ROOT\n"
                        );
                    }

                    free(result);

                } else {

                    printf(
                        RED "\nValue not found.\n" RESET
                    );
                }

                pauseScreen();

                break;
            }


            /*
             * ================================================
             * INORDER
             * ================================================
             */

            case 4:

                printStatus(tree);

                printf(
                    YELLOW "\nInOrder:\n\n" RESET
                );

                printInOrder(tree);

                pauseScreen();

                break;


            /*
             * ================================================
             * PREORDER
             * ================================================
             */

            case 5:

                printStatus(tree);

                printf(
                    YELLOW "\nPreOrder:\n\n" RESET
                );

                printPreOrder(tree);

                pauseScreen();

                break;


            /*
             * ================================================
             * POSTORDER
             * ================================================
             */

            case 6:

                printStatus(tree);

                printf(
                    YELLOW "\nPostOrder:\n\n" RESET
                );

                printPostOrder(tree);

                pauseScreen();

                break;


            /*
             * ================================================
             * PRINT TREE
             * ================================================
             */

            case 7:

                printStatus(tree);

                pauseScreen();

                break;


            /*
             * ================================================
             * MINIMUM
             * ================================================
             */

            case 8: {

                Node *min = findMin(tree);

                printStatus(tree);

                if (min != NULL) {

                    printf(
                        YELLOW "\nMinimum: %d\n" RESET,
                        min->data
                    );

                } else {

                    printf(
                        RED "\nTree is empty.\n" RESET
                    );
                }

                pauseScreen();

                break;
            }


            /*
             * ================================================
             * MAXIMUM
             * ================================================
             */

            case 9: {

                Node *max = findMax(tree);

                printStatus(tree);

                if (max != NULL) {

                    printf(
                        YELLOW "\nMaximum: %d\n" RESET,
                        max->data
                    );

                } else {

                    printf(
                        RED "\nTree is empty.\n" RESET
                    );
                }

                pauseScreen();

                break;
            }


            /*
             * ================================================
             * HEIGHT
             * ================================================
             */

            case 10:

                printStatus(tree);

                printf(
                    YELLOW "\nHeight: %d\n" RESET,
                    height(tree)
                );

                pauseScreen();

                break;


            /*
             * ================================================
             * NUMBER OF NODES
             * ================================================
             */

            case 11:

                printStatus(tree);

                printf(
                    YELLOW "\nNodes: %d\n" RESET,
                    countNodes(tree)
                );

                pauseScreen();

                break;


            /*
             * ================================================
             * NUMBER OF LEAVES
             * ================================================
             */

            case 12:

                printStatus(tree);

                printf(
                    YELLOW "\nLeaves: %d\n" RESET,
                    countLeaves(tree)
                );

                pauseScreen();

                break;


            /*
             * ================================================
             * CLEAR
             * ================================================
             */

            case 13:

                clear(tree);

                success("Tree cleared.", tree);

                break;


            /*
             * ================================================
             * EXIT
             * ================================================
             */

            case 0:

                break;


            /*
             * ================================================
             * INVALID OPTION
             * ================================================
             */

            default:

                errorMsg("Invalid option.", tree);

                break;
        }

    } while (option != 0);


    destroyBinarySearchTree(tree);

    clearScreen();

    printf(
        GREEN
        "\nThanks for using Binary Search Tree Demo!\n\n"
        RESET
    );

    return EXIT_SUCCESS;
}