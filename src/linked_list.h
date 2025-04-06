#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stdint.h>

typedef struct Node {
    void* data;
    int size;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct LinkedList {
    int length;
    Node *head;
    Node *tail;
} LinkedList;

LinkedList LinkedListGetEmptyList(void);
void   LinkedListAppend(LinkedList *list, void* data, int size);
void   LinkedListPrepend(LinkedList *list, void* data, int size);
void*  LinkedListGetAt(LinkedList *list, int index);
void*  LinkedListPopFirst(LinkedList *list);
void*  LinkedListPopLast(LinkedList *list);
void*  LinkedListPopAt(LinkedList *list, int index);
void   LinkedListClear(LinkedList *list);

#endif
