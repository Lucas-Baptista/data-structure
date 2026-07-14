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

DoublyLinkedList *initList();

#endif