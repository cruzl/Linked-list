#include "src/linked_list.h"

typedef struct {
    int a;
} SOME_STRUCT_t;

typedef enum {
    ELEMENT_1
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

    printf( "\r\nAdding the variable 'x' to the list\r\n" );
    LINKED_LIST_AddNode( list , ( void * )&x );

    printf( "\r\nDisplaying the list\r\n" );
    LINKED_LIST_DisplayList( list );

    printf( "\r\nAdding the variable 'y' to the list\r\n" );
    LINKED_LIST_AddNode( list , ( void * )&y );

    printf( "\r\nDisplaying the list\r\n" );
    LINKED_LIST_DisplayList( list );

    printf( "\r\nReversing the list\r\n" );
    LINKED_LIST_ReverseList( list );

    printf( "\r\nDisplaying the list\r\n" );
    LINKED_LIST_DisplayList( list );

    printf( "\r\nAdding the variable 'z' to the list\r\n" );
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
