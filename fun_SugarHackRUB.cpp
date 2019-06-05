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

RESULT( 0 )
RESULT( 0)
RESULT( 0 )

EQUATION("Gather")
/*
Agent collects sugar from Patch

'PSEUDO CODE':
how much sugar do i have? VORRAT?
how much amount is available? amount?
max-value VORRAT = 1
Einsammeln entspricht Vorrat des Agenten anzupassen
*/

V("x_size") ;
cur = search_position(SugarPatch) ;

RESULT( 0)
if(stock_sugar < 1) { 
  if(cur != NULL) { 
    WRITE("stock_sugar", (stock_sugar + VS(cur, "amount")))
   }
};


if(stock_sugar) > 1 { 
  WRITE(stock_sugar,1) 
};




RESULT( 0 )


//Sugar

EQUATION("Regrowth")
/*
Comment
*/

RESULT( 0)
RESULT( 0 )


EQUATION("Gather_local")
/*
Gives the number of suger available
*/
cur = SEARCH_POSITION_GRID("SugarPatch")
V[0]=VS(cur,"cur_sugar")
WRITES(cur,"cur_sugar",0)
RESULT(V[0])



MODELEND

// do not add Equations in this area

void close_sim( void )
{
	// close simulation special commands go here
}
