#pragma once
#include "eVTOL_Aircraft.h"
#include <vector>

///
/// The purpose of this class is to drive the simulation of the eVTOL_Aircraft
/// 
class Simulation
{
public:

	Simulation();

	//Drives simulation. Simulates in .01 Hour steps
	void Simulate();

	//Prints results from all aircraft types
	void printResults();

private:

	/// 
	/// \brief Calculates whether a fault occured or not, given a faultProbability
	/// 
	/// \param faultProbabiltiy the probability of a fault occuring
	/// 
	bool calculateFault(float faultProbability);

	/// Amount of aircraft to spawn for simulation
	const int AMOUNT_OF_AIRCRAFT = 20;

	//Total simulation time in hours
	const int SIMULATION_LENGTH = 3;

	// Current time of simulation
	float simulationTime;

	std::vector<eVTOL_Aircraft*> aircraft;
};