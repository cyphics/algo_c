#include <stdbool.h>

struct library {
  bool (*BinarySearch)(int target, int *sorted_array, int array_length);
  int (*IndexOf)(void *target, void *array, int array_length, int size);
  int (*IndexOfSorted)(int array[], int target, int length);
  void (*BubbleSort)(int array[], int size);
};

typedef struct SLLNode {
  int value;
  struct SLLNode *next;
} SLLNode;

typedef struct SingleLinkedList {
  int length;
  SLLNode *head;
} SingleLinkedList;

void SLLPrint(SingleLinkedList *list);
void InitializeSingleLinkedList(SingleLinkedList *list);
void SLLAppend(SingleLinkedList *list, int value);
void SLLPrepend(SingleLinkedList *list, int value);
int SLLGet(SingleLinkedList *list, int index);
int SLLRemoveAt(SingleLinkedList *list, int index);

extern const struct library Sorting;
