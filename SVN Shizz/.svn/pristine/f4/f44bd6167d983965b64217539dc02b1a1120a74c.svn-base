/*-----------------------------------------------------------------
 * Programmer: Mona K. Garvin
 * Name: main.cpp
 * Description: This file contains examples from lecture 14 on
 *              dynamically allocated arrays.
 -----------------------------------------------------------------*/
#include <iostream>
#include <stdlib.h>
using namespace std;

/* function prototype for initial example */
void dynamicallyAllocatedArrayExample(void);

/* function prototype for in-class practice */
void dynamicallyAllocatedArrayPractice(void);

/* function prototype for sizeof example */
void sizeofExample(void);

/* function prototype for function to print array */
void printArray(int *arr, int arr_size);

/* main function */
int main(void)
{
    /* call function containing initial example */
    cout << "\ndynamicallyAllocatedArrayExample()" << endl ;
    dynamicallyAllocatedArrayExample();

    /* call function containing practice code */
    cout << "\ndynamicallyAllocatedArrayPractice()" << endl ;
    dynamicallyAllocatedArrayPractice();

    /* call function containing sizeof example */
    cout << "\nsizeofExample()" << endl ;
    sizeofExample();

    return 0;
}

/* function to provide initial example of
   creating/using a dynamically allocated array */
void dynamicallyAllocatedArrayExample(void)
{
    int *arr;
    int i;

    /* allocate space for 10 integer values */
    arr = (int *) malloc(10 * sizeof(int));

    if (arr != NULL)
    {
        /* initialize all values to zero */
        for (i = 0; i < 10; i++)
        {
            arr[i] = 0;
        }

        /* modify select values using different syntax examples */
        *arr = 5;       /* set first int (element 0) to 5 */
        arr[1] = 3;     /* set second int (element 1) to 3 */
        *(arr + 4) = 1; /* set fifth int (element 4) to 1 */

        /* display all values */
        printArray(arr, 10);

        /* free memory */
        free(arr);
    }
    else
    {
        cout << "Error: unable to allocate memory." << endl ;
    }
}

/* function to practice creating/using
   a dynamically allocated array */
void dynamicallyAllocatedArrayPractice(void)
{
    int *arr = NULL;
    int numElements = 0;
    int i;

    while (numElements < 5 || numElements > 10)
    {
        cout << "Please enter a number from 5-10: ";
        cin >> numElements;
    }

    /* dynamically allocate an array with numElements */
    /* YOUR CODE HERE */


    if (arr != NULL)
    {
        /* obtain values for array from user */
        for (i = 0; i < numElements; i++)
        {
            cout << "Enter value for array element "<< i <<": ";
            /* YOUR CODE HERE TO READ THE ELEMENT */
        }

       /* print array */
       printArray(arr, numElements);

       /* free memory */
       /* YOUR CODE HERE */
    }
}

/* function to illustrate use of sizeof */
void sizeofExample(void)
{
    char c;
    short s;
    int i;
    long l;
    float f;
    double d;
    long double ld;
    int array[20];
    int *ptr = array;

    cout << "     sizeof c = "<< (int) sizeof c << "\tsizeof(char) = "<< (int) sizeof(char) << endl <<
           "     sizeof s = "<<(int) sizeof s << "\tsizeof(short) = " << (int) sizeof(short)<< endl <<
           "     sizeof i = "<< (int) sizeof i << "\tsizeof(int) = " << (int) sizeof(int) << endl <<
           "     sizeof l = "<< (int) sizeof l << "\tsizeof(long) = " << (int) sizeof(long) << endl <<
           "     sizeof f = "<< (int) sizeof f << "\tsizeof(float) = " << (int) sizeof(float)<< endl <<
           "     sizeof d = "<< (int) sizeof d << "\tsizeof(double) = " << (int) sizeof(double)<< endl <<
           "    sizeof ld = "<< (int) sizeof ld << "\tsizeof(long double) = " << (int) sizeof(long double) << endl <<
           " sizeof array = "<< (int) sizeof array << endl <<
           "   sizeof ptr = "<< (int) sizeof ptr << endl ;

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

