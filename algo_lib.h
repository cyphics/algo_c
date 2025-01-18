#include <stdbool.h>

    /*bool (*BinarySearch)(int target, int *sorted_array, int array_length);*/
int  IndexOf(void *target, void *array, int array_length, int size);
int  IndexOfSorted(int array[], int target, int length);
void BubbleSort(int array[], int size);


/************************************
* SINGLE LINKED LIST
*************************************/

typedef struct SLLNode {
    int value;
    struct SLLNode *next;
} SLLNode;

typedef struct SingleLinkedList {
    int length;
    SLLNode *head;
} SingleLinkedList;

void SLLPrint(SingleLinkedList *list);
SingleLinkedList SLLGetEmptyList(void);
void SLLAppend(SingleLinkedList *list, int value);
void SLLPrepend(SingleLinkedList *list, int value);
int  SLLGetAt(SingleLinkedList *list, int index);
int  SLLRemoveAt(SingleLinkedList *list, int index);
void SLLClear(SingleLinkedList *list);


/************************************
* DOUBLE LINKED LIST
*************************************/

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


extern const struct library Sorting;
