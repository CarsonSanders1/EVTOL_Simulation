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

//step simulation .01 hours
void eVTOL_Alpha::stepSimulation()
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

void eVTOL_Alpha::charge()
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