#include "eVTOL_Charlie.h"

eVTOL_Charlie::eVTOL_Charlie()
{
	this->cruiseSpeed = 160;
	this->batteryCapacity = 220;
	this->timeToCharge = .8;
	this->energyUse = 2.2;
	this->passengerCount = 3;
	this->faultProbability = .05;
}

void eVTOL_Charlie::charge(bool* charger)
{
	//Todo
}