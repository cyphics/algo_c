#ifndef __HEAP_H__
#define __HEAP_H__

#include "binary_tree.h"
typedef struct Heap {
    BinaryNode *head;
    int length;

} Heap;

Heap GetHeap(void);
void MinHeapInsert(Heap *heap, int value);
int  MinHeapDelete(Heap *heap);
void PrintHeap(Heap *heap);
void PrintNode(BinaryNode *node);
BinaryNode *MergeNodes(BinaryNode *n1, BinaryNode *n2);

#endif
