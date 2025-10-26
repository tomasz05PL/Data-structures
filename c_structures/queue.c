#include "queue.h"

Queue* create_queue(size_t data_size) {
    Queue* queue = malloc(sizeof(Queue));

    if(queue == NULL) {
        return NULL;
    }

    queue->data_size = data_size;
    queue->head = queue->tail = NULL;

    return queue;
}

bool enqueue(Queue* queue, void* value) {
    QueueNode* newNode = malloc(sizeof(QueueNode));
    if(newNode == NULL) {
        return false;
    }
    newNode->value = malloc(queue->data_size);
    if(newNode->value == NULL) {
        free(newNode);
        return false;
    }

    memcpy(newNode->value, value, queue->data_size);

    if(queue->head == NULL) {
        newNode->next = NULL;
        queue->head = queue->tail = newNode;
        return true;
    }

    newNode->next = NULL;
    queue->tail->next = newNode;
    queue->tail = newNode;
    return true;
}

bool dequeue(Queue* queue, void* destination) {
    if(queue == NULL) {
        return false;
    }

    if(queue->head == NULL) {
        return false;
    }

    if(destination != NULL) {
        memcpy(destination, queue->head->value, queue->data_size);
    }

    QueueNode* temp = queue->head;

    if(queue->head == queue->tail) {
        queue->head = queue->tail = NULL;
    }
    else {
        queue->head = queue->head->next;
    }

    free(temp->value);
    free(temp);

    return true;
}

bool queue_front(Queue* queue, void* destination) {
    if(queue == NULL) {
        return false;
    }
    if(queue->head == NULL) {
        return false;
    }
    if (destination != NULL) memcpy(destination, queue->head->value, queue->data_size);
    
    return true;
}

bool queue_isEmpty(Queue* queue) {
    if(queue == NULL) {
        return true;
    }
   return queue->head == NULL;
}

void free_queue(Queue* queue) {
    if(queue == NULL) {
        return;
    }
    while(!queue_isEmpty(queue)) {
        dequeue(queue, NULL);
    }
    free(queue);
}