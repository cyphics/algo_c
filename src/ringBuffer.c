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
        if (buffer->head > 0) printf("%*c", (buffer->head) * 3, ' ');
        printf(">");
        printf("%*c", (buffer->tail - buffer->head) * 3 - 1, ' ');
        printf("<");
    } else if (buffer->head > buffer->tail) {
        if (buffer->tail > 0)printf("%*c", (buffer->tail) * 3, ' ');
        printf("<");
        printf("%*c", (buffer->head - buffer->tail) * 3 - 1, ' ');
        printf(">");
    } else {
        if (buffer->tail > 0) printf("%*c", (buffer->tail) * 3, ' ');
        printf("^");
    }
    printf("\n");
}

void CheckSize(RingBuffer *buffer){
    if(buffer->length == buffer->capacity) {
        int *new_heap = calloc(2 * buffer->capacity * sizeof(int), sizeof(int));
        for (int i = 0; i < buffer->capacity; i++) {
            int position = (buffer->tail + i + 1) % buffer->capacity;
            int value = *(buffer->heap_position + position);
            *(new_heap + i) = value;
        }
        free(buffer->heap_position);
        buffer->heap_position = new_heap;
        buffer->tail = (buffer->tail - buffer->head + buffer->capacity) % buffer->capacity;
        buffer->head = 0;
        buffer->capacity *= 2;
    }
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
        CheckSize(buffer);
    };
    *GetAddress(buffer, buffer->head) = value;
    buffer->length++;
}

void AddToEnd(RingBuffer *buffer, int value) {
    if (buffer->length == 0) {
        buffer->tail = 0;
        buffer->head = 0;
    } else {
        CheckSize(buffer);
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

int PeekAt(RingBuffer *buffer, int index) {
    int ptr = buffer->head;
    for (int i = 0; i<index; i++) {
        IncrementPointer(buffer, &ptr);
    }
    return *GetAddress(buffer, ptr);
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

void ClearBuffer(RingBuffer *buffer) {
    for (int i = 0; i < buffer->capacity; i++) {
        *(buffer->heap_position + i) = 0;
        buffer->tail = 0;
        buffer->head = 0;
        buffer->length = 0;
    }
}

int* RingBufferToArray(RingBuffer* buffer) {
    int *arr = calloc(sizeof(int) * buffer->length, sizeof(int));
    int ptr = buffer->head;
    for (int i = 0; i < buffer->length; i++) {
        arr[i] = *GetAddress(buffer, ptr);
        IncrementPointer(buffer, &ptr);
    }
    return arr;
}
