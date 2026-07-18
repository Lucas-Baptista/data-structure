
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} LinkedList;

LinkedList *initList(void);

void printList(LinkedList *list);

void printNode(Node *node);

void pushFront(LinkedList *list, int value);

void pushBack(LinkedList *list, int value);

bool insertAt(LinkedList *list, int index, int value);

bool removeValue(LinkedList *list, int value);

Node *find(LinkedList *list, int value);

bool isEmpty(LinkedList *list);

int size(LinkedList *list);

void freeList(LinkedList *list);

void destroyList(LinkedList *list);

#endif
