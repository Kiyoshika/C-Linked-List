#include "include/linked_list.h"

int main()
{
    linked_list* mylist = NULL;
    list_init(&mylist); // create an empty head node

    // set head value
    int val = 10;
    list_set_value(mylist, &val, sizeof(int));

    // add a few other nodes at the end of the list
    val = 20;
    list_add_node(mylist, &val, sizeof(int));
    val = 30;
    list_add_node(mylist, &val, sizeof(int));
    val = 40;
    list_add_node(mylist, &val, sizeof(int));

    // pop off elements from the head to tail
    // note that since memory is deallocated upon popping, we must pass the reference
    int popped;
    list_pop(&mylist, &popped, sizeof(int));
    printf("%d\n", popped);

    list_pop(&mylist, &popped, sizeof(int));
    printf("%d\n", popped);

    list_pop(&mylist, &popped, sizeof(int));
    printf("%d\n", popped);

    list_pop(&mylist, &popped, sizeof(int));
    printf("%d\n", popped);

    // technically wouldn't need this since we popped every element (hence cleared entire memory)
    // but leaving here for reference in case you DON'T pop off all elements
    list_free(&mylist);
    return 0;
}
