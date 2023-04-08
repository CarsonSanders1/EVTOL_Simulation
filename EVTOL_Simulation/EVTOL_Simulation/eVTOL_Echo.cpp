#include "eVTOL_Echo.h"

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

void eVTOL_Echo::charge(bool* charger)
{
	//Todo
}