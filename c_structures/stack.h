#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef STACK_H
#define STACK_H

typedef struct {
    void* value;
    struct StackNode* next;
} StackNode;

typedef struct {
    size_t data_size;
    StackNode* top;
} Stack;

Stack* create_stack(size_t data_size);
bool stack_push(Stack* stack, void* value);
bool stack_pop(Stack* stack, void* destination);
bool stack_top(Stack* stack, void* destination);
bool stack_isEmpty(Stack* stack);
void free_stack(Stack* stack);

#endif