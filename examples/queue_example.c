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