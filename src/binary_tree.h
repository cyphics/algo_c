#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h>
#include "ringBuffer.h"
#include "queue.h"

typedef struct BinaryNode {
    int value;
    struct BinaryNode *left;
    struct BinaryNode *right;
} BinaryNode;

BinaryNode *GetNode(int value, BinaryNode *right, BinaryNode *left);
int NumChildren(BinaryNode *node);
void WalkTreePreorder(BinaryNode *node, RingBuffer *storage);
void BFSTraversal(BinaryNode *node, int value, Queue *queue);

#endif
