#include "queue.h"
#include <stdlib.h>
#include <string.h>

QueueInt GetQueueInt(void) {
    QueueInt queue;
    queue.head = NULL;
    queue.tail = NULL;
    queue.length = 0;
    return queue;
}

void EnQueueInt(QueueInt *queue, int value) {
    QueueNodeInt *node = malloc(sizeof(QueueNodeInt));
    node->value = value;
    if(queue->head == NULL) {
        queue->head = node;
        queue->tail = node;
        node->next = NULL;
    } else {
        queue->head->next = node;
        queue->head = node;
    }
    queue->length++;
}

int DeQueueInt(QueueInt *queue) {
    if(queue->head == NULL) {
        return 0;
    }
    QueueNodeInt *node = queue->tail;
    int result = node->value;
    if (queue->length == 1) {
        queue->head = NULL;
        queue->tail = NULL;
    } else {
        queue->tail = node->next;
    }
    free(node);
    queue->length--;
    return result;
}

int PeekQueueInt(QueueInt *queue) {
    if(queue->head == NULL) {
        return 0;
    }
    return queue->tail->value;
}

Queue GetQueue(void) {
    Queue queue;
    queue.head = NULL;
    queue.tail = NULL;
    queue.length = 0;
    return queue;
}

void EnQueue(Queue *queue, void* value) {
    QueueNode *node = malloc(sizeof(QueueNode));
    node->value = value;
    if(queue->head == NULL) {
        queue->head = node;
        queue->tail = node;
        node->next = NULL;
    } else {
        queue->head->next = node;
        queue->head = node;
    }
    queue->length++;
}

void* DeQueue(Queue *queue) {
    if(queue->head == NULL) {
        return NULL;
    }
    QueueNode *node = queue->tail;
    void* result = node->value;
    if (queue->length == 1) {
        queue->head = NULL;
        queue->tail = NULL;
    } else {
        queue->tail = node->next;
    }
    free(node);
    queue->length--;
    return result;
}

void* PeekQueue(Queue *queue) {
    if(queue->head == NULL) {
        return 0;
    }
    return queue->tail->value;
}

void ClearQueue(Queue *queue) {
    while(PeekQueue(queue) != NULL) {
        free(DeQueue(queue));
    }
}
