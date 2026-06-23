#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main() {
    LinkedList *list = malloc(sizeof(LinkedList));

    initList(list);

    pushBack(list, 31);

    printList(list);

    return 0;
}