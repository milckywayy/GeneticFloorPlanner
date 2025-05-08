#ifndef ROOM_H
#define ROOM_H


#include <string>


using namespace std;


class Room {
private:
    int id;
    string type;
    int x, y, width, height;

public:
    Room(int id, string type, int x, int y, int width, int height);
    int area();
};


#endif