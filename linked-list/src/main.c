#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main() {
    LinkedList *list = malloc(sizeof(LinkedList));

    initList(list);

    pushFront(list, 21); // 5
    pushFront(list, 65); // 4
    pushFront(list, 21);  // 3
    pushFront(list, 241); // 2
    pushFront(list, 120); // 1
    pushFront(list, 96); // 0
    
    pushBack(list, 31); // 6
    pushBack(list, 50); // 7
    pushBack(list, 325); // 8

    insertAt(list, 6, 400);

    printList(list);

    removeValue(list, 31);

    printList(list);

    return 0;
}