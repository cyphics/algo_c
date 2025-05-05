#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "ringBuffer.h"

typedef struct BinaryNode {
    int value;
    struct BinaryNode *left;
    struct BinaryNode *right;
} BinaryNode;

BinaryNode *GetNode(int value);
BinaryNode *CreateHead(int value, BinaryNode *right, BinaryNode *left);



int NumChildren(BinaryNode *node);
void WalkTreePreorder(BinaryNode *node, RingBuffer *storage);

#endif
