#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct Node {
    struct Node *right;
    struct Node *left;
    int data;
} Node;


typedef struct BinarySearchTree {
    struct Node *root;
} BinarySearchTree;

BinarySearchTree *initBinarySearchTree();

bool insert(BinarySearchTree *tree, int value);

Node *search(const BinarySearchTree *tree, int value);

#endif