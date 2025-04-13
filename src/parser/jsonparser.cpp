#include <iostream>
#include <string>
#include <json.hpp>
#include <fstream>
#include <sstream>


using json = nlohmann::json;
using namespace std;

string readFileAsString(const string& filename) {
    ifstream inFile(filename);
    ostringstream ss;
    ss << inFile.rdbuf();
    return ss.str();
}

void Jparser(string readBuffer){
    string readBuffer;
    try {
        auto parsed = json::parse(readBuffer);
        auto vectors = parsed["result"]["vector"];
        if (!vectors.empty()){
            auto coords = vectors[0];
            cout << "Coordinates" << endl;
            cout << "X: " << coords["X"] << endl;
            cout << "Y: " << coords["Y"] << endl;
            cout << "Z: " << coords["Z"] << endl;
        }
        else {
            cout << "No data" << endl;
        }
    }
    catch (const exception& e){
        cout << "Failed to parse JSON" << endl;
    }
}

int main(){
    Jparser(readFileAsString("test.json"));
}