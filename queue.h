typedef struct QueueNode {
    int value;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *head;
    QueueNode *tail;
    int length;
} Queue;

Queue GetQueue(void); 
void EnQueue(Queue *queue, int value);
int DeQueue(Queue *queue);
int PeekQueue(Queue *queue); 
