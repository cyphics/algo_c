#include <stdbool.h>

    /*bool (*BinarySearch)(int target, int *sorted_array, int array_length);*/
int  IndexOf(void *target, void *array, int array_length, int size);
int  IndexOfSorted(int array[], int target, int length);
void BubbleSort(int array[], int size);

typedef struct SLLNode {
    int value;
    struct SLLNode *next;
} SLLNode;

typedef struct SingleLinkedList {
    int length;
    SLLNode *head;
} SingleLinkedList;

void SLLPrint(SingleLinkedList *list);
void SLLInitialize(SingleLinkedList *list);
void SLLAppend(SingleLinkedList *list, int value);
void SLLPrepend(SingleLinkedList *list, int value);
int  SLLGetAt(SingleLinkedList *list, int index);
int  SLLRemoveAt(SingleLinkedList *list, int index);
bool SLLRemove(SingleLinkedList *list, int value);
void SLLClear(SingleLinkedList *list);
int  SLLGetLast(SingleLinkedList *list);
int  SLLPeek(SingleLinkedList *list);

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

void DLLPrint(DoubleLinkedList *list);
void DLLInitialize(DoubleLinkedList *list);
void DLLAppend(DoubleLinkedList *list, int value);
void DLLPrepend(DoubleLinkedList *list, int value);
int  DLLGetAt(DoubleLinkedList *list, int index);
int  DLLRemoveAt(DoubleLinkedList *list, int index);
bool DLLRemove(DoubleLinkedList *list, int value);
void DLLClear(DoubleLinkedList *list);
int  DLLGetLast(DoubleLinkedList *list);


extern const struct library Sorting;
