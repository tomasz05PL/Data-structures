#include "../c_structures/stack.h"
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