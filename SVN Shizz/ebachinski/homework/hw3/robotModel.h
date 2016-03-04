/*-------------------------------------------------------------------------------
 * Programmer: Mona K. Garvin
 * Name: robotModel.h
 * Description: This file contains a structure and associated function
 *              prototypes to model a robot. A RobotModel variable
 *              has members to model its current position (given by a row
 *              and column) and direction. The direction defines where
 *              the robot will move if the robot is to move straight ahead:
 *              0 = east or an increasing column direction,
 *              1 = north or a decreasing row direction
 *              2 = west or a decreasing column direction
 *              3 = south or an increasing row direction
 *              Functions are also provided to modify the current position and
 *              direction of a given robot to move one unit straight, move one
 *              unit to the left, move one unit to the right, and make a u-turn.
 -------------------------------------------------------------------------------*/
#ifndef ROBOTMODEL_H
#define ROBOTMODEL_H


/* struct robotModel is a data type to model a robot */
struct robotModel {
    int row; /* current row position */
    int col; /* current column position */
    int dir; /* current direction (0=East ->, 1=North ^, 2=West <-, 3=South v) */
};

typedef struct robotModel RobotModel; /* new type name for struct robotModel */

/*-----------------------------------------------------------------------------
 * Function name: moveStraight
 * Description: This function modifies the given robot's position so that it
 *              moves forward one unit.
 * Input: robot = RobotModel * = pointer to RobotModel structure that should
 *                               be modified (passed by simulated reference)
 * Output: robot = RobotModel * = pointer to modified RobotModel structure
 *                                after adjusting position so that robot
 *                                has moved one unit straight ahead
 ----------------------------------------------------------------------------*/
void moveStraight(RobotModel *robot);

/*-----------------------------------------------------------------------------
 * Function name: turnLeft
 * Description: This function modifies the given robot's position and direction
 *              so that the robot turns and moves one unit to the left.
 * Input: robot = RobotModel * = pointer to RobotModel structure that should
 *                               be modified (passed by simulated reference)
 * Output: robot = RobotModel * = pointer to modified RobotModel structure
 *                                after adjusting position so that robot
 *                                has turned and moved one unit to the left
 ----------------------------------------------------------------------------*/
void turnLeft(RobotModel *robot);


/*-----------------------------------------------------------------------------
 * Function name: turnRight
 * Description: This function modifies the given robot's position and direction
 *              so that the robot turns and moves one unit to the right.
 * Input: robot = RobotModel * = pointer to RobotModel structure that should
 *                               be modified (passed by simulated reference)
 * Output: robot = RobotModel * = pointer to modified RobotModel structure
 *                                after adjusting position so that robot
 *                                has turned and moved one unit to the right
 ----------------------------------------------------------------------------*/
void turnRight(RobotModel *robot);


/*-----------------------------------------------------------------------------
 * Function name: uTurn
 * Description: This function modifies the given robot's position and direction
 *              so that the robot performs a 180 degree turn and moves
 *              one unit in the new direction.
 * Input: robot = RobotModel * = pointer to RobotModel structure that should
 *                               be modified (passed by simulated reference)
 * Output: robot = RobotModel * = pointer to modified RobotModel structure
 *                                after adjusting position so that robot
 *                                has perfomed a u-turn and moved one unit
 *                                in the new direction
 ----------------------------------------------------------------------------*/
void uTurn(RobotModel *robot);

/*-----------------------------------------------------------------------------
 * Function name: reverse
 * Description: This function modifies the given robot's position so that
 *              it moves one unit in reverse (without changing its direction).
 * Input: robot = RobotModel * = pointer to RobotModel structure that should
 *                               be modified (passed by simulated reference)
 * Output: robot = RobotModel * = pointer to modified RobotModel structure
 *                                after adjusting position so that robot
 *                                has moved one unit in the reverse direction.
 ----------------------------------------------------------------------------*/
void reverse(RobotModel *robot);


#endif // ROBOTMODEL_H
