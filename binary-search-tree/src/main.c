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
    
    return 0;
}

