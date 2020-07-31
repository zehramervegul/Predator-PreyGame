#include <iostream>
#include <cstdlib>
#include <time.h>

#include "Ant.h"
#include "World.h"	
#include "PoisonousAnt.h"

using namespace std;

PoisonousAnt::PoisonousAnt() : Ant() {
	starveTicks = 0;
}

PoisonousAnt::PoisonousAnt(World *world, int x, int y) : Ant(world,x,y) {
	starveTicks = 0;
}

PoisonousAnt::~PoisonousAnt(){

}

void PoisonousAnt::breed(){

	int breedPoisonousAnt_x;
	int breedPoisonousAnt_y;

	breedPoisonousAnt_x = rand() % WORLDSIZE;
	breedPoisonousAnt_y = rand() % WORLDSIZE;

	breedTicks++;

	if (breedTicks == PANTBREED) {
		breedTicks = 0;

		//random cell
		if((world->getAt(breedPoisonousAnt_x,breedPoisonousAnt_y)==NULL))
			PoisonousAnt *newPoisonousAnt = new PoisonousAnt(world, breedPoisonousAnt_x, breedPoisonousAnt_y);

		else{
	// Try to make a new posionous ant either above, left, right, or down
			if ((y>0) && (world->getAt(x,y-1)==NULL)) {
				PoisonousAnt *newPoisonousAnt = new PoisonousAnt(world, x, y-1);
			}

			else if ((y<WORLDSIZE-1) && (world->getAt(x,y+1)==NULL)) {
				PoisonousAnt *newPoisonousAnt = new PoisonousAnt(world, x, y+1);
			}

			else if ((x>0) && (world->getAt(x-1,y)==NULL)) {
				PoisonousAnt *newPoisonousAnt = new PoisonousAnt(world, x-1, y);
			}

			else if ((x<WORLDSIZE-1) && (world->getAt(x+1,y)==NULL)) {
				PoisonousAnt *newPoisonousAnt = new PoisonousAnt(world, x+1, y);
			}

			else{
				remove(x+1,y);  // kill the last cell tried
			}

		}

	}	
}
	

void PoisonousAnt::move(){

	// Pick random direction to move
	int dir = rand() % 4;
// Try to move up, if not at an edge and empty spot
	if (dir==0) {
		if ((y>0) && (world->getAt(x,y-1)==NULL)) {
			world->setAt(x,y-1,world->getAt(x,y)); // Move to new spot
			world->setAt(x,y,NULL);
			y--;
			this->moved = true;
		}
	}

// Try to move down
	else if (dir==1) {
		if ((y<WORLDSIZE-1) && (world->getAt(x,y+1)==NULL)) {
			world->setAt(x,y+1,world->getAt(x,y)); // Move to new spot
			world->setAt(x,y,NULL); // Set current spot to empty
			y++;
			this->moved = true;
		}
	}

// Try to move left
	else if (dir==2) {
		if ((x>0) && (world->getAt(x-1,y)==NULL)) {
			world->setAt(x-1,y,world->getAt(x,y)); // Move to new spot
			world->setAt(x,y,NULL); // Set current spot to empty
			x--;
			this->moved = true;
		}
	}

// Try to move right
	else {
		if ((x<WORLDSIZE-1) && (world->getAt(x+1,y)==NULL)) {
			world->setAt(x+1,y,world->getAt(x,y)); // Move to new spot
			world->setAt(x,y,NULL); // Set current spot to empty
			x++;
			this->moved = true;
		}
	}


}
	
int PoisonousAnt::getType(){

	return POISONOUSANT;
}
	
bool PoisonousAnt::starve(){

	// Starve if no food eaten in last POISONOUSSTARVE time ticks
	if (starveTicks > POISONOUSSTARVE ) {
		return true;
	}

	else {
		return false;
	}


}
