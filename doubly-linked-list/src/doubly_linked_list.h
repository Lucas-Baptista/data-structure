#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    struct Node *next;
    struct Node *prev;
    int data;
} Node;


typedef struct DoublyLinkedList {
    struct Node *head;
    struct Node *tail;
    int size;
} DoublyLinkedList;

void printList(DoublyLinkedList *list);

DoublyLinkedList *initList();

void pushFront(DoublyLinkedList *list, int data);

#endif