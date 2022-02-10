#include "../include/linked_list.h"

void list_init(linked_list** list)
{
    *list = malloc(sizeof(linked_list));
    (*list)->value = NULL;
    (*list)->next = NULL;
}

void list_set_value(linked_list* list, void* value, size_t size)
{
    list->value = malloc(size);
    memcpy(list->value, value, size);
}

void list_add_node(linked_list* list, void* value, size_t size)
{
    linked_list* new_node = malloc(sizeof(linked_list));
    list_set_value(new_node, value, size);
    new_node->next = NULL;
    // add node to very end of linked list
    while (list != NULL)
    {
        if (list->next == NULL) break;
        list = list->next;
    }
    list->next = new_node;
}

void list_pop(linked_list** list, void* value, size_t size)
{
    memcpy(value, (*list)->value, size);
    linked_list *tmp = *list;
    *list = (*list)->next;
    free(tmp->value);
    tmp->value = NULL;
    free(tmp);
    tmp = NULL;
}

void list_free(linked_list** list)
{
    linked_list* tmp;
    while (*list != NULL)
    {
        tmp = *list;
        *list = (*list)->next;
        free(tmp->value);
        tmp->value = NULL;
        free(tmp);
        tmp = NULL;
    }
}