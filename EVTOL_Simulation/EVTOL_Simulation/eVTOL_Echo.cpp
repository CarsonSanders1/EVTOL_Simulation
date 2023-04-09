#include "eVTOL_Echo.h"

float eVTOL_Echo::totalFlightTime = 0;
int eVTOL_Echo::totalFlights = 0;
float eVTOL_Echo::totalDistanceTravelled = 0;
float eVTOL_Echo::timeSpentCharging = 0;
int eVTOL_Echo::chargeSessions = 0;
int eVTOL_Echo::totalFaults = 0;
float eVTOL_Echo::totalPassengerMiles = 0;


eVTOL_Echo::eVTOL_Echo()
{
	this->cruiseSpeed = 30;
	this->batteryCapacity = 150;
	this->currentBattery = 150.0;
	this->timeToCharge = .3;
	this->energyUse = 5.8;
	this->passengerCount = 2;
	this->faultProbability = .61;
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
	this->chargeSessions += .01;
}