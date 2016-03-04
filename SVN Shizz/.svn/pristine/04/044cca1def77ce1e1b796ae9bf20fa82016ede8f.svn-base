/*-----------------------------------------------------------------------------
 * Programmers: Ethan Bachinski & Eric Mensen
 * Name: sensorReadings2.c
 * Description: A 3pi robot program to obtain a user-specified number of
 *              sensor readings and display the median value.
 * To compile (using provided makefile) on linux:
 * > make
 * To load program onto robot (once usb programmer plugged in and robot on):
 * > make program
 ----------------------------------------------------------------------------*/
#include <pololu/3pi.h>   /* allow use of 3pi robot functions */
#include <stdlib.h>

/* function prototype for battery check */
void bat_check( void );

/* function prototype to obtain number of sensor readings from user */
int get_num_desired_readings_from_user( void );

/* function prototype for obtaining middle sensor value */
unsigned int get_middle_sensor_value( void );

/* function prototype for function to sort array using insertion sort */
void sort_array(unsigned int *arr, int arr_size);

int main( void )
{
    /* perform battery check */
    bat_check();

    /* set up sensors, using a value of 2000 for the timeout */
    pololu_3pi_init(2000);

    while (1)
    {
        unsigned int medianReading; /* found median reading */
        int i; /* for loop counter */
        int numReadings = 0;  /* number of desired sensor readings */

        /* pointer for dynamically allocated array of sensor readings: */
        unsigned int *savedSensorReadings = NULL;

        /* obtain number of sensor readings from user */
        numReadings = get_num_desired_readings_from_user();

        /* dynamically allocate memory for savedSensorReadings array */
<<<<<<< .mine
        savedSensorReadings = (int *)malloc(numReadings * sizeof(int));

||||||| .r89366
        /* TODO: YOUR CODE HERE */
        
=======
        /* TODO: YOUR CODE HERE */

>>>>>>> .r89374
        /* display initial message */
        clear();
        lcd_goto_xy(0,0);
        print_long(numReadings);
        print(" SENS");
        lcd_goto_xy(0,1);
        print("READINGS");
        delay_ms(2000);

        /* obtain numReadings sensor readings */
        for (i=0; i < numReadings; i++)
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
        sort_array(savedSensorReadings, numReadings);
        medianReading = savedSensorReadings[numReadings/2];
        clear();
        print("M = ");
        print_long(medianReading);
        lcd_goto_xy(0,1);
        print("PRESS B");

        wait_for_button(BUTTON_B);

        /* free memory */
        free(savedSensorReadings);
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
 * Function name: get_num_desired_readings_from_user
 * Description: This function obtains the number of desired sensor readings
 *              from the user by having the user select their choice from
 *              a menu. The menu-based approach ensures that only an
 *              odd-number (e.g., 5, 11, 21) of sensor readings will be
 *              chosen.
 * Output = int = user-specified number of sensor readings
 ----------------------------------------------------------------------------*/
int get_num_desired_readings_from_user( void )
{
    int choice = 0;        /* index of choice */
    int options[100];      /* array to store options */
    int i;                 /* for-loop index */
    unsigned char button;  /* stores button press */

    /* initialize options */
    /* start at 3 and increment by 2 to obtain odd numbers */
    for (i=0; i < 100; i++)
    {
        options[i] = i*2 + 3;
    }

    /* display instructions for 2 seconds */
    clear();
    lcd_goto_xy(0,0);
    print("SELECT");
    lcd_goto_xy(0,1);
    print("NUMBER");
    delay_ms(2000);

    /* display menu and obtain choice */
    while(!button_is_pressed(BUTTON_B))
    {
        clear();
        lcd_goto_xy(3,0);
        print_long(options[choice]);
        lcd_goto_xy(0,1);
        print("<  **  >");

        button = button_is_pressed(ANY_BUTTON);
        if (button == BUTTON_A)
        {
            choice--;
            if (choice < 0)
            {
                choice = 0;
            }

            wait_for_button_release(BUTTON_A);
        }
        else if (button == BUTTON_C)
        {
            choice++;
            if (choice > 99)
            {
                choice = 99;
            }

            wait_for_button_release(BUTTON_C);
        }

        /* small delay */
        delay_ms(50);
    }

    return options[choice];
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

/*-----------------------------------------------------------------------------
 * Function name: sort_array
 * Description: This sorts the input array arr so the elements will be in
 *              ascending order (i.e., from 'smallest' to 'largest')
 * Inputs: arr = unsigned int * = input array
 *         arr_size = integer = number of elements in the input array
 ----------------------------------------------------------------------------*/
void sort_array(unsigned int *arr, int arr_size)
{
    int j;            /* index of first unsorted value */
    int i;            /* index for while loop through sorted sequence */
    unsigned int key; /* key (= first unsorted value) */

    for (j = 1; j < arr_size; j++)
    {
        key = arr[j];

        /*--------------------------------------
         * insert key into the sorted sequence
         * arr[0] to arr[j-1]
         *-------------------------------------*/
        i = j - 1;
        while (i >= 0 && arr[i] > key)
        {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
}
