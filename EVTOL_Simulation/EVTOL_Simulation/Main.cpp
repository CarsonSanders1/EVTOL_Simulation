#include <iostream>
//#include <gtest/gtest.h>
#include "Simulation.h"

int main()//int argc, char* argv[])
{
	std::cout << "Hello Joby";

	Simulation* sim = new Simulation();

	sim->Simulate();

	sim->printResults();

	//testing::InitGoogleTest(&argc, argv);
	//return RUN_ALL_TESTS();
}