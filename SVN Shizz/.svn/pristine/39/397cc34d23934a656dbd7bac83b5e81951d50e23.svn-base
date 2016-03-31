/*-------------------------------------------------------------------------------
 * Name: hw4-utility.h
 * Description: This file contains prototypes for 3pi robot functions to aid
 *              in moving the robot around a maze/track.
 -------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 * Function name: bat_check
 * Description: This function checks the voltage on the batteries and
 *              displays a message on the LCD until the user presses B.
 *              The message on the first line cycles between the following:
 *              Bat Chk       [-> descriptive message]
 *              xxxxmV        [-> the battery voltage]
 *              Okay/Replace  [-> whether the batteries should be replaced]
 ----------------------------------------------------------------------------*/
void bat_check( void );

/*-----------------------------------------------------------------------------
 * Function name: auto_calibrate_line_sensors
 * Description: Assuming the robot is currently located on top of a black
 *              line on a white background (e.g., at the start of a maze-
 *              solving or line-following task), calling this function will
 *              have the robot rotate right and left to calibrate the line
 *              sensors.
 ----------------------------------------------------------------------------*/
void auto_calibrate_line_sensors(void);

/*-----------------------------------------------------------------------------
 * Function name: follow_segment
 * Description: A function (written by pololu) to have the robot follow a
 *              line segment until it reaches an "intersection" point where a
 *              choice must be made. Note that intersections include locations
 *              at which the robot should make a u-turn.
 ----------------------------------------------------------------------------*/
void follow_segment(void);


/*-----------------------------------------------------------------------------
 * Function name: get_surrounding_status
 * Description: This function uses the pololu's reflectance sensor values to
 *              determine if there is a black unit to the robot's left, if
 *              there is a black unit directly in front (i.e., ahead) of the
 *              robot, if there is a black unit to the robot's right, and if
 *              there is black all around the robot. As a necessary side effect
 *              of determining this information, the robot will move forward
 *              in order to line up with a potential line to the robot's
 *              left/right.
 * Inputs: black_to_left = int * = pointer to integer variable
 *         black_ahead = int * = pointer to integer variable
 *         black_to_right = int * = pointer to integer variable
 *         black_all_around = int * = pointer to integer variable
 *         (Note: the initial values of the integers for which the above
 *          pointers point does not matter as the values will be set in
 *          this function.)
 * Outputs: black_to_left = int * = pointer to modified integer variable that
 *                                  will be set to 1 if a black unit is to
 *                                  the robot's left and 0 otherwise
 *          black_ahead = int * = pointer to modified integer variable that
 *                                will be set to 1 if a black unit is
 *                                directly in front of the robot and 0
 *                                otherwise
 *          black_to_right = int * = pointer to modified integer variable
 *                                   variable that will be set to 1 if a
 *                                   black unit is to the robot's right and
 *                                   0 otherwise
 *          black_all_around = int * = pointer to modified integer variable
 *                                     that will be set to 1 if black units
 *                                     surround the robot
 ----------------------------------------------------------------------------*/
void get_surrounding_status(int *black_to_left,
                            int *black_ahead,
                            int *black_to_right,
                            int *black_all_around);

/*-----------------------------------------------------------------------------
 * Function name: turnLeft
 * Description: This function (based on a very similar function written by
 *              pololu) makes the robot take a left turn. It
 *              is assumed that the robot is moving straight when this
 *              function is called. After completing the left turn, the fucntion stops the robot.
  ----------------------------------------------------------------------------*/
void turnLeft();

/*-----------------------------------------------------------------------------
 * Function name: turnRight
 * Description: This function (based on a very similar function written by
 *              pololu) makes the robot take a right turn. It
 *              is assumed that the robot is moving straight when this
 *              function is called. After completing the right turn, the fucntion stops the robot.
  ----------------------------------------------------------------------------*/
void turnRight();

/*-----------------------------------------------------------------------------
 * Function name: uTurn
 * Description: This function (based on a very similar function written by
 *              pololu) makes the robot take a U turn. It
 *              is assumed that the robot is moving straight when this
 *              function is called. After completing the U turn, the fucntion stops the robot.
  ----------------------------------------------------------------------------*/
void uTurn();

/*-----------------------------------------------------------------------------
 * Function name: moveStraight
 * Description: This function (based on a very similar function written by
 *              pololu) makes the robot move straight at an intersection. It
 *              is assumed that the robot is moving straight when this
 *              function is called. After passing the intersection, the fucntion stops the robot.
  ----------------------------------------------------------------------------*/
void moveStraight();

/*-----------------------------------------------------------------------------
 * Function name: stopRobot
 * Description: This function (based on a very similar function written by
 *              pololu) stops the robot.
  ----------------------------------------------------------------------------*/
void stopRobot();


/*-----------------------------------------------------------------------------
 * Function name: get_number_from_user
 * Description: This function obtains a positive number ( >0 ) from the user
 *              using a menu-based approach.
 * Output: int = user-specified number
 ----------------------------------------------------------------------------*/
int get_number_from_user(int maxvalue);


/*-----------------------------------------------------------------------------
 * Function name: get_number_from_user
 * Description: This function obtains a positive number ( >0 ) from the user
 *              using a menu-based approach.
 * Output: int = user-specified number
 ----------------------------------------------------------------------------*/
int get_number_from_user(int maxvalue);

/*-----------------------------------------------------------------------------
 * Function name: get_number_from_user
 * Description: This function return a number between lowOption and highOption
 *              from the user using a menu-based approach. currentOption is the
 *              number display initially
 * Output: int = user-specified number
 ----------------------------------------------------------------------------*/
int readUserInput( int lowOption, int highOption, int currentOption);