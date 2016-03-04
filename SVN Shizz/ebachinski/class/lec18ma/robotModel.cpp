/* implementations of the RobotModel functions */
/* see robotModel.h for documentation */
#include "robotModel.h"

void moveStraight(RobotModel *robot)
{
    if (robot->dir == 0)
    {
        (robot->col)++;
    }
    else if (robot->dir == 1)
    {
        (robot->row)--;
    }
    else if (robot->dir == 2)
    {
        (robot->col)--;
    }
    else if (robot->dir == 3)
    {
        (robot->row)++;
    }
}

void turnLeft(RobotModel *robot)
{
    if (robot->dir == 0)
    {
        (robot->row)--;
        robot->dir = 1;
    }
    else if (robot->dir == 1)
    {
        (robot->col)--;
        robot->dir = 2;
    }
    else if (robot->dir == 2)
    {
        (robot->row)++;
        robot->dir = 3;
    }
    else if (robot->dir == 3)
    {
        (robot->col)++;
        robot->dir = 0;
    }
}

void turnRight(RobotModel *robot)
{
    if (robot->dir == 0)
    {
        (robot->row)++;
        robot->dir = 3;
    }
    else if (robot->dir == 1)
    {
        (robot->col)++;
        robot->dir = 0;
    }
    else if (robot->dir == 2)
    {
        (robot->row)--;
        robot->dir = 1;
    }
    else if (robot->dir == 3)
    {
        (robot->col)--;
        robot->dir = 2;
    }
}

void uTurn(RobotModel *robot)
{
    if (robot->dir == 0)
    {
        (robot->col)--;
        robot->dir = 2;
    }
    else if (robot->dir == 1)
    {
        (robot->row)++;
        robot->dir = 3;
    }
    else if (robot->dir == 2)
    {
        (robot->col)++;
        robot->dir = 0;
    }
    else if (robot->dir == 3)
    {
        (robot->row)--;
        robot->dir = 1;
    }
}

void reverse(RobotModel *robot)
{
    if (robot->dir == 0)
    {
        (robot->col)--;
    }
    else if (robot->dir == 1)
    {
        (robot->row)++;
    }
    else if (robot->dir == 2)
    {
        (robot->col)++;
    }
    else if (robot->dir == 3)
    {
        (robot->row)--;
    }
}
