#pragma once
#define private public //used to get access to private variables for testing
#include "pch.h"
#include "eVTOL_Alpha.h"
#include "eVTOL_Bravo.h"
#include "eVTOL_Charlie.h"
#include "eVTOL_Delta.h"
#include "eVTOL_Echo.h"
#include "Simulation.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(eVTOL_Alpha_TotalAircraft, eVTOLAlpha)
{
	eVTOL_Alpha* alpha = new eVTOL_Alpha();

	ASSERT_EQ(eVTOL_Alpha::totalAircraft, 1);

	eVTOL_Alpha* alpha2 = new eVTOL_Alpha();

	ASSERT_EQ(eVTOL_Alpha::totalAircraft, 2);
}

TEST(eVTOL_Alpha_incrementFaults, eVTOLAlpha)
{
	eVTOL_Alpha* alpha = new eVTOL_Alpha();

	alpha->incrementFaults();

	ASSERT_EQ(eVTOL_Alpha::totalFaults, 1);

	alpha->incrementFaults();

	ASSERT_EQ(eVTOL_Alpha::totalFaults, 2);

	eVTOL_Alpha* alpha2 = new eVTOL_Alpha();

	alpha2->incrementFaults();

	ASSERT_EQ(eVTOL_Alpha::totalFaults, 3);
}

TEST(eVTOL_Alpha_, eVTOLAlpha)
{
	eVTOL_Alpha* alpha = new eVTOL_Alpha();

	alpha->stepSimulation();

	ASSERT_GT(eVTOL_Alpha::totalDistanceTravelled, 0);

}

TEST(SimulationConstruction, SimulationTest)
{
	Simulation* sim = new Simulation();

	ASSERT_EQ(sim->aircraft.size(), sim->AMOUNT_OF_AIRCRAFT);
}

TEST(SimulationFaultChance, SimulationTest)
{
	Simulation* sim = new Simulation();

	ASSERT_EQ(sim->calculateFault(1), true);

	ASSERT_EQ(sim->calculateFault(0), false);
}

