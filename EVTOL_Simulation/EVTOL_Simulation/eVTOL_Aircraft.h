#pragma once

/// 
/// This class serves as an abstract base class for the different types of eVTOL aircraft
/// 
class eVTOL_Aircraft
{
public: 
	 
	/// Advance simulation by .01 hours
	void stepSimulation();

	// Returns the fault probability for use with simulation class
	float getFaultProbability();

	// Increment the amount of faults recorded per aircraft type
	virtual void incrementFaults() = 0;

protected:

	//Waits for available charger/Simulates charging .01 hours
	void charge();

	// Records the flight data that occured during that frame of the simulation
	virtual void recordFlightData() = 0;

	// Adds to the total flight count of the specific company type of eVTOl
	virtual void incrementTotalFlights() = 0;

	// Increases the total time spent charging by .01 hours. Tracked per vehicle type
	virtual void incrementTimeSpentCharging() = 0;

	//Increases the total charge sessions by 1. Tracked per vehicle type
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
