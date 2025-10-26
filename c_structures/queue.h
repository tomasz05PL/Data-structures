#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
    void* value;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    size_t data_size;
    QueueNode* head;
    QueueNode* tail;
} Queue;

Queue* create_queue(size_t data_size);
bool enqueue(Queue* queue, void* value);
bool dequeue(Queue* queue, void* destination);
bool queue_front(Queue* queue, void* destination);
bool queue_isEmpty(Queue* queue);
void free_queue(Queue* queue);

#endif