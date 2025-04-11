#include "linked_list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// TODO remove
#define LinkedList DLList

LinkedList get_empty_dllist(void){
    LinkedList list;
    list.length = 0;
    list.head = NULL;
    list.tail = NULL;
    return list;
}

Node* CreateNode(void* data, int size) {
    Node* new = (Node*)malloc(sizeof(Node));
    if (new == NULL) {
        return NULL;
    }
    new->data = malloc(size);
    if (new->data == NULL) {
        free(new);
        return NULL;
    }
    new->size = size;
    new->next = NULL;
    new->prev = NULL;
    memcpy(new->data, data, size);
    return new;
}

void add_initial_data(LinkedList *list, Node new_node) {
    list->head = &new_node;
    list->tail = &new_node;
}

// Add at the end of list
void   dllist_append(LinkedList *list, void* data, int size){
    Node* new = CreateNode(data, size);
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
void   dllist_prepend(LinkedList *list, void* data, int size){
    Node* new = CreateNode(data, size);
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

void*  dllist_get_at(LinkedList *list, int index){
    Node* node = list->head;
    if (index > list->length - 1){
        return NULL;
    }
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    // TODO check what happens if caller free() returned data
    return node->data;
}

void*  dllist_pop_first(LinkedList *list){
    if (list->head != NULL) {
        Node* to_delete = list->head;
        void* pop = to_delete->data;
        if (list->head->next != NULL) {
            list->head = list->head->next;
            list->head->prev = NULL;
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

void*  dllist_pop_last(LinkedList *list){
        Node* to_delete = NULL;
        void* pop = NULL;

    if (list->tail != NULL) {
        to_delete = list->tail;
        pop = to_delete->data;
        if (list->tail->prev != NULL) {
            list->tail = list->tail->prev;
            list->tail->next = NULL;
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

void*  dllist_pop_at(LinkedList *list, int index){
    if (index >= 0 && index < list->length) {
        Node* to_pop = list->head;
        for (int i = 0; i < index; i++) {
            to_pop = to_pop->next;
        }
        void* pop = to_pop->data;
        if(to_pop->prev == NULL) {
            list->head = list->head->next;
        } else if (to_pop->next == NULL) {
        } else {
            to_pop->prev->next = to_pop->next;
            to_pop->next->prev = to_pop->prev;
        }
        free(to_pop);
        list->length--;
        return pop;
    }
    return NULL;
}

void   dllist_clear(LinkedList *list){
    while (list->head != NULL) {
        free(dllist_pop_first(list));
    }
}
