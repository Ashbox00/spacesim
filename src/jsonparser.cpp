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