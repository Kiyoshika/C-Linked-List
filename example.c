#include "include/linked_list.h"

bool cmp(void* a, void* b)
{
    return *(int*)a == *(int*)b;
}

int main()
{
    linked_list* mylist = NULL;

    int val = 10;
    list_init(&mylist, &val, sizeof(int)); // create head node
    list_set_key(mylist, "examplekey");

    // add a few other nodes at the end of the list
    val = 20;
    list_add_node(mylist, &val, sizeof(int));
    val = 30;
    list_add_node_with_key(mylist, "apples", &val, sizeof(int));
    val = 40;
    list_add_node(mylist, &val, sizeof(int));

    int search_val = 20;
    list_remove_by_value(&mylist, &search_val, &cmp); // remove by value
    list_remove_by_key(&mylist, "apples"); // remove by key

    // pop off elements from the head to tail
    // note that since memory is deallocated upon popping, we must pass the reference
    int popped;
    while (mylist != NULL)
    {
        printf("Key: %s\n", mylist->key);
        list_pop(&mylist, &popped, sizeof(int));
        printf("Value: %d\n\n", popped);
    }

    // technically wouldn't need this since we popped every element (hence cleared entire memory)
    // but leaving here for reference in case you DON'T pop off all elements
    list_free(&mylist);
    return 0;
}
