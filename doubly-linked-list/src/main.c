
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "doubly_linked_list.h"

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

void printTitle(void){
    printf(CYAN);
    printf("=========================================================\n");
    printf("               DOUBLY LINKED LIST DEMO\n");
    printf("=========================================================\n");
    printf(RESET);
}

void printMenu(void){
    printf("\n");
    printf(" 1  - Push Front\n");
    printf(" 2  - Push Back\n");
    printf(" 3  - Insert At\n");
    printf("-----------------------------------------\n");
    printf(" 4  - Pop Front\n");
    printf(" 5  - Pop Back\n");
    printf(" 6  - Remove Value\n");
    printf(" 7  - Remove At\n");
    printf("-----------------------------------------\n");
    printf(" 8  - Find\n");
    printf(" 9  - Reverse List\n");
    printf("-----------------------------------------\n");
    printf("10  - Print List\n");
    printf("11  - Head\n");
    printf("12  - Tail\n");
    printf("13  - Size\n");
    printf("14  - Is Empty\n");
    printf("-----------------------------------------\n");
    printf(" 0  - Exit\n");
    printf("\nOption: ");
}

void printStatus(DoublyLinkedList *list){
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

void success(const char *msg,DoublyLinkedList *list){
    printStatus(list);
    printf(GREEN "\n✔ %s\n" RESET,msg);
    pauseScreen();
}

void errorMsg(const char *msg,DoublyLinkedList *list){
    printStatus(list);
    printf(RED "\n✖ %s\n" RESET,msg);
    pauseScreen();
}

int main(void){

    DoublyLinkedList *list = initList();

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
                pushFront(list,askValue());
                success("Value inserted at front.",list);
                break;

            case 2:
                pushBack(list,askValue());
                success("Value inserted at back.",list);
                break;

            case 3:{
                int value=askValue();
                int index=askIndex();

                if(insertAt(list,value,index))
                    success("Value inserted.",list);
                else
                    errorMsg("Invalid index.",list);
                break;
            }

            case 4:
                if(popFront(list))
                    success("First node removed.",list);
                else
                    errorMsg("List is empty.",list);
                break;

            case 5:
                if(popBack(list))
                    success("Last node removed.",list);
                else
                    errorMsg("List is empty.",list);
                break;

            case 6:{
                int value=askValue();

                if(removeValue(list,value))
                    success("Value removed.",list);
                else
                    errorMsg("Value not found.",list);
                break;
            }

            case 7:{
                int index=askIndex();

                if(removeAt(list,index))
                    success("Node removed.",list);
                else
                    errorMsg("Invalid index.",list);
                break;
            }

            case 8:{
                int value=askValue();

                Node *node=find(list,value);

                printStatus(list);

                if(node){
                    printf(GREEN "\nNode found:\n\n" RESET);
                    printNode(node);
                }else{
                    printf(RED "\nValue not found.\n" RESET);
                }

                pauseScreen();
                break;
            }

            case 9:
                reverseList(list);
                success("List reversed.",list);
                break;

            case 10:
                printStatus(list);
                pauseScreen();
                break;

            case 11:
                printStatus(list);

                if(!isEmpty(list))
                    printf(YELLOW "\nHead: %d\n" RESET,head(list));
                else
                    printf(RED "\nList is empty.\n" RESET);

                pauseScreen();
                break;

            case 12:
                printStatus(list);

                if(!isEmpty(list))
                    printf(YELLOW "\nTail: %d\n" RESET,tail(list));
                else
                    printf(RED "\nList is empty.\n" RESET);

                pauseScreen();
                break;

            case 13:
                printStatus(list);
                printf(YELLOW "\nSize: %d\n" RESET,size(list));
                pauseScreen();
                break;

            case 14:
                printStatus(list);

                if(isEmpty(list))
                    printf(YELLOW "\nThe list is empty.\n" RESET);
                else
                    printf(GREEN "\nThe list is NOT empty.\n" RESET);

                pauseScreen();
                break;

            case 0:
                break;

            default:
                errorMsg("Invalid option.",list);
        }

    }while(option!=0);

    destroyList(list);

    clearScreen();

    printf(GREEN "\nThanks for using Doubly Linked List Demo!\n\n" RESET);

    return EXIT_SUCCESS;
}
