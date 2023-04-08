#include "eVTOL_Delta.h"

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

void eVTOL_Delta::charge(bool* charger)
{
	//Todo
}