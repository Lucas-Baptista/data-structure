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

static void freeNode(Node *node) {
    free(node);
}

static void printNode(Node *node) {

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

SearchNode *search(const BinarySearchTree *tree, int value) {
    if (tree == NULL) {
        return NULL;
    }

    SearchNode *result = malloc(sizeof(SearchNode));

    if (result == NULL) {
        return NULL;
    }

    result->target = tree->root;
    result->parent = NULL;

    while (result->target != NULL) {

        if (result->target->data == value) {
            return result;
        }

        result->parent = result->target;

        if (value < result->target->data) {
            result->target = result->target->left;
        } else {
            result->target = result->target->right;
        }
    }

    free(result);

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
 * Remoção
 * ========================================================== */

bool removeValue(BinarySearchTree *tree, int value) {

    if (tree == NULL) {
        return false;
    }

    SearchNode *result = search(tree, value);

    if (result == NULL) {
        return false;
    }

    Node *target = result->target;
    Node *parent = result->parent;

    /*
     * =====================================================
     * 1º CASO: nó é uma folha
     * =====================================================
     */

    if (target->left == NULL && target->right == NULL) {

        if (parent == NULL) {
            tree->root = NULL;
        }
        else if (parent->left == target) {
            parent->left = NULL;
        }
        else {
            parent->right = NULL;
        }

        freeNode(target);
        free(result);

        return true;
    }

    /*
     * =====================================================
     * 2º CASO: nó possui apenas um filho
     * =====================================================
     */

    if (target->left == NULL || target->right == NULL) {

        Node *child;

        if (target->left != NULL) {
            child = target->left;
        }
        else {
            child = target->right;
        }

        if (parent == NULL) {
            tree->root = child;
        }
        else if (parent->left == target) {
            parent->left = child;
        }
        else {
            parent->right = child;
        }

        freeNode(target);
        free(result);

        return true;
    }

    /*
    * =====================================================
    * 3º CASO: nó possui dois filhos
    * =====================================================
    */

    Node *successorParent = target;
    Node *successor = target->right;

    while (successor->left != NULL) {
        successorParent = successor;
        successor = successor->left;
    }

    target->data = successor->data;

    if (successorParent->left == successor) {
        successorParent->left = successor->right;
    }
    else {
        successorParent->right = successor->right;
    }

    freeNode(successor);
    free(result);

    return true;
}

/* ==========================================================
 * Percursos
 * ========================================================== */

static void inOrder(Node *start, void (*action)(Node *)){
    if (start == NULL) return;

    inOrder(start->left, action);

    action(start);

    inOrder(start->right, action);

}

static void preOrder(Node *start, void (*action)(Node *)) {
    if (start == NULL) return;

    action(start);

    preOrder(start->left, action);

    preOrder(start->right, action);
}

static void postOrder(Node *start, void (*action)(Node *)) {
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

/* ==========================================================
 * Limpeza
 * ========================================================== */

static void clearRecursive(Node *node) {
    if (node == NULL) return;
    
    postOrder(node, freeNode);
}

void clear(BinarySearchTree *tree) {
    if (tree == NULL) return;

    clearRecursive(tree->root);

    tree->root = NULL;
}

void destroyBinarySearchTree(BinarySearchTree *tree) {
    if (tree == NULL) return;

    clearRecursive(tree->root);

    free(tree);
}

/* ==========================================================
 * Impressão da Árvore
 * ========================================================== */

void printTree(const BinarySearchTree *tree) {

    if (tree == NULL || tree->root == NULL) {
        printf("Arvore vazia.\n");
        return;
    }

    Node *queue[1024];

    int front = 0;
    int rear = 0;
    int height = -1;

    queue[rear++] = tree->root;

    /*
     * Descobre a altura da árvore
     */
    while (front < rear) {

        int levelSize = rear - front;

        height++;

        for (int i = 0; i < levelSize; i++) {

            Node *node = queue[front++];

            if (node->left != NULL) {
                queue[rear++] = node->left;
            }

            if (node->right != NULL) {
                queue[rear++] = node->right;
            }
        }
    }

    Node *level[1024];
    Node *nextLevel[1024];

    int levelSize = 1;

    level[0] = tree->root;

    /*
     * Define a largura máxima da impressão.
     */
    int width = (1 << (height + 1)) * 4;

    for (int currentLevel = 0;
        currentLevel <= height;
        currentLevel++) {

        int distance = width / (1 << currentLevel);
        int firstPosition = distance / 2;

        char line[4096];

        for (int i = 0; i < 4096; i++) {
            line[i] = ' ';
        }

        /*
         * Coloca os nós nas posições corretas.
         */
        for (int i = 0; i < levelSize; i++) {

            if (level[i] == NULL) {
                continue;
            }

            int position =
                firstPosition + (i * distance);

            char value[32];

            snprintf(
                value,
                sizeof(value),
                "%d",
                level[i]->data
            );

            int valueLength = 0;

            while (value[valueLength] != '\0') {
                valueLength++;
            }

            int start = position - (valueLength / 2);

            for (int j = 0; j < valueLength; j++) {
                line[start + j] = value[j];
            }
        }

        /*
         * Remove espaços desnecessários do final.
         */
        int last = width;

        while (last > 0 && line[last - 1] == ' ') {
            last--;
        }

        for (int i = 0; i < last; i++) {
            putchar(line[i]);
        }

        putchar('\n');

        /*
         * Monta o próximo nível.
         */
        int nextSize = 0;

        for (int i = 0; i < levelSize; i++) {

            if (level[i] != NULL) {

                nextLevel[nextSize++] =
                    level[i]->left;

                nextLevel[nextSize++] =
                    level[i]->right;

            } else {

                nextLevel[nextSize++] = NULL;
                nextLevel[nextSize++] = NULL;
            }
        }

        levelSize = nextSize;

        for (int i = 0; i < levelSize; i++) {
            level[i] = nextLevel[i];
        }
    }
}
