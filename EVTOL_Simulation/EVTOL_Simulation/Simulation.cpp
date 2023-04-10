#include "Simulation.h"
#include "eVTOL_Alpha.h"
#include "eVTOL_Bravo.h"
#include "eVTOL_Charlie.h"
#include "eVTOL_Delta.h"
#include "eVTOL_Echo.h"
#include <iostream>
#include <random>

Simulation::Simulation()
{
	// Seed the random number generator
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, 4);

	for (int i = 0; i < AMOUNT_OF_AIRCRAFT; i++)
	{
		int companyIndex = dist(gen);

        // Select the company based on the randomly generated index
        switch (companyIndex)
        {
            case 0:
                this->aircraft.push_back(new eVTOL_Alpha());
                break;
            case 1:
                this->aircraft.push_back(new eVTOL_Bravo());
                break;
            case 2:
                this->aircraft.push_back(new eVTOL_Charlie());
                break;
            case 3:
                this->aircraft.push_back(new eVTOL_Delta());
                break;
            case 4:
                this->aircraft.push_back(new eVTOL_Echo());
                break;
        }	
	}

    this->simulationTime = 0;
}

void Simulation::Simulate()
{
    while (this->simulationTime < SIMULATION_LENGTH)
    {
        for (eVTOL_Aircraft* aCraft : aircraft)
        {
            aCraft->stepSimulation();

            //if simulationTime is on a whole number (i.e every hour)
            if (floor(this->simulationTime) == this->simulationTime)
            {
                //calculate fault chance
                if (calculateFault(aCraft->getFaultProbability()))
                {
                    aCraft->incrementFaults();
                }
            }
        }

        this->simulationTime += .01;
    }
}

void Simulation::printResults()
{
    eVTOL_Alpha::printResults();
    eVTOL_Bravo::printResults();
    eVTOL_Charlie::printResults();
    eVTOL_Delta::printResults();
    eVTOL_Echo::printResults();
}


bool Simulation::calculateFault(float faultProbability)
{
    // Seed the random number generator with current time
    std::srand(std::time(0));

    // Generate a random float between 0 and 1
    float random = static_cast<float>(std::rand()) / RAND_MAX;

    // Check if the random float is less than the given probability
    if (random < faultProbability) {
        // Fault occurs
        return true;
    }
    else {
        // No fault
        return false;
    }
}
