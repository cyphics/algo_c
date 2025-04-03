#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stdint.h>

struct LLNode {
    void* data;
    int size;
    struct LLNode *next;
    struct LLNode *prev;
};

typedef struct LinkedList {
    int length;
    struct LLNode *head;
    struct LLNode *tail;
} LinkedList;

LinkedList LinkedListGetEmptyList(void);
void   LinkedListAppend(LinkedList *list, void* data, int size);
void   LinkedListPrepend(LinkedList *list, void* data, int size);
void*  LinkedListGetAt(LinkedList *list, int index);
void*  LinkedListRemoveFirst(LinkedList *list);
void*  LinkedListRemoveLast(LinkedList *list);
void*  LinkedListRemoveAt(LinkedList *list, int index);
void   LinkedListClear(LinkedList *list);

#endif
