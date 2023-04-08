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

//step simulation .01 hours
void eVTOL_Delta::stepSimulation()
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

void eVTOL_Delta::charge()
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