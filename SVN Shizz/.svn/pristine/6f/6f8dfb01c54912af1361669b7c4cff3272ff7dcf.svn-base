/*-----------------------------------------------------------------------------
 * Programmer: Mona K. Garvin
 * Name: sequenceRepeater.c
 * Description: A 3pi robot program that repeatedly (1) has the user play a 
 *              sequence (of a pre-specified length) of notes using the buttons 
 *              A, B, and C and then (2) plays these notes back to the user.
 * To compile (using provided makefile) on linux:
 * > make
 * To load program onto robot (once usb programmer plugged in and robot on):
 * > make program
 ----------------------------------------------------------------------------*/
#include <pololu/3pi.h>   /* allow use of 3pi robot functions */
#include <stdio.h>	      /* for printf() */

#define SEQUENCE_LEN 5    /* define sequence length */

/* function prototype for battery check */
void bat_check( void );

int main( void )
{
    /* define array to save button sequence */
    unsigned char buttonSequence[SEQUENCE_LEN]; 
    unsigned char volume = 10; /* volume for notes */
    
    /* perform battery check */
    bat_check();
    
    /* initialize use of printf */
    lcd_init_printf();
    
    while (1)
    {
        int i;   /* for-loop counter */
        
        /* display instructions to user */
        clear(); /* clear the lcd */
        printf("PLAY %d\nNOTES", SEQUENCE_LEN);
        
        /* save sequence as user presses/releases buttons */
        for (i=0; i < SEQUENCE_LEN; i++)
        {
            unsigned char button = wait_for_button(ANY_BUTTON);
            buttonSequence[i] = button;
            clear();
            switch (button)
            {
                case BUTTON_A:
                    printf("A");
                    play_note(A(4), 50, volume);
                    break;
                case BUTTON_B:
                    printf("B");
                    play_note(B(4), 50, volume);
                    break;
                case BUTTON_C:
                    printf("C");
                    play_note(C(4), 50, volume);
                    break;
            } /* end switch */
        } /* end for */
        
        /* wait for user to press/release button B for sequence to be repeated */
        clear();
        printf("PRESS B\n");
        wait_for_button(BUTTON_B);
        
        /* play back sequence */
        for (i=0; i < SEQUENCE_LEN; i++)
        {
            unsigned char button = buttonSequence[i];
            clear(); /* clear lcd */
            switch (button)
            {
                case BUTTON_A:
                    printf("A");
                    play_note(A(4), 50, volume);
                    break;
                case BUTTON_B:
                    printf("B");
                    play_note(B(4), 50, volume);
                    break;
                case BUTTON_C:
                    printf("C");
                    play_note(C(4), 50, volume);
                    break;
            } /* end switch */
            
            /* 0.5 s delay */
            delay_ms(500);
        } /* end for */
        
    } /* end infinite while */
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