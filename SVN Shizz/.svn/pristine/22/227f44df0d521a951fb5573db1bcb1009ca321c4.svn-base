/*-------------------------------------------------------------------------------
 * Programmer: Eric Mensen & Ethan Bachinski
 * Name: turnList.c
 * Description: This program implements a turns linked list and helper functions
 *              for the mail delivery robot. The first function that we had to write was the appendTurnToEnd which took a value &
 *              added it to the end of the linked list.  The next function was the freeAllMemoryInTurnArray which frees all the
 *              memory in a linked list and then sets the first pointer equal to NULL. After that we wrote the lengthTurnList
 *              which counted the number of turns that the robot made through the maze.  Next we giveAddressPointers takes in the
 *              length of the array and will count the U-turns made by the robot and increment them as an address.  Then as soon
 *              as we finished that we moved on to the concatenateTurnArrays function which concatenated two arrays.  Or if you
 *              did not know what that meant like myself it means link two arrays together by taking the butt end of one and
 *              attaching it to the beginning of the next list.  Next we built the giveOptimizedTurnList which creates a new
 *              optimal turns list to visit the delivery addresses specified by deliveries. It removed visits to stations
 *              not specified our delivery list. Then after that my partner and I went on to write the copyAndSimplifyTurnList
 *              function which creates a copy of a new linked list and takes a segment of it.  Those are all of the function that
 *              we had to write.  We were given the simplifyTurns function which looks super complicated. BOOM!!!!!!!!!!!
 *
  -------------------------------------------------------------------------------*/
#include "turnList.h"
#include <stddef.h>
#include <stdlib.h>
/*-----------------------------------------------------------------------------
 * Function name: appendTurnToEnd
 * Description: This function creates a new node with the given value and
 *              inserts it at the end of the linked list.
 * Input: topPtr = pointer to NodePtr = pointer to the pointer of the first
 *                                        node of the list. The list is
 *                                        assumed to be in ascending order.
 *        value = char = integer value of node to be created/inserted in
 *                      sorted linked list
 * Output: topPtr = pointer to NodePtr = pointer to the pointer of the first
 *                                         node of the list. If a node
 *                                         was inserted at the beginning of
 *                                         the list, the value of *startPtr
 *                                         will have changed.
 ----------------------------------------------------------------------------*/
void appendTurnToEnd(NodePtr *topPtr, char turn)
{
    NodePtr newNodePtr; /* will point to newly created node */
    NodePtr beforeNodePtr, afterNodePtr;

    /* dynamically allocate memory for new node */
    newNodePtr = (NodePtr) malloc(sizeof(Node));

    /* insert node in list */
    newNodePtr->turn = turn;
    newNodePtr->nextPtr = NULL;

    /* determine where node should be inserted    */
    /* by defining beforeNodePtr and afterNodePtr */
    beforeNodePtr = NULL;
    afterNodePtr = *topPtr;
    while (afterNodePtr != NULL)
    {
        beforeNodePtr = afterNodePtr;
        afterNodePtr = afterNodePtr->nextPtr;
    }

    /* case 1: insert at beginning of list (beforeNodePtr is still NULL) */
    if (beforeNodePtr == NULL)
    {
        newNodePtr->nextPtr = *topPtr; /* set link to prior start */
        *topPtr = newNodePtr;       /* set new value for the topPtr */
    }
    else /* case 2: insert in middle or at end of list */
    {
        beforeNodePtr->nextPtr = newNodePtr;
        newNodePtr->nextPtr = afterNodePtr;
    }

}

/*-----------------------------------------------------------------------------
 * Function name: freeAllMemoryInTurnArray
 * Description: This function frees all the memory in a linked list and
 *              sets the start pointer to be equal to NULL. All
 *              nodes in the linked list must have been dynamically allocated.
 * Input: topPtr = NodePtr * = pointer to pointer to the first node of linked
 *                               list
 * Output: topPtr = NodePtr * = modification of the startPtr so that it
 *                                equals NULL to indicate an empty list
 ----------------------------------------------------------------------------*/
void freeAllMemoryInTurnList(NodePtr *topPtr)
{
    //declares new variables in our structure
    NodePtr tmpPtr, currentPtr;
    //sets our current pointer to the pointer of the first node of our linked list
    currentPtr = *topPtr;
    //while loop to check if the current pointer is Null or not
    while (currentPtr != NULL)
    {
        tmpPtr = currentPtr;              /* keep a pointer to the node to be deleted */
        currentPtr = currentPtr->nextPtr; /* before memory for the node is freed, obtain a pointer to the next node */

        free(tmpPtr);                     /* free memory for the node */
    }

    /* indicate that the list is empty */
    *topPtr = NULL;

}

/*-----------------------------------------------------------------------------
 * Function name: lengthTurnList
 * Description: This function returns the length of the turns list
 * Input: topPtr = NodePtr = pointer to the first node of linked
 *                               list
 * Output: length = int = number of elements in the linked list
 ----------------------------------------------------------------------------*/
int lengthTurnList(NodePtr topPtr)
{
        // Set up a variable to store the current pointer being used
        NodePtr currentPtr;
        // Initialize a variable to store length of the list
        int length=0;
        // Set current pointer to the first location, which is the input pointer
        currentPtr = topPtr;
        // If the current pointer is NULL the list is empty
        if (currentPtr == NULL)
        {
            length = 0; // Set length to 0
        }
        else
        {
            // While the current pointer is not NULL
            while (currentPtr != NULL)
            {
                currentPtr = currentPtr->nextPtr;   // Set the current pointer to the next pointer location
                length++;                           // Increment length
            }
        }
        return length;

}

/*-----------------------------------------------------------------------------
 * Function name: giveAddressPointers
 * Description: This function returns the locations of the U turns in the array
 * Input: topPtr = NodePtr = pointer to the first node of linked
 *                               list
 *         addressLocations = NodePtr** = pointer to pointer to nodes of a linked list
 * Output: addressLocations = NodePtr** = modification of addressLocations such that
 *                                        it points to a dynamically allocated array of
 *                                        NodePtr; each entry in the array points to the
 *                                        node with U turns in the linked list. See first figure
 *                                        in description
 * Output: length = int = number of elements in the linked list
 ----------------------------------------------------------------------------*/
int giveAddressPointers(NodePtr topPtr, NodePtr **addressLocations)
{
    NodePtr addressPtr = topPtr;    // Create node pointer addressPtr to store the addresses of the U turns
    int nAddresses = 0;             // Initialize a variable to store the number of addresses found
    *addressLocations = NULL;       // sets *addressLocations to NULL
    int nActions = 0;               // initialize a variable nActions to 0
    while(topPtr != NULL)           // While our list is not empty
    {
        if (topPtr->turn == 'U')    // if the turn is an address which is also a 'U'
        {
            nAddresses++;           // Increments the number of addresses
        }
        topPtr = (topPtr)->nextPtr; //resets the topPtr to the next pointer
    }
    *addressLocations = (NodePtr*) malloc(sizeof(Node)*nAddresses); //allocating some memory dynamically!
    topPtr = addressPtr;            // sets topPtr to addressPtr
     while(topPtr != NULL)          // While the topPtr is not NULL
    {
        if (topPtr->turn == 'U')    // If our turn is equal to a 'U' which is our addresses
        {
            (*addressLocations)[nActions] = topPtr; //sets the addressLocations array for each action equal to our topPtr
            nActions++;             // Incrementing out actions
        }
        topPtr = (topPtr)->nextPtr; // Sets our topPtr to the next pointer
    }

    return (nAddresses); // does not count the last U turn.
}


/*-----------------------------------------------------------------------------
 * Function name: concatenateTurnArrays
 * Description: Concatenate two turn arrays
 * Input: topPtr = pointer to the pointer of the first
 *                                         list.
 *        inTurns  = pointer to the second list.
 * Input: topPtr = pointer to the pointer of the first list; the second list is
 *                 added to the end of the first list pointed by topPtr.
 ----------------------------------------------------------------------------*/
void concatenateTurnArrays(NodePtr *topPtr, NodePtr inTurns)
{
    NodePtr TmpPtr = *topPtr;       // A temporary pointer set to our topPtr
    int done = 0;                   // variable for the while loop
    if(*topPtr == NULL)             // if our topPtr is NULL
    {
        *topPtr = inTurns;          // Set our topPtr to inTurns
    }
    else
    {
        while(!done)                // While not done
        {
            if((TmpPtr)->nextPtr == NULL)   //If our temporary pointers next pointer is NULL
            {
                ((TmpPtr)->nextPtr) = inTurns;  //Set the next pointer of our temporary pointer to inTurns
                done = 1;                   // Set done to 1
            }
            TmpPtr = (TmpPtr)->nextPtr;     //Sets the temporary pointer that we are at to the next pointer of our TmpPtr
        }
    }


}

/*-----------------------------------------------------------------------------
 * Function name: giveOptimizedTurnList
 * Description: This function creates a new optimal turns list to visit the delivery
 * addresses specified by deliveries. It will remove visits to stations not specified
 * in the delivery list. See the second figure in the description for the details. This
 * function should call copyAndSimplifyTurnList on segments of the turnslist and concatenates
 * the resulting arrays.
 *
 * Input:       topPtr = NodePtr = pointer to the list of turns
 *              deliveries = int* = pointer to the list of deliveries
 *              nDeliveries = int = the number of deliveries (length of deliveries
 *                                  array
 ----------------------------------------------------------------------------*/

NodePtr giveOptimizedTurnList(NodePtr topPtr, int * deliveries,int nDeliveries)
{
    NodePtr optPtr = NULL, opt_list;    // Creating new pointer in our node
    NodePtr startPtr = topPtr;          //Setting startPtr to topPtr
    NodePtr endPtr;                     // Creating an end pointer
    NodePtr *addresslocations;          // Creating a pointer
    int num_addresses = giveAddressPointers(topPtr, &addresslocations); //setting our number of addresses to the give address function
    int i;                              // Initializing a variable for our loop
    opt_list = copyAndSimplifyTurnList(topPtr,addresslocations[deliveries[0]]); //setting our opt_list to copy&simplify
    concatenateTurnArrays(&optPtr, opt_list);   //Linking our first linked list
    for(i=1; i<nDeliveries; i++)            //For loop from 1 to <nDeliveries
    {
        startPtr = addresslocations[deliveries[i-1]]->nextPtr;  //startPtr to the addresslocations array next pointer
        endPtr = addresslocations[deliveries[i]];           //setting endPtr to the addresslocations array pointer
        opt_list = copyAndSimplifyTurnList(startPtr, endPtr);   //Opt_list to copy&simplify
        concatenateTurnArrays(&optPtr, opt_list);           //linking the lists
    }
    opt_list = copyAndSimplifyTurnList(addresslocations[deliveries[i-1]]->nextPtr, addresslocations[num_addresses-1]);  //opt_list to copy&simplify
    concatenateTurnArrays(&optPtr, opt_list);   //linking the lists
    return(optPtr);

}


/*-----------------------------------------------------------------------------
 * Function name: copyAndSimplifyTurnList
 * Description: This function creates a new linked list by copying
 *              a segment of a specified linked list
 *              (from startPtr to endPtr) and simplifies it
 *              by removing the visits to the intermediate stations
 * Input:       startPtr = NodePtr = pointer to the new list
 *              endPtr = NodePtr = pointer to the last turn in the list
 * Output:      simplifiedPtr = NodePtr = pointer to the simplified list
 ----------------------------------------------------------------------------*/
NodePtr copyAndSimplifyTurnList(NodePtr startPtr, NodePtr endPtr)
{
    NodePtr simplifiedPtr = NULL; //sets pointer to NULL
    NodePtr TmpPtr = startPtr;      // Temporary pointer to start pointer

    while(TmpPtr != (endPtr)->nextPtr && TmpPtr != NULL)    //while loop
    {
        appendTurnToEnd((&simplifiedPtr),(TmpPtr->turn));   //calls append functioin

        simplifyTurns(&simplifiedPtr);      //calls simplify turns function

        TmpPtr = TmpPtr->nextPtr;           // sets Temporary pointer to the next pointer of the tmpptr
    }


    return(simplifiedPtr); //GIVEN


}
/*-----------------------------------------------------------------------------
 * Function name: simplifyTurns
 * Description: This function optimizes the last three nodes of the
 *              specified linked list
 *              For example, it will update the list SSLUL to SSS
 *              Note that it will not simplify the list if U is not the second last
 *              turn. For example, if called with SLULSS, the result will be SLULSS.
 * Input:       startPtr = NodePtr* = pointer to pointer the linked list of input turns
 * Output:      startPtr = NodePtr* = pointer to pointer the linked list of output turns

 * note: based on code provided in maze-solve.c provided by 3pi
 ----------------------------------------------------------------------------*/


void simplifyTurns(NodePtr *startPtr)
{
    NodePtr endPtr=*startPtr;     // pointer to the last node
    NodePtr endMinusOnePtr=NULL;  // pointer to the second last node
    NodePtr endMinusTwoPtr=NULL;  // pointer to the node before the second last node

    char character;

    int total_angle;

    if (*startPtr==NULL) {  // EMPTY LIST; do nothing
        return;
    }

    while (endPtr->nextPtr != NULL)
    {
        endMinusTwoPtr = endMinusOnePtr;
        endMinusOnePtr = endPtr;
        endPtr = endPtr->nextPtr;
    }

    // If size <3 or second last element is not U, return;

    if(endMinusTwoPtr==NULL || endMinusOnePtr->turn != 'U')
        return;
    else
    {   // logic from maze-solve.c

        total_angle = 0;
        character = endMinusTwoPtr->turn;
        total_angle += (character=='R')*90 + (character=='L')*270 + (character=='U')*180;
        character = endMinusOnePtr->turn;
        total_angle += (character=='R')*90 + (character=='L')*270 + (character=='U')*180;
        character = endPtr->turn;
        total_angle += (character=='R')*90 + (character=='L')*270 + (character=='U')*180;
        total_angle = total_angle % 360;

        switch(total_angle)
        {
            case 0:
                endMinusTwoPtr->turn = 'S';
                break;
            case 90:
                endMinusTwoPtr->turn = 'R';
                break;
            case 180:
                endMinusTwoPtr->turn = 'U';
                break;
            case 270:
                endMinusTwoPtr->turn = 'L';
                break;
        }
        free(endPtr);
        free(endMinusOnePtr);
        endMinusTwoPtr->nextPtr = NULL;
    }
}


