# TRACES
Linked list library in C language for embedded software.


## Description

_\<insert here\>_


## Dependencies

`linked_list.c` includes the module [traces](https://github.com/cruzl/traces).


## API

* LINKED_LIST_CreateEmptyList
* LINKED_LIST_AddNode
* LINKED_LIST_DeleteNode
* LINKED_LIST_FindNode
* LINKED_LIST_DisplayList
* LINKED_LIST_ReverseList
* LINKED_LIST_DestroyList


## Usage

Example program [demo.c](demo.c):
```c
#include "linked_list.h"

typedef struct {
    int x;
} SOME_STRUCT_t;

typedef enum {
    ENUM_1 ,
    ENUM_2 ,
    ENUM_3
} SOME_ENUM_t;

static LIST_t * list = NULL;

void
main ( void )
{
    printf( "Creating the list\r\n" );
    list = LINKED_LIST_CreateEmptyList();

    if ( list == NULL ) return;

    static SOME_STRUCT_t x;
    static unsigned int  y;
    static SOME_ENUM_t   z;

    printf( "\r\nAdding the fist element to the list\r\n" );
    LINKED_LIST_AddNode( list , ( void * )&x );

    printf( "\r\nDisplaying the list\r\n" );
    LINKED_LIST_DisplayList( list );

    printf( "\r\nAdding the second element to the list\r\n" );
    LINKED_LIST_AddNode( list , ( void * )&y );

    printf( "\r\nDisplaying the list\r\n" );
    LINKED_LIST_DisplayList( list );

    printf( "\r\nReversing the list\r\n" );
    LINKED_LIST_ReverseList( list );

    printf( "\r\nDisplaying the list\r\n" );
    LINKED_LIST_DisplayList( list );

    printf( "\r\nAdding the third element to the list\r\n" );
    LINKED_LIST_AddNode( list , ( void * )&z );

    printf( "\r\nIterating the list\r\n" );
    NODE_t * node = list->head;
    while ( node != NULL )
    {
        void * data = node->data;
        printf( "Node = 0x%p, data = 0x%p\r\n" , node , data );
        node = node->next;
    }

    printf( "\r\nDeleting the node whose content is the variable 'x'\r\n" );
    LINKED_LIST_DeleteNode( list , ( void * )&x );

    printf( "\r\nDisplaying the list\r\n" );
    LINKED_LIST_DisplayList( list );

    printf( "\r\nDestroying the list before finishing the program\r\n" );
    LINKED_LIST_DestroyList( list );
}
```

Compiling and running the example program:
```console
foo@bar:~$ gcc -D DEBUG -c linked_list.c -o linked_list.o
foo@bar:~$ gcc -c demo.c -o demo.o
foo@bar:~$ gcc linked_list.o demo.o -o demo
foo@bar:~$ ./demo
```

Result:
```
Creating the list
linked_list.c:68:LINKED_LIST_CreateEmptyList()    List allocated successfully @ 0x00662930

Adding the fist element to the list
linked_list.c:315:linked_list_FindNode()    Searching the node whose data = 0x00408024 in list @ 0x00662930
linked_list.c:331:linked_list_FindNode()    Node not found
linked_list.c:292:linked_list_CreateNode()    Allocating node, data = 0x00408024
linked_list.c:306:linked_list_CreateNode()    Node allocated successfully @ 0x00662940
linked_list.c:99:LINKED_LIST_AddNode()    Node added @ list head

Displaying the list
linked_list.c:193:LINKED_LIST_DisplayList()    Displaying list @ 0x00662930
linked_list.c:204:LINKED_LIST_DisplayList()      - Node = 0x00662940 , data = 0x00408024
linked_list.c:205:LINKED_LIST_DisplayList()    End of list

Adding the second element to the list
linked_list.c:315:linked_list_FindNode()    Searching the node whose data = 0x00408028 in list @ 0x00662930
linked_list.c:331:linked_list_FindNode()    Node not found
linked_list.c:292:linked_list_CreateNode()    Allocating node, data = 0x00408028
linked_list.c:306:linked_list_CreateNode()    Node allocated successfully @ 0x00662950
linked_list.c:112:LINKED_LIST_AddNode()    Node added @ the end of the list

Displaying the list
linked_list.c:193:LINKED_LIST_DisplayList()    Displaying list @ 0x00662930
linked_list.c:199:LINKED_LIST_DisplayList()      - Node = 0x00662940 , data = 0x00408024
linked_list.c:204:LINKED_LIST_DisplayList()      - Node = 0x00662950 , data = 0x00408028
linked_list.c:205:LINKED_LIST_DisplayList()    End of list

Reversing the list
linked_list.c:234:LINKED_LIST_ReverseList()    List @ 0x00662930 reversed successfully

Displaying the list
linked_list.c:193:LINKED_LIST_DisplayList()    Displaying list @ 0x00662930
linked_list.c:199:LINKED_LIST_DisplayList()      - Node = 0x00662950 , data = 0x00408028
linked_list.c:204:LINKED_LIST_DisplayList()      - Node = 0x00662940 , data = 0x00408024
linked_list.c:205:LINKED_LIST_DisplayList()    End of list

Adding the third element to the list
linked_list.c:315:linked_list_FindNode()    Searching the node whose data = 0x0040802C in list @ 0x00662930
linked_list.c:331:linked_list_FindNode()    Node not found
linked_list.c:292:linked_list_CreateNode()    Allocating node, data = 0x0040802C
linked_list.c:306:linked_list_CreateNode()    Node allocated successfully @ 0x00662960
linked_list.c:112:LINKED_LIST_AddNode()    Node added @ the end of the list

Iterating the list
Node = 0x00662950, data = 0x00408028
Node = 0x00662940, data = 0x00408024
Node = 0x00662960, data = 0x0040802C

Deleting the node whose content is the variable 'x'
linked_list.c:315:linked_list_FindNode()    Searching the node whose data = 0x00408024 in list @ 0x00662930
linked_list.c:323:linked_list_FindNode()    Node found @ 0x00662940
linked_list.c:282:FREE()    Freeing pointer @ 0x00662940
linked_list.c:154:LINKED_LIST_DeleteNode()    The node whose data = 0x00408024 was removed from list @ 0x00662930

Displaying the list
linked_list.c:193:LINKED_LIST_DisplayList()    Displaying list @ 0x00662930
linked_list.c:199:LINKED_LIST_DisplayList()      - Node = 0x00662950 , data = 0x00408028
linked_list.c:204:LINKED_LIST_DisplayList()      - Node = 0x00662960 , data = 0x0040802C
linked_list.c:205:LINKED_LIST_DisplayList()    End of list

Destroying the list before finishing the program
linked_list.c:258:LINKED_LIST_DestroyList()    Freeing node @ 0x00662950
linked_list.c:282:FREE()    Freeing pointer @ 0x00662950
linked_list.c:258:LINKED_LIST_DestroyList()    Freeing node @ 0x00662960
linked_list.c:282:FREE()    Freeing pointer @ 0x00662960
linked_list.c:266:LINKED_LIST_DestroyList()    Freeing list @ 0x00662930
linked_list.c:282:FREE()    Freeing pointer @ 0x00662930
```


## Todo

Implement the functions `LINKED_LIST_GetSize`, `LINKED_LIST_FindHead`, and `LINKED_LIST_Iterator`.


## License

**TRACES** is licensed under the **MIT license**. See [LICENSE](LICENSE) for further information.
