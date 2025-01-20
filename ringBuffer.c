#include "ringBuffer.h"
#include <stdio.h>
#include <stdlib.h>

RingBuffer GetRingBuffer(int capacity) {
    int *heap_array = malloc(capacity * sizeof(int));
    for (int i = 0; i < capacity; i++) {
        *(heap_array + i) = 0;
    }
    RingBuffer buffer = {
            .capacity = capacity, .length = 0, heap_array, .head = 0, .tail = 0 
    };
    return buffer;
}

void PrintRingBuffer(RingBuffer *buffer) {
    for (int i = 0; i < buffer->capacity; i++) {
        int *position = (buffer->heap_position) + i;
        printf("[%d]", *position);
    }
    printf("\n ");
    if(buffer->tail > buffer->head) {
        if(buffer->head > 0) printf("%*c", (buffer->head) * 3, ' ');
        printf(">");
        printf("%*c", (buffer->tail - buffer->head) * 3 - 1, ' ');
        printf("<");
    } else {
        if(buffer->tail > 0) printf("%*c", (buffer->tail) * 3, ' ');
        printf("<");
        printf("%*c", (buffer->head - buffer->tail) * 3 - 1, ' ');
        printf(">");
    }
    printf("\n");
}

int *MaxBufferAddress(RingBuffer *buffer) {
    return buffer->heap_position + (buffer->capacity - 1) * sizeof(int);
}

void IncrementPointer(RingBuffer *buffer, int *pointer) {
    *pointer = (*pointer + 1) % buffer->capacity;
}

void DecrementPointer(RingBuffer *buffer, int *pointer) {
    *pointer = (*pointer - 1 + buffer->capacity) % buffer->capacity;
}

int *GetAddress(RingBuffer *buffer, int index) {
    return buffer->heap_position + index;
}

void SetValueAt(RingBuffer *buffer, int position, int value) {
     *(buffer->heap_position + position) = value;
}

void AddToStart(RingBuffer *buffer, int value) {
    if (buffer->length == 0) {
        buffer->tail = 0;
        buffer->head = 0;
    } else {
        DecrementPointer(buffer, &buffer->head);
    };
    *GetAddress(buffer, buffer->head) = value;
    buffer->length++;
}

void AddToEnd(RingBuffer *buffer, int value) {
    if (buffer->length == 0) {
        buffer->tail = 0;
        buffer->head = 0;
    } else {
        IncrementPointer(buffer, &buffer->tail);
    };
    *GetAddress(buffer, buffer->tail) = value;
    buffer->length++;
}

int PeekStart(RingBuffer *buffer) {
    return *(buffer->heap_position + buffer->head);
}
int PeekEnd(RingBuffer *buffer) {
    return *(buffer->heap_position + buffer->tail);
}

int RemoveFromStart(RingBuffer *buffer) {
    int *address = GetAddress(buffer, buffer->head);
    int value = *address;
    *address = 0;
    IncrementPointer(buffer, &buffer->head);
    buffer->length--;
    return value;
}

int RemoveFromEnd(RingBuffer *buffer) {
    int *address = GetAddress(buffer, buffer->tail);
    int value = *address;
    *address = 0;
    DecrementPointer(buffer, &buffer->tail);
    buffer->length--;
    return value;
}

