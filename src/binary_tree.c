#include "binary_tree.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "ringBuffer.h"
#include "queue.h"


int NumChildren(BinaryNode *node) {
    if (node == NULL) return 0;
    int left = NumChildren(node->left);
    int right = NumChildren(node->right);
    return 1 + left + right;
}

void WalkNodePreorder(BinaryNode *node, RingBuffer *buffer ) {
    AddToEnd(buffer, node->value);
    if (node->left != NULL) {
        WalkNodePreorder(node->left, buffer);
    }
    if (node->right != NULL) {
        WalkNodePreorder(node->right, buffer);
    }
}

void WalkTreePreorder(BinaryNode *node, RingBuffer *buffer) {
    WalkNodePreorder(node, buffer);
}

BinaryNode *GetNode(int value, BinaryNode *left, BinaryNode *right) {
    BinaryNode *node = malloc(sizeof(BinaryNode));
    node->right = right;
    node->left = left;
    node->value = value;
    return node;
}

// Breadth-Frist Search traversal
void BFSTraversal(BinaryNode *node, int value, Queue *queue) {
    if (node == NULL) return;
    printf("%i ", node->value);
    if (node->left != NULL) {
        EnQueue(queue, node->left);
    }
    if (node->right != NULL) {
        EnQueue(queue, node->right);
    }
    BFSTraversal(DeQueue(queue), value, queue);
}

bool BreadthFirstSearch(BinaryNode *node, int value) {
    Queue q = GetQueue();
    EnQueue(&q, node);
    while (PeekQueue(&q) != NULL) {
        BinaryNode *node = DeQueue(&q);
        if (node->value == value) return true;

        if (node->left != NULL) {
            EnQueue(&q, node->left);
        }
        if (node->right != NULL) {
            EnQueue(&q, node->right);
        }
    }
    return false;
}

bool CompareTrees(BinaryNode *n1, BinaryNode *n2) {
    // Structural test
    if (n1 == NULL || n2 == NULL) {
        return n1 == NULL && n2 == NULL;
    }

    // Value (semantic) test
    if (n1->value != n2->value) {
        return false;
    }

    return CompareTrees(n1->left, n2->left) && CompareTrees(n1->right, n2->right);
}
