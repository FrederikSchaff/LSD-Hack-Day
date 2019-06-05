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

RESULT( )

EQUATION("Gather")
/*
Comment
*/

RESULT( )


//Sugar

EQUATION("Regrowth")
/*
Comment
*/

RESULT( )


EQUATION("Gather_local")
/*
Comment
*/

RESULT( )



MODELEND

// do not add Equations in this area

void close_sim( void )
{
	// close simulation special commands go here
}
