#ifndef INDIVIDUALFACTORY_H
#define INDIVIDUALFACTORY_H


#include <string>
#include <vector>


using namespace std;


struct RoomSpec {
    string type;
    int min_area;
    int count;
};

struct BuildingConstraints {
    int max_width;
    int max_height;
};

struct InputData {
    BuildingConstraints constraints;
    vector<RoomSpec> room_specs;
    vector<pair<string, string>> adjacency;
};

class IndividualFactory {
private:
    InputData inputData;

public:
    IndividualFactory();
    void loadInputFromFile(string filename);
    InputData getInputData();
};


#endif
