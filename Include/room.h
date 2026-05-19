#pragma once

const int ROOM_WIDTH = 20;
const int ROOM_HEIGHT = 10;

struct Room {
    char map[ROOM_HEIGHT][ROOM_WIDTH];
    int northRoom; // índice de habitación al norte (-1 = no hay)
    int southRoom;
    int eastRoom;
    int westRoom;
    bool visited;
};

void initRoom(Room* room, int north, int south, int east, int west);
void drawRoom(Room* room);
