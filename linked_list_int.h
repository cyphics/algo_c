#ifndef LINKED_LIST_INT_H
#define LINKED_LIST_INT_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef struct DLLIntNode {
    int value;
    struct DLLIntNode *next;
    struct DLLIntNode *prev;
} DLLIntNode;

typedef struct DoubleLinkedListInt {
    int length;
    DLLIntNode *head;
    DLLIntNode *tail;
} DoubleLinkedListInt;

DoubleLinkedListInt DLLIntGetEmptyList(void);
void DLLIntAppend(DoubleLinkedListInt *list, int value);
void DLLIntPrepend(DoubleLinkedListInt *list, int value);
int  DLLIntGetAt(DoubleLinkedListInt *list, int index);
int  DLLIntRemoveFirst(DoubleLinkedListInt *list);
int  DLLIntRemoveLast(DoubleLinkedListInt *list);
int  DLLIntRemoveAt(DoubleLinkedListInt *list, int index);
int  DLLIntRemoveFirst(DoubleLinkedListInt *list);
int  DLLIntRemoveLast(DoubleLinkedListInt *list);
void DLLIntClear(DoubleLinkedListInt *list);

#endif
