#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "linked_list.h"

// TODO remove
#define LinkedList DLList

typedef struct BinaryNode {
    int value;
    struct BinaryNode *left;
    struct BinaryNode *right;
} BinaryNode;

int NumChildren(BinaryNode *node);
void PreOrderSearch(BinaryNode *head, DLList *storage);

#endif
