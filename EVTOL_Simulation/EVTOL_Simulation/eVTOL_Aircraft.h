#pragma once

class eVTOL_Aircraft
{
public: 

	eVTOL_Aircraft();
	 
	/// Advance simulation by .01 hours
	void stepSimulation();

	float getFaultProbability();

	// Increment the amount of faults recorded per aircraft type
	virtual void incrementFaults() = 0;

protected:

	void charge();

	virtual void recordFlightData() = 0;

	virtual void incrementTotalFlights() = 0;

	virtual void incrementTimeSpentCharging() = 0;

	virtual void incrementChargeSessions() = 0;

	static int availableChargers;

	int cruiseSpeed;
	int batteryCapacity;
	float currentBattery;
	float timeToCharge;
	float chargeTimeRemaining;
	float energyUse;
	int passengerCount;
	float faultProbability;

	int flightCount;
	float distanceTraveled;
	float passengerMiles;

	bool needsCharge = false;
	bool isCharging = false;
};
