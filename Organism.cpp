#include <iostream>

#include "World.h"

using namespace std;


// Organism Constructor
Organism::Organism() {
	world = NULL;
	moved = false;
	breedTicks = 0;
	x=0;
	y=0;
}

Organism::Organism(World *world, int x, int y) {
	this->world = world;  // Sets a reference back to the World object.
	moved = false;
	breedTicks = 0;
	this->x=x;
	this->y=y;
	world->setAt(x,y,this);
}

Organism::~Organism() {

}

//corresponding cell is assigned to NULL. So, the organism removed.
void Organism::remove(int x, int y){
	this->world->deleteOrganism(x,y);
}

// set the organism type
void Organism::set(int x, int y, Organism *org){
	this->world->setAt(x,y,org);
}