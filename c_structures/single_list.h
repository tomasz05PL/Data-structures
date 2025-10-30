#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

typedef struct {
    void* value;
    struct SingleListNode* next;
} SingleListNode;

typedef struct {
    size_t data_size, list_size;
    SingleListNode* head;
    SingleListNode* tail;
} SingleList;

SingleList* create_single_list(size_t data_size, void* init_arr, size_t init_arr_size);
bool single_list_push_back(SingleList* list, void* value);
bool single_list_push_front(SingleList* list, void* value);
bool single_list_pop_back(SingleList* list, void* destination);
bool single_list_pop_front(SingleList* list, void* destination);
bool single_list_isEmpty(SingleList* list);
bool single_list_front(SingleList* list, void* destination);
bool single_list_back(SingleList* list, void* destination);
size_t single_list_size(SingleList* list);
bool single_list_insert(SingleList* list, void* value, size_t index);
bool single_list_remove(SingleList* list, void* destination, size_t index);
bool single_list_get(SingleList* list, void* destination, size_t index);
void* single_list_to_arr(SingleList* list);
void free_single_list(SingleList* list);

#endif