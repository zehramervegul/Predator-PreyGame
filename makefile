all: output

output: main.o World.o Organism.cpp DoodleBug.o Ant.o PoisonousAnt.cpp
	g++ main.o World.o Organism.cpp DoodleBug.o Ant.o PoisonousAnt.cpp -o output

main.o: main.cpp
	g++ -c main.cpp -std=c++11

World.o:World.cpp
	g++ -c World.cpp -std=c++11

Organism.o: Organism.cpp
	g++ -c Organism.cpp -std=c++11	

DoodleBug.o: DoodleBug.cpp
	g++ -c DoodleBug.cpp -std=c++11

Ant.o: Ant.cpp
	g++ -c Ant.cpp -std=c++11

PoisonousAnt.o:PoisonousAnt.cpp
	g++ -c PoisonousAnt.cpp -std=c++11	

run : 
	./output

clean:
	rm -rf *.o output
	