#include "eVTOL_Echo.h"

float eVTOL_Echo::totalFlightTime = 0;
int eVTOL_Echo::totalFlights = 0;
float eVTOL_Echo::totalDistanceTravelled = 0;
float eVTOL_Echo::timeSpentCharging = 0;
int eVTOL_Echo::chargeSessions = 0;
int eVTOL_Echo::totalFaults = 0;
float eVTOL_Echo::totalPassengerMiles = 0;


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

//step simulation .01 hours
void eVTOL_Echo::stepSimulation()
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

void eVTOL_Echo::charge()
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