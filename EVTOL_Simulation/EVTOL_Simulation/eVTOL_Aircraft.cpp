#include "eVTOL_Aircraft.h"

//Initialize Chargers
int eVTOL_Aircraft::availableChargers = 3;

eVTOL_Aircraft::eVTOL_Aircraft()
{

}

//Simulate .01 hours
void eVTOL_Aircraft::stepSimulation()
{
	if (needsCharge)
	{
		charge();
	}
	else
	{
		//Update tracking data
		recordFlightData();

		this->currentBattery -= (.01 * this->cruiseSpeed) * this->energyUse;

		if (currentBattery <= 0)
		{
			currentBattery = 0;
			incrementTotalFlights();
			this->needsCharge = true;
		}
	}
}

void eVTOL_Aircraft::charge()
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

		//this->timeSpentCharging += .01;
		incrementTimeSpentCharging();

		//if finished charging
		if (this->currentBattery >= this->batteryCapacity)
		{
			//this->chargeSessions += 1;
			incrementChargeSessions();
			this->isCharging = false;
			this->needsCharge = false;
			this->availableChargers += 1;
		}
	}
}