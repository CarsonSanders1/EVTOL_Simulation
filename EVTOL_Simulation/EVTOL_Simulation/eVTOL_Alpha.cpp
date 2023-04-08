#include "eVTOL_Alpha.h"

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

void eVTOL_Alpha::charge(bool* charger)
{
	//Todo
}