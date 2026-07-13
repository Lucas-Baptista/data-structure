#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    struct Node *front;
    struct Node *rear;
    int size;
} Queue;

void printQueue(Queue *queue);

void printNode(Node *node, char *type);

Queue *initQueue();

void enqueue(Queue *queue, int value);

int dequeue(Queue *queue);

Node *front(Queue *queue);

Node *rear(Queue *queue);

bool isEmpty(Queue *queue);

int size(Queue *queue);

void freeQueue(Queue *queue);

#endif