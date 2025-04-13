#include <iostream>
#include <string>
#include <json.hpp>
#include <fstream>
#include <sstream>

#include "planet.h"

using json = nlohmann::json;
using namespace std;

void Jparser(const string &readBuffer)
{
    try
    {
        auto parsed = json::parse(readBuffer);
        auto vectors = parsed["result"]["vector"];
        if (!vectors.empty())
        {
            for (auto vector : vectors)
            {
                // auto coords = vectors[0];
                double x = stod(string(vector["X"])) * 149597870.7;
                double y = stod(string(vector["Y"])) * 149597870.7;
                double z = stod(string(vector["Z"])) * 149597870.7;

                double vx_km = stod(string(vector["VX"])) * 149597870.7 / 24 / 60 / 60;
                double vy_km = stod(string(vector["VY"])) * 149597870.7 / 24 / 60 / 60;
                double vz_km = stod(string(vector["VZ"])) * 149597870.7 / 24 / 60 / 60;

                std::string target_name = vector["target"];
                for (int i = 0; i < NUM_PLANETS; i++)
                {
                    if (initialState.planets[i].name == target_name)
                    {
                        initialState.planets[i].position = vec3d(x, y, z);
                        initialState.planets[i].velocity = vec3d(vx_km, vy_km, vz_km);

                        break;
                    }
                }
            }
        }
        else
        {
            cout << "No data" << endl;
        }
    }
    catch (const exception &e)
    {
        cout << "Failed to parse JSON" << endl;
    }
}