# C Queue 
Secure, generic queue implementation in C programing language

| Function | Description |
|---|---|
| Queue* create_queue(size_t data_size) | It creates an empty queue. It takes data size in bytes as an argument. It returns pointer to the queue or ```NULL``` in case of memory allocation error |
| bool enqueue(Queue* queue, void* value) | Adds element on the tail of the queue. It takes queue pointer and value pointer as arguments. It returns ```true``` if operation was a success or ```false``` if it wasn't |
| bool dequeue(Queue* queue, void* destination) | Removes element from queue head and copies it into ```destination```. It takes queue pointer and destination pointer as arguments. ```destination``` can be ```NULL```.  It returns ```true``` if operation was a success or ```false``` if it wasn't |
| bool queue_front(Queue* queue, void* destination) | Copies element from queue head into ```destination```. It takes queue pointer and destination pointer as arguments. It returns ```true``` if operation was a success or ```false``` if it wasn't |
| bool queue_isEmpty(Queue* queue) | Checks if queue is empty. It takes queue pointer as an argument. It returns ```true``` if queue is empty and ```false``` if it isn't |
| void free_queue(Queue* queue) | Frees all memory used by queue including nodes and queue itself |

# Queue Usage Example

```c
#include "../c_structures/queue.h"
#include <stdio.h>

int main() {
    int val;

    // 1. Create queue
    Queue* queue = create_queue(sizeof(int));

    if(queue == NULL) {
        printf("Failed to create queue\n");
        return -1;
    }

    // 2. Add few elements to the queue
    for(int i = 0; i < 5; ++i) {
        if(enqueue(queue, &i)) {
            printf("Added %d to queue\n", i);
        }
    }

    // 3. Check queue head
    if(queue_front(queue, &val)) {
        printf("Element in the front od a queue is %d\n", val);
    }

    // 4. Remove element from the queue
    if(dequeue(queue, &val)) {
        printf("Removed %d from the list, ", val);
    }

    if(queue_front(queue, &val)) {
        printf("current element in the front is %d\n", val);
    }
    else {
        printf("\n");
    }

    // 5. Checking if queue is empty
    printf("Is queue empty: %s\n", queue_isEmpty(queue) ? "Yes" : "No");

    // 6. Free memory
    free_queue(queue);

    return 0;
}
```

# How to compile
Compilation example for stack module and main program
```
gcc -o program main.c c_structures/queue.c
```