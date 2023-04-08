#pragma once
#include "eVTOL_Aircraft.h"

class eVTOL_Echo : public eVTOL_Aircraft
{
public:

	//Constructor
	eVTOL_Echo();

	//Deconstructor
	~eVTOL_Echo();

	void charge(bool* charger);
};