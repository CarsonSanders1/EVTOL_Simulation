#include "eVTOL_Charlie.h"

float eVTOL_Charlie::totalFlightTime = 0;
int eVTOL_Charlie::totalFlights = 0;
float eVTOL_Charlie::totalDistanceTravelled = 0;
float eVTOL_Charlie::timeSpentCharging = 0;
int eVTOL_Charlie::chargeSessions = 0;
int eVTOL_Charlie::totalFaults = 0;
float eVTOL_Charlie::totalPassengerMiles = 0;

eVTOL_Charlie::eVTOL_Charlie()
{
	this->cruiseSpeed = 160;
	this->batteryCapacity = 220;
	this->currentBattery = 220.0;
	this->timeToCharge = .8;
	this->energyUse = 2.2;
	this->passengerCount = 3;
	this->faultProbability = .05;
}

//step simulation .01 hours
void eVTOL_Charlie::stepSimulation()
{
	if (needsCharge)
	{
		charge();
	}
	else
	{
		//Update tracking data
		this->totalFlightTime += .01;
		this->totalDistanceTravelled += (.01 * this->cruiseSpeed);
		//@Todo calculate fault
		this->totalPassengerMiles += (.01 * this->cruiseSpeed * this->passengerCount);

		this->currentBattery -= (.01 * this->cruiseSpeed) * this->energyUse;

		if (currentBattery <= 0)
		{
			currentBattery = 0;
			this->needsCharge = true;
		}
	}
}

void eVTOL_Charlie::charge()
{
	if (!isCharging)
	{
		if (eVTOL_Aircraft::availableChargers <= 0)
		{
			//wait for charger to become available...
		}
		else
		{
			eVTOL_Aircraft::availableChargers -= 1;
			this->isCharging = true;
		}
	}

	if (isCharging)
	{
		auto chargeRate = this->batteryCapacity / this->timeToCharge;

		this->currentBattery += chargeRate * .01;

		this->timeSpentCharging += .01;

		//if finished charging
		if (this->currentBattery >= this->batteryCapacity)
		{
			this->chargeSessions += 1;
			this->isCharging = false;
			this->needsCharge = false;
			this->availableChargers += 1;
		}
	}
}