#include <iostream>
#include <string>
#include <json.hpp>
#include <fstream>
#include <sstream>

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
            auto coords = vectors[0];

            cout << "Coordinates" << endl;
            cout << "X: " << coords["X"] << endl;
            cout << "Y: " << coords["Y"] << endl;
            cout << "Z: " << coords["Z"] << endl;

            double vx = stod(string(coords["X"])) * 100;
            double vy = stod(string(coords["Y"])) * 100;
            double vz = stod(string(coords["Z"])) * 100;

            cout << "Velocity" << endl;
            double vx_km = stod(string(coords["VX"])) * 1731.46;
            double vy_km = stod(string(coords["VY"])) * 1731.46;
            double vz_km = stod(string(coords["VZ"])) * 1731.46;
            cout << "VX: " << vx_km << endl;
            cout << "VY: " << vy_km << endl;
            cout << "VZ: " << vz_km << endl;
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