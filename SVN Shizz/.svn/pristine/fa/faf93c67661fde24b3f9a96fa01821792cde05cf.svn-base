/*------------------------------------------------------------------------------
 * Programmers: Ethan Bachinski & Eric Mensen
 * Name: hw4.c
 * Description: For this group assignment we had to implement a code that helped the robot go around a maze and keeping track of
 * the addresses that it visits by adding them to a linked list.
 * *****************************************Part 1*******************************************************************************
 * The robot will learn the maze by following the left hand on wall rule.  When the robot makes a left turn or right turn it will
 * be recorded in a linked list and when it comes to a uturn.
 * To get the robot to follow the maze and properly store the turns and addresses we implemented several functions.  The first
 * one is appendTurnToEnd which assigned a value to a given turn and added it to the end of the linked list.  We next wrote the
 * function freeAllMemoryInTurnList that freed all the memory in out linked list.  After that we wrote the function lengthTurnList
 * that records the uturns that the robot makes and stores them as addresses, this also returns the pointers of the nodes that
 * correspond to that address. Next we wrote the function concatenateTurnArrays which took the end of one linked list and linked
 * it to the start of another linked list.
 * ****************************************Part 2********************************************************************************
 * After our robot has learned to traverse the maze, stores the addresses and turns in a linked list and then returns back to the
 * dispatch station it will ask the user to choose from a list of addresses that the user wants the robot to deliver to between
 * 0 and the max number of addresses that the robot has found. The robot will then go to only the addresses that have been
 * selected, skipping over any that have not been chosen to be delivered to.  In order for our robot to do that we had to implement
 * the copyAndSimplifyTurnList function that took a segment of the linked list and removed the portions that were addresses that
 * were not specified to be visited.  We then wrote the function giveOptimizedTurnList that created an optimized path from the
 * linked list of our original path.  This function uses our getAddressLocations function, gets the input for the addresses for
 * which to be delivered, and then simplifies the path to create the final optimized linked list.
 * ***************************************Part 3*********************************************************************************
 * Once the user has entered the addresses that they want the robot to deliver to the robot will then take the optimized path that
 * was created from the giveOptimizedTurnList function and
 -------------------------------------------------------------------------------*/
#include <pololu/3pi.h>         /* allow use of 3pi robot functions */
#include "hw4-utility.h"        /* extra functions for hw4 */
#include "turnList.h"           /* linked list functions */
#include <stddef.h>
#include <stdlib.h>


/* function prototypes for HW4-part2
 -------------------------------------------------------------------------------*/
void learnAddresses(NodePtr *learnedTurns);
void goToAddresses(NodePtr learnedTurns);


/* initialize needed variables
 -------------------------------------------------------------------------------*/
NodePtr learnedTurns;


// Music
//-------
const char Ready[] PROGMEM = "T500>d-d-r16>d-r8r8r8";

const char welcome[] PROGMEM = ">g32>>c32";

const char oniowa[] PROGMEM = "T500>d-2r8>d-r16>d-r16>d-r16>d-r16>d>d>d>d>d>dr8r8r8 >d-2r8>d-r16>d-r16>d-r16>d-r16>f>f>f>f>f>fr8r8r8>f>f>fr16r16r16>e>e>er16r16r16>e->e->e-r16r16r16>d>d>dr16r16r16 >d->d->d->d->d->d-r8r8r8>c>c>cr16r16r16b-b-b-r16r16r16a-a-r8b-r16>c>cr8b-r16a-a-a-a-a-a-r8r8r8";

/* main function
 -------------------------------------------------------------------------------*/
int main( void )
{
    /* perform battery check */
    bat_check();

        /* calibrate line sensors */

    play_from_program_space(welcome);
    clear();
    print("Calibration");
    auto_calibrate_line_sensors();


    /// TODO: learn the addresses by going around the track: call learnAddresses
    //-------------------------------------------------------------------
    learnAddresses(&learnedTurns);


    while(1)
    {
	int nDeliveries = 0;
        clear();
        print("Delivery");
        lcd_goto_xy(0,1);
        print("Press B");
        wait_for_button(ANY_BUTTON);

        play_from_program_space(Ready);
        //while(is_playing());

        /// get the delivery addresses from the user
        //---------------------------------------------
	int deliveries;
        nDeliveries = get_number_from_user(deliveries);


        /// print, play music, and wait
        //-------------------------------
	play_from_program_space(oniowa);


        /// obtain the optimal turn list: call giveOptimizedTurnList
        //------------------------------------------------------------
		

        giveOptimizedTurnList(learnedTurns, &deliveries, nDeliveries);

        /// go to the addresses: call goToAddresses
        //------------------------------------------------
        goToAddresses(learnedTurns);


    }

}

//----------------------------------------------------------------------------
// learnTrack: learn the track by going around the track and
//              adding to the linked list
// Input   learnedTurns = NodePtr*   (pointer to the linked list)
// Output  learnedTurns = NodePtr* = this list will be updated by the learned
//                        turns.
//---------------------------------------------------------------------------------

void learnAddresses(NodePtr *learnedTurns)
{
    ///Need to add this to the linked list
    int mail_addresses=0;
    int done = 0;
    /// Until the packing station is reached, repeat the following
    //-----------------------------------------
	
	clear();
	lcd_goto_xy(0,0);
	print("Learning");
	lcd_goto_xy(0,1);
	print("the Maze");
	play_from_program_space(oniowa);
	while (done != 1)
    	{
		int btl; //black to left
	   int btr; //black to right
	   int ba;  //black ahead
	   int ball;//black all around
	   int turn;//number of turns
        /*  1. followSegment (move along straight lines until intersection
                              is reached)
        ------------------------------------------------------------------ */
	/*clear();
	lcd_goto_xy(0,0);
	print("Check In");
	delay_ms(500);*/

	
	follow_segment();


       /*  2. get the status of the robot based on sensor readings)
       --------------------------------------------------------------------*/

       get_surrounding_status(&btl,&ba,&btr,&ball);

      /* 3. Check if robot has reached back at dispatch by checking atEnd flag
            If so, make a U turn, record it in linked list, stop the robot, and
            return or set done to 1.
       --------------------------------------------------------------------*/
       if(ball==1)
       {
	stopRobot();
	uTurn();
		done = 1;
       }
       else if(btl==1)
       {
	stopRobot();
	//Adding turn to Linked List
	appendTurnToEnd(learnedTurns,'L');
           turnLeft();
           //turn is incremented when a left turn is made
	
           turn++;
	//follow_segment();
       }
       else if (btr==1)
       {
	stopRobot();
	appendTurnToEnd(learnedTurns,'R');
           turnRight();
           // turn incremented when a right turn is made
           turn++;
           //Adding that turn to the linked list
           //*learnedTurns=*learnedTurns->nextPtr;
	//follow_segment();
       }
	else if(ball==0 && btl==0 && btr==0 && ba==0)
       {
	stopRobot();
	appendTurnToEnd(learnedTurns,'U');
        uTurn();
	//follow_segment();
            //address is added to linked list when the robot hits a uturn
        mail_addresses++;
       }
    }
	clear();
	lcd_goto_xy(0,0);
	print("Danger");
	lcd_goto_xy(0,1);
	print("Zone");
	
    return;
}

//----------------------------------------------------------------------------
// goToAddresses: go to the delivery addresses by following the optimal path
//              specified by turnList
// Input   learnedTurns = NodePtr  = pointer to the linked list
//---------------------------------------------------------------------------------

void goToAddresses(NodePtr turnList)
{

    int done = 1;
    while (! done)
    {


        /*  1. followSegment (move along straight lines until intersection)
         ----------------------------------------------------------------- */
         follow_segment();

        /*  2. obtain sensor values
         ----------------------------------------------------------------- */
		 int btl; //black to left
		 int btr; //black to right
		 int ba;  //black ahead
		 int ball;//black all around
         get_surrounding_status(&btl,&ba,&btr,&ball);

        /*  3. stop robot if at end; at dispatch: stop the robot &return from
               program or set done=1
         ------------------------------------------------------------------ */
         if(ball == 1)
         {
             stopRobot();
             done=1;
         }
         else if(ba == 0)
         {
			 
			 stopRobot();

			 if (learnedTurns->nextPtr == NULL )  // if the pointer to the next location is null character, we are back at dispatch
			 {
				stopRobot();
				done = 1;
			 }
			 else
			 {
				// look at next turn in list
				if ( learnedTurns->turn == 'L') // If next turn in list if 'L'
				{
					turnLeft();
				}
				else if ( learnedTurns->turn== 'R') // If next turn in list if 'R'
				{
					turnRight();
				}
				else if ( learnedTurns->turn== 'U') // If next turn in list if 'U'
				{
					turnRight();
				}
			 }
          }
    }
}
