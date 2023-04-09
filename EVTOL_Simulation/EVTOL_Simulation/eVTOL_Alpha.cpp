#include "eVTOL_Alpha.h"

float eVTOL_Alpha::totalFlightTime = 0;
int eVTOL_Alpha::totalFlights = 0;
float eVTOL_Alpha::totalDistanceTravelled = 0;
float eVTOL_Alpha::timeSpentCharging = 0;
int eVTOL_Alpha::chargeSessions = 0;
int eVTOL_Alpha::totalFaults = 0;
float eVTOL_Alpha::totalPassengerMiles = 0;

eVTOL_Alpha::eVTOL_Alpha()
{
	this->cruiseSpeed = 120;
	this->batteryCapacity = 320;
	this->currentBattery = 320.0;
	this->timeToCharge = .6;
	this->energyUse = 1.6;
	this->passengerCount = 4;
	this->faultProbability = .25;
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