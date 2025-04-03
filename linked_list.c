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

struct LLNode* CreateNode(void* data, int size) {
    struct LLNode* new = (struct LLNode*)malloc(sizeof(struct LLNode));
    new->data = malloc(size);
    new->size = size;
    memcpy(new->data, data, size);
    return new;
}

void add_first_data(LinkedList *list, struct LLNode new_node) {
    list->head = &new_node;
    list->tail = &new_node;
}

// Add at the end of list
void   LinkedListAppend(LinkedList *list, void* data, int size){
    struct LLNode* new = CreateNode(data, size);
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
    struct LLNode* new = CreateNode(data, size);
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
    struct LLNode* node = list->head;
    if (index > list->length - 1){
        return NULL;
    }
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    return node->data;
}

void*  LinkedListRemoveFirst(LinkedList *list){}
void*  LinkedListRemoveLast(LinkedList *list){}
void*  LinkedListRemoveAt(LinkedList *list, int index){}

void   LinkedListClear(LinkedList *list){
    int counter = 0;
    struct LLNode* current = list->head;
    while (current != NULL) {
        printf("Round %i\n", counter);
        counter++;
        struct LLNode* next = NULL;
        if(current->data != NULL) {
            printf("Current: %s\n", (char*)current->data);
            //free(current->data);
        }
        if (current->next != NULL) {
            next = current->next;
        } 
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
}
