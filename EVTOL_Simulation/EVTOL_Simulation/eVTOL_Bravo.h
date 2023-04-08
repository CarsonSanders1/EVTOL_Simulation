#pragma once
#include "eVTOL_Aircraft.h"

class eVTOL_Bravo : eVTOL_Aircraft
{
public:

	//Constructor
	eVTOL_Bravo();

	//Deconstructor
	~eVTOL_Bravo();

	void charge(bool* charger);
};