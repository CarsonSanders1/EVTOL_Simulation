#pragma once
#include "eVTOL_Aircraft.h"

class eVTOL_Alpha : public eVTOL_Aircraft
{
public:

	//Constructor
	eVTOL_Alpha();

	//Deconstructor
	~eVTOL_Alpha();

	void charge(bool* charger);
};