#include <stdio.h>
#include <stdlib.h>

#include "binary_search_tree.h"

/* ==========================================================
 * Helpers privados
 * ========================================================== */

static Node *createNode(int value) {
    Node *newNode = malloc(sizeof(Node));

    if (!newNode) {
        return NULL;
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

static void printNode(const Node *node) {

    if (node == NULL) {
        printf("NULL\n");
        return;
    }

    printf("Address : %p\n", (void *)node);
    printf("Data    : %d\n", node->data);
    printf("Left    : %p\n", (void *)node->left);
    printf("Right    : %p\n", (void *)node->right);
    printf("\n\n");
}

/* ==========================================================
 * Inicialização
 * ========================================================== */

BinarySearchTree *initBinarySearchTree() {
    BinarySearchTree *tree = malloc(sizeof(BinarySearchTree));

    if (!tree) {
        return NULL;
    }

    tree->root = NULL;

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

static Node *findMinNode(Node *node) {
    if (node == NULL) return NULL;

    while (node->left != NULL) {
        node = node->left;
    }

    return node;
}

Node *findMin(const BinarySearchTree *tree) {
    if (tree == NULL) return NULL;

    return findMinNode(tree->root);
}

static Node *findMaxNode(Node *node) {
    if (node == NULL) return NULL;

    while (node->right != NULL) {
        node = node->right;
    }

    return node;
}

Node *findMax(const BinarySearchTree *tree) {
    if (tree == NULL) return NULL;

    return findMaxNode(tree->root);
}

/* ==========================================================
 * Percursos
 * ========================================================== */

static void inOrder(const Node *start, void (*action)(const Node *)){
    if (start == NULL) return;

    inOrder(start->left, action);

    action(start);

    inOrder(start->right, action);

}

static void preOrder(const Node *start, void (*action)(const Node *)) {
    if (start == NULL) return;

    action(start);

    preOrder(start->left, action);

    preOrder(start->right, action);
}

static void postOrder(const Node *start, void (*action)(const Node *)) {
    if (start == NULL) return;

    postOrder(start->left, action);

    postOrder(start->right, action);

    action(start);
}


void printInOrder(const BinarySearchTree *tree) {
    if (tree == NULL) return;

    inOrder(tree->root, printNode);
}

void printPreOrder(const BinarySearchTree *tree) {
    if (tree == NULL) return;

    preOrder(tree->root, printNode);
}

void printPostOrder(const BinarySearchTree *tree) {
    if (tree == NULL) return;

    postOrder(tree->root, printNode);
}

/* ==========================================================
 * Altura
 * ========================================================== */

static int heightNode(const Node *node) {
    if (node == NULL)
        return -1;

    int leftHeight = heightNode(node->left);
    int rightHeight = heightNode(node->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;

    return rightHeight + 1;
}

int height(const BinarySearchTree *tree) {
    if (tree == NULL)
        return -1;

    return heightNode(tree->root);
}

/* ==========================================================
 * Numero de Nós
 * ========================================================== */

static int countNodesRecursive(const Node *node) {
    if (node == NULL) return 0;

    int leftNodes = countNodesRecursive(node->left);
    int rightNodes = countNodesRecursive(node->right);

    return leftNodes + rightNodes + 1;
}

int countNodes(const BinarySearchTree *tree) {
    if (tree == NULL || tree->root == NULL) return 0;

    return countNodesRecursive(tree->root);
}

/* ==========================================================
 * Numero de Folhas
 * ========================================================== */

static int countLeavesRecursive(const Node *node) {
    if (node == NULL) return 0;

    if (node->left == NULL && node->right == NULL) return 1;

    int leftLeaves = countLeavesRecursive(node->left);
    int rightLeaves = countLeavesRecursive(node->right);

    return leftLeaves + rightLeaves;
}

int countLeaves(const BinarySearchTree *tree) {
    if (tree == NULL) return 0;

    return countLeavesRecursive(tree->root);
}