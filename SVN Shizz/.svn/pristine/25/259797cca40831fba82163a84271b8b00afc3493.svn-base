/*-----------------------------------------------------------------------------
 * Programmer: YOUR NAMES HERE
 * Name: sensorReadings.c
 * Description: A 3pi robot program to obtain a specified number of sensor
 *              readings and display the median value.
 *              For the mini-assignment, you must complete the implementation
 *              of the sort_array function to sort an input array using
 *              insertion sort.
 * To compile (using provided makefile) on linux:
 * > make
 * To load program onto robot (once usb programmer plugged in and robot on):
 * > make program
 ----------------------------------------------------------------------------*/
#include <pololu/3pi.h>   /* allow use of 3pi robot functions */
#include "insertionSort.h"  /*for the insertion sort function*/

#define NUM_READINGS 11   /* number of sensor readings to obtain */

/* function prototype for battery check */
void bat_check( void );

/* function prototype for obtaining middle sensor value */
unsigned int get_middle_sensor_value( void );


int main( void )
{
    /* perform battery check */
    bat_check();

    /* set up sensors, using a value of 2000 for the timeout */
    pololu_3pi_init(2000);

    while (1)
    {
        /* define variables */
        unsigned int savedSensorReadings[NUM_READINGS]; /* array for sensor readings */
        unsigned int medianReading; /* found median reading */
        int i; /* for loop counter */

        /* display initial message */
        clear();
        lcd_goto_xy(0,0);
        print_long(NUM_READINGS);
        print(" SENS");
        lcd_goto_xy(0,1);
        print("READINGS");
        delay_ms(2000);

        /* obtain NUM_READINGS sensor readings */
        for (i=0; i < NUM_READINGS; i++)
        {
            unsigned int middleLineSensorValue; /* middle sensor value */

            /* display instructions to user */
            clear();
            print("NUM ");
            print_long(i+1);
            lcd_goto_xy(0,1);
            print("PRESS B");

            /* wait for user to press B */
            wait_for_button(BUTTON_B);

            /* extract middle sensor value, display, and save in array */
            middleLineSensorValue = get_middle_sensor_value();
            clear();
            print_long(middleLineSensorValue);
            delay_ms(1000);
            savedSensorReadings[i] = middleLineSensorValue;
        }

        /* compute median reading and display until user presses B */
        sort_array(savedSensorReadings, NUM_READINGS);
        medianReading = savedSensorReadings[NUM_READINGS/2];
        clear();
        print("M = ");
        print_long(medianReading);
        lcd_goto_xy(0,1);
        print("PRESS B");

        wait_for_button(BUTTON_B);
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
 * Function name: get_middle_sensor_value
 * Description: This function returns the current middle sensor value.
 * Output: unsigned int = current middle sensor value
 ----------------------------------------------------------------------------*/
unsigned int get_middle_sensor_value( void )
{
    /* need array to store all five sensor values */
    unsigned int fiveLineSensorValues[5];

    /* get all five sensor values with IR LEDs turned on
     so that we will obtain reflectance values */
    read_line_sensors(fiveLineSensorValues, IR_EMITTERS_ON);

    /* return middle sensor value */
    return fiveLineSensorValues[2];
}

