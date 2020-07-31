# Predator-Prey Game


## Description

The goal for this  project is to create a simple 2D predator-prey simulation. In this simulation the prey are ants and the predators are doodlebugs.

## Game rules

The ants :
 •Move. Every time step, randomly try to move up, down, left or right. If the neighboring cell in the selecteddirection is occupied or would move the ant off the grid, then the ant stays in the current cell.
 •Breed. If an ant survives for three time steps, then at the end of the time step (i.e. after moving) the ant will breed. This is simulated by creating a new ant in an adjacent (up, down, left, or right) cell that is empty. If there is no empty cell available then no breeding occurs. Once an offspring is produced an ant cannot producean offspring until three more time steps have elapsed. There is a possibility of mutation. Randomly, with a small probability, the new ant can be a mutated version. Randomly mutate an ant make it poisonous. If apoisonous ant breeds, the new ant is also poisonous.

The poisonous ants :
•Move. Every time step, randomly try to move up, down, left or right. If the selected direction would move theant off the grid, then the poisonous ant stays in the current cell.
•Breed. If a poisonous ant survives for four time steps, then at the end of the time step (i.e. after moving) theant will breed. This is simulated by creating a new poisonous ant in an adjacent (up, down, left, or right) cellthat is empty. If the randomly selected cell is not empty, the poisonous ant looks for other adjacent cells. If the selected cell is empty a new poisonous ant is created in the selected cell. If all of the adjacent cells are occupied, the new poisonous ant fights and kills the occupant in the last cell tried(killing means replacing)Once an offspring(the new poisonous ant) is produced an ant cannot produce an offspring until four more timesteps have elapsed.

The doodlebugs :
•Move. Every time step, if there is an adjacent ant (up, down, left, or right) then the doodlebug will move tothat cell and eat the ant. Otherwise the doodlebug moves according to the same rules as the ant. Note that adoodlebug cannot eat other doodlebugs.
•Breed. If a doodlebug survives for eight time steps, then at the end of the time step it will spawn off a newdoodlebug in the same manner as the ant.
•Starve. If a doodlebug has not eaten an ant within the last three time steps, then at the end of the third timestep it will starve and die. The doodlebug should then be removed from the grid of cells.
•A doodlebug can eat ants and poisonous ants. If a doodlebug eats a poisonous ant, it can only live two timesteps.

### Executing program

* Type below in your terminal
```
make
```
* And then type to run
```
make run
```
* And then type at the end
```
make clean
```

## Authors

Zehra Merve Gül


## Version History

* 0.1
    * Initial Release
