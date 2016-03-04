/*-----------------------------------------------------------------------------
 * Programmer: Ethan Bachinski
 * Name: main.cpp
 * Description: This program contains the mini-assignment associated with
 *              lecture 6 on arrays. For the mini-assignment, the
 *              implementation of the function
 *              int findMinArrayValue(int arr[], int n)
 *              needs to be completed.
 -----------------------------------------------------------------------------*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* prototype for function to print array */
void printArray(int arr[], int n);

/* prototype for function to return minimum value in array */
int findMinArrayValue(int arr[], int n);

int main( void )
{
    int a1[10] = {4, 6, 3, 8, 9, 6, 8, 2, 7, 11};
    int size_a1 = 10;
    int a2[15] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size_a2 = 15;
    int a3[7] = {4, 5, 0, 2, 99, 23, 3};
    int size_a3 = 7;

    /* display a1 and its minimum value */
    cout<<"a1 = ";
    printArray(a1, size_a1);
    cout << "The minimum value in array a1 is "<< findMinArrayValue(a1,size_a1) << "." << endl ;
    /* display a2 and its minimum value */
    cout<<"a2 = ";
    printArray(a2, size_a2);
    cout << "The minimum value in array a2 is "<<findMinArrayValue(a2,size_a2)<< "." << endl ;
    /* display a3 and its minimum value */
    cout<<"a3 = ";
    printArray(a3, size_a3);
    cout << "The minimum value in array a3 is "<< findMinArrayValue(a3,size_a3)<< "." << endl ;

    return 0;
}



/*-----------------------------------------------------------------------------
 * Function name: printArray
 * Description: This function prints the given input array, printing a new line
 *              every 10 values
 * Inputs: arr = integer array = input array
 *         n = integer = number of elements in the input array
 ----------------------------------------------------------------------------*/
void printArray(int arr[], int n)
{
    int i;
    for (i=0; i < n; i++)
    {
        if (i % 10 == 0) /* begin new line every 10 values */
        {
            cout << endl;
        }
        cout << arr[i] << " ";
    }
    cout << endl;
}


/*-----------------------------------------------------------------------------
 * Function name: findMinArrayValue
 * Description: This function returns the minimum element of an input array
 * Inputs: arr = integer array = input array
 *         n = integer = number of elements in the input array (must be > 0)
 * Output: the minimum element in the array (as an integer)
 ----------------------------------------------------------------------------*/
int findMinArrayValue(int arr[], int n)
{
    int minVal = -1; /* will store the minimum value */
    int i;           /* index to be used in for loop */

    if (n > 0)
    {
        minVal=arr[i];
        for(i=0;i<n;i++)
        {

            if(arr[i]<minVal)
            {
                minVal=arr[i];
            }

        }

    }
    else
    {
        cout << "Error: findMinArrayValue function called with an array size <= 0" << endl;
    }

    return minVal;
}
