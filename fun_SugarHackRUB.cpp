//#define EIGENLIB			// uncomment to use Eigen linear algebra library
//#define NO_POINTER_INIT	// uncomment to disable pointer checking

#include "fun_head_fast.h"

// do not add Equations in this area

MODELBEGIN

// insert your equations here, between the MODELBEGIN and MODELEND words



EQUATION("Init")
/*
Comment
*/



RESULT( 0 )

//Agents

EQUATION("Move")
/*
The agent moves in a random direction.
*/

double where = uniform_int(0,8);
MOVE(where);

RESULT( 0 )


EQUATION("Metabolism")
/*
Comment
*/

RESULT( 0)

EQUATION("Gather")
/*
Comment
*/

V("x_size")

RESULT( 0)


//Sugar

EQUATION("Regrowth")
/*
Comment
*/

RESULT( 0)


EQUATION("Gather_local")
/*
Gives the number of suger available
*/

double currentSugar;
cur = SEARCH_POSITION_GRID("SugarPatch");
currentSugar=VS(cur,"cur_sugar");
WRITES(cur,"cur_sugar",0);
RESULT(currentSugar)



MODELEND

// do not add Equations in this area

void close_sim( void )
{
	// close simulation special commands go here
}
