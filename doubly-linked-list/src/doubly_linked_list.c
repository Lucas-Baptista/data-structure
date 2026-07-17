#include <stdio.h>
#include <stdlib.h>

#include "doubly_linked_list.h"

/* ==========================================================
 * Helpers privados
 * ========================================================== */

static Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));

    if (node == NULL)
        return NULL;

    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

static Node *getNodeAt(DoublyLinkedList *list, int index) {

    if (list == NULL || index < 0 || index >= list->size)
        return NULL;

    Node *current;

    if (index < list->size / 2) {

        current = list->head;

        for (int i = 0; i < index; i++)
            current = current->next;

    } else {

        current = list->tail;

        for (int i = list->size - 1; i > index; i--)
            current = current->prev;
    }

    return current;
}

/* ==========================================================
 * Inicialização
 * ========================================================== */

DoublyLinkedList *initList() {

    DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));

    if (list == NULL)
        return NULL;

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

/* ==========================================================
 * Impressão
 * ========================================================== */

void printList(DoublyLinkedList *list) {

    printf("\n=========================Doubly Linked List===========================\n\n");

    if (list == NULL || list->head == NULL) {
        printf("Head -> NULL <- Tail\n");
        printf("Size : 0\n");
        printf("\n=====================================================================\n");
        return;
    }

    printf("Head -> ");

    Node *current = list->head;

    while (current != NULL) {

        printf("[%d]", current->data);

        if (current->next != NULL)
            printf(" <-> ");

        current = current->next;
    }

    printf(" <- Tail\n");
    printf("Size : %d\n", list->size);
    printf("\n=====================================================================\n");

}

void printNode(Node *node) {

    if (node == NULL) {
        printf("NULL\n");
        return;
    }

    printf("Address : %p\n", (void *)node);
    printf("Data    : %d\n", node->data);
    printf("Prev    : %p\n", (void *)node->prev);
    printf("Next    : %p\n", (void *)node->next);
}

/* ==========================================================
 * Inserção
 * ========================================================== */

void pushFront(DoublyLinkedList *list, int data) {

    if (list == NULL)
        return;

    Node *newNode = createNode(data);

    if (newNode == NULL)
        return;

    if (list->head == NULL) {

        list->head = list->tail = newNode;

    } else {

        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }

    list->size++;
}

void pushBack(DoublyLinkedList *list, int data) {

    if (list == NULL)
        return;

    Node *newNode = createNode(data);

    if (newNode == NULL)
        return;

    if (list->tail == NULL) {

        list->head = list->tail = newNode;

    } else {

        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->size++;
}

bool insertAt(DoublyLinkedList *list, int value, int index) {

    if (list == NULL || index < 0 || index > list->size)
        return false;

    if (index == 0) {
        pushFront(list, value);
        return true;
    }

    if (index == list->size) {
        pushBack(list, value);
        return true;
    }

    Node *current = getNodeAt(list, index);

    Node *newNode = createNode(value);

    if (newNode == NULL)
        return false;

    newNode->next = current;
    newNode->prev = current->prev;

    current->prev->next = newNode;
    current->prev = newNode;

    list->size++;

    return true;
}

/* ==========================================================
 * Remoção
 * ========================================================== */

bool popFront(DoublyLinkedList *list) {

    if (list == NULL || list->head == NULL)
        return false;

    Node *tmp = list->head;

    list->head = tmp->next;

    if (list->head)
        list->head->prev = NULL;
    else
        list->tail = NULL;

    free(tmp);
    list->size--;

    return true;
}

bool popBack(DoublyLinkedList *list) {

    if (list == NULL || list->tail == NULL)
        return false;

    Node *tmp = list->tail;

    list->tail = tmp->prev;

    if (list->tail)
        list->tail->next = NULL;
    else
        list->head = NULL;

    free(tmp);
    list->size--;

    return true;
}

bool removeAt(DoublyLinkedList *list, int index) {

    if (list == NULL || index < 0 || index >= list->size)
        return false;

    if (index == 0)
        return popFront(list);

    if (index == list->size - 1)
        return popBack(list);

    Node *current = getNodeAt(list, index);

    current->prev->next = current->next;
    current->next->prev = current->prev;

    free(current);

    list->size--;

    return true;
}

bool removeValue(DoublyLinkedList *list, int value) {

    if (list == NULL || list->head == NULL)
        return false;

    Node *current = list->head;

    while (current != NULL) {

        if (current->data == value) {

            if (current == list->head)
                return popFront(list);

            if (current == list->tail)
                return popBack(list);

            current->prev->next = current->next;
            current->next->prev = current->prev;

            free(current);

            list->size--;

            return true;
        }

        current = current->next;
    }

    return false;
}

/* ==========================================================
 * Consulta
 * ========================================================== */

Node *find(DoublyLinkedList *list, int value) {

    if (list == NULL)
        return NULL;

    Node *current = list->head;

    while (current != NULL) {

        if (current->data == value)
            return current;

        current = current->next;
    }

    return NULL;
}

int head(DoublyLinkedList *list) {
    return (list && list->head) ? list->head->data : -1;
}

int tail(DoublyLinkedList *list) {
    return (list && list->tail) ? list->tail->data : -1;
}

bool isEmpty(DoublyLinkedList *list) {
    return list == NULL || list->size == 0;
}

int size(DoublyLinkedList *list) {
    return list ? list->size : 0;
}

/* ==========================================================
 * Manipulação
 * ========================================================== */

void reverseList(DoublyLinkedList *list) {

    if (list == NULL)
        return;

    Node *current = list->head;

    while (current != NULL) {

        Node *tmp = current->next;
        current->next = current->prev;
        current->prev = tmp;
        current = tmp;
    }

    Node *tmp = list->head;
    list->head = list->tail;
    list->tail = tmp;
}

/* ==========================================================
 * Destruição
 * ========================================================== */

void freeList(DoublyLinkedList *list) {

    if (list == NULL)
        return;

    Node *current = list->head;

    while (current != NULL) {

        Node *next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void destroyList(DoublyLinkedList *list) {

    if (list == NULL)
        return;

    freeList(list);
    free(list);
}
