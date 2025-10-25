#include "stack.h"

Stack* create_stack(size_t data_size){
    Stack* newStack = malloc(sizeof(Stack));

    if(newStack == NULL){
        return NULL;
    }

    newStack->data_size = data_size;
    newStack->top = NULL;

    return newStack;
}

bool stack_push(Stack* stack, void* value){
    if(stack == NULL){
        return false;
    }
    StackNode* newNode = malloc(sizeof(StackNode));
    if(newNode == NULL){
        return false;
    }

    newNode->value = malloc(stack->data_size);
    if(newNode->value == NULL){
        free(newNode);
        return false;
    }

    memcpy(newNode->value, value, stack->data_size);
    newNode->next = stack->top;
    stack->top = newNode;
    return true;
}

bool stack_pop(Stack* stack, void* destination){
    if(stack == NULL){
        return false;
    }
    if(stack->top == NULL){
        return false;
    }

    if(destination != NULL) memcpy(destination, stack->top->value, stack->data_size);
    StackNode* temp = stack->top;
    stack->top = stack->top->next;
    free(temp->value);
    free(temp);
    return true;
}

bool stack_top(Stack* stack, void* destination){
    if(stack == NULL){
        return false;
    }
    if(stack->top == NULL){
        return false;
    }
    if(destination != NULL) memcpy(destination, stack->top->value, stack->data_size);
    return true;
}

bool stack_isEmpty(Stack* stack){
    if(stack == NULL){
        return true;
    }
    return stack->top == NULL;
}

void free_stack(Stack* stack){
    if(stack == NULL){
        return;
    }
    while(!stack_isEmpty(stack)){
        stack_pop(stack, NULL);
    }
    free(stack);
}