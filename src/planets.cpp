#include <string>

struct PlanetInfo {
    std::string name;
    double mass_kg; 
    double radius_km;
};


PlanetInfo sun = {
    "Sun",
    1.989e30,
    695700.0
};

PlanetInfo mercury = {
    "Mercury",
    3.301e23,
    2439.7
};
PlanetInfo venus = {
    "Venus",
    4.867e24,
    6051.8
};

PlanetInfo earth = {
    "Earth",
    5.972e24,
    6371.0
};

PlanetInfo mars = {
    "Mars",
    6.417e23,
    3389.5
};
