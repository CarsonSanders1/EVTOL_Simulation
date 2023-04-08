#include <iostream>
#include "Simulation.h"

int main()
{
	std::cout << "Hello Joby";

	Simulation* sim = new Simulation();

	sim->Simulate();
}