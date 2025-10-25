# Data-structures
Education project by Cybersecurity student to understand data structures and train C/C++

# Design philosophy
All modules in this repository are designed using these principles:
- Error handling: Functions that modify data structures return bool type. They return ```true``` when operation was a success or ```false``` when operation failed
- Memory management: All data structures are created using ```_create``` functions and they manage their own memory. User is responsible for calling ```_free``` functions to free memory used by structures
- Genericity: All data structures are implemented in a generic way. C modules are implemented by using ```void*``` and ```memcpy``` which puts responsibility for type casting and providing correct data sizes on user

# Modules
As for now, repository contains these modules:
- C Stack

# C Stack
Secure, generic stack implementation in C programing language. 

| Function | Description|
|---|---|
| Stack* create_stack(size_t data_size) | It creates an empty stack. It takes data size in bytes (```data_size```) as an argument. It returns pointer to Stack or ```NULL``` in case of memory allocation error |
| bool stack_push(Stack* stack, void* value) | It puts element on stack. It takes stack pointer and value pointer as arguments. It returns ```true``` if operation was a success or ```false``` if it wasn't |
| bool stack_pop(Stack* stack, void* destination) | It removes element from stack. It takes stack pointer and destination pointer as arguments. Destination pointer determines where to store removed data. Destination can be ```NULL```. It returns ```true``` if operations was a success and ```false``` if it wasn't |
| bool stack_top(Stack* stack, void* destination) | It copies the top value of a stack into desired destination. It takes stack pointer and destination pointer as arguments. It returns ```true``` if operation was a success and ```false``` if it wasn't |
| bool stack_isEmpty(Stack* stack) | It checks if stack is empty. It takes stack pointer as an argument. It returns ```true``` if stack is empty and ```false``` if it isn't |
| void free_stack(Stack* stack) | It frees all memory used by stack, including all nodes and structure itself |

# Usage Example 
```c
#include "C structures/stack.h"
#include <stdio.h>

int main() {
    int val;

    // 1. Creating stack for int type elements
    Stack* stack = create_stack(sizeof(int));
    
    if(stack == NULL) {
        printf("Failed to create stack\n");
        return -1;
    }

    // 2. Pushing some elements on stack
    int a = 10, b = 20;
    stack_push(stack, &a);
    stack_push(stack, &b);

    // 3. Check stack top
    if(stack_top(stack, &val)) {
        printf("Element on top of the stack: %d\n", val); // Prints 20
    }

    // 4. Remove element from stack
    if(stack_pop(stack, &val)) {
        printf("Removed from stack: %d\n", val); // Prints 20
    }

    // 5. Check if stack is empty
    printf("Is stack empty: %s\n", stack_isEmpty(stack) ? "Yes" : "No");

    // 6. Free memory
    free_stack(stack);
    stack = NULL; // Not necessary but it's a good practice

    return 0;
}
```

# How to compile
Compilation example for stack module and main program
```
gcc -o program main.c c_structures/stack.c
```