#ifndef ANT_H_
#define ANT_H_

#include <iostream>
#include "World.h"

using namespace std;

class Ant : public Organism
{

friend class World;
	
public:

	Ant();
	Ant(World *world, int x, int y);

	void breed(); // Must define this since virtual
	void move(); // Must define this since virtual
	int getType(); // Must define this since virtual
	bool starve() // Return false, ant never starves
	{ return false; 
	}	
	
};

#endif