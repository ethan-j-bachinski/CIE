/*-----------------------------------------------------------------------------
 * Programmers: Ethan Bachinski and Eric Mensen
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
        /* TODO: YOUR CODE HERE */

        /* compare passwords, displaying appropriate message */
        for(i=0;i>MAX_LEN+1;i++)
        {
            if(userPassword[i]==correctPassword[i])
            {
                cout<<"Passwords match"<<endl;
            }
            else if(userPassword[i]!=correctPassword[i])
            {
                cout<<"Passwords do not match"<<endl;
            }
        }
        print_two_lines("LINE 1","LINE 2");
        delay_ms(2000);
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
