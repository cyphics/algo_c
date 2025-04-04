#include "linked_list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

LinkedList LinkedListGetEmptyList(void){
    LinkedList list;
    list.length = 0;
    list.head = NULL;
    list.tail = NULL;
    return list;
}

struct Node* CreateNode(void* data, int size) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = malloc(size);
    new->size = size;
    new->next = NULL;
    new->prev = NULL;
    memcpy(new->data, data, size);
    return new;
}

void add_initial_data(LinkedList *list, struct Node new_node) {
    list->head = &new_node;
    list->tail = &new_node;
}

// Add at the end of list
void   LinkedListAppend(LinkedList *list, void* data, int size){
    struct Node* new = CreateNode(data, size);
    if (list->tail == NULL) {
        list->tail = new;
        list->head = new;
    } else {
        list->tail->next = new;
        new->prev = list->tail;
        list->tail = new;
        if (list->length == 1) {
            list->head->next = list->tail;
        }
    }
    list->length ++;
}

// Add at the begining of list
void   LinkedListPrepend(LinkedList *list, void* data, int size){
    struct Node* new = CreateNode(data, size);
    if (list->tail == NULL) {
        list->tail = new;
        list->head = new;
    } else {
        list->head->prev = new;
        new->next = list->head;
        list->head = new;
        if (list->length == 1) {
            list->head->next = list->tail;
        }
    }
    list->length ++;
}

void*  LinkedListGetAt(LinkedList *list, int index){
    struct Node* node = list->head;
    if (index > list->length - 1){
        return NULL;
    }
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    return node->data;
}

void*  LinkedListPopFirst(LinkedList *list){
    if (list->head != NULL) {
        Node* to_delete = list->head;
        void* pop = to_delete->data;
        if (list->head->next != NULL) {
            list->head = list->head->next;
        } else {
            list->head = NULL;
            list->tail = NULL;
        }
        free(to_delete);
        list->length--;
        return pop;
    }
    return NULL;
}

void*  LinkedListPopLast(LinkedList *list){
    if (list->tail != NULL) {
        struct Node* to_delete = list->tail;
        void* pop = to_delete->data;
        if (list->tail->prev != NULL) {
            list->tail = list->tail->prev;
        } else {
            list->head = NULL;
            list->tail = NULL;
        }
        free(to_delete);
        list->length--;
        return pop;
    }
    return NULL;
}

void*  LinkedListPopAt(LinkedList *list, int index){
    if (index < list->length) {

    }
}

void   LinkedListClear(LinkedList *list){
    while (list->head != NULL) {
        free(LinkedListPopFirst(list));
    }
}
