/*-------------------------------------------------------------------------------
 * Programmer: Mona K. Garvin
 * Name: maze.h
 * Description: This file contains a structure and associated function
 *              prototypes to model a maze for a robot. A Maze variable
 *              is designed to be initialized through the readMaze function.
 *              After initialization, the robot "sensor" functions can be
 *              called to determine whether a "black" unit is located to the
 *              left, to the right, in front, or directly below the specified
 *              robot. In addition, the maze and the robot can be printed
 *              using the printMazePlusCurrentPos function (using the curses
 *              library).
 * Example use:
 *    Maze maze;
 *    RobotModel robot;
 *    char *inputFileName = argv[1];
 *    int success = readMaze(inputFileName, &maze, &robot);
 *    if (success)
 *    {
 *        int bTL = blackToLeft(maze, robot);
 *        printMazePlusCurrentPos(maze, robot);
 *        ....
 *        clearMaze(&maze);
 *    }
 -------------------------------------------------------------------------------*/
#ifndef MAZE_H
#define MAZE_H

#include "robotModel.h"

/* struct maze is a data type to model a robot maze */
struct maze {
    int *mazeArray; /* array to store maze */
    int rows;       /* number of rows of maze */
    int cols;       /* number of columns of maze */
};

typedef struct maze Maze; /* new type name for struct maze */

/*-----------------------------------------------------------------------------
 * Function name: readMaze
 * Description: This function reads an input maze file in order to initialize
 *              the given Maze and RobotModel variables. The maze file contains
 *              the size of the maze and its individual values. It also
 *              contains the starting position and direction of the robot.
 * Inputs: filename = string = name of maze file
 *         m = Maze * = pointer to Maze structure that should be initialized
 *                      in this function (passed by simulated reference)
 *         robot = RobotModel * = pointer to RobotModel that should be
 *                                initialized in this function (passed by
 *                                simulated reference)
 * Outputs: m = Maze * = pointer to initialized Maze
 *          robot = RobotModel * = pointer to initialized RobotModel
 *          int = 1 if maze file read successfully
 *                0 if error encountered while reading maze file
 ----------------------------------------------------------------------------*/
int readMaze(const char *fileName, Maze *m, RobotModel *robot);

/*-----------------------------------------------------------------------------
 * Function name: clearMaze
 * Description: This function frees the dynamically allocated memory
 *              associated with a Maze that was initialized using the
 *              readMaze function. It also sets the rows/cols to zero.
 * Input: m = Maze * = pointer to Maze structure that should be cleared
 *                      in this function (passed by simulated reference)
 * Output: m = Maze * = pointer to cleared Maze
 ----------------------------------------------------------------------------*/
void clearMaze(Maze *m);

/*-----------------------------------------------------------------------------
 * Function name: printMazePlusCurrentPos
 * Description: This function displays (using the curses library, when
 *              defined) the maze and indicated robot. "Black" portions of
 *              the maze are displayed with the 'X' character, "white"
 *              portions of the maze are displayed with the '.' character,
 *              and the current position of the robot is displayed with the
 *              '*' character.
 * Inputs: m = Maze = maze to be displayed
 *         robot = RobotModel = robot to be displayed
 ----------------------------------------------------------------------------*/
void printMazePlusCurrentPos(Maze m, RobotModel robot);

/*-----------------------------------------------------------------------------
 * Function name: blackToLeft
 * Description: Given a maze and robot, this function returns whether a
 *              black unit is to the left of the robot's current position
 *              and direction
 * Inputs: m = Maze = maze
 *         robot = RobotModel = robot
 * Output: int = 1 if black is to the left; 0 otherwise
 ----------------------------------------------------------------------------*/
int blackToLeft(Maze m, RobotModel robot);

/*-----------------------------------------------------------------------------
 * Function name: blackToRight
 * Description: Given a maze and robot, this function returns whether a
 *              black unit is to the right of the robot's current position
 *              and direction
 * Inputs: m = Maze = maze
 *         robot = RobotModel = robot
 * Output: int = 1 if black is to the right; 0 otherwise
 ----------------------------------------------------------------------------*/
int blackToRight(Maze m, RobotModel robot);

/*-----------------------------------------------------------------------------
 * Function name: blackInFront
 * Description: Given a maze and robot, this function returns whether a
 *              black unit is in front of the robot's current position
 *              and direction
 * Inputs: m = Maze = maze
 *         robot = RobotModel = robot
 * Output: int = 1 if black is in front; 0 otherwise
 ----------------------------------------------------------------------------*/
int blackInFront(Maze m, RobotModel robot);

/*-----------------------------------------------------------------------------
 * Function name: onBlack
 * Description: Given a maze and robot, this function returns whether the
 *              robot is on a black unit
 * Inputs: m = Maze = maze
 *         robot = RobotModel = robot
 * Output: int = 1 if robot is on black unit; 0 otherwise
 ----------------------------------------------------------------------------*/
int onBlack(Maze m, RobotModel robot);

#endif // MAZE_H
