/*-----------------------------------------------------------------
 * Programmer: Mona K. Garvin/Guadalupe Canahuate
 * Name: main.cpp
 * Description: This file contains examples from lecture 15 on
 *              returning dynamically allocated arrays from
 *              functions.
 -----------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/* function prototype for function to print array */
void printArray(int *arr, int arr_size);

/* function prototypes for clicker question 1 */
void optionA(void);
int * getNew3DPointOptionA(void);
void optionB(void);
void getNew3DPointOptionB(int **ptr2ptr);

/* function prototypes for clicker questions 2 and 3 */
void optionAMod(void);
int * getNew3DPointOptionAMod(void);
void optionBMod(void);
void getNew3DPointOptionBMod(int **ptr2ptr);
void doSomething(void);


/* main function */
int main(void)
{
    /* clicker question 1 */
    //cout << "\n\noptionA(): " << endl ;
    //optionA();
    //cout << "\n\noptionB(): " << endl ;
    //optionB();

    /* clicker question 2 */
    cout << "\n\noptionAMod(): " << endl ;
    optionAMod();

    /* clicker question 3 */
    cout << "\n\noptionBMod(): " << endl ;
    optionBMod();

    return 0;
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

/* function associated with clicker question 1 - option A */
void optionA(void)
{
    int *ptr;
    ptr = getNew3DPointOptionA();
    printArray(ptr, 3);
    doSomething();
    printArray(ptr, 3);
}

/* helper function associated with option A */
int * getNew3DPointOptionA(void)
{
    int point[3] = {-1, -2, -3};
    int *ptr = point;
    return ptr;
}

/* function associated with clicker question 1 - option B */
void optionB(void)
{
    int *ptr;

    getNew3DPointOptionB(&ptr);
    printArray(ptr, 3);
    doSomething();
    printArray(ptr, 3);
}

/* helper function associated with option B */
void getNew3DPointOptionB(int **ptr2ptr)
{
    int point[3] = {-1, -2, -3};
    *ptr2ptr = point;
}

/* function associated with clicker question 2 */
void optionAMod(void)
{
    int *ptr = NULL;

    ptr = getNew3DPointOptionAMod();

    if (ptr != NULL)
    {
        printArray(ptr, 3);
        doSomething();
        printArray(ptr, 3);

        free(ptr);
    }
}

/* helper function associated for clicker question 2 */
int * getNew3DPointOptionAMod(void)
{
     /* TODO: CHANGE CODE TO RETURN POINTER TO DYNAMICALLY ALLOCATED ARRAY */
    /* OLD 'BAD' CODE:
    int point[3] = {-1, -2, -3};
    int *ptr = point;
    return ptr;
    */

    int *ptr = NULL;
    /* YOUR CODE HERE */

    return ptr;
}

/* function associated with clicker question 3 */
void optionBMod(void)
{
    int *ptr = NULL;

    getNew3DPointOptionBMod(&ptr);

    if (ptr != NULL)
    {
        printArray(ptr, 3);
        doSomething();
        printArray(ptr, 3);

        free(ptr);
    }
}

/* helper function for clicker question 3 */
void getNew3DPointOptionBMod(int **ptr2ptr)
{
    /* TODO: CHANGE CODE TO SET *ptr2ptr TO POINT TO DYNAMICALLY ALLOCATED ARRAY */
    /* OLD 'BAD' CODE:
    int point[3] = {-1, -2, -3};
    *ptr2ptr = point;
    */

    /* YOUR CODE HERE */
}

/* helper function associated with clicker questions 3 and 4 */
void doSomething(void)
{
    int a[10] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
}



