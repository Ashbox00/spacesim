#pragma once

#include "planet.h"

void updatePlanets(double timesec);

Planet satelliteStep(Planet &satellite, double timesec);
