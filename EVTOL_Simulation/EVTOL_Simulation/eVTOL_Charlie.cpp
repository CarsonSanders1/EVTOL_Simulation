#include "eVTOL_Charlie.h"
#include <iostream>

float eVTOL_Charlie::totalFlightTime = 0;
int eVTOL_Charlie::totalFlights = 0;
float eVTOL_Charlie::totalDistanceTravelled = 0;
float eVTOL_Charlie::timeSpentCharging = 0;
int eVTOL_Charlie::chargeSessions = 0;
int eVTOL_Charlie::totalFaults = 0;
float eVTOL_Charlie::totalPassengerMiles = 0;
int eVTOL_Charlie::totalAircraft = 0;

eVTOL_Charlie::eVTOL_Charlie()
{
	this->cruiseSpeed = 160;
	this->batteryCapacity = 220;
	this->currentBattery = 220.0;
	this->timeToCharge = .8;
	this->energyUse = 2.2;
	this->passengerCount = 3;
	this->faultProbability = .05;
	this->totalAircraft += 1;
}

void eVTOL_Charlie::recordFlightData()
{
	this->totalFlightTime += .01;
	this->totalDistanceTravelled += (.01 * this->cruiseSpeed);
	////@Todo calculate fault
	this->totalPassengerMiles += (.01 * this->cruiseSpeed * this->passengerCount);
}

void eVTOL_Charlie::incrementTotalFlights()
{
	this->totalFlights += 1;
}

void eVTOL_Charlie::incrementTimeSpentCharging()
{
	this->timeSpentCharging += .01;
}

void eVTOL_Charlie::incrementChargeSessions()
{
	this->chargeSessions += .01;
}

void eVTOL_Charlie::printResults()
{
	std::cout << "\n Alpha Company Results: \n Total Aircraft: " << eVTOL_Charlie::totalAircraft << "\n Average Flight Time per flight: " << eVTOL_Charlie::totalFlightTime / eVTOL_Charlie::totalFlights;
	std::cout << "\n Average distance traveled per flight: " << eVTOL_Charlie::totalDistanceTravelled / eVTOL_Charlie::totalFlights << "\n Average time spent charging per session: " << eVTOL_Charlie::timeSpentCharging / eVTOL_Charlie::chargeSessions;
	std::cout << "\n Total Number of Faults: " << eVTOL_Charlie::totalFaults << "\n Total number of passenger miles: " << eVTOL_Charlie::totalPassengerMiles;
}