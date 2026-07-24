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

/* ==========================================================
 * Percursos
 * ========================================================== */

static void inOrder(Node *start) {
    if (start == NULL) return;

    inOrder(start->left);

    printf("%d ", start->data);

    inOrder(start->right);

}

static void preOrder(Node *start) {
    if (start == NULL) return;

    printf("%d ", start->data);

    preOrder(start->left);

    preOrder(start->right);
}

static void postOrder(Node *start) {
    if (start == NULL) return;

    postOrder(start->left);

    postOrder(start->right);

    printf("%d ", start->data);
}


void printInOrder(const BinarySearchTree *tree) {
    if (tree == NULL) return;

    printf("\n");

    inOrder(tree->root);

    printf("\n\n");
}

void printPreOrder(const BinarySearchTree *tree) {
    if (tree == NULL) return;

    printf("\n");

    preOrder(tree->root);

    printf("\n\n");
}

void printPostOrder(const BinarySearchTree *tree) {
    if (tree == NULL) return;

    printf("\n");

    postOrder(tree->root);

    printf("\n\n");
}

