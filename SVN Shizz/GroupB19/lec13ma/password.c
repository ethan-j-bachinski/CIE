/*-----------------------------------------------------------------------------
 * Programmers: Ethan Bachinski & Eric Mensen
 * Name: password.c
 * Description: A 3pi robot program that provides a password "security"
 *              functionality so that the user has to enter the password
 *              correctly to see a secret message. It repeatedly (1) asks the
 *              user for a password (pressing C to end), (2) stores the
 *              password internally based on the pressed buttons, and (3)
 *              compares the password to the one stored internally, displaying
 *              a special message if the password is entered correctly (but
 *              a try again message if it is incorrectly entered).
 * To compile (using provided makefile) on linux:
 * > make
 * To load program onto robot (once usb programmer plugged in and robot on):
 * > make program
 ----------------------------------------------------------------------------*/
#include <pololu/3pi.h>   /* allow use of 3pi robot functions */
#include <string.h>       /* for string functions */

#define MAX_LEN 10        /* define maximum password length */

/* function prototype for battery check */
void bat_check( void );

/* function prototype to print two lines on lcd */
void print_two_lines(const char *line1, const char *line2);

int main( void )
{
    /* define correct password */
    const char correctPassword[] = "AABBA";
    /* define character array to store user password */
    /* add 1 to length for terminating character */
    char userPassword[MAX_LEN+1];

    /* perform battery check */
    bat_check();

    while (1)
    {
		for (int i=0;i < MAX_LEN; i++ )			//Reset the each element in userPassword to \0 each time the loop starts over
		{
			userPassword[i] = '\0'; 
		}
        int done = 0;    /* whether done obtaining password */
        int curPos = 0;  /* current position in password array */

        /* display instructions to user */
        clear(); /* clear the lcd */
        print_two_lines("PRESS C","+PASS +C");

        /* wait for user to press C before reading password */
        wait_for_button(BUTTON_C);

        /* read password, ending when user presses C or maximum length of
           possible password has been exceeded */
        while (!done)
        {
            unsigned char button = wait_for_button(ANY_BUTTON);
            switch (button)
            {
                case BUTTON_A:
                    userPassword[curPos] = 'A';
                    curPos++;
                    break;
                case BUTTON_B:
                    userPassword[curPos] = 'B';
                    curPos++;
                    break;
                case BUTTON_C:
                    done = 1;
                    break;
            }

            if (curPos >= MAX_LEN)
            {
                done = 1;
            }
        }
        /* add terminating null character ('\0') to user password array */
        //userPassword[curPos+1]= '\0';

        /* compare passwords, displaying appropriate message */
		if (strlen(correctPassword) == strlen(userPassword))			//Check is correctPassword and userPassword have the same length
			{
				int ck = 0;
				while (ck == 0)											//While ck is equal to 0
				{
					for (int i = 0; i < strlen(correctPassword);i++)	//For the number of elements in correctPassword
				{
					if (*userPassword == *correctPassword)				//If the ith element in userPassword is equal to the ith element of correctPassword
					{
						ck = ck+1;										//Increment ck by 1
					}
					else
					{
						break;											//If the ith element in userPassword is not equal to the ith element of correctPassword
																		//Break because the password does not match
					}
					
				}
				}
				if (ck == strlen(correctPassword))						//If ck is equal to the string length of correctPassword, all characters match and the
																		//password is correct.  Print "Correct Password"
				{
					print_two_lines("Correct","Password");
					delay_ms(2000);
				}
				else													//If ck is not equal to the length of correctPassword, the characters did not match and the
																		//password is not correct.  Print "Wrong Password"
				{
					print_two_lines("Wrong","Password");
					delay_ms(2000);
					break;
				}
				
			}
		else 															//If correctPassword and userPassword are not the same string length, the passwords do not match
																		//Print "Wrong Password"
			{
				print_two_lines("Wrong","Password");   
				delay_ms(2000);
			}
    }
}

/*-----------------------------------------------------------------------------
 * Function name: bat_check
 * Description: This function checks the voltage on the batteries and
 *              displays a message on the LCD until the user presses B.
 *              The message on the first line cycles between the following:
 *              BAT CHK       [-> descriptive message]
 *              xxxxmV        [-> the battery voltage]
 *              OKAY/REPLACE  [-> whether the batteries should be replaced]
 ----------------------------------------------------------------------------*/
void bat_check( void )
{
    int firstLineType = 0; /* what should be displayed on line 1 */
                           /*  0-19: BAT CHK */
                           /* 20-39: xxxxmV  */
                           /* 40-59: OKAY/REPLACE */
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
         BAT CHK
         xxxxmV
         Okay/Replace */

        if (firstLineType < 20)
        {
            print("BAT CHK");
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
                print("OKAY"); /* okay */
            }
            else
            {
                print("REPLACE"); /* replace */
            }
        }
        firstLineType++;
        firstLineType = firstLineType % 60;

        /* SECOND LINE */
        /* set lcd position to beginning of second line */
        lcd_goto_xy(0,1);
        print("PRESS B");

        /* small delay */
        delay_ms(50);
    }

    /* once pressed, wait a little bit */
    delay_ms(500);
}

/*-----------------------------------------------------------------------------
 * Function name: print_two_lines
 * Description: This function clears the LCD and prints the string given by
 *              line1 on the first line and the string given by line2 on the
 *              second line.
 * Inputs: line1 = const char * = string to be displayed on first line
 *         line2 = const char * = string to be displayed on second line
 ----------------------------------------------------------------------------*/
void print_two_lines(const char *line1, const char *line2)
{
    /* clear lcd */
    clear();

    /* print first line */
    lcd_goto_xy(0,0);
    print(line1);

    /* print second line */
    lcd_goto_xy(0,1);
    print(line2);
}
