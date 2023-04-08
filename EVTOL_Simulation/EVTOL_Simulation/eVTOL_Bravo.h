#pragma once
#include "eVTOL_Aircraft.h"

class eVTOL_Bravo : public eVTOL_Aircraft
{
public:

	//Constructor
	eVTOL_Bravo();

	//Deconstructor
	~eVTOL_Bravo();

	void charge(bool* charger);

private:
	//Per Vehicle type statistics to track
	static float totalFlightTime;
	static int totalFlights;
	static float totalDistanceTravelled;

	static float timeSpentCharging;
	static int chargeSessions;

	static int totalFaults;

	static float totalPassengerMiles;
};