#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

int main() {
    
    DoublyLinkedList *list = initList();

    pushFront(list, 30);
    pushFront(list, 40);
    pushFront(list, 50);
    pushFront(list, 60);

    printList(list);

    return 0;
}