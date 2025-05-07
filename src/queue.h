#ifndef QUEUE_H
#define QUEUE_H

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

#endif
