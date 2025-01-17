#include "algo_lib.h"
#include "helpers.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*bool BinarySearch(int target, int *sorted_list, int list_size) { return false; }*/


int IndexOf(void *target, void *array, int array_length, int size) {

  for (int idx = 0; idx < array_length; idx++) {
    char *position = (char *)array + idx * size;
    
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
    /*.BinarySearch = BinarySearch,*/
    .IndexOf = IndexOf,
    .IndexOfSorted = IndexOfSorted,
    .BubbleSort = BubbleSort,
};

SLLNode* CreateNode(void) {
  SLLNode *node;
  node = malloc(sizeof(SLLNode));
  node->value = 0;
  node->next = NULL;
  /*printf("Allocating new node at address %p.\n", node);*/
  return node;
}

void SLLFree(SLLNode *node) {
  /*printf("Freeing node of value %d at memory %p\n", node->value, node);*/
  free(node);
}

/**
 * @brief Initialize a Single Linked List passed by reference with 0/NULL values;
 *
 * @param list The list to initalize
 */
void SLLInitialize(SingleLinkedList *list) {
  list->length = 0;
  list->head = NULL;
}

void SLLPrintNode(SLLNode *node) {
  printf("Value: %d\n", node->value);
  printf("Address: %p\n", node);
  printf("Next: %p\n", node->next);
}

/**
 * @brief Outputs a graphical representation of the list to the Stdout
 *
 * @param list List to print
 */
void SLLPrint(SingleLinkedList *list) {
  if (list->head == NULL) {
    printf("List is empty.\n");
    return;
  } 
  SLLNode *current = list->head;
  while(current != NULL) {
    printf("%d -> ", current->value);
    current = current->next;
  }
  printf("NULL\n");
}


/**
 * @brief Adds a new node with the <value> parameter at the end of the <list>
 *
 * @param list SingleLinkedList to append to
 * @param value Value to add at the end of the list
 */
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

/**
 * @brief Add a node containing <value> at the end of the list
 *
 * @param list 
 * @param value 
 */
void SLLPrepend(SingleLinkedList *list, int value) {
  SLLNode *new = CreateNode();
  new->value = value;
  new->next = list->head;
  list->head = new;
  list->length++;
}

/**
 * @brief Return the value stored at the <index> location on the <list>
 *
 * @param list 
 * @param index 
 * @return Value stored at <index>
 */
int SLLGetAt(SingleLinkedList *list, int index) {
  if (index >= list->length) {
    printf("WARNING! Out-of-boud access attempt with SLLGet\n");
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

/**
 * @brief Remove the node at the <index> location.
 *
 * @param list 
 * @param index 
 * @return value removed at <index>. In case of out-of-bound, returns 0 (not very satisfying but what can we do...)
 */
int SLLRemoveAt(SingleLinkedList *list, int index) {
  if (index >= list->length) {
    printf("WARNING! Out-of-boud access attempt with SLLRemoveAt\n");
    return 0;
  }
  int result;
  if (index == 0) {
    SLLNode *to_delete = list->head;
    list->head = list->head->next;
    result = to_delete->value;
    SLLFree(to_delete);
  } else {
    SLLNode *current = list->head;
    for (int i = 0; i < index - 1; i++) {
      current = current->next;
    }
    SLLNode *previous = current;
    SLLNode *to_delete = previous->next;
    SLLNode *next = to_delete->next;
    previous->next = next;
    result = to_delete->value;
    SLLFree(to_delete);
  }
  list->length--;
  return result;
}


/**
 * @brief Remove first node found countaining <value>
 *
 * @param list 
 * @param value 
 * @return true if removal successful, false if value not found
 */
bool SLLRemove(SingleLinkedList *list, int value) {
  SLLNode *current = list->head;
  for(int i = 0; i < list->length; i++) {
    if (current->value == value) {
      SLLRemoveAt(list, i);
      return true;
    }
  }
  return false;
}

void SLLClear(SingleLinkedList *list) {
  if (list->head == NULL) {
    return;
  }
  SLLNode *to_delete = list->head;
  while (to_delete->next != NULL) {
    SLLNode *next = to_delete->next;
    free(to_delete);
    list->length--;
    to_delete = next;
  }
  free(to_delete);
  list->length--;
  list->head = NULL;
}

