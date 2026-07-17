#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

int main() {
    DoublyLinkedList *list = initList();

    pushFront(list, 30);
    pushFront(list, 40);
    pushFront(list, 50);
    pushFront(list, 60);

    pushBack(list, 20);
    pushBack(list, 10);

    printList(list);

    reverseList(list);

    printList(list);

    reverseList(list);

    head(list);

    tail(list);

    isEmpty(list);

    size(list);

    find(list, 55);

    insertAt(list, 23, 2);

    printList(list);

    popFront(list);

    printList(list);

    popBack(list);

    printList(list);

    return 0;
}