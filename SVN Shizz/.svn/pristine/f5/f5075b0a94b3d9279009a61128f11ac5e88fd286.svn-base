/*-------------------------------------------------------------------------
 * Programmer: Ethan Bachinski
 * Name: main.cpp
 * Description: This example program is for the mini-assignment associated
 *              with lecture 2 (on using svn). It provides a menu
 *              with two options: (1) print name, and (2) compute x*x.
 *              For the mini-assignment, you must modify the code
 *              associated with the "print name" option so that your name
 *              is printed rather than YOUR NAME HERE. You must also
 *              replace "Your Name Here" with your name.
 -------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

int main( void )
{
    int userMenuChoice; /* stores menu choice selected by user */
    int done = 0;       /* whether the user is done (0-false, 1-true) */
    float x = 0;        /* stores value of x (entered by user for option 2) */

    while (done != 1)
    {
        /* print menu */
        cout << endl <<"---------------" << endl;
       	cout << "1: print name" << endl;
        cout << "2: compute x*x" << endl;
        cout << "---------------" << endl;

        /* request choice from user */
        cout << "Please select a choice (or -1 to end): ";
        cin >> userMenuChoice ;

        /*  run code based on user choice */
        if (userMenuChoice == 1) /* print name */
        {
           	cout <<"My name is Ethan Bachinski." << endl;
        }
        else if (userMenuChoice == 2) /* compute x*x */
        {
            cout << "Please enter a value for x: ";
            cin >> x;
            cout << "x*x = "<< x*x << endl;
        }
        else if (userMenuChoice == -1) /* exit */
        {
            done = 1;
        }
        else /* invalid choice */
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

