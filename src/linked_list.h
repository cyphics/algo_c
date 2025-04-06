#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stdint.h>

// TODO make this private
typedef struct Node {
    void* data;
    int size;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct DoubleLinkedList {
    int length;
    Node *head;
    Node *tail;
} DLList;

DLList get_empty_dllist(void);
void   dllist_append(DLList *list, void* data, int size);
void   dllist_prepend(DLList *list, void* data, int size);
void*  dllist_get_at(DLList *list, int index);
void*  dllist_pop_first(DLList *list);
void*  dllist_pop_last(DLList *list);
void*  dllist_pop_at(DLList *list, int index);
void   dllist_clear(DLList *list);

#endif
