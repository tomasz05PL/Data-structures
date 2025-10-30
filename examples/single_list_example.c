#include "../c_structures/single_list.h"
#include <stdio.h>

#define data_size sizeof(int)

int main() {
    int val;

    // 1. Creating array to initialize list - this step is optional
    int init_arr[5] = {1,2,3,4,5}; 

    // 2. Creating single linked list from array
    SingleList* list = create_single_list(data_size, init_arr, 5);
    if(list == NULL) {
        printf("Failed to create list\n");
        return -1;
    }

    // 3. Getting first list element
    if(single_list_front(list, &val)) {
        printf("First element in the list is %d\n", val); // prints 1
    }

    // 4. Getting last list element
    if(single_list_back(list, &val)) {
        printf("Last element in the list is %d\n", val); //prints 5
    }

    // 5. Getting third list element
    if(single_list_get(list, &val, 2)) {
        printf("3rd element in the list is %d\n", val); //prints 3
    }

    // 6. Pushing element to the front of the list 
    val = 0;
    if(single_list_push_front(list, &val)) {
        printf("Added element %d to the front of the list\n", val); // Current list - [0,1,2,3,4,5]
    }

    // 7. Pushing element on the back of the list
    val = 6;
    if(single_list_push_back(list, &val)) {
        printf("Added element %d on the back of the list\n", val); // Current list - [0,1,2,3,4,5,6]
    }

    // 8. Inserting element on the 3rd place in the list
    val = 7;
    if(single_list_insert(list, &val, 2)) {
        printf("Added element %d on the 3rd place in the list\n", val); // Current list - [0,1,7,2,3,4,5,6]
    }

    // 9. Checking list size
    printf("List size is %u\n", single_list_size(list));

    // 10. Checking if list is empty
    printf("Is list empty: %s\n", single_list_isEmpty(list) ? "Yes" : "No");

    // 11. Removing first element in the list
    if(single_list_pop_front(list, &val)) {
        printf("Removed first element in the list which was %d\n", val); // Current list - [1,7,2,3,4,5,6]
    }

    // 12. Removing last element in the list
    if(single_list_pop_back(list, &val)) {
        printf("Removed last element in the list which was %d\n", val); // Current list [1,7,2,3,4,5]
    }

    // 13. Removing 4th element in the list
    if(single_list_remove(list, &val, 3)) {
        printf("Removed 4th element in the list which was %d\n", val); // Current list - [1,7,2,4,5]
    }

    // 14. Converting list back to the array
    int* list_arr = (int*)single_list_to_arr(list);

    // 15. Printing list
    printf("List: ");
    for(int i = 0; i < single_list_size(list); ++i){
        printf("%d, ", list_arr[i]); // prints 1, 7, 2, 4, 5
    }
    printf("\n");

    // 16. Free memory after list AND after list_arr
    free_single_list(list);
    free(list_arr);
    
    return 0;
}