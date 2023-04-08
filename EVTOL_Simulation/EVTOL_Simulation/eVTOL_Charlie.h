#pragma once
#include "eVTOL_Aircraft.h"

class eVTOL_Charlie : eVTOL_Aircraft
{
public:

	//Constructor
	eVTOL_Charlie();

	//Deconstructor
	~eVTOL_Charlie();

	void charge(bool* charger);
};