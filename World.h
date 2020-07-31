#ifndef WORLD_H_
#define WORLD_H_


const int WORLDSIZE = 20;
const int INITIALANTS = 100;
const int INITIALBUGS = 5;
const int DOODLEBUG = 1;
const int ANT = 2;
const int POISONOUSANT = 3;
const int ANTBREED = 3;
const int PANTBREED = 4;
const int DOODLEBREED = 8;
const int DOODLESTARVE = 3;
const int POISONOUSSTARVE = 3;


class Organism;
class DoodleBug;
class Ant;
class PoisonousAnt;


// World Class
class World
{
	friend class Organism; // Allow Organism to access grid
	friend class DoodleBug; // Allow Organism to access grid
	friend class Ant; // Allow Organism to access grid
	friend class PoisonousAnt;

public:

	World();
	~World();

	Organism* getAt(int x, int y);
	void setAt(int x, int y, Organism *org);
	void Display();
	void SimulateOneStep();
	void deleteOrganism(int x, int y);

protected:
	Organism* grid[WORLDSIZE][WORLDSIZE];  //creating a WORLDSIZE by WORLDSIZE array of type Organism

private:
	bool isFirstTime = true;
	
};


// Organism base class. 
class Organism {

friend class World; // Allow world to affect organism

public:

	Organism();
	Organism(World *world, int x, int y);
	~Organism();
	
	virtual void breed() = 0; // Whether or not to breed
	virtual void move() = 0; // Rules to move the critter
	virtual int getType() = 0; // Return if ant, poisonous ant or doodlebug
	virtual bool starve() = 0; // Determine if organism starves

protected:

	int x,y; // Position in the world
	bool moved; // Bool to indicate if moved this turn
	int breedTicks; // Number of ticks since breeding
	World *world;   //Each organism has a reference back to the World object so it can move itself  about in the world.

	void remove(int x, int y); //corresponding cell is assigned to NULL. So, the organism removed.
	void set(int x, int y, Organism *org); // set the organism type

};


#endif