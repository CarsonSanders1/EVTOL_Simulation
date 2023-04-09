#include "eVTOL_Alpha.h"
#include <iostream>

float eVTOL_Alpha::totalFlightTime = 0;
int eVTOL_Alpha::totalFlights = 0;
float eVTOL_Alpha::totalDistanceTravelled = 0;
float eVTOL_Alpha::timeSpentCharging = 0;
int eVTOL_Alpha::chargeSessions = 0;
int eVTOL_Alpha::totalFaults = 0;
float eVTOL_Alpha::totalPassengerMiles = 0;
int eVTOL_Alpha::totalAircraft = 0;

eVTOL_Alpha::eVTOL_Alpha()
{
	this->cruiseSpeed = 120;
	this->batteryCapacity = 320;
	this->currentBattery = 320.0;
	this->timeToCharge = .6;
	this->energyUse = 1.6;
	this->passengerCount = 4;
	this->faultProbability = .25;

	this->totalAircraft += 1;
}

void eVTOL_Alpha::recordFlightData()
{
	this->totalFlightTime += .01;
	this->totalDistanceTravelled += (.01 * this->cruiseSpeed);
	////@Todo calculate fault
	this->totalPassengerMiles += (.01 * this->cruiseSpeed * this->passengerCount);
}

void eVTOL_Alpha::incrementTotalFlights()
{
	this->totalFlights += 1;
}

void eVTOL_Alpha::incrementTimeSpentCharging()
{
	this->timeSpentCharging += .01;
}

void eVTOL_Alpha::incrementChargeSessions()
{
	this->chargeSessions += .01;
}

void eVTOL_Alpha::printResults()
{
	std::cout << "\n Alpha Company Results: \n Total Aircraft: " << eVTOL_Alpha::totalAircraft << "\n Average Flight Time per flight: " << eVTOL_Alpha::totalFlightTime / eVTOL_Alpha::totalFlights;
	std::cout << "\n Average distance traveled per flight: " << eVTOL_Alpha::totalDistanceTravelled / eVTOL_Alpha::totalFlights << "\n Average time spent charging per session: " << eVTOL_Alpha::timeSpentCharging / eVTOL_Alpha::chargeSessions;
	std::cout << "\n Total Number of Faults: " << eVTOL_Alpha::totalFaults << "\n Total number of passenger miles: " << eVTOL_Alpha::totalPassengerMiles;
}