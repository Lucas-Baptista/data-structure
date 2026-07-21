#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

/* ==========================================================
 * Helpers privados
 * ========================================================== */

static Node *createNode(int value) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        return NULL;
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

/* ==========================================================
 * Inicialização
 * ========================================================== */

Queue *initQueue(void) {
    Queue *queue = malloc(sizeof(Queue));

    if (queue == NULL) {
        return NULL;
    }

    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;

    return queue;
}

/* ==========================================================
 * Inserção
 * ========================================================== */

bool enqueue(Queue *queue, int value) {
    if (queue == NULL) {
        return false;
    }

    Node *newNode = createNode(value);

    if (!newNode) return false;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    queue->size++;

    return true;
}

/* ==========================================================
 * Remoção
 * ========================================================== */

bool dequeue(Queue *queue, int *value) {
    if (queue == NULL || isEmpty(queue)) {
        return false;
    }

    Node *temp = queue->front;

    *value = temp->data;

    queue->front = temp->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);

    queue->size--;

    return true;
}

/* ==========================================================
 * Consulta
 * ========================================================== */

const Node *front(const Queue *queue) {
    if (queue == NULL) {
        return NULL;
    }

    return queue->front;
}

const Node *rear(const Queue *queue) {
    if (queue == NULL) {
        return NULL;
    }

    return queue->rear;
}

bool isEmpty(const Queue *queue) {
    return queue == NULL || queue->front == NULL;
}

int size(const Queue *queue) {
    if (queue == NULL) {
        return 0;
    }

    return queue->size;
}

/* ==========================================================
 * Impressão
 * ========================================================== */

void printQueue(const Queue *queue) {
    printf("Front -> ");

    if (queue == NULL || isEmpty(queue)) {
        printf("NULL <- Rear\n");
        printf("\nQueue size: 0\n");

        return;
    }

    const Node *current = queue->front;

    while (current != NULL) {
        printf("[%d]", current->data);

        if (current->next != NULL) {
            printf(" -> ");
        }

        current = current->next;
    }

    printf(" <- Rear");
    printf("\nQueue size: %d\n", queue->size);
}

void printNode(const Node *node) {
    if (node == NULL) {
        printf("Node: NULL\n");

        return;
    }

    printf("=============== NODE ===============\n");
    printf("Address : %p\n", (void *)node);
    printf("Data    : %d\n", node->data);
    printf("Next    : %p\n", (void *)node->next);
    printf("====================================\n");
}

/* ==========================================================
 * Limpeza
 * ========================================================== */

void freeQueue(Queue *queue) {
    if (queue == NULL) {
        return;
    }

    Node *current = queue->front;

    while (current != NULL) {
        Node *next = current->next;

        free(current);

        current = next;
    }

    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

void destroyQueue(Queue *queue) {
    if (queue == NULL) {
        return;
    }

    freeQueue(queue);

    free(queue);
}