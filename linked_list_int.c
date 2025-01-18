#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list_int.h"

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
