#ifndef FLOORPLAN_H
#define FLOORPLAN_H


#include <vector>
#include <memory>
#include "room.h"


using namespace std;


class FloorPlan {
private:
    vector<unique_ptr<Room>> rooms;

public:
    FloorPlan();

    void addRoom(unique_ptr<Room> room);
    int roomNum();
};


#endif