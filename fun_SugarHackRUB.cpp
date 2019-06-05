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

RESULT( 0)


//Sugar

EQUATION("Regrowth")
/*
wenn amount_t < max_amount, dann (amount_t * (1 + Wachstumsfaktor)) , max Wert = 2 * amount_0 
*/
if ( T == 0) {double amount_sugar_max = V("amount") * 2};												//Maximal sugar amount ist doppelter sugar amount von t=0

if(V("amount") < V("amount_sugar_max")) {WRITE("amount",V("amount")*1.01)};       // Wenn maximum nicht erreicht, dann wachse um 1%

RESULT( 0)


EQUATION("Gather_local")
/*
Comment
*/

RESULT(0 )



MODELEND

// do not add Equations in this area

void close_sim( void )
{
	// close simulation special commands go here
}
