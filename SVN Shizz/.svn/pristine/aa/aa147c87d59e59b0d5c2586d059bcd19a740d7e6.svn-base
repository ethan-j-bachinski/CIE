/*-------------------------------------------------------------------------------
 * Programmer: YOUR NAME HERE
 * Name: linkedList.h
 * Description: This file contains a structure and associated function
 *              prototypes to model a maze for a robot. A Maze variable
 *              is designed to be initialized through the readMaze function.
 *              After initialization, the robot "sensor" functions can be
 *              called to determine whether a "black" unit is located to the
 *              left, to the right, in front, or directly below the specified
 *              robot. In addition, the maze and the robot can be printed
 *              using the printMazePlusCurrentPos function (using the curses
 *              library).
 * Example use:
 *    Maze maze;
 *    RobotModel robot;
 *    char *inputFileName = argv[1];
 *    int success = readMaze(inputFileName, &maze, &robot);
 *    if (success)
 *    {
 *        int bTL = blackToLeft(maze, robot);
 *        printMazePlusCurrentPos(maze, robot);
 *        ....
 *        clearMaze(&maze);
 *    }
 -------------------------------------------------------------------------------*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/* struct node is used to represent a node in a linked list of chars */
struct node {
    char turn;                 /* value of node */
    struct node * nextPtr;    /* pointer to next node in linked list */
};

typedef struct node Node;       /* Node is now an alias for struct node */
typedef struct node * NodePtr;  /* NodePtr is now an alias for struct node * */


/* prototypes for general linked list functions */
/*-----------------------------------------------------------------------------
 * Function name: appendToEnd
 * Description: This function creates a new node with the given value and
 *              inserts it at the end of the linked list.
 * Input: startPtr = pointer to NodePtr = pointer to the pointer of the first
 *                                        node of the list. The list is
 *                                        assumed to be in ascending order.
 *        value = char = integer value of node to be created/inserted in
 *                      sorted linked list
 * Output: startPtr = pointer to NodePtr = pointer to the pointer of the first
 *                                         node of the list. If a node
 *                                         was inserted at the beginning of
 *                                         the list, the value of *startPtr
 *                                         will have changed.
 ----------------------------------------------------------------------------*/

void appendTurnToEnd(NodePtr *startPtr, char turn);
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
void freeAllMemoryInTurnList(NodePtr *startPtr);
/*-----------------------------------------------------------------------------
 * Function name: copyAndSimplifyTurns
 * Description: This function creates a new linked list by copying
 *              a segment of a specified linked list
 *              (from start to the nth (turns) node)
 * Input:       newPtr = NodePtr* = pointer to pointer to the new list
 *              startPtr = NodePtr = pointer to the linked list of turns
 *              turns = int = the nth node
 ----------------------------------------------------------------------------*/
NodePtr copyAndSimplifyTurnList(NodePtr startPtr, NodePtr endPtr);
/*-----------------------------------------------------------------------------
 * Function name: simplifyTurns
 * Description: This function optimizes the last three nodes of the
 *              specified linked list
 * Input:       startPtr = NodePtr* = pointer to pointer the linked list of turns
 * note: based on code provided in maze-solve.c provided by 3pi
 ----------------------------------------------------------------------------*/
void simplifyTurns(NodePtr *startPtr);

/*-----------------------------------------------------------------------------
 * Function name: stackPush
 ----------------------------------------------------------------------------*/
void stackPush(NodePtr *topPtr, char turn);

/*-----------------------------------------------------------------------------
 * Function name: stackPop
 ----------------------------------------------------------------------------*/
char stackPop(NodePtr *topPtr);
/*-----------------------------------------------------------------------------
 * Function name: length
 ----------------------------------------------------------------------------*/

int lengthTurnList(NodePtr topPtr);
void appendTurnToEnd(NodePtr *startPtr, char turn);
NodePtr giveOptimizedTurnList(NodePtr startPtr, int * deliveries, int nDeliveries);
NodePtr giveTurnPtrAt(NodePtr topPtr,int i);
void concatenateTurnArrays(NodePtr *startPtr, NodePtr inTurns);
int giveAddressPointers(NodePtr topPtr, NodePtr **addressLocations);


#endif // LINKEDLIST_H
