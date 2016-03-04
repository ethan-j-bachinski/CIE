/*-----------------------------------------------------------------
 * Programmer: Your name
 * Name: main.cpp
 * Description: This file contains the mini-assignment from lecture 15 on
 *              returning dynamically allocated arrays from
 *              functions.
 -----------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/* function prototype for function to print array */
void printArray(int *arr, int arr_size);

/* function prototypes to copy an array */
int * copyArray(const int *inputArray, int inputArraySize);

/* function prototypes to return a sorted copy of the array */
int * sortArray(const int *inputArray, int inputArraySize);

/* function prototypes to sort an input array; will not create a copy */
void sortArrayOriginal(int *inputArray, int inputArraySize);

/* function prototypes to return an array of a user-defined size */
int * obtainArrayOfUserDefinedSize(int maxSize, int *resultingSize);

/* main function */
int main(void)
{
    int a[] = {3,1,4,2};
    int *ptr = NULL;
    int resultingSize = 0;

    cout << "Original Array " << endl ;
    printArray(a,4);

    /* Mini-assignment: complete copyArray function to create a copy of the input array */
    ptr = copyArray(a,4);

    if (ptr != NULL) {
        cout << "Copied Array " << endl ;
        printArray(ptr,4);
    }
    free(ptr);

    /* practice problem: return sorted version of array */
    ptr = sortArray(a,4);
    if (ptr != NULL) {
        cout << "Sorted copy of the array " << endl ;
        printArray(ptr,4);
    }
    free(ptr);


    cout << "Original Array " << endl ;
    printArray(a,4);

    /* practice problem: return array of user-defined size */
    ptr = obtainArrayOfUserDefinedSize(10, &resultingSize);
    printArray(a,resultingSize);
    free(ptr);


    return 0;
}


/*-----------------------------------------------------------------------------
 * Function name: copyArray
 * Description: This function makes a copy of the inputArray.
 * Inputs: inputArray = pointer to const int = address of the first element of
 *                                             the input array
 *         inputArraySize = int = number of elements of input array
 * Output: pointer to int = pointer to dynamically allocated array that
 *                          is a copy of the inputArray
 ----------------------------------------------------------------------------*/
int * copyArray(const int *inputArray, int inputArraySize)
{
    int * ptr = NULL;

    /* YOUR CODE HERE */

    return ptr;
}


/*-----------------------------------------------------------------------------
 * Function name: sortArray
 * Description: This sorts the input array inputArray so the elements will be
 *              in ascending order in the newly returned array (i.e., from
 *              'smallest' to 'largest')
 * Inputs: inputArray = const int array = input array
 *         inputArraySize = integer = number of elements in the input array
 * Output: pointer to int = pointer to dynamically allocated sorted array
 ----------------------------------------------------------------------------*/
int * sortArray(const int *inputArray, int inputArraySize)
{
    int * ptr = NULL;

    /* YOUR CODE HERE */


    return ptr;
}

/*-----------------------------------------------------------------------------
 * Function name: obtainArrayOfUserDefinedSize
 * Description: This function obtains a desired number of elements from the
 *              user (up to maxSize) and then returns a newly allocated
 *              array with all of the elements initialized to zero.
 * Inputs: maxSize = int = maximum number of elements in returned array
 *         resultingSize = pointer to int = address of integer containing any
 *                                          value (value will be modified in
 *                                          function)
 * Outputs: resultingSize = pointer to int = address of integer containing
 *                                           the resulting size of the newly
 *                                           allocated array
 *          pointer to int = pointer to dynamically allocated array of size
 *                          *resultingSize (with all elements initialized to
 *                           zero)
 ----------------------------------------------------------------------------*/
int * obtainArrayOfUserDefinedSize(int maxSize, int *resultingSize)
{
    int * ptr = NULL;

    /* obtain integer from user between 1 and maxSize to obtain the desired size */
    /* YOUR CODE HERE TO PRINT MESSAGE TO USER */
    /* YOUR CODE HERE TO READ VALUE, SAVING VALUE IN *resultingSize */

    if (*resultingSize >= 1 && *resultingSize <= maxSize)
    {
        /* dynamically allocate array of specified number of elements */
        /* YOUR CODE HERE TO ALLOCATE MEMORY FOR ARRAY, INITIALIZING ALL ELEMENTS TO ZERO */

    }
    else
    {
        cout << "Error: incorrect size entered. Not creating array." << endl ;
    }

    return ptr;
}


/*-----------------------------------------------------------------------------
 * Function name: sortArrayOriginal
 * Description: This sorts the input array inputArray so the elements will be
 *              in ascending order (i.e., from 'smallest' to 'largest')
 * Inputs: inputArray = int array = input array that will become sorted
 *         inputArraySize = integer = number of elements in the input array
 * Output: inputArray = int array = sorted integer array
 ----------------------------------------------------------------------------*/
void sortArrayOriginal(int *inputArray, int inputArraySize)
{
    int j;   /* index of first unsorted value */
    int i;   /* index for while loop through sorted sequence */
    int key; /* key (= first unsorted value) */

    for (j = 1; j < inputArraySize; j++)
    {
        key = inputArray[j];

        /*--------------------------------------
         * insert key into the sorted sequence
         * inputArray[0] to inputArray[j-1]
         *-------------------------------------*/
        i = j - 1;
        while (i >= 0 && inputArray[i] > key)
        {
            inputArray[i+1] = inputArray[i];
            i--;
        }
        inputArray[i+1] = key;
    }
}

/* function to print array arr of length arr_size */
void printArray(int *arr, int arr_size)
{
    int i;
    for (i=0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl ;
}

