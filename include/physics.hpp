#pragma once

#include "planet.h"

// void updatePlanets(double timesec);

Planet satelliteStep(const PlanetStates &state, const Planet &satellite, double timesec);
