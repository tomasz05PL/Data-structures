#include "single_list.h"

SingleList* create_single_list(size_t data_size, void* init_arr, size_t init_arr_size) {
    SingleList* list = malloc(sizeof(SingleList));
    if(list == NULL) {
        return NULL;
    }
    list->data_size = data_size;
    list->head = list->tail = NULL;
    list->list_size = 0;
    if(init_arr != NULL) {
        for(int i = 0; i < init_arr_size; ++i) {
            if(!single_list_push_back(list, (char*)init_arr + (i * data_size))) {
                free_single_list(list);
                return NULL;
            }
        }
    }
    return list;
}

bool single_list_push_back(SingleList* list, void* value) {
    if(list == NULL) {
        return false;
    }
    SingleListNode* newNode = malloc(sizeof(SingleListNode));
    if(newNode == NULL) {
        return false;
    }

    newNode->value = malloc(list->data_size);
    if(newNode->value == NULL) {
        free(newNode);
        return false;
    }

    memcpy(newNode->value, value, list->data_size);
    newNode->next = NULL;

    if(list->list_size == 0) {
        list->head = list->tail = newNode;
        list->list_size++;
        return true;
    }

    list->tail->next = newNode;
    list->tail = newNode;
    list->list_size++;

    return true;
}

bool single_list_push_front(SingleList* list, void* value) {
    if(list == NULL) {
        return false;
    }

    SingleListNode* newNode = malloc(sizeof(SingleListNode));
    if(newNode == NULL) {
        return false;
    }

    newNode->value = malloc(list->data_size);
    if(newNode->value == NULL) {
        free(newNode);
        return false;
    }

    memcpy(newNode->value, value, list->data_size);
    newNode->next = list->head;

    if(list->list_size == 0) {
        list->head = list->tail = newNode;
        list->list_size++;
        return true;
    }
    
    list->head = newNode;
    list->list_size++;
    return true;
}

bool single_list_pop_back(SingleList* list, void* destination) {
    if(list == NULL) {
        return false;
    }

    if(list->head == NULL) {
        return false;
    }

    SingleListNode* popped = list->tail;
    SingleListNode* newTail = list->head;

    if(destination != NULL) {
        memcpy(destination, list->tail->value, list->data_size);
    }

    if(list->head == list->tail) {
        list->head = list->tail = NULL;
    }
    else { 

        while(newTail->next != list->tail) {
            newTail = newTail->next;
        }
        newTail->next = NULL;
        list->tail = newTail;
    }

    free(popped->value);
    free(popped);
    list->list_size--;
    return true;
}

bool single_list_pop_front(SingleList* list, void* destination) {
    if(list == NULL) {
        return false;
    }
    
    if(list->head == NULL) {
        return false;
    }

    if(destination != NULL) {
        memcpy(destination, list->head->value, list->data_size);
    }

    SingleListNode* temp = list->head;
    
    if(list->head == list->tail) {
        list->head = list->tail = NULL;
    } 
    else {
        list->head = list->head->next;
    }

    free(temp->value);
    free(temp);
    list->list_size--;
    return true;
}

bool single_list_isEmpty(SingleList* list) {
    if(list == NULL) {
        return true;
    }
    return list->list_size == 0;
}

bool single_list_front(SingleList* list, void* destination) {
    if(list == NULL) {
        return false;
    }

    if(list->head == NULL) {
        return false;
    }

    if(destination != NULL) {
        memcpy(destination, list->head->value, list->data_size);
    }
    return true;
}

bool single_list_back(SingleList* list, void* destination) {
    if(list == NULL) {
        return false;
    }

    if(list->head == NULL) {
        return false;
    }

    if(destination != NULL) {
        memcpy(destination, list->tail->value, list->data_size);
    }
    return true;
}

size_t single_list_size(SingleList* list) {
    if(list == NULL) {
        return 0;
    }
    return list->list_size;
}

bool single_list_insert(SingleList* list, void* value, size_t index) {
    if(list == NULL) {
        return false;
    }
    if(index == 0) {
        if(single_list_push_front(list, value)) return true;
        return false;
    }
    if(index >= list->list_size) {
        if(single_list_push_back(list, value)) return true;
        return false;
    }

    SingleListNode* newNode = malloc(sizeof(SingleListNode));
    if(newNode == NULL) {
        return false;
    }

    newNode->value = malloc(list->data_size);
    if(newNode->value == NULL) {
        free(newNode);
        return false;
    }

    memcpy(newNode->value, value, list->data_size);
    
    SingleListNode* temp = list->head;

    for(int i = 0; i < index-1; ++i) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    list->list_size++;
    return true;
}

bool single_list_remove(SingleList* list, void* destination, size_t index) {
    if(list == NULL) {
        return false;
    }
    if(list->head == NULL) {
        return false;
    }

    if(index >= list->list_size) return false;

    if(index == 0) {
        if(single_list_pop_front(list, destination)) return true;
        return false;
    }
    if(index == list->list_size-1) {
        if(single_list_pop_back(list, destination)) return true;
        return false;
    }

    SingleListNode* temp = list->head;

    for(int i = 0; i < index-1; ++i) {
        temp = temp->next;
    }

    SingleListNode* popped = temp->next;
    temp->next = popped->next;

    if(destination != NULL) {
        memcpy(destination, popped->value, list->data_size);
    }

    free(popped->value);
    free(popped);
    list->list_size--;
    return true;
}

bool single_list_get(SingleList* list, void* destination, size_t index) {
    if(list == NULL) {
        return false;
    }

    if(list->head == NULL) {
        return false;
    }

    if(index >= list->list_size) return false;

    if(index == 0) {
        if(single_list_front(list, destination)) return true;
        return false;
    }
    if(index == list->list_size-1) {
        if(single_list_back(list, destination)) return true;
        return false;
    }

    SingleListNode* temp = list->head;
    for(int i = 0; i < index; ++i) {
        temp = temp->next;
    }
    if(destination != NULL) memcpy(destination, temp->value, list->data_size);
    
    return true;
}

void* single_list_to_arr(SingleList* list) {
    void* arr = malloc(list->list_size*list->data_size);
    if(arr == NULL) {
        return arr;
    }

    SingleListNode* node = list->head;

    for(int i = 0; i < list->list_size; ++i){
        memcpy((char*)arr + i * list->data_size, node->value, list->data_size);
        node = node->next;
    }

    return arr;
}

void free_single_list(SingleList* list) {
    if(list == NULL){
        return;
    }
    while(list->list_size > 0) {
        single_list_pop_front(list, NULL);
    }
    free(list);
}