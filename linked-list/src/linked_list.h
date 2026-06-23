#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

typedef struct {
    Node *head;
} LinkedList;

void initList(LinkedList *list);

void printList(LinkedList *list);

void pushFront(LinkedList *list, int value);

void pushBack(LinkedList *list, int value);

#endif