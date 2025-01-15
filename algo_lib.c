#include "algo_lib.h"
#include "helpers.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool BinarySearch(int target, int *sorted_list, int list_size) { return false; }


int IndexOf(void *target, void *array, int array_length, int size) {
  for (int idx = 0; idx < array_length; idx++) {
    void *position = array + idx * size;
    int result = memcmp(target, position, size);
    if (!result) {
      return idx;
    }
  }
  return -1;
}

int IndexOfSorted(int array[], int target, int length) {
  int low = 0;
  int high = length;

  while (low < high) {
    int m = low + (high - low) / 2;
    if (array[m] == target) {
      return m;
    } else if (target < array[m]) {
      high = m;
    } else {
      low = m + 1;
    }
  }
  return -1;
}

void BubbleSort(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
}

const struct library Sorting = {
    .BinarySearch = BinarySearch,
    .IndexOf = IndexOf,
    .IndexOfSorted = IndexOfSorted,
    .BubbleSort = BubbleSort,
};

SLLNode* CreateNode() {
  SLLNode *node;
  node = malloc(sizeof(SLLNode));
  node->value = 0;
  node->next = NULL;
  return node;
}

void InitializeSingleLinkedList(SingleLinkedList *list) {
  list->length = 0;
  list->head = NULL;
}

void SLLAppend(SingleLinkedList *list, int value) {
  SLLNode *new = CreateNode();
  new->value = value;

  SLLNode *current = list->head;
  if (list->head == NULL) {
    list->head = new;
  } else {
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new;
  }
  list->length++;
}

void SLLPrint(SingleLinkedList *list) {
  SLLNode *current = list->head;
  while (current != NULL) {
    printf("%d -> ", current->value);
    current = current->next;
  }
  printf("\n");
}

int SLLGet(SingleLinkedList *list, int index) {
  if (index >= list->length) {
    return 0;
  }
  SLLNode *current = list->head;
  for (int i = 0; i < index; i++) {
    if (current->next != NULL) {
      current = current->next;
    }
  }
  return current->value;
}
int SLLRemoveAt(SingleLinkedList *list, int index) {
  if (index >= list->length) {
    return 0;
  }
  int value;
  if (index == 0) {
    SLLNode *to_delete = list->head;
    list->head = list->head->next;
    value = to_delete->value;
    free(to_delete);
  } else {
    SLLNode *current = list->head;
    for (int i = 0; i < index - 1; i++) {
      current = current->next;
    }
    SLLNode *previous = current;
    SLLNode *to_delete = previous->next;
    SLLNode *next = to_delete->next;
    previous->next = next;
    value = to_delete->value;
    free(to_delete);
  }
  list->length--;
  return value;
}

void SLLPrepend(SingleLinkedList *list, int value) {
  SLLNode *new = CreateNode();
  new->value = value;
  new->next = list->head;
  list->head = new;
  list->length++;
}
