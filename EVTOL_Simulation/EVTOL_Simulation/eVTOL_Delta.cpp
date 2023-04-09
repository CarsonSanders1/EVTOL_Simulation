#include "eVTOL_Delta.h"

float eVTOL_Delta::totalFlightTime = 0;
int eVTOL_Delta::totalFlights = 0;
float eVTOL_Delta::totalDistanceTravelled = 0;
float eVTOL_Delta::timeSpentCharging = 0;
int eVTOL_Delta::chargeSessions = 0;
int eVTOL_Delta::totalFaults = 0;
float eVTOL_Delta::totalPassengerMiles = 0;

eVTOL_Delta::eVTOL_Delta()
{
	this->cruiseSpeed = 90;
	this->batteryCapacity = 120;
	this->currentBattery = 120.0;
	this->timeToCharge = .62;
	this->energyUse = .8;
	this->passengerCount = 2;
	this->faultProbability = .22;
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