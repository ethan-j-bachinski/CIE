/*-------------------------------------------------------------------------
 * Programmer: Mona K. Garvin
 * Name: main.cpp
 * Description: This file contains examples from lecture 13 on strings
 *              and using const with pointers.
 -------------------------------------------------------------------------*/
#include <iostream>
#include <stdlib.h>
#include <string.h> /* for string functions */
#include <ctype.h>  /* for islower and toupper */
using namespace std;

/* function prototype for function to call strlen functions */
void callStrlen( void );
/* function prototype for function to compute length of string: version 1 */
int myStrlen1(const char *sPtr);
/* function prototype for function to compute length of string: version 2 */
int myStrlen2(const char *sPtr);

/* function prototype for function to call mysteryFunction */
void callMysteryFunction( void );
/* function prototype for 'mystery' string function */
void mysteryFunction(char *s1, char *s2);

/* function prototypes for array modification example */
void arrayModificationExample(void);
void tryToModifyArray(int *arr, int n);
void printArray(int arr[], int arr_size);

/* function prototypes for constant array example */
void constantArrayExample(void);
int computeArraySum(const int * arr, int n);

/* function prototypes for additional string example */
void additionalStringExample( void );
void convertToUpperCase(char *sPtr);

int main(void)
{
    cout << "\ncallStrlen()" << endl ;
    callStrlen();

    //cout << "\ncallMysteryFunction()" << endl ;
    //callMysteryFunction();

    cout << "\narrayModificationExample()" << endl ;
    arrayModificationExample();

    cout << "\nconstantArrayExample()" << endl ;
    constantArrayExample();

    cout << "\nadditionalStringExample()" << endl ;
    additionalStringExample();

    return 0;
}

/* function to call the strlen functions */
void callStrlen( void )
{
    /* define some strings */
    char s1[] = "string 1";
    char s2[] = {'s', 't', 'r', 'i', 'n', 'g', ' ', '2', '\0'};
    char *s3 = "string 3";

    /* print the results of the strlen, myStrlen1, and myStrlen2 functions */
    cout << "strlen(s1) = " << strlen(s1) << " ";
    cout << "myStrlen1(s1) = " << myStrlen1(s1) << " ";
    cout << "myStrlen2(s1) = " << myStrlen2(s1)<< " ";
    cout << endl ;
    cout << "strlen(s2) = " << strlen(s2)<< " ";
    cout << "myStrlen1(s2) = " << myStrlen1(s2)<< " ";
    cout << "myStrlen2(s2) = " << myStrlen2(s2)<< " ";
    cout << endl ;
    cout << "strlen(s3) = " << strlen(s3)<< " ";
    cout << "myStrlen1(s3) = " << myStrlen1(s3)<< " ";
    cout << "myStrlen2(s3) = " << myStrlen2(s3)<< " ";
    cout << endl ;
}

/*-----------------------------------------------------------------------------
 * Function name: myStrlen1
 * Description: This function computes and returns the length of the null-
 *              terminated input string (version 1)
 * Input: sPtr = const char * = input string (constant character array
 *                              with null terminating character '\0')
 * Output: int = length of string up to, but not including, the null
 *               terminating character
 ----------------------------------------------------------------------------*/
int myStrlen1(const char *sPtr)
{
    int length = 0;

    while (*sPtr != '\0')
    {
        length++;
        sPtr++;
    }

    return length;
}

/*-----------------------------------------------------------------------------
 * Function name: myStrlen1
 * Description: This function computes and returns the length of the null-
 *              terminated input string (version 2)
 * Input: sPtr = const char * = input string (constant character array
 *                              with null terminating character '\0')
 * Output: int = length of string up to, but not including, the null
 *               terminating character
 ----------------------------------------------------------------------------*/
int myStrlen2(const char *sPtr)
{
    int length = 0;
    int i = 0;

    while (sPtr[i] != '\0')
    {
        length++;
        i++;
    }

    return length;
}

/* function to call mysteryFunction */
void callMysteryFunction( void )
{
    char s1[100] = "My string 1";
    char s2[100] = "string 2";

    cout << "Before function call:" << endl ;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    mysteryFunction(s1, s2);
    cout << "After function call:" << endl ;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
}

/* mystery function */
void mysteryFunction(char *s1, char *s2)
{
    while ((*s1 = *s2) != '\0')
    {
        s1++;
        s2++;
    }
}

/* array modification example */
void arrayModificationExample(void)
{
    int a[5] = {2, 2, 2, 2, 2};

    printArray(a, 5);
    tryToModifyArray(a, 5);
    printArray(a, 5);
}

/* function that modifies array arr of length n */
void tryToModifyArray(int *arr, int n)
{
    int i;
    for (i=0; i < n; i++)
    {
        arr[i] = arr[i] - 1;
    }
}

/* function to print array arr of length arr_size */
void printArray(int arr[], int arr_size)
{
    int i;
    for (i=0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl ;
}

/* function that calls a function that doesn't need to
   modify an array */
void constantArrayExample(void)
{
    int a[5] = {1, 1, 1, 1, 1};
    int n = 5;
    int sum;

    sum = computeArraySum(a, n);
    printArray(a, n);
    cout << "sum = " << sum << endl;
}

/* function to compute/return sum of elements in
   integer array arr of length n */
int computeArraySum(const int * arr, int n)
{
    int sum = 0;
    int i;

    for (i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum;
}

/* a string example based on Fig. 7.10  */
void additionalStringExample( void )
{
    char string1[] = "a sample string";
    cout << "The original string: "<< string1 << endl;
    convertToUpperCase(string1);
    cout << "The modified string: " << string1 << endl;
}

/* convert string to uppercase letters */
void convertToUpperCase(char *sPtr)
{
    while (*sPtr != '\0')  /* while current character is not '\0' */
    {
        if (islower(*sPtr))  /* if character is lowercase */
        {
            *sPtr = toupper(*sPtr); /* convert to uppercase */
        }
        ++sPtr; /* move sPtr to the next character */
    }
}
