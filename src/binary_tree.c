#include "binary_tree.h"
#include <string.h>

int NumChildren(BinaryNode *node) {
    int left = 0;
    int right = 0;
    if (node->left != NULL) left = 1 + NumChildren(node->left);
    if (node->right != NULL) right = 1 + NumChildren(node->right);
    return left + right;
}

void WalkTreePreorder(BinaryNode *node, LinkedList *storage) {
    if (node == NULL) return;
    WalkTreePreorder(node->left, storage);
    WalkTreePreorder(node->right, storage);
    // LinkedListAppend(storage, node->value);
}

void PreOrderSearch(BinaryNode *head, LinkedList *storage) {
    WalkTreePreorder(head, storage);
}

