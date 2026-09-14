#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct Node {
    struct Node *right;
    struct Node *left;
    int data;
} Node;

typedef struct SearchNode {
    struct Node *target;
    struct Node *parent;
} SearchNode;

typedef struct BinarySearchTree {
    struct Node *root;
} BinarySearchTree;

BinarySearchTree *initBinarySearchTree();

bool insert(BinarySearchTree *tree, int value);

SearchNode *search(const BinarySearchTree *tree, int value);

Node *findMin(const BinarySearchTree *tree);

Node *findMax(const BinarySearchTree *tree);

bool removeValue(BinarySearchTree *tree, int value);

void printInOrder(const BinarySearchTree *tree);

void printPreOrder(const BinarySearchTree *tree);

void printPostOrder(const BinarySearchTree *tree);

int height(const BinarySearchTree *tree);

int countNodes(const BinarySearchTree *tree);

int countLeaves(const BinarySearchTree *tree);

void clear(BinarySearchTree *tree);

void destroyBinarySearchTree(BinarySearchTree *tree);

void printTree(const BinarySearchTree *tree);

#endif