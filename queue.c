#include "queue.h"
#include <stdlib.h>
#include <string.h>

Queue GetQueue(void) {
    Queue queue;
    queue.head = NULL;
    queue.tail = NULL;
    queue.length = 0;
    return queue;
}

void EnQueue(Queue *queue, int value) {
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

int DeQueue(Queue *queue) {
    if(queue->head == NULL) {
        return 0;
    }
    QueueNode *node = queue->tail;
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

int PeekQueue(Queue *queue) {
    if(queue->head == NULL) {
        return 0;
    }
    return queue->tail->value;
}
