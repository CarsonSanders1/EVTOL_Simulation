#include "eVTOL_Bravo.h"

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

void eVTOL_Bravo::charge(bool* charger)
{
	//Todo
}