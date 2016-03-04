/*-------------------------------------------------------------------------
 * Programmer: Mona K. Garvin
 * Name: main.c
 * Description: This file contains examples from lecture 11 over the
 *              similarities of pointers and arrays.
 -------------------------------------------------------------------------*/
#include <iostream>
#include <stdlib.h>
using namespace std;

/* function prototype for first example */
void subscriptsWithPointers(void);

/* function prototypes for clicker questions */
void clickerQuestion1(void);
void clickerQuestion2(void);
void clickerQuestion3(void);

/* function prototypes for additional "clicker" question */
void additionalClickerQuestion1(void);
void additionalClickerQuestion2(void);
void addTwoToAllElements(int *a, int n);
void swap(int *a, int *b);
void additionalClickerQuestion3(void);
void setAllToZero(int *a, int n);

int main(void)
{
    /* first example */
    cout << "subscriptsWithPointers(): " << endl ;
    subscriptsWithPointers();

    /* first set of clicker questions */
    cout << "\nCQ 1: " << endl ;
    clickerQuestion1();
    cout << "\nCQ 2: " << endl ;
    clickerQuestion2();
    cout << "\nCQ 3: " << endl ;
    clickerQuestion3();

    /* additional "clicker" questions */
    cout << "\nAdditional CQ 1: " << endl ;
    additionalClickerQuestion1();
    cout << "\nAdditional CQ 2: " << endl ;
    additionalClickerQuestion2();
    cout << "\nAdditional CQ 3: " << endl ;
    additionalClickerQuestion3();

    return 0;
}

void subscriptsWithPointers(void)
{
    int a[5] = {1, 2, 3, 4, 5};
    int *p;
    int i;

    p = a;
    /* use pointer to modify elements of array */
    for (i = 0; i < 5; i++)
    {
        p[i] = p[i] + 1;
    }
    /* print array */
    for (i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl ;
}

void clickerQuestion1(void)
{
    /*
    int a[3] = {1, 2, 3};
    int b = 5;
    int *p1 = NULL;
    int *p2 = NULL;

    p1 = a;
    p2 = &b;

    p1[1] = *p2;
    b = 2;
    p2[0] = 7;

    cout << a[0] << " " << a[1] << " " << a[2] << " " << b << endl;
    */
}

void clickerQuestion2(void)
{
    /*
    int c[5] = {0};
    int *p;
    int i;

    p = &(c[1]);

    for (i = 0; i < 3; i++)
    {
        p[i] = 1;
    }

    for (i = 0; i < 5; i++)
    {
        cout << c[i] << " " ;
    }
    cout << endl ;
    */
}


void clickerQuestion3(void)
{
    /*
    int a[5] = {1, 2, 3};
    int i;

    for (i = 0; i < 5; i++)
    {
        cout << i[a] << " " ;
    }
    cout << endl ;
    */
}

void additionalClickerQuestion1(void)
{
    /*
    int a[3] = {2, 2, 2};
    int *ptr = NULL;

    ptr = a;
    ptr++;

    *ptr = *ptr + 2;

    cout << a[0] << " " << a[1] << " " << a[2] << endl;
    */
}

void additionalClickerQuestion2(void)
{
    int h[5] = {9, 10, 11, 12, 13};
    int n = 5;

    //addTwoToAllElements(&h, n);
    //swap(&(h[3]), &(h[4]));

    //addTwoToAllElements(h, n);
    //swap(&(h[3]), &(h[4]));

    //addTwoToAllElements(&h, n);
    //swap(h[3], h[4]);

    //addTwoToAllElements(h, n);
    //swap(h[3], h[4]);

    cout << h[3] << " " << h[4] << endl;
}

void addTwoToAllElements(int *a, int n)
{
    int i;
    for (i=0; i < n; i++)
    {
        a[i] += 2;
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void additionalClickerQuestion3(void)
{
    int arr[6] = {2, 2, 2, 2, 2, 2};
    int i;

    //setAllToZero(&arr, 3);
    //setAllToZero(arr, 3);
    //setAllToZero(&arr[3], 3);
    //setAllToZero(arr[3], 3);
    //setAllToZero(&arr, 6);
    //setAllToZero(arr, 6);
    //setAllToZero(&arr[3], 6);
    //setAllToZero(arr[3], 6);

    for (i=0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl ;
}

void setAllToZero(int *a, int n)
{
    int i;
    for (i=0; i < n; i++)
    {
        a[i] = 0;
    }
}


