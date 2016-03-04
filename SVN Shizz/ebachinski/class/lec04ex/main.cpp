/*-------------------------------------------------------------------------
 * Programmer: Garvin/Canahuate
 * Name: main.cpp
 * Description: This program implements all of the clicker questions
 *              from lecture 4. A menu is presented to the user for
 *              selecting the function choices. Once the user
 *              selects his/her function choice, the output of the
 *              corresponding function is printed. This process repeats
 *              until the user enters -1.
 -------------------------------------------------------------------------*/
#include <iostream>
#include <stdlib.h>
using namespace std;

/* function prototypes corresponding to clicker questions */
void arithmeticReview();
void ifElseReview();
void whileLoopReview();
void doWhileLoopReview();
void forLoopReview();

int main( void )
{
    int questionChoice; /* stores question/function choice selected by user */
    int done = 0;       /* whether the user is done (0-false, 1-true) */

    /* print menu */
    cout << "Function choices:" << endl ;
    cout << "1: arthimeticReview" << endl ;
    cout << "2: ifElseReview" << endl ;
    cout << "3: whileLoopReview" << endl ;
    cout << "4: doWhileLoopReview" << endl ;
    cout << "5: forLoopReview" << endl ;

    /* while user is not done, ask them to enter a function choice (or -1 to end). Run the
       corresponding function, or indicate that the user is done as appropriate. */
    while (! done)
    {
        cout << endl << "Which function output do you want to see (enter a number between 1 and 5, -1 to end)? ";
        cin >> questionChoice;

        if (questionChoice == -1)
        {
            cout << "Done." << endl ;
            done = 1;
        }
        else if (questionChoice < 1 || questionChoice > 5)
        {
            cout << "Invalid choice. Please try again." << endl ;
        }
        else
        {
            cout << "----------------" << endl ;
            cout << "Function " << questionChoice << ": " << endl;
            switch(questionChoice)
            {
                case 1:
                    cout << "arithmeticReview()" << endl ;
                    arithmeticReview();
                    break;
                case 2:
                    cout << "ifElseReview()" << endl ;
                    ifElseReview();
                    break;
                case 3:
                    cout << "whileLoopReview()" << endl ;
                    whileLoopReview();
                    break;
                case 4:
                    cout << "doWhileLoopReview()" << endl ;
                    doWhileLoopReview();
                    break;
                case 5:
                    cout << "forLoopReview()" << endl ;
                    forLoopReview();
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

void arithmeticReview()
{
    float a_f = 9.0;
    float b_f = 10.0;
    int a_i = 9;
    int b_i = 10;

    cout << a_f/b_f <<" "<< a_i/b_i << " " << b_i%a_i << endl;
}

void ifElseReview()
{
    int x = 3;
    int isY = 1;

    if (x < 2 || !isY)
    {
        cout << "A" << endl ;
    }
    else if (isY && x > 0)
    {
        cout << "B" << endl ;
    }
    else
    {
        cout << "C" << endl ;
    }
}

void whileLoopReview()
{
    int x = 1;
    while (x < 100)
    {
        x = x*2;
    }

    cout << x << endl;
}

void doWhileLoopReview()
{
    int i = 0;
    do
    {
        i = i+5;
    } while (i <= 15);

    cout << i << endl;
}

void forLoopReview()
{
    int i = 0;
    int x = 0;
    for (i = 0; i < 10; i++)
    {
        x = x + 2;
    }

    cout << i <<", " << x << endl;
}