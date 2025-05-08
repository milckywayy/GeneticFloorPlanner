#include "room.h"


Room::Room(int id, string type, int x, int y, int width, int height) {
    this->id = id;
    this->type = type;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

int Room::area() {
    return this->width * this->height;
}