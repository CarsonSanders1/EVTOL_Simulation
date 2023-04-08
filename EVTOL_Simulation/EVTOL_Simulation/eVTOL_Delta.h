#pragma once
#include "eVTOL_Aircraft.h"

class eVTOL_Delta : public eVTOL_Aircraft
{
public:

	//Constructor
	eVTOL_Delta();

	//Deconstructor
	~eVTOL_Delta();

	void charge(bool* charger);
};