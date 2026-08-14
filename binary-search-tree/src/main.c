#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "binary_search_tree.h"

int main() {
    BinarySearchTree *tree = initBinarySearchTree();

    if(tree == NULL){
        printf("Failed to create tree.\n");
        return -1;
    }

    insert(tree, 50);
    insert(tree, 30);
    insert(tree, 70);
    insert(tree, 20);
    insert(tree, 40);
    insert(tree, 60);
    insert(tree, 80);
    insert(tree, 10);

    printf(search(tree, 60) ? "FOUND\n\n" : "NOT FOUND\n");

    printf(search(tree, 100) ? "FOUND\n" : "NOT FOUND\n");

    printInOrder(tree);

    printPreOrder(tree);
    
    printPostOrder(tree);

    Node *min = findMin(tree);
    min ? printf("Mínimo: %d\n\n", min->data) : printf("Arvore vazia\n\n");

    Node *max = findMax(tree);
    max ? printf("Máximo: %d\n\n", max->data) : printf("Arvore vazia\n\n");

    printf("%d\n\n", height(tree));

    printf("%d\n\n", countNodes(tree));

    printf("%d\n", countLeaves(tree));

    clear(tree);
    
    return 0;
}

