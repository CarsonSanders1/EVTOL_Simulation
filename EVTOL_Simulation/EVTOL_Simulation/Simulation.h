#pragma once
#include "eVTOL_Aircraft.h"
#include <vector>

class Simulation
{
public:

	Simulation();

	void Simulate();

private:

	const int AMOUNT_OF_AIRCRAFT = 20;

	const int AMOUNT_OF_CHARGERS = 3;

	//Total simulation time in hours
	const int SIMULATION_LENGTH = 3;

	float simulationTime;

	std::vector<eVTOL_Aircraft*> aircraft;

	std::vector<bool*> chargers;
};