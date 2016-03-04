/*-----------------------------------------------------------------------------
 * Programmer: Mona K. Garvin 
 * Name: randomNumbers.c
 * Description: A 3pi robot program that displays random numbers between 0-9
 * To compile (using provided makefile) on linux:
 * > make
 * To load program onto robot (once usb programmer plugged in and robot on):
 * > make program
 ----------------------------------------------------------------------------*/
#include <pololu/3pi.h>   /* allow use of 3pi robot functions */
#include <stdlib.h>       /* for random() functions */

/* function prototype for battery check */
void bat_check( void );

int main( void )
{
    /* perform battery check */
    bat_check();
    
    /* display welcome message and  */
    /* seed random number generator */
    clear();
    lcd_goto_xy(0,0);
    print("Welcome!");
    lcd_goto_xy(0,1);
    print("Press B");
    wait_for_button_press(BUTTON_B);   /* button down */
    long seed = 0;
    while(button_is_pressed(BUTTON_B)) /* while button not released */
        seed++;
    srandom(seed);
    
    while(1) 
    {
        clear();
        
        /* obtain random number between 0-9 */
        int val = random() % 10;
        
        /* display number */
        lcd_goto_xy(0,0);
        print_long(val);
        lcd_goto_xy(0,1);
        print("Press B");
        
        /* wait for user to press/release B */
        wait_for_button(BUTTON_B);
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
