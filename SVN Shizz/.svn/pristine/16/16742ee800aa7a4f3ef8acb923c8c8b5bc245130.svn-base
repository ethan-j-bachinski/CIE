/*-------------------------------------------------------------------------
 * Programmer: Mona K. Garvin
 * Name: main.cpp
 * Description: This program implements two of the clicker questions
 *              from lecture 5. A menu is presented to the user for
 *              selecting the function choices. Once the user
 *              selects his/her function choice, the output of the
 *              corresponding function is printed. This process repeats
 *              until the user enters -1.
 -------------------------------------------------------------------------*/
#include <iostream>
#include <stdlib.h>
using namespace std;

/* function prototypes corresponding to clicker questions */
void functionsByValueReview();
void functionsBySimulatedReferenceReview();

/* helper function prototypes called by some of the clicker questions */
int mysteryFunction1(int val1, int val2);
int mysteryFunction2(int *val1, int *val2);

int main( void )
{
    int questionChoice; /* stores question/function choice selected by user */
    int done = 0;       /* whether the user is done (0-false, 1-true) */

    /* print menu */
    cout << "Function choices:" << endl ;
    cout << "1: functionsByValueReview" << endl ;
    cout << "2: functionsByReferenceReview" << endl ;

    /* while user is not done, ask them to enter a function choice (or -1 to end). Run the
       corresponding function, or indicate that the user is done as appropriate. */
    while (! done)
    {
        cout << "\nWhich function output do you want to see (enter 1 or 2, -1 to end)? ";
        cin >> questionChoice;

        if (questionChoice == -1)
        {
            cout << "Done." << endl ;
            done = 1;
        }
        else if (questionChoice < 1 || questionChoice > 2)
        {
            cout << "Invalid choice. Please try again." << endl ;
        }
        else
        {
            cout << "----------------" << endl ;
            cout << "Function "<< questionChoice <<": "<< endl ;
            switch(questionChoice)
            {
                case 1:
                    cout << "functionsByValueReview()" << endl ;
                    functionsByValueReview();
                    break;
                case 2:
                    cout << "functionsBySimulatedReferenceReview()" << endl ;
                    functionsBySimulatedReferenceReview();
                    break;
                default: /* default is not necessary, but provided for syntax review */
                    cout << "Reached default case." << endl ;
                    break;
            }
            cout << "----------------" << endl ;
        }
    }

    return 0;
}

void functionsByValueReview()
{
    int a = 1;
    int b = 2;
    int c = 0;

    c = mysteryFunction1(a,b);

    cout << a << ", " << b << ", " << c << endl;
}

int mysteryFunction1(int val1, int val2)
{
    val1 = val1*2;
    val2 = val2+2;

    return val1+val2;
}

void functionsBySimulatedReferenceReview()
{
    int a = 1;
    int b = 2;
    int c = 0;

    c = mysteryFunction2(&a,&b);

    cout << a << ", " << b << ", " << c << endl;
}

int mysteryFunction2(int *val1, int *val2)
{
    *val1 = *val1*2;
    *val2 = *val2+2;

    return *val1+*val2;
}
