#ifndef _DOODLEBUG_H
#define _DOODLEBUG_H

#include <iostream>

#include "World.h"

using namespace std;

class DoodleBug : Organism
{

friend class World;

public:

	DoodleBug();
	DoodleBug(World *world, int x, int y);

	void breed(); // Must define this since virtual
	void move(); // Must define this since virtual
	int getType(); // Must define this since virtual
	bool starve(); // Check if a doodlebug starves to death

private:
	int starveTicks; // Number of moves before starving
	
};

#endif