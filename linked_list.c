#include "linked_list.h"
#include <stdlib.h>
#include <string.h>

LinkedList LinkedListGetEmptyList(void){
    LinkedList list;
    list.length = 0;
    list.head = NULL;
    list.tail = NULL;
    return list;
}

void add_first_data(LinkedList *list, struct LLNode new_node) {
    list->head = &new_node;
    list->tail = &new_node;
}

// Add at the end of list
void   LinkedListAppend(LinkedList *list, void* data, int size){
    struct LLNode* new = (struct LLNode*)malloc(sizeof(struct LLNode));
    new->data = malloc(size);
    new->size = size;
    memcpy(new->data, data, size);
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
void   LinkedListPrepend(LinkedList *list, void* data){}
void*  LinkedListGetAt(LinkedList *list, int index){}
void*  LinkedListRemoveFirst(LinkedList *list){}
void*  LinkedListRemoveLast(LinkedList *list){}
void*  LinkedListRemoveAt(LinkedList *list, int index){}
void   LinkedListClear(LinkedList *list){}
