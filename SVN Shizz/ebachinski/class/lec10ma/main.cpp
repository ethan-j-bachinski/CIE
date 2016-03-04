/*---------------------------------------------------------------
 * Programmer: Ethan Bachinski
 * Name: main.cpp
 * Description: This file contains the implementation of the
 *              mini-assignment associated with lecture 10.
 *              The program must:
 *              - contain/call a function that uses simulated
 *                pass-by-reference to modify the value of two
 *                input integers
 *              - contain/call a function that modifies an
 *                input array, but so that the input parameter
 *                is declared using a pointer
 ---------------------------------------------------------------*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void change2ints(int *val,int *val2);
void setArray(int *arr,int arrSize, int newValue);
int main(void)
{

    int x=1, y=3,i;
    int *ptr=&x;
    int *ptr2=&y;
    int arrSize=5, newValue;
    int arr[5]={1,2,3,4,5};
    cout<<"Original x= "<<x<<endl<<"Original y= "<<y<<endl;
    cout<<"Original array= "<<arr[0]<<","<<arr[1]<<","<<arr[2]<<","<<arr[3]<<","<<arr[4]<<endl;
    change2ints(&x,&y);
    setArray(arr,arrSize,newValue);
    cout<<"x= "<<x<<endl<<"y= "<<y<<endl;
    cout<<"Array value= "<<arr[0]<<","<<arr[1]<<","<<arr[2]<<","<<arr[3]<<","<<arr[4]<<endl;
    return 0;
}
void change2ints(int *val, int *val2)
{
    *val=*val+2;
    *val2=*val2+5;
}
void setArray(int *arr, int arrSize, int newValue)
{
    int NewValue=8;
    for(int i=0; i<arrSize;i++)
    {
        arr[i]=NewValue;
    }

}
