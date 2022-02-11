# C-Linked-List
A very barebones implementation of a generic linked list in C.

The linked list supports key/value data by default which I'm using to build a hashmap structure.

See my hashmap project: https://github.com/Kiyoshika/C-Hash-Map

# Example
```c
#include "include/linked_list.h"

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

    // pop off elements from the head to tail
    // note that since memory is deallocated upon popping, we must pass the reference
    int popped;
    printf("Key: %s\n", mylist->key);
    list_pop(&mylist, &popped, sizeof(int));
    printf("Value: %d\n\n", popped);

    printf("Key: %s\n", mylist->key);
    list_pop(&mylist, &popped, sizeof(int));
    printf("Value: %d\n\n", popped);

    printf("Key: %s\n", mylist->key);
    list_pop(&mylist, &popped, sizeof(int));
    printf("Value: %d\n\n", popped);

    printf("Key: %s\n", mylist->key);
    list_pop(&mylist, &popped, sizeof(int));
    printf("Value: %d\n\n", popped);

    // technically wouldn't need this since we popped every element (hence cleared entire memory)
    // but leaving here for reference in case you DON'T pop off all elements
    list_free(&mylist);
    return 0;
}
```
Output:
```text
Key: examplekey
Value: 10

Key: (null)
Value: 20

Key: apples
Value: 30

Key: (null)
Value: 40
```