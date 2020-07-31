#include "World.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;


// World constructor
World::World() {

	int i,j;

	for (i=0; i<WORLDSIZE; i++) {
		for (j=0; j<WORLDSIZE; j++){
			grid[i][j]=NULL;
		}
	}
}

World::~World() {
	
}


// Returns the entry stored in the grid array at x,y
Organism* World::getAt(int x, int y) {
	if ((x>=0) && (x<WORLDSIZE) && (y>=0) && (y<WORLDSIZE))
		return grid[x][y];
	return NULL;
}

// Sets the entry at x,y to the value passed in
void World::setAt(int x, int y, Organism *org) {
	if ((x>=0) && (x<WORLDSIZE) && (y>=0) && (y<WORLDSIZE)) {
		grid[x][y] = org;
	}
}


// Displays the world in ASCII. Uses o for ant, c for poisonous ant, X for doodlebug.
void World::Display() {

	int i,j;

	cout  << endl;

	for (j=0; j<WORLDSIZE; j++) {

		cout << "  ";

		for (i=0; i<WORLDSIZE; i++) {
			if (grid[i][j]==NULL)
				cout << ".";
			else if (grid[i][j]->getType() == ANT)
				cout << "o";
			else if(grid[i][j]->getType() == DOODLEBUG)
				cout << "X";
			else if (grid[i][j]->getType() == POISONOUSANT)
				cout << "c";
			
		}

	cout << endl;
	}

}


// This is the main routine that simulates one turn in the world.
void World::SimulateOneStep() {
	int i,j;
// First reset all organisms to not moved
	if(this->isFirstTime){
		this->isFirstTime = false;
		for (i=0; i<WORLDSIZE; i++){
			for (j=0; j<WORLDSIZE; j++) {
				if (grid[i][j]!=NULL)
					grid[i][j]->moved = false;
			}
		}	

	}
	
// Loop through cells in order and move if it's a Doodlebug
	
	for (i=0; i<WORLDSIZE; i++){
		for (j=0; j<WORLDSIZE; j++) {
			if ((grid[i][j]!=NULL) && (grid[i][j]->getType() == DOODLEBUG)) {
								
					grid[i][j]->move();				
				
				
			}
		}
	}	

	
// Loop through cells in order and move if it's an Ant 
	
	for(i = 0; i < WORLDSIZE; i++){
		for (j=0; j<WORLDSIZE; j++) {

			if ((grid[i][j]!=NULL) && (grid[i][j]->getType()==ANT)) {
				
					grid[i][j]->move();
				
			}
		}
	}

	

// Loop through cells in order and check if we should breed
	for (i=0; i<WORLDSIZE; i++){

		for (j=0; j<WORLDSIZE; j++) {
// Kill off any doodlebugs that haven't eaten recently
			if ((grid[i][j]!=NULL) && (grid[i][j]->getType()==DOODLEBUG)) {
				if (grid[i][j]->starve()) {
					
					grid[i][j] = NULL;
				}
			}
		}
	}	
	

// Loop through cells in order and check if we should breed
	for (i=0; i<WORLDSIZE; i++){
		for (j=0; j<WORLDSIZE; j++){
		// Only breed organisms that have moved, since
		// breeding places new organisms on the map we
		// don't want to try and breed those
			if ((grid[i][j]!=NULL) && (grid[i][j]->moved==true)) {
				grid[i][j]->breed();
			}
		}
	}

}

void World::deleteOrganism(int x, int y){
	grid[x][y] = NULL;
}

