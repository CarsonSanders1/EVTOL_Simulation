#pragma once
#include "eVTOL_Aircraft.h"

class eVTOL_Echo : public eVTOL_Aircraft
{
public:

	//Constructor
	eVTOL_Echo();

	//Deconstructor
	~eVTOL_Echo();

	//Prints tracked results to the console
	static void printResults();

	void incrementFaults();

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