#include "binary_tree.h"
#include <string.h>

// TODO remove
#define LinkedList DLList

int NumChildren(BinaryNode *node) {
    int left = 0;
    int right = 0;
    if (node->left != NULL) left = 1 + NumChildren(node->left);
    if (node->right != NULL) right = 1 + NumChildren(node->right);
    return left + right;
}

void WalkTreePreorder(BinaryNode *node, DLList *storage) {
    if (node == NULL) return;
    WalkTreePreorder(node->left, storage);
    WalkTreePreorder(node->right, storage);
    // LinkedListAppend(storage, node->value);
}

void PreOrderSearch(BinaryNode *head, DLList *storage) {
    WalkTreePreorder(head, storage);
}

