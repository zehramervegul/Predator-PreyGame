#ifndef _POISONOUS_H
#define _POISONOUS_H

#include <iostream>

#include "Ant.h"
#include "World.h"

using namespace std;

class PoisonousAnt : public Ant 
{

	friend class World;
	
public:
	PoisonousAnt();
	PoisonousAnt(World*, int, int);
	~PoisonousAnt();

	void breed(); // Must define this since virtual
	void move(); // Must define this since virtual
	int getType(); // Must define this since virtual
	bool starve(); // Return false, ant never starves
	
private:
	int starveTicks; // Number of moves before starving
	
};

#endif