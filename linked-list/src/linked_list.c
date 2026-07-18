
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

/* ==========================================================
 * Helpers privados
 * ========================================================== */
static Node *createNode(int value) {
    Node *newNode = malloc(sizeof(Node));

    if (!newNode) {
        return NULL;
    }
    
    newNode->data = value;
    newNode->next = NULL;
    
    return newNode;
}

static Node *getNodeAt(LinkedList *list, int index) {
    Node *current = list->head;
    
    for(int i = 0; current && i < index; i++)
        current=current->next;
    
    return current;
}

/* ==========================================================
 * Inicialização
 * ========================================================== */

LinkedList *initList(void) {
    LinkedList *list = malloc(sizeof(LinkedList));
   
    if (!list) {
        return NULL;
    }
    
    list->head = NULL;

    return list;
}

/* ==========================================================
 * Impressão
 * ========================================================== */

 void printList(LinkedList *list) {
    printf("Head -> ");
    
    Node *current = list->head;

    while (current != NULL) {
        printf("[%d] -> ", current->data);

        current = current->next;
    }
    
    printf("NULL\n\nList size: %d\n", size(list));
}

void printNode(Node *node) {
    if (!node) { 
        printf("Node: NULL\n"); 

        return; 
    }
    
    printf("=============== NODE ===============\n");
    printf("Address : %p\n",(void*)node);
    printf("Data    : %d\n",node->data);
    printf("Next    : %p\n",(void*)node->next);
    printf("====================================\n");
}

/* ==========================================================
 * Inserção
 * ========================================================== */

 void pushFront(LinkedList *list, int value){
    Node *newNode = createNode(value);
    
    if (!newNode) return;
    
    newNode->next = list->head;
    list->head = newNode;
}

void pushBack(LinkedList *list, int value){
    Node *newNode = createNode(value);
    
    if (!newNode) {
        return;
    }
    
    if (isEmpty(list)) { 
        list->head = newNode; 
        
        return; 
    }
    
    Node *current = list->head;
    
    while(current->next) {
        current = current->next;
    }
    
    current->next = newNode;
}

bool insertAt(LinkedList *list, int index, int value){
    if (index < 0) {
        return false;
    }

    if (index == 0) {
        pushFront(list, value);
        
        return true;
    }
    
    Node *prev = getNodeAt(list, index - 1);

    if (!prev) {
        return false;
    }
    
    Node *newNode = createNode(value);
    
    if (!newNode) {
        return false;
    }
    
    newNode->next = prev->next;
    
    prev->next = newNode;
    
    return true;
}

/* ==========================================================
 * Remoção
 * ========================================================== */

bool removeValue(LinkedList *list,int value){
    if (isEmpty(list)) {
        return false;
    }

    if (list->head->data == value) {
        Node *tempNode = list->head;

        list->head = tempNode->next;

        free(tempNode);

        return true;
    }

    Node *current = list->head;

    while (current->next) {
        
        if(current->next->data == value) {
            
            Node *tempNode=current->next;

            current->next = tempNode->next;
            
            free(tempNode);
            
            return true;
        }

        current=current->next;
    }

    return false;
}

/* ==========================================================
 * Consulta
 * ========================================================== */

bool isEmpty(LinkedList *list){
    return !list || list->head == NULL;
}

int size(LinkedList *list) {
    Node *current = list->head;

    int count = 0;

    while (current != NULL) {
        count++;

        current = current->next;
    }
    
    return count;
}


Node *find(LinkedList *list, int value) {
    Node *current = list->head;
    
    while (current != NULL) {

        if(current->data == value) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

/* ==========================================================
 * Destruição
 * ========================================================== */

void freeList(LinkedList *list) {
    Node *current = list->head;

    while (current != NULL) {
        Node *temp = current->next;
        
        free(current);
        
        current = temp;
    }

    list->head = NULL;
}

void destroyList(LinkedList *list) {
    if (!list) {
        return;
    }

    freeList(list);
    
    free(list);
}

