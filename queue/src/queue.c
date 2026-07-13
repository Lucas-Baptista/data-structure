#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./queue.h"

void printQueue(Queue *queue) {
    Node *current = queue->front;
    
    printf(" front\n  ↓ \n");

    if (current == NULL) {
        printf(" NULL \n");
        printf("  ↑ \n Rear \n\n");
        printf("Queue size: %d\n\n", queue->size);
        printf("---------------------------------------\n\n");
        return;
    }
     
    printf("+----+\n");
    printf("  %d  \n", current->data);
    printf("+----+\n");

    current = current->next;
    
    while (current != NULL){
        printf("  ↓ \n");
        printf("+----+\n");
        printf("  %d  \n", current->data);
        printf("+----+\n");

        current = current->next;
    }

    printf("  ↑ \n Rear \n\n");
    printf("Queue size: %d\n\n", queue->size);
    printf("---------------------------------------\n\n");
}

void printNode (Node *node, char *type) {

    printf("Node........: %s\n", type);
    printf("Node........: %p\n", (void *)node);

    if (node == NULL) {
        printf("NULL\n\n");
        return;
    }

    printf("data........: %d\n", node->data);
    printf("next........: %p\n", (void *)node->next);
    printf("&data.......: %p\n", (void *)&node->data);
    printf("&next.......: %p\n\n", (void *)&node->next);

    printf("---------------------------------------\n\n");
}

Queue *initQueue() {
    Queue *queue = malloc(sizeof(Queue));

    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;

    return queue;
}

void enqueue(Queue *queue, int data) {
    Node *newNode = malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

   if (queue->front == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    queue->size++;
}

int dequeue(Queue *queue) {
    if (queue == NULL || queue->front == NULL) {
        printf("Queue is empty!\n");
        return -1; // ou outro valor de erro
    }

    Node *frontTmp = queue->front;
    int tmpData = frontTmp->data;

    queue->front = frontTmp->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(frontTmp);
    queue->size--;

    return tmpData;
}

Node *front(Queue *queue) {
    Node *frontNode = queue->front; 
    return frontNode;
}

Node *rear(Queue *queue) {
    Node *rearNode = queue->rear; 
    return rearNode;
}

bool isEmpty(Queue *queue) {
    bool empty = queue->front == NULL;
    
    printf(empty ? "A FILA ESTÁ VAZIA\n\n" : "A FILA NÃO ESTÁ VAZIA\n\n");

    return empty;
}

int size(Queue *queue) {
    printf("HÁ %d ELEMENTOS NA FILA\n\n", queue->size);

    return queue->size;
}

void freeQueue(Queue *queue) {
    printf("LINPANDO A LISTA -----------------------------\n\n");

    Node *current = queue->front;

    while (current != NULL){
        Node *next = current->next;

        free(current);

        current = next;
    }

    queue->size = 0;
    queue->front = NULL;
    queue->rear = NULL;
}
