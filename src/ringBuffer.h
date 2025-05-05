#ifndef RING_BUFFER_H
#define RING_BUFFER_H

typedef struct RingBuffer {
    int capacity;
    int length;
    int *heap_position;
    int head;
    int tail;
} RingBuffer;

RingBuffer GetRingBuffer(int capacity);
void AddToStart(RingBuffer *buffer, int value);
void AddToEnd(RingBuffer *buffer, int value);
int  RemoveFromStart(RingBuffer *buffer);
int  RemoveFromEnd(RingBuffer *buffer);
int  PeekStart(RingBuffer *buffer);
int  PeekEnd(RingBuffer *buffer);
void PrintRingBuffer(RingBuffer *buffer);
void ClearBuffer(RingBuffer *buffer);

#endif
