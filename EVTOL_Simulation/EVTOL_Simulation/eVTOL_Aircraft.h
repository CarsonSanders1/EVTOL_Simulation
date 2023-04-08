#pragma once

class eVTOL_Aircraft
{
public: 
	 
	/// Advance simulation by .01 hours
	void stepSimulation();

	virtual void charge(bool* charger) = 0;

protected:

	int cruiseSpeed;
	int batteryCapacity;
	float timeToCharge;
	float energyUse;
	int passengerCount;
	float faultProbability;

	int flightCount;
	float distanceTraveled;
	float passengerMiles;
};
