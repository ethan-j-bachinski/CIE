/*-----------------------------------------------------------------------------
 * Programmer: Mona K. Garvin
 * Name: musicalInstrument1.c
 * Description: A 3pi robot program to provide a simple musical instrument.
 *              After a battery check and musical welcome, each time one of 
 *              the three user buttons is pressed, a note is played.
 * To compile (using provided makefile) on linux:
 * > make
 * To load program onto robot (once usb programmer plugged in and robot on):
 * > make program
 ----------------------------------------------------------------------------*/
#include <pololu/3pi.h>   /* allow use of 3pi robot functions */
#include <avr/pgmspace.h> /* allow use of program space */

/* first part of On Iowa! stored in program space */ 
const char onIowa[] PROGMEM = "T500>d-2r8>d-r16>d-r16>d-r16>d-r16>d>d>d>d>d>dr8r8r8 >d-2r8>d-r16>d-r16>d-r16>d-r16>f>f>f>f>f>fr8r8r8>f>f>fr16r16r16>e>e>er16r16r16>e->e->e-r16r16r16>d>d>dr16r16r16 >d->d->d->d->d->d-r8r8r8>c>c>cr16r16r16b-b-b-r16r16r16a-a-r8b-r16>c>cr8b-r16a-a-a-a-a-a-r8r8r8";

/* function prototype for battery check */
void bat_check( void );

int main( void )
{
    /* perform battery check */
    bat_check();
    
    /* play first part of On Iowa! */
    /* and wait for music to finish */
    clear(); /* clear the lcd */
    print("On Iowa!");
    play_from_program_space(onIowa);
    while(is_playing());
    
    /* 3-note musical instrument */
    /* whenever A, B, or C is pressed, a note is played */
    unsigned char volume = 15;
    clear();
    print("Play!");
    while(1) 
    {
        unsigned char buttons = button_is_pressed(ANY_BUTTON);
        if (buttons == (BUTTON_A)) /* button A is pressed */
        {
            play_note(C(4), 10, volume);
        }
        else if (buttons == (BUTTON_B)) /* button B is pressed */
        {
            play_note(D(4), 10, volume);
        }
        else if (buttons == (BUTTON_C)) /* button C is pressed */
        {
            play_note(E(4), 10, volume);
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