#include "individualFactory.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>


IndividualFactory::IndividualFactory() {}

void IndividualFactory::loadInputFromFile(string filename) {
    ifstream in(filename);
    if (!in.is_open()) throw std::runtime_error("Cannot open file!");

    nlohmann::json j;
    in >> j;

    inputData.constraints.max_width = j["building_constraints"]["max_width"];
    inputData.constraints.max_height = j["building_constraints"]["max_height"];

    for (const auto& room : j["rooms"]) {
        RoomSpec spec;
        spec.type = room["type"];
        spec.min_area = room["min_area"];
        spec.count = room["count"];
        inputData.room_specs.push_back(spec);
    }

    for (const auto& pair : j["adjacency_requirements"]) {
        inputData.adjacency.emplace_back(pair[0], pair[1]);
    }
}

InputData IndividualFactory::getInputData() {
    return inputData;
}