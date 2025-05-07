#include "binary_tree.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "ringBuffer.h"
#include "queue.h"

// TODO remove

int NumChildren(BinaryNode *node) {
    int left = 0;
    int right = 0;
    if (node->left != NULL) left = 1 + NumChildren(node->left);
    if (node->right != NULL) right = 1 + NumChildren(node->right);
    return left + right;
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

BinaryNode *GetNode(int value, BinaryNode *right, BinaryNode *left) {
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

bool BreadthFirstSearch(BinaryNode *node, int value, Queue *queue) {
    if (node == NULL) return false;
    if (node->value == value) return true;
    if (node->left != NULL) {
        EnQueue(queue, node->left);
    }
    if (node->right != NULL) {
        EnQueue(queue, node->right);
    }
    return BreadthFirstSearch(DeQueue(queue), value, queue);
}

