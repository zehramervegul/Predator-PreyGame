#include <iostream>

#include "DoodleBug.h"

using namespace std;

DoodleBug::DoodleBug() : Organism() {
	starveTicks = 0;
}

DoodleBug::DoodleBug(World *world, int x, int y) : Organism(world,x,y) {
	starveTicks = 0;
}

// Look up, down, left or right for a bug. If one is found, move there
// and eat it, resetting the starveTicks counter.
void DoodleBug::move(){
// Look in each direction and if a bug is found move there
// and eat it.

	if ((y>0) && (world->getAt(x,y-1)!=NULL) && (world->getAt(x,y-1)->getType() == ANT)) {
		
		remove(x,y-1);
		set(x,y-1,world->getAt(x,y));

		world->setAt(x,y,NULL); // free previous cell
		starveTicks =0 ; // Reset hunger
		y--;
		this->moved = true;
		return;


	}

	else if ((y<WORLDSIZE-1) && (world->getAt(x,y+1)!=NULL) && (world->getAt(x,y+1)->getType() == ANT)) {
		
		remove(x,y+1);
		set(x,y+1,world->getAt(x,y));
		
		world->setAt(x,y,NULL);
		starveTicks =0 ; // Reset hunger
		y++;
		this->moved = true;
		return;
	}

	else if ((x>0) && (world->getAt(x-1,y)!=NULL) && (world->getAt(x-1,y)->getType() == ANT)) {
		
		remove(x-1,y);

		set(x-1,y,world->getAt(x,y));

		world->setAt(x,y,NULL);
		starveTicks =0 ; // Reset hunger
		x--;
		this->moved = true;
		return;
	}

	else if ((x<WORLDSIZE-1) && (world->getAt(x+1,y)!=NULL) && (world->getAt(x+1,y)->getType() == ANT)) {
		
		remove(x+1,y);
		set(x+1,y,world->getAt(x,y));

		world->setAt(x,y,NULL);
		starveTicks =0 ; // Reset hunger
		x++;
		this->moved = true;
		return;
	}

	
	int dir = rand() % 4;
// Try to move up, if not at an edge and empty spot
	if (dir==0) {
		if ((y>0) && (world->getAt(x,y-1)==NULL)) {
			world->setAt(x,y-1,world->getAt(x,y)); // Move to new spot
			world->setAt(x,y,NULL);
			y--;
		}
	}

// Try to move down
	else if (dir==1) {
		if ((y<WORLDSIZE-1) && (world->getAt(x,y+1)==NULL)) {
			world->setAt(x,y+1,world->getAt(x,y)); // Move to new spotworld->setAt(x,y,NULL); // Set current spot to empty
			world->setAt(x,y,NULL);
			y++;
		}
	
	}

// Try to move left
	else if (dir==2) {
		if ((x>0) && (world->getAt(x-1,y)==NULL)) {
			world->setAt(x-1,y,world->getAt(x,y)); // Move to new spot
			world->setAt(x,y,NULL); // Set current spot to empty
			x--;
		}
	}

// Try to move right
	else {
		if ((x<WORLDSIZE-1) && (world->getAt(x+1,y)==NULL)) {
			world->setAt(x+1,y,world->getAt(x,y)); // Move to new spot
			world->setAt(x,y,NULL); // Set current spot to empty
			x++;
		}
	}

	starveTicks++; // Increment starve tick since we didn't
	this->moved = true;
// eat on this turn
}


//determine what type of organism 
int DoodleBug::getType() {
	return DOODLEBUG;
}


// Creates a new DoodleBug adjacent to the current cell
void DoodleBug::breed() {

	breedTicks++;

	if (breedTicks == DOODLEBREED) {
		breedTicks = 0;
// Try to make a new ant either above, left, right, or down
		if ((y>0) && (world->getAt(x,y-1)==NULL)) {
			DoodleBug *newDoodle = new DoodleBug(world, x, y-1);
		}

		else if ((y<WORLDSIZE-1) && (world->getAt(x,y+1)==NULL)) {
			DoodleBug *newDoodle = new DoodleBug(world, x, y+1);
		}

		else if ((x>0) && (world->getAt(x-1,y)==NULL)) {
			DoodleBug *newDoodle = new DoodleBug(world, x-1, y);
		}

		else if ((x<WORLDSIZE-1) && (world->getAt(x+1,y)==NULL)) {
			DoodleBug *newDoodle = new DoodleBug(world, x+1, y);
		}
	}
}

// Returns true or false if a DoodleBug should die off
bool DoodleBug::starve() {
// Starve if no food eaten in last DOODLESTARVE time ticks
	if (starveTicks > DOODLESTARVE) {
		return true;
	}

	else {
		return false;
	}

}
