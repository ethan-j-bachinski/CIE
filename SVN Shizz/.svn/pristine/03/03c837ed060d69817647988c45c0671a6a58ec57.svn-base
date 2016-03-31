/*------------------------------------------------------------------------------
 * Programmer:
 * Name: testTurnList.c
 -------------------------------------------------------------------------------*/
#include <iostream>
#include <string.h>
#include "turnList.h"        /* linked list functions */

void testMode1();
void testMode3();

using namespace std;
void printTurnList(NodePtr startPtr);

int main( void )
{

    testMode1();
    testMode3();

}

// TESTING PART 1 TURNLIST FUNCTIONS
//-------------------------------------
void testMode1()
{
    char turnArray[] = "SLULSSLLURLSSLULSSU";

    NodePtr turnList = NULL;

    for (int i=0; i<strlen(turnArray); i++) {
        appendTurnToEnd(&turnList, turnArray[i]);
    }

    // TESTING PART 1 TURNLIST FUNCTIONS
    //-------------------------------------

    cout<<"*********TESTING PART 1********************"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout << " length of Array: " << (unsigned)strlen(turnArray)<<endl;
    cout << " length of Turns: " << lengthTurnList(turnList) <<endl;
    cout << "Both should be the same "<<endl;
    cout<<"---------------------------------------------------------"<<endl;


    cout << "Array:"<<turnArray<< endl;
    cout << "List: ";
    printTurnList(turnList);
    cout<<"Verify if the array and List is the same" << endl;
    cout<<"---------------------------------------------------------"<<endl;

    NodePtr *addressPointerLocations;
    int naddresses =  giveAddressPointers(turnList, &addressPointerLocations);
    cout << "Found "<<naddresses << " addresses (U Turns)"<<endl;
    cout << "Should be 4" << endl;
    cout<<"---------------------------------------------------------"<<endl;

    int i;
    for (i=0; i<naddresses; i++) {
        cout << "Length of the turn list from the address "<< i << " is "<< lengthTurnList(addressPointerLocations[i])<<endl;
    }
    cout << "It should be 17, 11, 5, 1"<< endl;
    cout<<"---------------------------------------------------------"<<endl;


    cout << "Freeing memory "<<endl;
    freeAllMemoryInTurnList(&turnList);
    cout << "Length of Turns: " << lengthTurnList(turnList) <<endl;
    cout << "Should be zero "<<endl;
    cout<<"---------------------------------------------------------"<<endl;

    cout<<"Concatenation"<<endl;
    char turnArray1[] = "SLU";
    NodePtr turnList1 = NULL;

    for (int i=0; i<strlen(turnArray1); i++) {
        appendTurnToEnd(&turnList1, turnArray1[i]);
    }
    char turnArray2[] = "SSSS";
    NodePtr turnList2 = NULL;

    for (int i=0; i<strlen(turnArray2); i++) {
        appendTurnToEnd(&turnList2, turnArray2[i]);
    }

    cout << "length of Turns1: " << lengthTurnList(turnList1) <<endl;
    cout << "length of Turns2: " << lengthTurnList(turnList2) <<endl;
    cout << "List1: ";
    printTurnList(turnList1);
    cout << "List2: ";
    printTurnList(turnList2);

    concatenateTurnArrays(&turnList1,turnList2);
    cout << " length of Turns1 after concatenation: " << lengthTurnList(turnList1) <<endl;
    cout << "List1 after concatenation: ";
    printTurnList(turnList1);
    cout<<"---------------------------------------------------------"<<endl;

    freeAllMemoryInTurnList(&turnList1);

    // No need to free turnList2; all the nodes are freed when turnList1 is freed

    cout<<"********* PART 1 TEST DONE ********************"<<endl;
}



// TESTING PART 3 TURNLIST FUNCTIONS
//-------------------------------------
void testMode3()
{

    char turnArray[] = "SLULSSLLURLSSLULSSU";
    NodePtr turnList = NULL;

    for (int i=0; i<strlen(turnArray); i++) {
        appendTurnToEnd(&turnList, turnArray[i]);
    }




    cout<<endl<<endl<<"*********TESTING PART 3********************"<<endl;
    cout << "Initial List: ";
    printTurnList(turnList);
    cout<<endl<<endl;
    cout<<"-------------------------------------------------"<<endl;

    int deliveries[] = {0,1,2};
    int nDeliveries = 1;

    NodePtr optList1 = giveOptimizedTurnList(turnList, deliveries,nDeliveries);
    cout << "Optimized List:           ";
    printTurnList(optList1);
    cout<<" Verify if the output is: S L U L S S S S S S S S U" << endl;
    cout<<"-------------------------------------------------"<<endl;


    /* Output should be the following */
    /*S L U L S S S S S S S S U*/

    nDeliveries = 2;
    NodePtr optList2 = giveOptimizedTurnList(turnList, deliveries,nDeliveries);
    cout << "Optimized List:           ";
    printTurnList(optList2);
    cout<<" Verify if the output is: S L U L S S L L U R L S S S S S U" << endl;
    cout<<"-------------------------------------------------"<<endl;


    /* Output should be the following */
    /* S L U L S S L L U R L S S S S S U*/

    nDeliveries = 3;
    NodePtr optList3 = giveOptimizedTurnList(turnList, deliveries,nDeliveries);
    cout << "Optimized List:           ";
    printTurnList(optList3);
    cout<<" Verify if the output is: S L U L S S L L U R L S S L U L S S U" << endl;
    cout<<"-------------------------------------------------"<<endl;

    /* Output should be the following */
    /*S L U L S S L L U R L S S L U L S S U*/

    freeAllMemoryInTurnList(&turnList);
    freeAllMemoryInTurnList(&optList1);
    freeAllMemoryInTurnList(&optList2);
    freeAllMemoryInTurnList(&optList3);

    cout<<"********* PART 3 TEST DONE ********************"<<endl;

}
/*-----------------------------------------------------------------------------
 * Function name: printTurnList
 * Description: This function prints all of the values in a linked list.
 * Input: startPtr = NodePtr = pointer to first node of linked list
 ----------------------------------------------------------------------------*/
void printTurnList(NodePtr startPtr)
{
    NodePtr currentPtr;
    for (currentPtr = startPtr; currentPtr != NULL; currentPtr = currentPtr->nextPtr)
    {
        cout << currentPtr->turn<< " ";
    }
    cout << endl;
}

