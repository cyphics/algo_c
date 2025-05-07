#ifndef QUEUE_H
#define QUEUE_H

// QUEUE FOR INT
typedef struct QueueNodeInt {
    int value;
    struct QueueNodeInt *next;
} QueueNodeInt;

typedef struct QueueInt {
    QueueNodeInt *head;
    QueueNodeInt *tail;
    int length;
} QueueInt;

QueueInt GetQueueInt(void); 
void EnQueueInt(QueueInt *queue, int value);
int DeQueueInt(QueueInt *queue);
int PeekQueueInt(QueueInt *queue); 

typedef struct QueueNode {
    void* value;
    struct QueueNode *next;
} QueueNode;

// QUEUE FOR *void
typedef struct Queue {
    QueueNode *head;
    QueueNode *tail;
    int length;
} Queue;

Queue GetQueue(void); 
void EnQueue(Queue *queue, void* value);
void* DeQueue(Queue *queue);
void* PeekQueue(Queue *queue); 
void ClearQueue(Queue *queue);

#endif
