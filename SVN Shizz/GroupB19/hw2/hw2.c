/*-----------------------------------------------------------------------------
 * Programmers: Ethan Bachinski & Eric Mensen
 * Name: hw2.c
 * Description: In this program we implemented the number guessing game.
 * We have 3 menu options.  The first is for the user to play a new game,
 * the second is to see the best score for each individual player ID and 
 * the third is to see the best overall score.  When the first or second 
 * option is selected the game will also ask for a player ID to assign a 
 * score to the ID and/ or to spit out the score for the entered ID				
 * To compile (using provided makefile) on linux:
 * > make
 * To load program onto robot (once usb programmer plugged in and robot on):
 * > make program
 ----------------------------------------------------------------------------*/

#include <pololu/3pi.h>   /* allow use of 3pi robot functions */
#include <avr/pgmspace.h> /* allow use of program space */
#include <stdlib.h>       /* for random() functions */


/* function prototype for battery check */
void bat_check( void );
/* function prototype for menuSelect*/
int menuSelect (void);
/* function prototype for readUserInput*/
void readUserInput (int, int, int *);
/* function prototype for getOverallBest*/
void getOverallBest(int , int);


/*Other suggested functions (optional):
getUserScore
playGame
*/

int main( void )
{
	//initializing our parameters
	int player_guess;
	int player_score;
	int player_ID = 1;
	int *ptr2;
	ptr2 = &player_ID;
	int best_scores[20];
	int Overallbest[1][2] = {{0 }};
	/* perform battery check before starting the game */
	bat_check();
	
	
	//Initialize the best scores array to all -1*/
	for (int i = 0; i <= 20; i++)
	{
	best_scores[i] = -1;
	}



		int mingame = 1;   /* the lowest game number */
	    int maxgame = 100; /* the highest game number */
		int minID = 1;     /* the lowest ID number */
		int maxID = 20;    /* the highest ID number */


    while (1)
	{
        clear(); // clear the LCD
        int userOption = menuSelect();
		clear();
		delay_ms(1000);


		switch (userOption)
		{
			case 1:
				//Start player_score and player_guess to their beginning values
				player_guess = 1;
				player_score = 1;
				int *ptr;
				ptr = &player_guess;


				//Call readUserInput function to allow the user to choose their player ID
				readUserInput(minID, maxID, ptr2);

				/* obtain random number between 1-100 */
				clear();
				
				//Seeds the random number for the game
				long seed;
				seed = 0;
				//Prints to start the game for the user
				lcd_goto_xy(0,0);
				print("Press B");
				lcd_goto_xy(0,1);
				print("to start");
				(wait_for_button_press(BUTTON_B));
				
				while(button_is_pressed(BUTTON_B)) /* while button not released */
				{
					seed++;
				}				
				srand(seed);
				int val = 1+ rand() % 100;


				//Set up a while loop there will continue until the user guesses the number
				while (player_guess != val)
				{
					readUserInput(mingame, maxgame,ptr); //Call readUserInput function to allow user to guess
					//Depending on if the player_guess is too high or too low, output hints
					if (player_guess > val)
					{
						//Prints hint to user
						lcd_goto_xy(0,0);
						print("Too high!!");
						player_score++;
						delay_ms(1000);
					}
					else if (player_guess < val)
					{
						//prints hint to user
						lcd_goto_xy(0,0);
						print("Too low!!");
						player_score++;
						delay_ms(1000);
					}

				}
				//Display a sentence based on whether it took more than one guess
				if (player_score > 1)
				{
					//Lets user know that they guessed the correct number
					clear();
					lcd_goto_xy(0,0);
					print("Correct! ");
					lcd_goto_xy(0,1);
					print_long(player_score);
					print(" guesses");
					delay_ms(2000);
				}
				
				else
				{
					clear();
					lcd_goto_xy(0,0);
					print("Correct! ");
					lcd_goto_xy(0,1);
					print("1 guess");
					delay_ms(2000);
				}
				/*Save the latest player_score if it is lower than the current player ID's lowest score or
				if the score is the player ID's first score*/
				if ((best_scores[player_ID] > player_score) || (best_scores[player_ID] == -1))
				{
					best_scores[*ptr2] = player_score;
					if ((player_score < Overallbest[1][2]) || Overallbest[1][2] == 0)
					{
						//Uses pointers directed at the array
						Overallbest[1][2] = player_score;
						Overallbest[1][1] = *ptr2;
					}
				}
				break;

			//Get individual high score
			case 2:
				//Use getplayer_ID to have the user input their player_ID
				readUserInput(minID, maxID, ptr2);
				//Differentiate between not having a score yet and having a current score
				if (best_scores[*ptr2] != -1)
				{
					//Displays "Your best score is (score here)" in sections
				
						clear();
						lcd_goto_xy(0,0);
						print("          Your best score is ");
						print_long(best_scores[*ptr2]);
						lcd_scroll(LCD_LEFT,35,200);
						
					
				}
				else
				{
					//Displays "Sorry, you do not have any scores." in sections
					int firstLineType = 0;
					while (!button_is_pressed(ANY_BUTTON))
					{
						clear();
						lcd_goto_xy(0,0);
						if (firstLineType < 20)
						{
							print("Sorry,     ");
						}
						else if (firstLineType < 40)
						{
							print("no     ");
						}
						else if (firstLineType < 60)
						{
							print("scores    ");
						}
						else if (firstLineType < 80)
						{
							print("set yet.       ");
						}
						firstLineType++;
						firstLineType = firstLineType % 80;
						delay_ms(35);
					}
				}
				break;

			//Get overall best score
			case 3:
				{
					//function call for the get overall best function
					getOverallBest(Overallbest[1][1],Overallbest[1][2]);
				}

 
        clear();

    }
}
}
/*-----------------------------------------------------------------------------
* Function name: menuSelect
* Description:  Allows the user to select from 1 of 3 options.
				Pressing the A button will move left through the options until the first option is reached
				Pressing the B button will move right through the options until the last option is reached
---------------------------------------------------------------------------- */
int menuSelect (void)
{
    int min = 1;   /* the first option */
    int max = 3; /* the last option */

    while (1)
    {
        int done=0;

        /* display message indicating that a menu option should be selected */
        clear();
        lcd_goto_xy(0,0);
        print("SELECT");
        lcd_goto_xy(0,1);
        print(" OPTION ");

        /* wait 1 second */
        delay_ms(1000);

        /* present options to user and obtain user selection */
        int menuOption = 1;
        clear();


        while (!done)
		{
            unsigned char button = button_is_pressed(ANY_BUTTON);
            if (button == BUTTON_A) /* move to prior option */
            {
	            if (menuOption > min) /* if a smaller option available */
	            {
		            menuOption--;
	            }

	            wait_for_button_release(BUTTON_A);
            }
            else if (button == BUTTON_C) /* move to next option */
            {
	            if (menuOption < max) /* if larger option available */
	            {
		            menuOption++;
	            }

	            wait_for_button_release(BUTTON_C);
            }
			//option for player to play a new game
            if (menuOption == 1)
            {
                lcd_goto_xy(0,0);
				print("New Game");
				lcd_goto_xy(0,1);
		        print("<  **  >");
            }
			//Option for the best score for the individual player
            else if (menuOption == 2)
            {

				lcd_goto_xy(0,1);
				print("<  **  >");

				int firstLineType = 0;
				while (!button_is_pressed(ANY_BUTTON))
				{
					//Alternate between displaying "Best" and "Score"
					lcd_goto_xy(0,0);
					if (firstLineType < 20)
					{
						print("Best    ");
					}
					else if (firstLineType < 40)
					{
						print("Score   ");
					}
					firstLineType++;
					firstLineType = firstLineType % 40;
					delay_ms(40);
				}
            }
			//option for the player to see the overall best score
            else if (menuOption == 3)
            {
				lcd_goto_xy(0,1);
				print("<  **  >");

				int firstLineType = 0;
				while (!button_is_pressed(ANY_BUTTON))
				{
					//Alternate between displaying "Overall", "Best" and "Score"
					lcd_goto_xy(0,0);
					if (firstLineType < 20)
					{
						print("Overall    ");
					}
					else if (firstLineType < 40)
					{
						print("Best   ");
					}
					else if (firstLineType < 60)
					{
						print("Score   ");
					}
					firstLineType++;
					firstLineType = firstLineType % 60;
					delay_ms(40);
				}
            }

            while (button_is_pressed(BUTTON_B)) /* move to next option */
            {
                /* user pressed button to select option:
                   now wait for button B to be released */
                wait_for_button_release(BUTTON_B);
                done=1;
            }
        }
            /* display selected option */
            clear();
            return menuOption;

    }
}


/*-----------------------------------------------------------------------------
* Function name: readUserInput
* Description:  This function allows the user to select a number between min and max
*				Pressing or holding the A button will decrease the selection incrementally down to min
*				Pressing or holding the B button will increase the selection incrementally up to max
---------------------------------------------------------------------------- */
void readUserInput (int min, int max, int *currentOption)
{

    
    {
        

        // display message indicating that number should be selected
        if (max > 20)
		{
			//prints instructions for user's guess
			clear();
		    lcd_goto_xy(0,0);
		    print("SELECT");
		    lcd_goto_xy(0,1);
		    print("GUESS");
		}
		else
		{
			//prints instructions for user to enter player ID
			clear();
			lcd_goto_xy(0,0);
			print("SELECT");
			lcd_goto_xy(0,1);
			print("ID NUM");
		}

        // wait 1 second
        delay_ms(1000);

        // present options to user and obtain user selection
        //int currentOption = 1;
        clear();
        lcd_goto_xy(3,0);
        print_long(*currentOption);
        lcd_goto_xy(0,1);
        print("<  **  >");
		
		int done=0;
        while (!done) 
		{
            int delay = 500;
            while (button_is_pressed(BUTTON_A))
            {
                if (*currentOption > min) // if a smaller option available
                {
                  --*currentOption;
                }
                clear();
                lcd_goto_xy(3,0);
                print_long(*currentOption);
                lcd_goto_xy(0,1);
                print("<  **  >");

                delay_ms(delay);
                delay=50;
            }
            while (button_is_pressed(BUTTON_C)) // move to next option
            {
                if (*currentOption < max) // if larger option available
                {
                    ++*currentOption;
                }

                clear();
                lcd_goto_xy(3,0);
                print_long(*currentOption);
                lcd_goto_xy(0,1);
                print("<  **  >");
				//Delay
                delay_ms(delay);
                delay=50;
            }
            while (button_is_pressed(BUTTON_B)) // move to next option
            {
                // user pressed button to select option:
                // now wait for button B to be released
                wait_for_button_release(BUTTON_B);
                done=1;
            }
        }
            // wait .5 seconds
            delay_ms(500);

    }
	
}

/*-----------------------------------------------------------------------------
 * Function name: getOverallBest
 * Description: Returns error message if no games have been played yet.  
				Prints out the player ID and the corresponding score that is the overall best
 ----------------------------------------------------------------------------*/
void getOverallBest(int ID , int score)
{
  if (ID < 1)
  {
	  //If OverallBest is less than one there are no scores stored yet, display accordingly
	  clear();
	  lcd_goto_xy(0,0);
	  print("          Sorry, no scores yet. ");
	  lcd_scroll(LCD_LEFT,35,200);
  }
  else
  {
	  //Display the overall best score if at least one score has been stored
	  clear();
	  lcd_goto_xy(0,0);
	  print("ID: ");
	  print_long(ID);
	  lcd_goto_xy(0,1);
	  print("Score:");
	  print_long(score);
	  delay_ms(2000);
	  

	
  }
}



/*-----------------------------------------------------------------------------
 * Function name: bat_check
 * Description: This function checks the voltage on the batteries and
 *              displays a message on the LCD until the user presses B.
 *              The message on the first line cycles between the following:
 *              Bat Chk       [-> descriptive message]
 *              xxxxmV        [-> the battery voltage]
 *              Okay/Replace  [-> whether the batteries should be replaced]
 ----------------------------------------------------------------------------*/
void bat_check( void )
{
    int firstLineType = 0; /* what should be displayed on line 1 */
                           /*  0-19: Bat Chk */
                           /* 20-39: xxxxmV  */
                           /* 40-59: Okay/Replace */
    int bat = 0;           /* last read battery voltage */

    /* wait for user to press button B */
    while(!button_is_pressed(BUTTON_B))
    {
        /* clear the lcd */
        clear();

        /* FIRST LINE */
        /* set lcd position to beginning of first line */
        lcd_goto_xy(0,0);

        /* for first line, alternate between displaying:
         Bat Check
         xxxxmV
         Okay/Replace */

        if (firstLineType < 20)
        {
            print("Bat Chk");
        }
        else if (firstLineType < 40)
        {
            bat = read_battery_millivolts();
            print_long(bat);
            print("mV");
        }
        else if (firstLineType < 60)
        {
            if (bat >= 4500)
            {
                print("Okay"); /* okay */
            }
            else
            {
                print("Replace"); /* replace */
            }
        }
        firstLineType++;
        firstLineType = firstLineType % 60;

        /* SECOND LINE */
        /* set lcd position to beginning of second line */
        lcd_goto_xy(0,1);
        print("Press B");

        /* small delay */
        delay_ms(50);
    }

    /* once pressed, wait a little bit */
    delay_ms(500);
}
