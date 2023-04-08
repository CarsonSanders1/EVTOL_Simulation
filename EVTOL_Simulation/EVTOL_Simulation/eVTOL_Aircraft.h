#pragma once

class eVTOL_Aircraft
{
public: 

	eVTOL_Aircraft();
	 
	/// Advance simulation by .01 hours
	virtual void stepSimulation() = 0;

	virtual void charge() = 0;

	static int availableChargers;

protected:

	int cruiseSpeed;
	int batteryCapacity;
	float currentBattery;
	float timeToCharge;
	float energyUse;
	int passengerCount;
	float faultProbability;

	int flightCount;
	float distanceTraveled;
	float passengerMiles;

	bool needsCharge = false;
	bool isCharging = false;
};
