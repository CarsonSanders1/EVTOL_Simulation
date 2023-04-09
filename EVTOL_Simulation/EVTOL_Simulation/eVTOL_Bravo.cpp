#include "eVTOL_Bravo.h"
#include <iostream>

float eVTOL_Bravo::totalFlightTime = 0;
int eVTOL_Bravo::totalFlights = 0;
float eVTOL_Bravo::totalDistanceTravelled = 0;
float eVTOL_Bravo::timeSpentCharging = 0;
int eVTOL_Bravo::chargeSessions = 0;
int eVTOL_Bravo::totalFaults = 0;
float eVTOL_Bravo::totalPassengerMiles = 0;
int eVTOL_Bravo::totalAircraft = 0;

eVTOL_Bravo::eVTOL_Bravo()
{
	this->cruiseSpeed = 100;
	this->batteryCapacity = 100;
	this->currentBattery = 100.0;
	this->timeToCharge = .2;
	this->energyUse = 1.5;
	this->passengerCount = 5;
	this->faultProbability = .1;

	this->totalAircraft += 1;
}

void eVTOL_Bravo::recordFlightData()
{
	this->totalFlightTime += .01;
	this->totalDistanceTravelled += (.01 * this->cruiseSpeed);
	////@Todo calculate fault
	this->totalPassengerMiles += (.01 * this->cruiseSpeed * this->passengerCount);
}

void eVTOL_Bravo::incrementTotalFlights()
{
	this->totalFlights += 1;
}

void eVTOL_Bravo::incrementTimeSpentCharging()
{
	this->timeSpentCharging += .01;
}

void eVTOL_Bravo::incrementChargeSessions()
{
	this->chargeSessions += .01;
}

void eVTOL_Bravo::printResults()
{
	std::cout << "\n Bravo Company Results: \n Total Aircraft: " << eVTOL_Bravo::totalAircraft << "\n Average Flight Time per flight: " << eVTOL_Bravo::totalFlightTime / eVTOL_Bravo::totalFlights;
	std::cout << "\n Average distance traveled per flight: " << eVTOL_Bravo::totalDistanceTravelled / eVTOL_Bravo::totalFlights << "\n Average time spent charging per session: " << eVTOL_Bravo::timeSpentCharging / eVTOL_Bravo::chargeSessions;
	std::cout << "\n Total Number of Faults: " << eVTOL_Bravo::totalFaults << "\n Total number of passenger miles: " << eVTOL_Bravo::totalPassengerMiles;
}