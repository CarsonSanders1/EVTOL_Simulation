#include "eVTOL_Delta.h"
#include <iostream>

float eVTOL_Delta::totalFlightTime = 0;
int eVTOL_Delta::totalFlights = 0;
float eVTOL_Delta::totalDistanceTravelled = 0;
float eVTOL_Delta::timeSpentCharging = 0;
int eVTOL_Delta::chargeSessions = 0;
int eVTOL_Delta::totalFaults = 0;
float eVTOL_Delta::totalPassengerMiles = 0;
int eVTOL_Delta::totalAircraft = 0;

eVTOL_Delta::eVTOL_Delta()
{
	this->cruiseSpeed = 90;
	this->batteryCapacity = 120;
	this->currentBattery = 120.0;
	this->timeToCharge = .62;
	this->energyUse = .8;
	this->passengerCount = 2;
	this->faultProbability = .22;

	this->totalAircraft += 1;
}

void eVTOL_Delta::recordFlightData()
{
	this->totalFlightTime += .01;
	this->totalDistanceTravelled += (.01 * this->cruiseSpeed);
	////@Todo calculate fault
	this->totalPassengerMiles += (.01 * this->cruiseSpeed * this->passengerCount);
}

void eVTOL_Delta::incrementTotalFlights()
{
	this->totalFlights += 1;
}

void eVTOL_Delta::incrementTimeSpentCharging()
{
	this->timeSpentCharging += .01;
}

void eVTOL_Delta::incrementChargeSessions()
{
	this->chargeSessions += .01;
}

void eVTOL_Delta::printResults()
{
	std::cout << "\n Alpha Company Results: \n Total Aircraft: " << eVTOL_Delta::totalAircraft << "\n Average Flight Time per flight: " << eVTOL_Delta::totalFlightTime / eVTOL_Delta::totalFlights;
	std::cout << "\n Average distance traveled per flight: " << eVTOL_Delta::totalDistanceTravelled / eVTOL_Delta::totalFlights << "\n Average time spent charging per session: " << eVTOL_Delta::timeSpentCharging / eVTOL_Delta::chargeSessions;
	std::cout << "\n Total Number of Faults: " << eVTOL_Delta::totalFaults << "\n Total number of passenger miles: " << eVTOL_Delta::totalPassengerMiles;
}