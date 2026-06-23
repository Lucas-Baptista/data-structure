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

    printf("NULL\n\n");
}

void printNode(Node *node) {

    printf("node........: %p\n", (void *)node);

    if (node == NULL) {
        printf("NULL\n\n");
        return;
    }

    printf("data........: %d\n", node->data);
    printf("next........: %p\n", (void *)node->next);
    printf("&data.......: %p\n", (void *)&node->data);
    printf("&next.......: %p\n", (void *)&node->next);

    printf("\n");
}

void pushFront (LinkedList *list, int value) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        return;
    }

    newNode->data = value;
    newNode->next = list->head;

    list->head = newNode;
    
}

void pushBack (LinkedList *list, int value) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        return;
    }

    newNode->data = value;
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

void insertAt(LinkedList *list, int index, int value) {
    if (index < 0) {
        return;
    }

    if (index == 0) {
        pushFront(list, value);
        return;
    }

    Node *current = list->head;

    for (int i = 0; i < index - 1; i++) {

        if (current == NULL) {
            return;
        }

        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        return;
    }

    newNode->data = value;
    newNode->next = current->next;

    current->next = newNode;
}

void removeValue(LinkedList *list, int value) {

    if (list->head == NULL) {
        return;
    }

    if (list->head->data == value) {

        Node *tmp = list->head;

        list->head = list->head->next;

        free(tmp);

        return;
    }

    Node *current = list->head;

    while (current->next != NULL) {

        if (current->next->data == value) {

            Node *tmp = current->next;

            current->next = tmp->next;

            free(tmp);

            return;
        }

        current = current->next;
    }
}

Node *find(LinkedList *list, int value) {
    Node *current = list->head;

    while (current != NULL) {

        if (current->data == value) {
            return current;
        }

        current = current->next;
    }

    return NULL;
    
}

void freeList (LinkedList *list) {
    Node *current = list->head;

    while (current != NULL){
        Node *next = current->next;

        free(current);

        current = next;
    }

    list->head = NULL;
}
