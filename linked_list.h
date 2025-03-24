#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stdint.h>

typedef struct DLLNode {
    void* data;
    struct DLLNode *next;
    struct DLLNode *prev;
} DLLNode;

typedef struct DoubleLinkedList {
    int length;
    DLLNode *head;
    DLLNode *tail;
} DoubleLinkedList;

DoubleLinkedList DLLGetEmptyList(void);
void DLLAppend(DoubleLinkedList *list, int value);
void DLLPrepend(DoubleLinkedList *list, int value);
int  DLLGetAt(DoubleLinkedList *list, int index);
int  DLLRemoveFirst(DoubleLinkedList *list);
int  DLLRemoveLast(DoubleLinkedList *list);
int  DLLRemoveAt(DoubleLinkedList *list, int index);
int  DLLRemoveFirst(DoubleLinkedList *list);
int  DLLRemoveLast(DoubleLinkedList *list);
void DLLClear(DoubleLinkedList *list);

#endif
