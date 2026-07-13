#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./queue.h"


int main() {
    Queue *queue = initQueue();

    size(queue);

    isEmpty(queue);

    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    
    printQueue(queue);

    printNode(front(queue), "F");
    printNode(rear(queue), "R");

    size(queue);

    isEmpty(queue);

    dequeue(queue);

    printQueue(queue);

    printNode(front(queue), "F");
    printNode(rear(queue), "R");

    size(queue);

    isEmpty(queue);

    freeQueue(queue);

    size(queue);

    isEmpty(queue);

    return 0;
}
