#ifndef HASHMAP_LINKED_LIST_H
#define HASHMAP_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    const char* key;
    void* value;
    struct node* next;
} linked_list;

void list_init(linked_list** list, void* value, size_t size);

void list_free(linked_list** list);

void list_add_node(linked_list* list, void* value, size_t size);

void list_set_key(linked_list* list, const char* key);

void list_add_node_with_key(linked_list* list, const char* key, void* value, size_t size);

void list_pop(linked_list** list, void* value, size_t size);

#endif //HASHMAP_LINKED_LIST_H
