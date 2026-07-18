#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"

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

void clearScreen(void){
    system(CLEAR);
}

void pauseScreen(void){
    printf("\nPress ENTER to continue...");
    getchar();
    getchar();
}

void printTitle(void) {
    printf(CYAN);
    printf("=========================================================\n");
    printf("               LINKED LIST DEMO\n");
    printf("=========================================================\n");
    printf(RESET);
}

void printMenu(void){
    printf("\n");
    printf(" 1  - Push Front\n");
    printf(" 2  - Push Back\n");
    printf(" 3  - Insert At\n");
    printf("-----------------------------------------\n");
    printf(" 4  - Remove Value\n");
    printf("-----------------------------------------\n");
    printf(" 5  - Find\n");
    printf("-----------------------------------------\n");
    printf(" 6  - Print List\n");
    printf(" 7  - Size\n");
    printf(" 8  - Is Empty\n");
    printf(" 9  - Clear List\n");
    printf("-----------------------------------------\n");
    printf(" 0  - Exit\n");
    printf("\nOption: ");
}

void printStatus(LinkedList *list){
    clearScreen();
    printTitle();
    printList(list);
}

int askValue(void){
    int value;
    printf("\nValue: ");
    scanf("%d",&value);
    return value;
}

int askIndex(void){
    int index;
    printf("Index: ");
    scanf("%d",&index);
    return index;
}

void success(const char *msg, LinkedList *list){
    printStatus(list);
    printf(GREEN "\n✔ %s\n" RESET,msg);
    pauseScreen();
}

void errorMsg(const char *msg, LinkedList *list){
    printStatus(list);
    printf(RED "\n✖ %s\n" RESET,msg);
    pauseScreen();
}

int main() {
   LinkedList *list = initList();

    if(list==NULL){
        printf("Failed to create list.\n");
        return EXIT_FAILURE;
    }

    int option;

    do{

        printStatus(list);
        printMenu();

        scanf("%d",&option);

        switch(option){

            case 1:
                pushFront(list, askValue());

                success("Value inserted at front.", list);

                break;

            case 2:
                pushBack(list, askValue());

                success("Value inserted at back.", list);

                break;

            case 3:{
                int value=askValue();
                
                int index=askIndex();

                if(insertAt(list, index, value))
                    success("Value inserted.", list);

                else
                    errorMsg("Invalid index.", list);

                break;
            }

            case 4:{
                int value=askValue();

                if(removeValue(list,value))
                    success("Value removed.", list);

                else
                    errorMsg("Value not found.", list);
                break;
            }

            case 5:{
                int value = askValue();

                Node *node = find(list, value);

                printStatus(list);

                if(node){
                    printf(GREEN "\nNode found:\n\n" RESET);

                    printNode(node);

                } else {
                    printf(RED "\nValue not found.\n" RESET);
                }

                pauseScreen();

                break;
            }

            case 6:
                printStatus(list);
                pauseScreen();
                break;

            case 7:
                printStatus(list);
                printf(YELLOW "\nSize: %d\n" RESET, size(list));
                pauseScreen();
                break;

            case 8:
                printStatus(list);

                if(isEmpty(list))
                    printf(YELLOW "\nThe list is empty.\n" RESET);
                else
                    printf(GREEN "\nThe list is NOT empty.\n" RESET);

                pauseScreen();
                break;

            case 9:
                freeList(list);

                printStatus(list);

                printf(GREEN "\n✔ List cleared. \n" RESET);

                pauseScreen();
                break;

            case 0:
                break;

            default:
                errorMsg("Invalid option.",list);
        }

    } while(option!=0);

    destroyList(list);

    clearScreen();

    printf(GREEN "\nThanks for using Linked List Demo!\n\n" RESET);

    return EXIT_SUCCESS;
}