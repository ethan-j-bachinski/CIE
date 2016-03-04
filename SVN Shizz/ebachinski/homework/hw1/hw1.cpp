/*-------------------------------------------------------------------------
 * Programmer: Ethan Bachinski
 * Name: main.cpp
 * Description: This program is the random number guessing game.  First it asks the user to choose an option from the menu.
 * If they choose option one the game will then ask for a player ID.
 * Next, they will play the game guessing the random number.  Each guess they make will be tallied.
 * When they guess the number they will then have a score recorded for their particular ID.
 * Again the menu will pop up asking them to choose an option.
 * If they choose option two it will again ask for a player ID. When they give their ID it will spit out a highscore for that individual player ID.
 * If they have not played any games yet it will pop up an error message saying "no games recorded yet".
 * The menu will pop up again asking them to choose an option.
 * If they choose option 3 they will then be given the overall highscore out of all the player ID's.
 * If no games have been recorded yet there will be an error message saying that no games have been played yet.
 * The menu will pop up again asking them to choose another option.
 * If they choose option 4 it will pop up with the 3 top scores from the game.
 * The menu will pop up again asking them to choose an option.
 * Option 5 is to quit the game.
 ------------------------------------------------------------------------*/
 //Including Libraries to use different commands
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
//Function Prototype to get the best overall score from the game
int getOverallBest(int player_scores[], int n);
int theleaderBoard(int player_scores[],int n);
int main( void )
{
    //Declaring my variables to use throughout my program
    int randomNumber;
    int userNumber;
    int option;
    int playerID=-1;
    int userGuess;
    int player_scores[20];
    int overallScore;
    int leaders1,leaders2,leaders3,ID1,ID2,ID3;
    for(int i=0;i<20;i++)
    {
        player_scores[i]=-1;
    }



    srand( time(NULL) );
    cout << "Welcome to the Number Game!!!"<<endl;

while(option!=5)
{

        randomNumber = rand() % 101;
/* The beginning of the game that will ask the player a few questions and give them some options*/
        cout << "Please choose one of the 3 following options: "<<endl;
        cout<<"1. Play a new game"<<endl;
        cout<<"2. See my high score"<<endl;
        cout<<"3. See overall high score"<<endl;
        cout<<"4. Check out the leaderboard."<<endl;
        cout<<"5. Quit."<<endl;

/* The player enters what option they want for the game*/
        cin>>option;
        //while loop that ensures the user to enter a correct integer for option
        while(option<1 || option>5)
        {
            cout<<"Error, not a valid entry!!!"<<endl;
            cin>>option;
        }
   if(option!=5)
    {
/* Using a switch statement to run through the options*/
        switch(option)
        {
            case 1://Play the game
                cout<<"Please enter player ID. (1 through 20)"<<endl;
                cin>>playerID;
                //ensures that the user enters an ID that is valid
                 while(playerID<1 || playerID>20)
                    {
                        cout<<"Invalid ID entry."<<endl;
                        cin>>playerID;
                    }
                            cout<<"Guess the correct number between 1-100!!!!"<<endl;
                            cout<<"Good Luck!"<<endl;
                            userGuess=0;
                        /* While loop to count the number of guesses by the user*/
                            while(userNumber!=randomNumber)
                            {
                                //cout<<randomNumber;
                                cout<<"Your Guess: ";
                                cin >> userNumber;
                                //ensures the user enters a guess between the given parameters
                                if(userNumber<1 || userNumber>100)
                                {
                                    cout<<"Error not a valid entry, guess again"<<endl;
                                    cout<<"Your Guess: ";
                                    cin>>userNumber;
                                }
                                //gives the user hints about the guess they made
                                if(userNumber>randomNumber)
                                {
                                    cout<<"Your guess is too high."<<endl;
                                    cout<<"Guess lower."<<endl;
                                    userGuess=userGuess+1;
                                }
                                else if(userNumber<randomNumber)
                                {
                                    cout<<"Your guess is too low."<<endl;
                                    cout<<"Guess higher."<<endl;
                                    userGuess=userGuess+1;
                                }
                                else if(userNumber=randomNumber)
                                {
                                    userGuess=userGuess+1;
                                    cout<<"That is correct!"<<endl;
                                    cout<<"Good Job!!!"<<endl;
                                    cout<<"Your score is: "<<userGuess<<endl;
                                    player_scores[playerID]=userGuess;
                                }
                            }
                break;
            case 2://Users best score
                cout<<"Please enter player ID. (1 through 20)"<<endl;
                cin>>playerID;
                //ensures the user enters a valid player ID
                 while(playerID<1 || playerID>20)
                    {
                        cout<<"Invalid ID entry."<<endl;
                        cin>>playerID;
                    }

                            //prints out the individuals highscore
                        if(player_scores[playerID]!=-1)
                        {
                            cout<<"Your highscore is: "<<player_scores[playerID]<<endl;
                        }
                        else
                        {
                            cout<<"No games recorded yet."<<endl;
                        }


                break;
            case 3://Best Score option

                //function call for getOverallBest
                overallScore=getOverallBest(player_scores,20);
                if(overallScore<1)
                {
                    cout<<"No games recorded yet."<<endl;
                }
                else
                    cout<<"The overall high score is: "<<overallScore<<endl;
                break;
           case 4:
                //Function call for the leaderboard function.  This will print out the top three scores in order.
                (leaders1,leaders2,leaders3,ID1,ID2,ID3)=theleaderBoard(player_scores,20);
                if(overallScore!=-1)
                {
                    cout<<"The top 3 scores are: "<<endl;
                    cout<<"1. Player #: "<<ID1<<" Score: "<<leaders1<<endl;
                    cout<<"2. Player #: "<<ID2<<" Score: "<<leaders2<<endl;
                    cout<<"3. Player #: "<<ID3<<" Score: "<<leaders3<<endl;
                }

        }
    }
}
    return 0;
}
/*
    Function definition of the getOverallBest function.
    Returns the best score from the player[] array.
*/
int getOverallBest(int player_scores[],int n)
{
    int overallScore=-1;
    int i;
    for(i=1;i<=n;i++)
    {
        if(player_scores[i]!=-1)
        {
            if(overallScore==-1)
            {
                overallScore=player_scores[i];
            }
            else if(player_scores[i]<overallScore)
            {
                overallScore=player_scores[i];
            }
        }
    }
    return overallScore;
}
/*
Function definition for the leaderboard
returns the top three scores from the player_scores arrays
*/
int theleaderBoard(int player_scores[], int n)
{
    //Declaring variables in the function
    int leaders1,leaders2,leaders3;
    int ID1,ID2,ID3;
    int leaders=-1;
    int ID=-1;
    int i;
    //for loop to cycle through all of the player scores
    for(i=0;i<n;i++)
    {
        //if no previous games have been recorded sets the players score to the score that was just recorded
        if(player_scores[i]!=-1)
        {
            if(leaders==-1)
            {
                leaders=player_scores[i];
                ID=i;
            }
            else if(player_scores[i]<leaders)
            {
                leaders=player_scores[i];
                ID=i;
            }
        }
        //sets players score to a value if the previous score is lower
        else if(player_scores[i]<player_scores[i+1])
        {
            if(leaders==-1)
            {
                leaders=player_scores[i];
                ID=i;
            }
            else if(player_scores[i]<leaders)
            {
                leaders=player_scores[i];
                ID=i;
            }
        }
        //sets player score to a later score if previous score is higher
        else if(player_scores[i+1]<player_scores[i])
        {
            if(leaders==-1)
            {
                leaders=player_scores[i];
                ID=i;
            }
            else if(player_scores[i]<leaders)
            {
                leaders=player_scores[i];
                ID=i;
            }
        }
    }
    //if no games have been recorded yet tells user that no games have been played yet
    if(player_scores[i]==-1)
    {
        cout<<"No games recorded yet."<<endl;
    }
    //sets scores to leaders1 to be returned as top leader board score
    leaders=leaders1;
    ID=ID1;
    //values to be returned
    return leaders1,leaders2,leaders3,ID1,ID2,ID3;
}


