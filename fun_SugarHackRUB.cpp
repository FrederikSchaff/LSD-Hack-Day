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
	SET_LAT_COLORS(cur,3); //Yellow
	SET_LAT_PRIORITYS(cur,1);
}



PARAMETER //Only call method once
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

EQUATION("Gather")
/*
Comment
*/

RESULT( 0 )


//Sugar

EQUATION("Regrowth")
/*
Comment
*/

RESULT( 0 )


EQUATION("Gather_local")
/*
Comment
*/

RESULT( 0 )



MODELEND

// do not add Equations in this area

void close_sim( void )
{
	// close simulation special commands go here
}
