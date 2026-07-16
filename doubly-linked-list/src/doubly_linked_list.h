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

void reverseList(DoublyLinkedList *list);

void printList(DoublyLinkedList *list);

void printNode(Node *node);

void pushFront(DoublyLinkedList *list, int data);

void pushBack(DoublyLinkedList *list, int data);

int head(DoublyLinkedList *list);

int tail(DoublyLinkedList *list);

bool isEmpty(DoublyLinkedList *list);

int size(DoublyLinkedList *list);

Node *find(DoublyLinkedList *list, int value);

bool insertAt(DoublyLinkedList *list, int value, int index);

#endif