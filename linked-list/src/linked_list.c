#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

void initList (LinkedList *list) {
    list->head = NULL;
}

void printList (LinkedList *list) {
    Node *current = list->head;

    while (current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

void pushFront (LinkedList *list, int data) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        return;
    }

    newNode->data = data;
    newNode->next = list->head;

    list->head = newNode;
    
}

void pushBack (LinkedList *list, int data) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    Node *current = list->head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    
}