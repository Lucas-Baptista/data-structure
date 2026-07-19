#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
    int size;
} Queue;

Queue *initQueue(void);

bool enqueue(Queue *queue, int value);

bool dequeue(Queue *queue, int *value);

const Node *front(const Queue *queue);

const Node *rear(const Queue *queue);

bool isEmpty(const Queue *queue);

int size(const Queue *queue);

void printQueue(const Queue *queue);

void printNode(const Node *node);

void freeQueue(Queue *queue);

void destroyQueue(Queue *queue);

#endif