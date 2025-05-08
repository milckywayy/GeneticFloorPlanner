#include "floorPlan.h"


FloorPlan::FloorPlan() {}

void FloorPlan::addRoom(std::unique_ptr<Room> room) {
    rooms.push_back(std::move(room));
}

int FloorPlan::roomNum() {
    return rooms.size();
}
