#include <stdio.h>
#include <stdlib.h>

#include "binary_search_tree.h"

/* ==========================================================
 * Helpers privados
 * ========================================================== */

Node *createNode(int value) {
    Node *newNode = malloc(sizeof(Node));

    if (!newNode) {
        return NULL;
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

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

/* ==========================================================
 * Inserção
 * ========================================================== */

bool insert(BinarySearchTree *tree, int value) {
    if (tree == NULL) {
        return false;
    }

    Node *newNode = createNode(value);
                
    if (!newNode) return false;

    if (tree->root == NULL) {
        tree->root = newNode;
        
        return true;
    }

    Node *current = tree->root;

    Node *parent = NULL;

    while (current != NULL) {

        if (current->data == value) {
            free(newNode);

            return false;
        }

        parent = current;

        if (value < current->data) {

            current = current->left;
        
        } else if (value > current->data) {
        
            current = current->right;
        }
    }

    if (value < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return true;
}

/* ==========================================================
 * Busca
 * ========================================================== */

Node *search(const BinarySearchTree *tree, int value) {
    if (tree == NULL) {
        return NULL;
    }

    Node *current = tree->root;

    while (current != NULL) {

        if (current->data == value) return current;

        if (value < current->data) {

            current = current->left;
        
        } else if (value > current->data) {
        
            current = current->right;
        }
    }

    return NULL;
}

