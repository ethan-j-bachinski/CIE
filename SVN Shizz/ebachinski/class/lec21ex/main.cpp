/*-------------------------------------------------------------------------------
 * Programmer: Mona K. Garvin
 * Name: main.cpp
 * Description: This program contains in-class examples associated with
 *              class on lecture 21 on creating and inserting nodes into linked
 *              lists.
 -------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/* struct node is used to represent a node in a linked list of integers */
struct node {
    int data;                 /* value of node */
    struct node * nextPtr;    /* pointer to next node in linked list */
};

typedef struct node Node;       /* Node is now an alias for struct node */
typedef struct node * NodePtr;  /* NodePtr is now an alias for struct node * */

/* prototype for function to display all values in a linked list */
void printLinkedList(NodePtr startPtr);

/* prototypes for functions dealing with linked list creation */
void createListWithoutDynamicMemory(void);
void createListWithDynamicMemory(void);

/* prototype for function to free memory associated with linked list */
void freeAllMemoryInLinkedList(NodePtr *startPtr);

int main(void)
{
    /* call function to illustrate creating a list
       without dynamic memory allocation */
    cout << "createListWithoutDynamicMemory():" << endl ;
    createListWithoutDynamicMemory();

    /* call function to illustrate creating a list
       with dynamic memory allocation */
    cout << "\ncreateListWithDynamicMemory():" << endl ;
    createListWithDynamicMemory();

    return 0;
}

/*-----------------------------------------------------------------------------
 * Function name: printLinkedList
 * Description: This function prints all of the values in a linked list.
 * Input: startPtr = NodePtr = pointer to first node of linked list
 ----------------------------------------------------------------------------*/
void printLinkedList(NodePtr startPtr)
{
    NodePtr currentPtr;
    for (currentPtr = startPtr; currentPtr != NULL; currentPtr = currentPtr->nextPtr)
    {
        cout << currentPtr->data << " ";
    }
    cout << endl ;
}

/*-----------------------------------------------------------------------------
 * Function name: createListWithoutDynamicMemory
 * Description: This function creates/prints a linked list without using
 *              dynamic memory allocation. It is similar to the example used
 *              in the last class, but is NOT the standard way linked lists
 *              are created.
 ----------------------------------------------------------------------------*/
void createListWithoutDynamicMemory(void)
{
    /* create nodes */
    Node n1, n2, n3, n4, n5;
    NodePtr startPtr = NULL; /* equivalent to writing struct node *startPtr */

    /* set start of list as n1 */
    startPtr = &n1;

    /* put data in nodes and link nodes */
    n1.data = 3;
    n1.nextPtr = &n2;

    n2.data = 15;
    n2.nextPtr = &n3;

    n3.data = 19;
    n3.nextPtr = &n4;

    n4.data = 25;
    n4.nextPtr = &n5;

    n5.data = 33;
    n5.nextPtr = NULL;

    /* print linked list */
    printLinkedList(startPtr);
}

/*-----------------------------------------------------------------------------
 * Function name: createListWithDynamicMemory
 * Description: This function creates/prints a linked list that was created
 *              by dynamically creating each node.
 ----------------------------------------------------------------------------*/
void createListWithDynamicMemory(void)
{
    NodePtr startPtr = NULL;
    NodePtr currentPtr = NULL;

    /*--------------------------------------------------------------
       Dynamically allocate memory for all nodes, linking
       them together as we go. To make the concepts of this
       example cleaner, we are not checking if NULL is returned
       from malloc and thus are assuming memory can be
       sucessfully allocated in each case. However, it is good
       practice to check the possibility that NULL may be returned
       from malloc.
    --------------------------------------------------------------*/

    /* dynamically allocate memory for first node,
       make currentPtr refer to this node, and
       set data value through currentPtr */
    startPtr = (NodePtr) malloc(sizeof(Node));
    currentPtr = startPtr; /* use currentPtr to refer to current node */
    currentPtr->data = 3;

     /* dynamically allocate memory for second node,
       make currentPtr refer to this node, and
       set data value through currentPtr */
    currentPtr->nextPtr = (NodePtr) malloc(sizeof(Node));
    currentPtr = currentPtr->nextPtr;
    currentPtr->data = 15;

    /* dynamically allocate memory for third node,
       make currentPtr refer to this node, and
       set data value through currentPtr */
    currentPtr->nextPtr = (NodePtr) malloc(sizeof(Node));
    currentPtr = currentPtr->nextPtr;
    currentPtr->data = 19;

    /* dynamically allocate memory for fourth node,
       make currentPtr refer to this node, and
       set data value through currentPtr */
    currentPtr->nextPtr = (NodePtr) malloc(sizeof(Node));
    currentPtr = currentPtr->nextPtr;
    currentPtr->data = 25;

    /* dynamically allocate memory for fifth node,
       make currentPtr refer to this node, and
       set data value through currentPtr */
    currentPtr->nextPtr = (NodePtr) malloc(sizeof(Node));
    currentPtr = currentPtr->nextPtr;
    currentPtr->data = 33;

    /* set the fifth node as the end of the list */
    currentPtr->nextPtr = NULL;

    /* print linked list */
    printLinkedList(startPtr);

    /* free all memory in the linked list */
    freeAllMemoryInLinkedList(&startPtr);
}

/*-----------------------------------------------------------------------------
 * Function name: freeAllMemoryInLinkedList
 * Description: This function frees all the memory in a linked list and
 *              sets the start pointer to be equal to NULL. All
 *              nodes in the linked list must have been dynamically allocated.
 * Input: startPtr = NodePtr * = pointer to pointer to the first node of linked
 *                               list
 * Output: startPtr = NodePtr * = modification of the startPtr so that it
 *                                equals NULL to indicate an empty list
 ----------------------------------------------------------------------------*/
void freeAllMemoryInLinkedList(NodePtr *startPtr)
{
    NodePtr tmpPtr, currentPtr;
    currentPtr = *startPtr;

    while (currentPtr != NULL)
    {
        tmpPtr = currentPtr;              /* keep a pointer to the node to be deleted */
        currentPtr = currentPtr->nextPtr; /* before memory for the node is freed, obtain a pointer to the next node */

        free(tmpPtr);                     /* free memory for the node */
    }

    /* indicate that the list is empty */
    *startPtr = NULL;
}
