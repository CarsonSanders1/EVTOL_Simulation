#pragma once
#include "eVTOL_Aircraft.h"

class eVTOL_Delta : public eVTOL_Aircraft
{
public:

	//Constructor
	eVTOL_Delta();

	//Deconstructor
	~eVTOL_Delta();

	static void printResults();

private:

	void recordFlightData();

	void incrementTotalFlights();

	void incrementTimeSpentCharging();

	void incrementChargeSessions();

	//Per Vehicle type statistics to track
	static float totalFlightTime;
	static int totalFlights;
	static float totalDistanceTravelled;

	static float timeSpentCharging;
	static int chargeSessions;

	static int totalFaults;

	static float totalPassengerMiles;

	static int totalAircraft;
	
};