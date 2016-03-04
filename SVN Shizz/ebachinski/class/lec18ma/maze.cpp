/* implementations of the Maze functions */
/* see maze.h for documentation */

/* set to zero if you aren't using curses */
#define CURSESPRINT 1

#include "maze.h"
#include <stdio.h>
#include <stdlib.h>
#if CURSESPRINT /* if using curses */
#include "useCurses.h"    /* include header */
#define PRINT printw      /* define macro for printing in curses */
#define MOVE00 move(0,0); /* define macro for calling move(0,0); */
#define REFRESH refresh(); /* define macro for refreshing screen */
#else /* if not using curses */
#define PRINT printf /* define macro for printing using printf */
#define MOVE00       /* define MOVE00 macro to do nothing */
#define REFRESH      /* define REFRESH to do nothing */
#endif

int readMaze(const char *fileName, Maze *m, RobotModel *robot)
{
    int r, c;           /* current row and column indices */
    FILE *inputFile;    /* file pointer to input file */
    int success = 0;    /* whether we succeeded */

    /* open input file */
    inputFile = fopen(fileName, "r");

    /* fill data array */
    if (inputFile != NULL)
    {
        fscanf(inputFile, "%d %d", &(m->rows), &(m->cols));
        fscanf(inputFile, "%d %d %d", &(robot->row), &(robot->col), &(robot->dir));
        m->mazeArray = (int *) malloc((m->rows)*(m->cols)*sizeof(int));
        int *arr = m->mazeArray;
        success = 1;
        for (r = 0; r < m->rows; r++)
        {
            for (c = 0; c < m->cols; c++)
            {
                if (fscanf(inputFile, "%d", &(arr[r*m->cols + c])) == EOF)
                {
                    success = 0;
                }
            }
        }

        fclose(inputFile);
    }

    return success;
}

void clearMaze(Maze *m)
{
    if (m->mazeArray != NULL)
    {
        free(m->mazeArray);
        m->mazeArray = NULL;
    }

    m->rows = 0;
    m->cols = 0;
}

void printMazePlusCurrentPos(Maze m, RobotModel robot)
{
    /* note: in this program, anything > 0 is considered black
             to mimic robot sensor values that result in larger
             values when placed over a dark surface.
             (opposite of the convention used for images) */
    MOVE00 /* move(0,0); in curses mode */
    int r, c;
    for (r=0; r < m.rows; r++)
    {
        for (c=0; c < m.cols; c++)
        {
            if (r == robot.row && c == robot.col)
            {
                PRINT("* ");
            }
            else if (m.mazeArray[r*m.cols + c] > 0)
            {
                PRINT("X ");
            }
            else
            {
                PRINT(". ");
            }
        }
        PRINT("\n");
    }

    REFRESH
}


int blackToLeft(Maze m, RobotModel robot)
{
    int bToL = 0;

    if ((robot.dir == 0 && m.mazeArray[(robot.row-1)*m.cols + robot.col  ] > 0) ||   /* moving in increasing column direction */
        (robot.dir == 1 && m.mazeArray[    robot.row*m.cols + robot.col-1] > 0) ||   /* moving in decreasing row direction */
        (robot.dir == 2 && m.mazeArray[(robot.row+1)*m.cols + robot.col  ] > 0) ||   /* moving in decreasing column direction */
        (robot.dir == 3 && m.mazeArray[    robot.row*m.cols + robot.col+1] > 0) )    /* moving in increasing row direction */
    {
        bToL = 1;
    }

    return bToL;
}

int blackToRight(Maze m, RobotModel robot)
{
    int bToR = 0;

    if ((robot.dir == 0 && m.mazeArray[(robot.row+1)*m.cols + robot.col  ] > 0) ||   /* moving in increasing column direction */
        (robot.dir == 1 && m.mazeArray[    robot.row*m.cols + robot.col+1] > 0) ||   /* moving in decreasing row direction */
        (robot.dir == 2 && m.mazeArray[(robot.row-1)*m.cols + robot.col  ] > 0) ||   /* moving in decreasing column direction */
        (robot.dir == 3 && m.mazeArray[    robot.row*m.cols + robot.col-1] > 0))     /* moving in increasing row direction */
    {
        bToR = 1;
    }

    return bToR;
}

int blackInFront(Maze m, RobotModel robot)
{
    int bInF = 0;

    if ((robot.dir == 0 && m.mazeArray[    robot.row*m.cols + robot.col+1] > 0) ||   /* moving in increasing column direction */
        (robot.dir == 1 && m.mazeArray[(robot.row-1)*m.cols + robot.col  ] > 0) ||   /* moving in decreasing row direction */
        (robot.dir == 2 && m.mazeArray[    robot.row*m.cols + robot.col-1] > 0) ||   /* moving in decreasing column direction */
        (robot.dir == 3 && m.mazeArray[(robot.row+1)*m.cols + robot.col  ] > 0))     /* moving in increasing row direction */
    {
        bInF = 1;
    }

    return bInF;
}

int onBlack(Maze m, RobotModel robot)
{
    int onB = 0;
    if (m.mazeArray[robot.row*m.cols + robot.col] > 0)
    {
        onB = 1;
    }

    return onB;
}

