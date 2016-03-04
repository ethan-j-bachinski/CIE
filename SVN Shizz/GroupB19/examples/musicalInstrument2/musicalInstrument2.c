/*-----------------------------------------------------------------------------
 * Programmer: Mona K. Garvin
 * Name: musicalInstrument2.c
 * Description: A 3pi robot program to provide a simple musical instrument.
 *              After a battery check, each time any combination of the three 
 *              user buttons is pressed, a note is played.
 *              This is very similar to musicalInstrument1, but a musical 
 *              welcome is NOT played and more notes can be played as all
 *              combinations of the buttons are used. 
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
    /* perform battery check */
    bat_check();
    
    /* 6-note musical instrument */
    /* whenever A, B, or C is pressed, a note is played */
    unsigned char volume = 15;
    clear();
    print("Play!");
    while(1) 
    {
        unsigned char buttons = button_is_pressed(ANY_BUTTON);
        if (buttons == (BUTTON_A | BUTTON_B)) /* A and B pressed */
        {
            play_note(B(3), 10, volume);
        }
        if (buttons == (BUTTON_A)) /* only A pressed */
        {
            play_note(C(4), 10, volume);
        }
        else if (buttons == (BUTTON_B)) /* only B pressed */
        {
            play_note(D(4), 10, volume);
        }
        else if (buttons == (BUTTON_C)) /* only C pressed */
        {
            play_note(E(4), 10, volume);
        }
        else if (buttons == (BUTTON_B | BUTTON_C)) /* B and C pressed */
        {
            play_note(F(4), 10, volume);
        }
        else if (buttons == (BUTTON_A | BUTTON_B | BUTTON_C)) /* A, B, and C pressed */
        {
            play_note(G(4), 10, volume);
        }
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