#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef struct DLLNode {
    int value;
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

