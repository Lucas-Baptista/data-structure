#include <stdio.h>
#include <stdlib.h>

#include "doubly_linked_list.h"

void printList(DoublyLinkedList *list) {
     Node *current = list->head;
    
    printf(" Head\n  ↓ \n");

    if (current == NULL) {
        printf(" NULL \n");
        printf("  ↑ \n Tail \n\n");
        printf("List size: %d\n\n", list->size);
        printf("---------------------------------------\n\n");
        return;
    }
     
    printf("+----+\n");
    printf("  %d  \n", current->data);
    printf("+----+\n");

    current = current->next;
    
    while (current != NULL){
        printf("  ↑↓ \n");
        printf("+----+\n");
        printf("  %d  \n", current->data);
        printf("+----+\n");

        current = current->next;
    }

    printf("  ↑ \n Tail \n\n");
    printf("list size: %d\n\n", list->size);
    printf("---------------------------------------\n\n");
}

DoublyLinkedList *initList () {
    DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

void pushFront (DoublyLinkedList *list, int data) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        return
    }

    newNode->data = data;
    newNode->prev = NULL;

    list->size++;

    if (list->head == NULL) {
        newNode->next = NULL;
        list->head = list->tail = newNode;
        return;
    }

    newNode->next = list->head;
    
    list->head->prev = newNode;
    
    list->head = newNode;
}

void pushBack(DoublyLinkedList *list, int data) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    list->size++;

    if (list->head == NULL) {
        newNode->prev = NULL;
        list->head = list->tail = newNode;
        return;
    }

    newNode->prev = list->tail;
    
    list->tail->next = newNode;
    
    list->tail = newNode;
}