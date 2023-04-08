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

//step simulation .01 hours
void eVTOL_Bravo::stepSimulation()
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

void eVTOL_Bravo::charge()
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