#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ringBuffer.h"

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
    if (node->right != NULL) {
        WalkNodePreorder(node->right, buffer);
    }
    if (node->left != NULL) {
        WalkNodePreorder(node->left, buffer);
    }
}

void WalkTreePreorder(BinaryNode *node, RingBuffer *buffer) {
    // if (node == NULL) return;
    WalkNodePreorder(node, buffer);
}


BinaryNode *GetNode(int value) {
    BinaryNode *node = malloc(sizeof(BinaryNode));
    node->right = NULL;
    node->left = NULL;
    node->value = value;
    return node;
}

BinaryNode *CreateHead(int value, BinaryNode *right, BinaryNode *left) {
    BinaryNode *head = GetNode(value);
    head->right = right;
    head->left = left;
    return head;
}
