/*-----------------------------------------------------------------------------
 * Programmers: Mona K. Garvin
 * Name: numberSelection.c
 * Description: Example program to (repeatedly) have the user select a number 
 *              from 1-10. Once the number is selected, it is displayed.
 * To compile (using provided makefile) on linux:
 * > make
 * To load program onto robot (once usb programmer plugged in and robot on):
 * > make program
 ----------------------------------------------------------------------------*/

#include <pololu/3pi.h>   /* allow use of 3pi robot functions */
#include <avr/pgmspace.h> /* allow use of program space */

/* function prototype for battery check */
void bat_check( void );

int main( void )
{
    int lowOption = 1;   /* the first option */
    int highOption = 10; /* the last option */
    
    /* perform battery check */
    bat_check();
    clear();

    while (1)
    {
        /* display message indicating that number should be selected */
        clear();
        lcd_goto_xy(0,0);
        print("SELECT");
        lcd_goto_xy(0,1);
        print(" NUM");
        
        /* wait 1 second */
        delay_ms(1000);
        
        /* present options to user and obtain user selection */
        int currentOption = 1;
        while (! button_is_pressed(BUTTON_B)) /* wait until user presses B to make selection */
        {
            clear();
            lcd_goto_xy(3,0);
            print_long(currentOption);
            lcd_goto_xy(0,1);
            print("<  **  >");
            
            unsigned char button = button_is_pressed(ANY_BUTTON);
            if (button == BUTTON_A) /* move to prior option */
            {
                if (currentOption > lowOption) /* if a smaller option available */
                {
                    currentOption--;
                }
                
                wait_for_button_release(BUTTON_A);
            }
            else if (button == BUTTON_C) /* move to next option */
            {
                if (currentOption < highOption) /* if larger option available */
                {
                    currentOption++;
                }
                
                wait_for_button_release(BUTTON_C);
            }

            /* add small delay */
            delay_ms(50);
            
        }
        
        /* user pressed button to select option:
           now wait for button B to be released */
        wait_for_button_release(BUTTON_B);
        
        /* display selected option */
        clear();
        lcd_goto_xy(0,0);
        print("NUM = ");
        print_long(currentOption);
        
        /* wait 2 seconds */
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

