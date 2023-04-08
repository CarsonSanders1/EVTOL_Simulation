#pragma once

class eVTOL_Aircraft
{
public: 

	eVTOL_Aircraft();
	 
	/// Advance simulation by .01 hours
	void stepSimulation();

	virtual void charge(bool* charger) = 0;

	// 3 chargers to be used by all eVTOL_Aircraft. true = charger is available
	static bool* charger1;
	static bool* charger2;
	static bool* charger3;

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
};
