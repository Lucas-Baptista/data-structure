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
    Node *current = list->head;
    
    printf(" Head\n  ↓ \n");

    if (current == NULL) {
        printf(" NULL \n");
        printf("  ↑ \n Tail \n\n");
        printf("List size: %d\n\n", list->size);
        printf("---------------------------------------\n\n");
        return;
    }
     
    printf("+----+\n");
    printf("  %d  \n", current->data);
    printf("+----+\n");

    current = current->next;
    
    while (current != NULL){
        printf("  ↑↓ \n");
        printf("+----+\n");
        printf("  %d  \n", current->data);
        printf("+----+\n");

        current = current->next;
    }

    printf("  ↑ \n Tail \n\n");
    printf("list size: %d\n\n", list->size);
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

    printf("ELEMENTO INSERIDO NA POSICAO DESEJADA\n\n");

    return true;
}