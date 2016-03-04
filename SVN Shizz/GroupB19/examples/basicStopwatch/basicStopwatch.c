/*-----------------------------------------------------------------------------
 * Programmer: Mona K. Garvin 
 * Name: basicStopwatch.c
 * Description: A 3pi robot program to provide a basic stopwatch (adapted
 *              from the 3pi demo program). Button C starts/stops the stopwatch
 *              and button A resets it. As the timer runs, a beep sounds
 *              every second. In addition, a beep sounds when button A or 
 *              button C is pressed. 
 * To compile (using provided makefile) on linux:
 * > make
 * To load program onto robot (once usb programmer plugged in and robot on):
 * > make program
 ----------------------------------------------------------------------------*/
#include <pololu/3pi.h>   /* allow use of 3pi robot functions */
#include <avr/pgmspace.h> /* allow use of program space */

/* function prototype for battery check */
void bat_check( void );

/* simple tunes */
const char beep_button_a[] PROGMEM = "!c32";
const char beep_button_c[] PROGMEM = "!g32";
const char timer_tick[] PROGMEM = "!v8>>c32";

int main( void )
{
    long elapsed_time = 0;    /* the elapsed time (in ms) on the timer */
    long last_read_time = 0;  /* the most recently read computer time (in ms) */
    int is_ticking = 0;       /* whether we are in a timing mode */
    int a_is_pressed = 0;     /* whether button A has been pressed */
    int c_is_pressed = 0;     /* whether button C has been pressed */
    int seconds = 0;          /* the current seconds value */
    int last_seconds = 0;     /* the prior seconds value */
    
    /* perform battery check before going into stopwatch mode */
    bat_check();
    
    /* clear lcd to prepare for displaying time on upper row */
    clear();
    lcd_goto_xy(0,0);
    
    while(1) 
    {
        /* update current time (and elapsed time if currently timing) */
        long current_time = get_ms();
        if(is_ticking) /* if in timing mode */
        {
            elapsed_time += current_time - last_read_time;
        }
        last_read_time = current_time; /* update last read time */
        
        /* reset the stopwatch as the user just starts to press button A        */
        /* Note that button A will be pressed for many iterations, but we       */
        /* only need to perform the 'reset' as soon as it is initially pressed. */
        if(button_is_pressed(BUTTON_A) && !a_is_pressed)
        {
            a_is_pressed = 1;
            is_ticking = 0;   /* no longer time anything */
            elapsed_time = 0; /* reset the elapsed time to 0 */
           
            play_from_program_space(beep_button_a); /* play small sound */
        }
        
        /* find the end of the button press without stopping */
        if(!button_is_pressed(BUTTON_A))
        {
            a_is_pressed = 0;
        }
        
        /* as soon as the user just starts to press button C, switch between 
           starting/stopping the stopwatch */
        if(button_is_pressed(BUTTON_C) && !c_is_pressed)
        {
            c_is_pressed = 1;
            is_ticking = !is_ticking; /* if currently timing, stop timing; if currently not timing, start timing */
            
            play_from_program_space(beep_button_c); /* play small sound */
        }
        
        /* find the end of the button press without stopping */
        if(!button_is_pressed(BUTTON_C))
        {
            c_is_pressed = 0;
        }
        
        /* display elapsed time */
        print_long((elapsed_time/1000/60/10)%10); /* tens of minutes */
        print_long((elapsed_time/1000/60)%10); /* minutes */
        print_character(':');
        print_long((elapsed_time/1000)%60/10); /* tens of seconds */
        seconds = ((elapsed_time/1000)%60)%10;
        print_long(seconds); /* seconds */
        print_character('.');
        print_long((elapsed_time/100)%10); /* tenths of seconds */
        print_long((elapsed_time/10)%10); /* hundredths of seconds */
     
        lcd_goto_xy(0,0); /* reset lcd to beginning */
        
        /* beep every second */
        if(seconds != last_seconds && elapsed_time != 0 && !is_playing())
        {
            play_from_program_space(timer_tick);
        }
        last_seconds = seconds;
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