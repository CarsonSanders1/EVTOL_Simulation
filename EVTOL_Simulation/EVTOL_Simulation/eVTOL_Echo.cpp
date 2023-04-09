#include "eVTOL_Echo.h"
#include <iostream>

float eVTOL_Echo::totalFlightTime = 0;
int eVTOL_Echo::totalFlights = 0;
float eVTOL_Echo::totalDistanceTravelled = 0;
float eVTOL_Echo::timeSpentCharging = 0;
int eVTOL_Echo::chargeSessions = 0;
int eVTOL_Echo::totalFaults = 0;
float eVTOL_Echo::totalPassengerMiles = 0;
int eVTOL_Echo::totalAircraft = 0;


eVTOL_Echo::eVTOL_Echo()
{
	this->cruiseSpeed = 30;
	this->batteryCapacity = 150;
	this->currentBattery = 150.0;
	this->timeToCharge = .3;
	this->energyUse = 5.8;
	this->passengerCount = 2;
	this->faultProbability = .61;

	this->totalAircraft += 1;
}

void eVTOL_Echo::recordFlightData()
{
	this->totalFlightTime += .01;
	this->totalDistanceTravelled += (.01 * this->cruiseSpeed);
	////@Todo calculate fault
	this->totalPassengerMiles += (.01 * this->cruiseSpeed * this->passengerCount);
}

void eVTOL_Echo::incrementTotalFlights()
{
	this->totalFlights += 1;
}

void eVTOL_Echo::incrementTimeSpentCharging()
{
	this->timeSpentCharging += .01;
}

void eVTOL_Echo::incrementChargeSessions()
{
	this->chargeSessions += 1;
}

void eVTOL_Echo::printResults()
{
	std::cout << "\n \n Echo Company Results: \n Total Aircraft: " << eVTOL_Echo::totalAircraft << "\n Average Flight Time per flight: " << eVTOL_Echo::totalFlightTime / eVTOL_Echo::totalFlights;
	std::cout << "\n Average distance traveled per flight: " << eVTOL_Echo::totalDistanceTravelled / eVTOL_Echo::totalFlights << "\n Average time spent charging per session: " << eVTOL_Echo::timeSpentCharging / eVTOL_Echo::chargeSessions;
	std::cout << "\n Total Number of Faults: " << eVTOL_Echo::totalFaults << "\n Total number of passenger miles: " << eVTOL_Echo::totalPassengerMiles;
}