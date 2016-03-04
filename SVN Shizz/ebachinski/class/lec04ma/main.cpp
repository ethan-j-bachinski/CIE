/*-------------------------------------------------------------------------
 * Programmer: Ethan Bachinski
 * Name: main.cpp
 * Description: this program reads a sequence of integers (entered one at a time), keeping track of the number
 * of times a 2 is entered. The program will EITHER
 *    (a) Accept enter 10 number or integers OR
 *    (b) Keep on accepting integers until the user enters a -1 (optional)
 *  Once the sequence has been entered by the user, the total number of 2's will be printed.
 -------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

int main(void)
{
    int number2s = 0;
    int userNumber = 0;
    int i;

    cout << "Please enter sequence of 10 integers: " << endl;



   for(i=0;i<10;i++)
   {
       cin >> userNumber;

       if(userNumber==2)
       {
           number2s=number2s+1;

       }

   }
    cout << "The total number of 2's entered was " << number2s << endl;

}
