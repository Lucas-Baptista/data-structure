#include <stdio.h>
#include <stdlib.h>

#include "doubly_linked_list.h"

DoublyLinkedList *initList () {
    DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));

    if (list == NULL) {
        printf("NÃO FOI POSSIVEL CRIAR UMA NOVA LISTA\n\n");
        return false;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

void reverseList(DoublyLinkedList *list) {
    Node *current = list->head;

    while (current != NULL) {
        Node *temp = current->next;
        current->next = current->prev;
        current->prev = temp;

        current = temp;
    }

    Node *temp = list->head;
    list->head = list->tail;
    list->tail = temp;
}

void printList(DoublyLinkedList *list) {
    printf("---------------------------------------\n");

    if (list == NULL || list->head == NULL) {
        printf("Head -> NULL <- Tail\n");
        printf("List size: %d\n", list ? list->size : 0);
        printf("---------------------------------------\n\n");
        return;
    }

    Node *current = list->head;

    printf("Head -> ");

    while (current != NULL) {
        printf("[%d]", current->data);

        if (current->next != NULL)
            printf(" ⇄ ");

        current = current->next;
    }

    printf(" <- Tail\n");

    printf("List size: %d\n", list->size);
    printf("---------------------------------------\n\n");
}

void printNode (Node *node) {

    printf("Node........: %p\n", (void *)node);

    if (node == NULL) {
        printf("NULL\n\n");
        return;
    }

    printf("data........: %d\n", node->data);
    printf("next........: %p\n", (void *)node->next);
    printf("prev........: %p\n", (void *)node->prev);
    printf("&data.......: %p\n", (void *)&node->data);
    printf("&next.......: %p\n\n", (void *)&node->next);

    printf("---------------------------------------\n\n");
}

void pushFront (DoublyLinkedList *list, int data) {
    printf("INSERINDO O VALOR %d NO INICIO DA LISTA....\n\n", data);

    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("NÃO FOI POSSIVEL CRIAR UM NOVO NO\n\n");
        return;
    }

    newNode->data = data;
    newNode->prev = NULL;

    list->size++;

    if (list->head == NULL) {
        newNode->next = NULL;
        list->head = list->tail = newNode;
        return;
    }

    newNode->next = list->head;
    
    list->head->prev = newNode;
    
    list->head = newNode;
}

void pushBack(DoublyLinkedList *list, int data) {
    printf("INSERINDO O VALOR %d NO FINAL DA LISTA....\n\n", data);

    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("NÃO FOI POSSIVEL CRIAR UM NOVO NO\n\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    list->size++;

    if (list->head == NULL) {
        newNode->prev = NULL;
        list->head = list->tail = newNode;
        return;
    }

    newNode->prev = list->tail;
    
    list->tail->next = newNode;
    
    list->tail = newNode;
}

int head(DoublyLinkedList *list) {
    Node *head = list->head;

    printf("INICIO DA LISTA---------------------\n\n");
    
    printNode(head);
    
    return head->data;
}

int tail(DoublyLinkedList *list) {
    Node *tail = list->tail;

    printf("FINAL DA LISTA---------------------\n\n");
    
    printNode(tail);
    
    return tail->data;
}

bool isEmpty(DoublyLinkedList *list) {
    bool empty = list->size == 0;

    empty ? printf("A LISTA ESTA VAZIA\n\n") : printf("A LISTA NAO ESTA VAZIA\n\n");
    
    return empty;
}

int size(DoublyLinkedList *list) {
    printf("TAMANHO DA LISTA: %d\n\n", list->size);
    return list->size;
}

Node *find(DoublyLinkedList *list, int value) {
    Node *current = list->head;

    while (current != NULL) {
        if (current->data == value) {
            printf("ELEMENTO %d ENCONTRADO\n\n", value);
            return current;
        }

        current = current->next;
    }

    printf("ELEMENTO %d NAO ENCONTRADO\n\n", value);
    return NULL;
    
}

bool insertAt(DoublyLinkedList *list, int value, int index) {

    if (index < 0 || index > list->size) {
        printf("NÃO FOI POSSIVEL INSERIR NA POSICAO DESEJADA\n\n");
        return false;
    }

    if (index == 0) {
        pushFront(list, value);
        return true;
    }

    if (index == list->size) {
        pushBack(list, value);
        return true;
    }

    Node *current = list->head;

    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("NÃO FOI POSSIVEL CRIAR UM NOVO NO\n\n");
        return false;
    }

    newNode->data = value;
    newNode->next = current->next;
    newNode->prev = current;

    current->next->prev = newNode;
    current->next = newNode;

    list->size++;

    printf("ELEMENTO INSERIDO NA POSICAO DESEJADA\n\n");

    return true;
}

int popFront(DoublyLinkedList *list) {

    if (list == NULL || list->head == NULL)
        return -1;

    Node *tmp = list->head;
    int data = tmp->data;

    list->head = tmp->next;

    if (list->head != NULL)
        list->head->prev = NULL;
    else
        list->tail = NULL;

    free(tmp);

    list->size--;

    return data;
}

int popBack(DoublyLinkedList *list) {

    if (list == NULL || list->tail == NULL)
        return -1;

    Node *tmp = list->tail;
    int data = tmp->data;

    list->tail = tmp->prev;

    if (list->tail != NULL)
        list->tail->next = NULL;
    else
        list->head = NULL;

    free(tmp);

    list->size--;

    return data;
}

bool removeValue(DoublyLinkedList *list, int value) {

    if (list == NULL || list->head == NULL){
        return false;
    }

    if (list->head->data == value) {
        popFront(list);
        return true;
    }

    if (list->tail->data == value) {
        popBack(list);
        return true;
    }

    Node *current = list->head->next;

    while (current != list->tail) {

        if (current->data == value) {

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
