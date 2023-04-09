#include "eVTOL_Bravo.h"

float eVTOL_Bravo::totalFlightTime = 0;
int eVTOL_Bravo::totalFlights = 0;
float eVTOL_Bravo::totalDistanceTravelled = 0;
float eVTOL_Bravo::timeSpentCharging = 0;
int eVTOL_Bravo::chargeSessions = 0;
int eVTOL_Bravo::totalFaults = 0;
float eVTOL_Bravo::totalPassengerMiles = 0;

eVTOL_Bravo::eVTOL_Bravo()
{
	this->cruiseSpeed = 100;
	this->batteryCapacity = 100;
	this->currentBattery = 100.0;
	this->timeToCharge = .2;
	this->energyUse = 1.5;
	this->passengerCount = 5;
	this->faultProbability = .1;
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