#pragma once
#include "eVTOL_Aircraft.h"

class eVTOL_Charlie : public eVTOL_Aircraft
{
public:

	//Constructor
	eVTOL_Charlie();

	//Deconstructor
	~eVTOL_Charlie();

	/// Advance simulation by .01 hours
	void stepSimulation();

	void charge();

	//Per Vehicle type statistics to track
	static float totalFlightTime;
	static int totalFlights;
	static float totalDistanceTravelled;

	static float timeSpentCharging;
	static int chargeSessions;

	static int totalFaults;

	static float totalPassengerMiles;

private:
	
};