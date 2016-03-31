/*-------------------------------------------------------------------------------
 * Programmer: Ethan Bachinski
 * Name: main.cpp
 * Description: This program contains in-class examples and the mini-assignment
 *              associated with lecture 24 on stacks/queues.
 *
 *              For the mini-assignment, finish the implementations of the
 *              functions to:
 *              (1) pop a node from a stack (one added line required),
 *              (2) dequeue a node from a queue (four added lines required),
 *              (3) push a node onto a stack (two added lines required), and
 *              (4) enqueue a node into a queue (three added lines required).
 -------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/* struct node is used to represent a node in a linked-list representation
   of a stack or a queue */
struct node {
    int data;              /* integer data value */
    struct node * nextPtr; /* pointer to next node on stack/queue */
};

typedef struct node Node;
typedef Node * NodePtr;

/* function prototype for function associated with the stack example */
void stackExample();
/* function prototype for function associated with the queue example */
void queueExample();

/* function prototype for function to print a linked list */
void printLinkedList(NodePtr startPtr);
/* function prototype for function to test whether linked list is empty */
int isEmpty(NodePtr startPtr);

/* function prototype for function to remove top node from stack
   and return its value */
int stackPop(NodePtr *topPtr);
/* function prototype for function to remove first node from queue
   and return its value */
int queueDequeue(NodePtr *headPtr, NodePtr *tailPtr);

/* function prototype for function to add a node to the top of a stack */
void stackPush(NodePtr *topPtr, int value);
/* function prototype for function to add a node to the beginning of
   a queue */
void queueEnqueue(NodePtr *headPtr, NodePtr *tailPtr, int value);

int main(void)
{
    /* stack example */
    cout << "\n****** STACK EXAMPLE ******" << endl ;
    stackExample();

    /* queue example */
    cout << "\n****** QUEUE EXAMPLE ******" << endl ;
    queueExample();

    return 0;
}

/*-----------------------------------------------------------------------------
 * Function name: stackExample
 * Description: This function demonstrates using push and pop with a stack.
 ----------------------------------------------------------------------------*/
void stackExample()
{
    NodePtr topNodePtr = NULL;
    int value;

    /* add nodes to stack, printing stack after each addition */
    stackPush(&topNodePtr, 2);
    cout << "Stack Push 2" << endl ;
    cout << "Resulting stack: ";
    printLinkedList(topNodePtr);

    stackPush(&topNodePtr, 7);
    cout << "\nStack Push 7" << endl ;
    cout << "Resulting stack: ";
    printLinkedList(topNodePtr);

    stackPush(&topNodePtr, 1);
    cout << "\nStack Push 1" << endl ;
    cout << "Resulting stack: ";
    printLinkedList(topNodePtr);

    stackPush(&topNodePtr, 15);
    cout << "\nStack Push 15" << endl ;
    cout << "Resulting stack: ";
    printLinkedList(topNodePtr);

    /* pop all nodes from stack */
    while (!isEmpty(topNodePtr))
    {
        cout << "\nStack Pop" << endl ;
        cout << "Original stack: ";
        printLinkedList(topNodePtr);
        value = stackPop(&topNodePtr);
        cout << "Returned value: " << value << endl;
        cout << "Remaining stack: ";
        printLinkedList(topNodePtr);
    }
}

/*-----------------------------------------------------------------------------
 * Function name: queueExample
 * Description: This function demonstrates using enqueue and dequeue with a
 *              queue.
 ----------------------------------------------------------------------------*/
void queueExample()
{
    NodePtr headNodePtr = NULL;
    NodePtr tailNodePtr = NULL;
    int value;

    /* add nodes to queue, printing queue after each addition */
    queueEnqueue(&headNodePtr, &tailNodePtr, 2);
    cout << "Queue Enqueue 2" << endl ;
    cout << "Resulting queue: ";
    printLinkedList(headNodePtr);

    queueEnqueue(&headNodePtr, &tailNodePtr, 7);
    cout << "\nQueue Enqueue 7" << endl ;
    cout << "Resulting queue: ";
    printLinkedList(headNodePtr);

    queueEnqueue(&headNodePtr, &tailNodePtr, 1);
    cout << "\nQueue Enqueue 1" << endl ;
    cout << "Resulting queue: ";
    printLinkedList(headNodePtr);

    queueEnqueue(&headNodePtr, &tailNodePtr, 15);
    cout << "\nQueue Enqueue 15" << endl ;
    cout << "Resulting queue: ";
    printLinkedList(headNodePtr);

    /* pop all nodes from stack */
    while (!isEmpty(headNodePtr))
    {
        cout << "\nQueue Dequeue" << endl ;
        cout << "Original queue: ";
        printLinkedList(headNodePtr);
        value = queueDequeue(&headNodePtr, &tailNodePtr);
        cout << "Returned value: " << value << endl;
        cout << "Remaining queue: ";
        printLinkedList(headNodePtr);
    }

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
 * Function name: isEmpty
 * Description: This function tests whether the given linked list is empty.
 * Input: startPtr = NodePtr = pointer to first node of linked list
 * Output: int = 1 if linked list is empty; 0 otherwise
 ----------------------------------------------------------------------------*/
int isEmpty(NodePtr startPtr)
{
    return startPtr == NULL;
}

/*-----------------------------------------------------------------------------
 * Function name: stackPop
 * Description: This function deletes the top node from the stack and returns
 *              its value. The stack is assumed to not be empty.
 * Input: topPtr = pointer to NodePtr = pointer to the pointer of the top
 *                                      of the stack (first node in list).
 * Output: topPtr = pointer to NodePtr = pointer to the pointer of the new
 *                                       first node of the list.
 *         int = returned value of first node in list
 ----------------------------------------------------------------------------*/
int stackPop(NodePtr *topPtr)
{
    int value = 0;
    NodePtr originalTopNodeToDelete;

    if (*topPtr != NULL)
    {
        /* save data member value of top node */
        value = (*topPtr)->data;

        /* save pointer to original top node in the variable originalTopNodeToDelete */
        originalTopNodeToDelete = *topPtr;

        /* modify *topPtr to point to next node */
        *topPtr = (*topPtr)->nextPtr;

        /* free memory for the original top of the stack */
        free(originalTopNodeToDelete);
    }
    else
    {
        cout << "Error. Attempting to pop node from empty stack." << endl ;
    }

    return value;
}

/*-----------------------------------------------------------------------------
 * Function name: queueDequeue
 * Description: This function deletes the head (first) node from the queue and
 *              returns its value. The queue is assumed to not be empty.
 * Input: headPtr = pointer to NodePtr = pointer to the pointer of the head
 *                                       of the queue (first node in list)
 *        tailPtr = pointer to NodePtr = pointer to pointer of the tail of
 *                                       the queue (last node in list)
 * Output: headPtr = pointer to NodePtr = pointer to the pointer of the new
 *                                        head of the queue.
 *         tailPtr = pointer to NodePtr = pointer to the pointer of the new
 *                                        tail of the queue. This will only
 *                                        be modified if the list becomes
 *                                        empty.
 ----------------------------------------------------------------------------*/
int queueDequeue(NodePtr *headPtr, NodePtr *tailPtr)
{
    int value = 0;
    NodePtr originalHeadNodeToDelete;

    if (*headPtr != NULL)
    {
        /* save data member value of head node */
        value = (*headPtr)->data;

        /* save pointer to original head node in the variable originalHeadNodeToDelete */
        originalHeadNodeToDelete = *headPtr;

        /* modify *headPtr to point to next node */
        *headPtr = (*headPtr)->nextPtr;

        /* if list is now empty, need to also set *tailPtr to be NULL */
        if (*headPtr == NULL)
        {
            *tailPtr=NULL;
        }

        /* free memory for the original head of the queue */
        free(originalHeadNodeToDelete);
    }
    else
    {
        cout << "Error. Attempting to dequeue node from empty queue." << endl ;
    }

    return value;
}

/*-----------------------------------------------------------------------------
 * Function name: stackPush
 * Description: This function creates a new node with the given value and
 *              inserts it at the top (i.e., beginning) of the linked list
 *              representation of a stack.
 * Input: topPtr = pointer to NodePtr = pointer to the pointer of the top
 *                                      of the stack (first node in list).
 *        value = int = integer value of node to be created/inserted at the
 *                      top of the stack (i.e., the beginning of the list)
 * Output: topPtr = pointer to NodePtr = pointer to the pointer of the new
 *                                       first node of the list.
 ----------------------------------------------------------------------------*/
void stackPush(NodePtr *topPtr, int value)
{
    NodePtr newNodePtr = NULL;

    /* create new node */
    newNodePtr = (NodePtr) malloc(sizeof(Node));

    /* make new node the top of the stack */
    if (newNodePtr != NULL)
    {
        /* set appropriate member values of newNodePtr */
        /* YOUR CODE HERE TO SET DATA MEMBER VALUE (ONE LINE) */
        newNodePtr->data=value;
        /* YOUR CODE HERE TO SET NEXTPTR MEMBER VALUE (ONE LINE) */
        newNodePtr->nextPtr;


        /* modify *topPtr so that it points to the top of the stack */
        *topPtr = newNodePtr;
    }
    else
    {
        cout << "Error. No memory available to insert " << value << " onto the stack.\n";
    }
}

/*-----------------------------------------------------------------------------
 * Function name: queueEnqueue
 * Description: This function creates a new node with the given value and
 *              inserts it at the tail (i.e., end) of the queue represented
 *              as a linked list.
 * Input: headPtr = pointer to NodePtr = pointer to the pointer of the head
 *                                       of the queue (first node in list)
 *        tailPtr = pointer to NodePtr = pointer to pointer of the tail of
 *                                       the queue (last node in list)
 *        value = int = integer value of node to be created/inserted at the
 *                      tail of the queue (i.e., the end of the list)
 * Output: headPtr = pointer to NodePtr = pointer to the pointer of the new
 *                                        head of the queue. This will
 *                                        only be modified when the original
 *                                        list is empty.
 *         tailPtr = pointer to NodePtr = pointer to the pointer of the new
 *                                        tail of the queue.
 ----------------------------------------------------------------------------*/
void queueEnqueue(NodePtr *headPtr, NodePtr *tailPtr, int value)
{
    NodePtr newNodePtr = NULL;

    /* create new node */
    newNodePtr = (NodePtr) malloc(sizeof(Node));
    /* add the new node to the tail of the queue */
    if (newNodePtr != NULL)
    {

        /* set appropriate member values of newNodePtr */
        /* YOUR CODE HERE TO SET DATA MEMBER VALUE (ONE LINE) */
         newNodePtr->data=value;
        /* YOUR CODE HERE TO SET NEXTPTR MEMBER VALUE (ONE LINE) */
         newNodePtr->nextPtr;
        /* make the nextPtr of the current tail pointer point to the new node */
        if(*tailPtr != NULL) /* if a node exists in the list */
        {
            (*tailPtr)->nextPtr = newNodePtr;
        }

        /* make *tailPtr point to the new node */
        *tailPtr = newNodePtr;

        /*  if queue was previously empty, modify *headPtr to also point to the new node */
        if (*headPtr == NULL)
        {
            *headPtr = newNodePtr;
        }

    }
    else
    {
        cout << "Error. No memory available to insert " << value << " into the queue.\n" ;
    }

}


