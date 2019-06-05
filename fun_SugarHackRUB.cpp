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

ABMAT_ADD_MICRO("Move");

//Create the GIS, as it is the main GIS root is part
INIT_SPACE_ROOT(V("x_size"),V("y_size"));

//Create a graphical Representation
INIT_LAT_GIS(0);


//Create missing agents
double add_agents = V("n_agent")-1;//one exists already
if (add_agents > 0){
	ADDNOBJ("Agent",add_agents); 
}

//Add them to the space, they may share the same position
CYCLE(cur,"Agent"){
	ADD_TO_SPACE_RND_GRIDS(cur,root); //add to random position, snap to grid
	SET_LAT_COLORS(cur,5); //Blue
	SET_LAT_PRIORITYS(cur,2);
}

//Add the Sugar to random positions, create missing sugar. No two SugarPots at the same place.
double amount_sugar_patches =  floor(	V("x_size") * V("y_size") * V("rel_sugar") -1);
if (amount_sugar_patches > 0) {
	ADDNOBJ("SugarPatch",amount_sugar_patches); 	
}

ADD_TO_SPACE_RNDS(SEARCH("SugarPatch"),root);



//Initialise the Sugar parameters

CYCLE(cur,"SugarPatch"){
	WRITES(cur,"Amount",RND); //in 0 and 1
	WRITES(cur,"max_sugar",RND);
	//SET_LAT_COLORS(cur,3); //Yellow
	//SET_LAT_PRIORITYS(cur,1);
}



PARAMETER //Only call method once
RESULT( 0 )

//Agents

EQUATION("Move")
PLOG("\nMove");
/*
The agent moves in a random direction.
*/

double where = uniform_int(0,8);
MOVE(where);

RESULT( where )


EQUATION("Metabolism")
/*
Comment
*/

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
PLOG("\nGather");

V("x_size");
cur = SEARCH_POSITION("SugarPatch") ;

if( V("stock_sugar") < 1) { 
  if(cur != NULL) { 
    WRITE("stock_sugar", (V("stock_sugar") + VS(cur, "amount")));
   }
}


if( V("stock_sugar") > 1 ) { 
  WRITE("stock_sugar",1); 
}


RESULT( 0 )


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
Gives the number of suger available
*/
cur = SEARCH_POSITION_GRID("SugarPatch");
v[0]=VS(cur,"cur_sugar");
WRITES(cur,"cur_sugar",0);
RESULT(v[0])


MODELEND

// do not add Equations in this area

void close_sim( void )
{
	// close simulation special commands go here
}
