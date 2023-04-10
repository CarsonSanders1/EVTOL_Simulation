#include "eVTOL_Aircraft.h"
#include <cstdlib>
#include <ctime>

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
			
			//Increments total flights when battery is dead. This is assuming that each flight lasts for the entire battery duration of the aircraft.
			//@TODO:Implement flight system with random distances
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
			this->chargeTimeRemaining = this->timeToCharge;
			eVTOL_Aircraft::availableChargers -= 1;

			//Track how many times this type of aircraft has stopped to charge
			incrementChargeSessions();
			this->isCharging = true;
		}
	}

	if (isCharging)
	{
		this->chargeTimeRemaining -= .01;

		incrementTimeSpentCharging();

		//if finished charging
		if (this->chargeTimeRemaining <= 0)
		{
			this->isCharging = false;
			this->needsCharge = false;
			this->availableChargers += 1;
		}
	}
}

float eVTOL_Aircraft::getFaultProbability()
{
	return this->faultProbability;
}