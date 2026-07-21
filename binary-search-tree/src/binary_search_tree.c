#include <stdio.h>
#include <stdlib.h>

#include "binary_search_tree.h"

/* ==========================================================
 * Inicialização
 * ========================================================== */

BinarySearchTree *initBinarySearchTree() {
    BinarySearchTree *tree = malloc(sizeof(BinarySearchTree));

    if (!tree) {
        return NULL;
    }

    return tree;
}