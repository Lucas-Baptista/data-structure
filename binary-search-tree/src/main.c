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

    printf(search(tree, 60) ? "FOUND\n\n" : "NOT FOUND\n");

    printf(search(tree, 100) ? "FOUND\n" : "NOT FOUND\n");

    printInOrder(tree);

    printPreOrder(tree);
    
    printPostOrder(tree);
    
    return 0;
}

