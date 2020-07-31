#include <iostream>

#include "World.h"
#include "Ant.h"
#include "PoisonousAnt.h"
#include "DoodleBug.h"

using namespace std;

int main(int argc, char const *argv[]){	
	
	World w;
	
	string s;

	srand(time(NULL)); // Seed random number generator

	// Randomly create 100 ants
	int antcount = 0;
	while (antcount < INITIALANTS){
		int x = rand() % WORLDSIZE;
		int y = rand() % WORLDSIZE;
		if (w.getAt(x,y)==NULL) // Only put ant in empty spot
		{
			antcount++;
			Ant *a1 = new Ant(&w,x,y);
		}
	}

	// Randomly create 5 doodlebugs
	int doodlecount = 0;
	while (doodlecount < INITIALBUGS){
		int x = rand() % WORLDSIZE;
		int y = rand() % WORLDSIZE;
		if (w.getAt(x,y)==NULL) {// Only put doodlebug in empty spot
		
			doodlecount++;
			DoodleBug *d1 = new DoodleBug(&w,x,y);
		}
	}
	
	// Run simulation until user cancels
	while (true){
		w.Display();
		w.SimulateOneStep();
		getline(cin,s);
	}
	
	return 0;
}
