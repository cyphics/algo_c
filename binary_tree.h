#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "linked_list_int.h"

typedef struct BinaryNode {
    int value;
    struct BinaryNode *left;
    struct BinaryNode *right;
} BinaryNode;

int NumChildren(BinaryNode *node);
void PreOrderSearch(BinaryNode *head, DoubleLinkedListInt *storage);

#endif
