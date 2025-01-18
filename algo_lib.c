#include "algo_lib.h"
#include "helpers.h"
#include <stdbool.h>
#include <stdint.h>
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

SLLNode* CreateNode(void) {
    SLLNode *node;
    node = malloc(sizeof(SLLNode));
    node->value = 0;
    node->next = NULL;
    return node;
}

void SLLFree(SLLNode *node) {
    free(node);
}

/**
 * @brief Initialize a Single Linked List passed by reference with 0/NULL values;
 *
 * @param list The list to initalize
 */
SingleLinkedList SLLGetEmptyList(void) {
    SingleLinkedList list;
    list.length = 0;
    list.head = NULL;
    return list;
}

void SLLPrintNode(SLLNode *node) {
    printf("Value: %d\n", node->value);
    printf("Address: %p\n", (void *)node);
    printf("Next: %p\n", (void *)node->next);
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
 * @brief Add a node containing <value> at the start of the list
 *
 * @param list 
 * @param value 
 */
void SLLPrepend(SingleLinkedList *list, int value) {
    SLLNode *new = CreateNode();
    new->value = value;
    if(list->length == 0) {
        list->head = new;
    } else {
        new->next = list->head;
        list->head = new;
    }
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
        if (list->length > 1) {
            list->head = list->head->next;
        } else {
            list->head = NULL;
        }
        result = to_delete->value;
        SLLFree(to_delete);
    } else {
        SLLNode *current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        SLLNode *previous = current;
        SLLNode *to_delete = current->next;
        previous->next = NULL;
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


DoubleLinkedList DLLGetEmptyList(){
    DoubleLinkedList list;
    list.length = 0;
    list.head = NULL;
    list.tail = NULL;
    return list;
}

bool IsEmpty(DoubleLinkedList *list) {
    return list->head == NULL;
}


/**
 * @brief Add new node with <value> at the END of the list
 *
 * @param list 
 * @param value 
 */
void DLLAppend(DoubleLinkedList *list, int value){
    DLLNode *new = malloc(sizeof(DLLNode));
    new->value = value;
    if (IsEmpty(list)) {
        list->head = new;
        list->tail = new;
    } else {
        list->tail->next = new;
        new->prev = list->tail;
        list->tail = new;
        if (list->length == 1) {
            list->head->next = list->tail;
        }
    }
    list->length++;
}

/**
 * @brief Add new node with <value> at the START of the list
 *
 * @param list 
 * @param value 
 */
void DLLPrepend(DoubleLinkedList *list, int value){
    DLLNode *new = malloc(sizeof(DLLNode));
    new->value = value;
    if (IsEmpty(list)) {
        list->head = new;
        list->tail = new;
    } else {
        new->next = list->head;
        list->head->prev = new;
        list->head = new;
        if (list->length == 1) {
            list->tail->prev = list->head;
        }
    }
    list->length++;
}

/**
 * @brief Return value of node stored at position <index>
 *
 * @param list 
 * @param index 
 * @return 
 */
int DLLGetAt(DoubleLinkedList *list, int index){
    if (index >= list->length) {
        printf("WARNING! Out-of-boud access attempt with DLLGet (index %d)\n", index);
        return 0;
    }
    DLLNode *current;    
    if (index < (list->length)/2) {
        // Start from head
        current = list->head;
        for (int i = 0; i < index; i++) {
            if (current->next != NULL) {
                current = current->next;
            } else {
                printf("WARNING: Attempt to access NULL pointer in SLLGetAt, index %d.\n", index);
            }
        }
    } else {
        // Start from tail downwards
        current = list->tail;
        for (int i = list->length -1; i > index; i--) {
            if (current->prev != NULL) {
                current = current->prev;
            }else {
                printf("WARNING: Attempt to access NULL pointer in SLLGetAt, index %d.\n", index);
            }
        }
    }
    return current->value;
}

int DLLRemoveEmptyOrOne(DoubleLinkedList *list) {
    if (list->length == 0) {
        printf("Warning: Attempt to remove first of empty list.\n");
        return 0;
    } else { // length == 1
        int value;
        value = list->head->value;
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->length = 0;
        return value;
    }
}

int DLLRemoveFirst(DoubleLinkedList *list) {
    if (list->length <= 1) {
        return DLLRemoveEmptyOrOne(list);
    }
    return  DLLRemoveAt(list, 0);
}

int DLLRemoveLast(DoubleLinkedList *list) {
    if (list->length <= 1) {
        return DLLRemoveEmptyOrOne(list);
    }
    return DLLRemoveAt(list, list->length - 1);
}

int DLLRemoveAt(DoubleLinkedList *list, int index){
    if (list->length <= 1) {
        return DLLRemoveEmptyOrOne(list);
    }
    if(index >= list->length) {
        printf("WARNING! Out-of-boud access attempt with DLLRemoveAt (index %d)\n", index);
        return 0;
    }
    DLLNode *to_remove = list->head;
    int value;
    for (int i = 0; i < index; i++) {
      to_remove = to_remove->next;
    }
    // If erase first node
    if (to_remove->prev == NULL) {
      list->head = to_remove->next;
    } else {
        to_remove->prev->next = to_remove->next;
    }
    // If erase last node
    if (to_remove->next == NULL) {
      list->tail = to_remove->prev;
    } else {
        to_remove->next->prev = to_remove->prev;
    }
    value = to_remove->value;
    free(to_remove);
    list->length--;
    return value;
}

bool DLLRemove(DoubleLinkedList *list, int value){
    return false;
}
void DLLClear(DoubleLinkedList *list){
    while(list->length > 0) {
        DLLRemoveFirst(list);
    }
}

int DLLGetLast(DoubleLinkedList *list){
    return 0;
}
