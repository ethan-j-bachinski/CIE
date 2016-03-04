/*-----------------------------------------------------------------------------
 * Programmer: Mona K. Garvin/Guadalupe Canahuate
 * Name: main.cpp
 * Description: This program contains examples associated with
 *              lecture 6 on arrays.
 -----------------------------------------------------------------------------*/
#include <iostream>
#include <stdlib.h>
using namespace std;

/* function prototype for first array clicker question */
void doSomething();

/* function prototype second array clicker question */
void doSomething2();

/* function prototype for helper function associated with doSomething2 */
int obtainArraySum(int arr[], int arr_size);

int main( void )
{
    /* first clicker question */
    //doSomething();

    /* second clicker question */
    //doSomething2();

    return 0;
}

/* first array clicker question */
void doSomething()
{
    int hist[5] = {0};
    int num_bins = 5;
    int indices[10] = {0, 0, 2, 3, 3, 3, 3, 4, 4, 4};
    int num_indices = 10;
    int i;

    for (i=0; i < num_indices; i++)
    {
        hist[indices[i]]++;
    }

    for (i=0; i < num_bins; i++)
    {
        cout << hist[i] << " ";
    }
    cout << endl;
}


/* function used for second clicker question */
void doSomething2()
{
    int a[3] = {2, 2, 2};
    int n = 3;
    int sum;

    sum = obtainArraySum(a, n);

    cout << sum << " " << a[0] << " " << a[1] << " " << a[2] << endl;
}

/* helper function used as part of the second clicker question */
int obtainArraySum(int arr[], int arr_size)
{
    int i;
    for (i=1; i < arr_size; i++)
    {
        arr[i] = arr[i] + arr[i-1];
    }

    return arr[arr_size - 1];
}
