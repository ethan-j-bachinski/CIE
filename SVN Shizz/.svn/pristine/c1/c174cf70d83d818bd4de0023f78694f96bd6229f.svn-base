/*-----------------------------------------------------------------------------
 * Implementation of 3pi robot functions. See hw4-utility.h for documentation.
 *-----------------------------------------------------------------------------*/

#include <pololu/3pi.h>

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


void auto_calibrate_line_sensors(void)
{
    pololu_3pi_init(2000);
    int counter;
    /* Auto-calibration: turn right and left while calibrating the
       sensors. */
    for(counter=0; counter<80; counter++)
    {
        if(counter < 20 || counter >= 60)
        {
            set_motors(40,-40);
        }
        else
        {
            set_motors(-40,40);
        }

        /* This function records a set of sensor readings and keeps
           track of the minimum and maximum values encountered.  The
           IR_EMITTERS_ON argument means that the IR LEDs will be
           turned on during the reading, which is usually what you
           want. */
        calibrate_line_sensors(IR_EMITTERS_ON);

        /* Since our counter runs to 80, the total delay will be
           80*20 = 1600 ms. */
        delay_ms(20);
    }
    set_motors(0,0);
}

void follow_segment(void)
{
    int last_proportional = 0;
    long integral=0;

    while(1)
    {
        /* Normally, we will be following a line.  The code below is
           similar to the 3pi-linefollower-pid example, but the maximum
           speed is turned down to 60 for reliability. */

        /* Get the position of the line. */
        unsigned int sensors[5];
        unsigned int position = read_line(sensors,IR_EMITTERS_ON);

        /* The "proportional" term should be 0 when we are on the line. */
        int proportional = ((int)position) - 2000;

        /* Compute the derivative (change) and integral (sum) of the
           position. */
        int derivative = proportional - last_proportional;
        integral += proportional;

        /* Remember the last position. */
        last_proportional = proportional;

        /* Compute the difference between the two motor power settings,
           m1 - m2.  If this is a positive number the robot will turn
           to the left.  If it is a negative number, the robot will
           turn to the right, and the magnitude of the number determines
           the sharpness of the turn. */
        int power_difference = proportional/20 + integral/10000 + derivative*3/2;

        /* Compute the actual motor settings.  We never set either motor
           to a negative value. */
        const int max = 60; /* the maximum speed */
        if(power_difference > max)
            power_difference = max;
        if(power_difference < -max)
            power_difference = -max;

        if(power_difference < 0)
            set_motors(max+power_difference,max);
        else
            set_motors(max,max-power_difference);

        /* We use the inner three sensors (1, 2, and 3) for
           determining whether there is a line straight ahead, and the
           sensors 0 and 4 for detecting lines going to the left and
           right. */

        if(sensors[1] < 100 && sensors[2] < 100 && sensors[3] < 100)
        {
            /* There is no line visible ahead, and we didn't see any
               intersection.  Must be a dead end. */
            return;
        }
        else if(sensors[0] > 200 || sensors[4] > 200)
        {
            /* Found an intersection. */
            return;
        }

    }
}

void stopRobot()
{
    set_motors(0,0);
}

void turnLeft()
{
    set_motors(-80,80);
    delay_ms(200);
    stopRobot();
}

void turnRight()
{
    set_motors(80,-80);
    delay_ms(200);
    stopRobot();
}

void uTurn()
{
    set_motors(80,-80);
    delay_ms(400);
    stopRobot();
}

void moveStraight()
{
    return;
}

void get_surrounding_status(int *line_to_left, int *line_ahead, int *line_to_right, int *at_end)
{
    *line_to_left = 0;
    *line_ahead = 0;
    *line_to_right = 0;
    *at_end = 0;

    set_motors(50,50);
    delay_ms(50);

    /* Now read the sensors and check the intersection type. */
    unsigned int sensors[5];
    read_line(sensors,IR_EMITTERS_ON);

    /* Check for left and right exits. */
    if(sensors[0] > 100)
    {
        *line_to_left = 1;
    }
    if(sensors[4] > 100)
    {
        *line_to_right = 1;
    }

    /* Drive straight a bit more - this is enough to line up our
       wheels with the intersection. */
    set_motors(40,40);
    delay_ms(200);

    /* Check for a straight exit. */
    read_line(sensors,IR_EMITTERS_ON);
    if(sensors[1] > 200 || sensors[2] > 200 || sensors[3] > 200)
    {
        *line_ahead = 1;
    }

    /* Check for the ending spot.
       If all three middle sensors are on dark black, we have
       solved the maze. */
    if(sensors[1] > 600 && sensors[2] > 600 && sensors[3] > 600)
    {
        *at_end = 1;
    }
}


int get_number_from_user(int min, int max, int choice)
{
    unsigned char button;  /* stores button press */


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
        print_long(choice);
        lcd_goto_xy(0,1);
        print("<  **  >");

        button = button_is_pressed(ANY_BUTTON);
        if (button == BUTTON_A)
        {
            choice--;
            if (choice < 1)
            {
                choice = 1;
            }

            wait_for_button_release(BUTTON_A);
        }
        else if (button == BUTTON_C)
        {
            choice++;
            wait_for_button_release(BUTTON_C);
        }

        /* small delay */
        delay_ms(50);
    }
    wait_for_button_release(BUTTON_B);

    return choice;
}

int readUserInput( int lowOption, int highOption, int currentOption)
{
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

	return currentOption;
}
