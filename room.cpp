#include "room.h"
#include <iostream>

void initRoom(Room* room, int north, int south, int east, int west) {
    room->northRoom = north;
    room->southRoom = south;
    room->eastRoom = east;
    room->westRoom = west;
    room->visited = false;

    // Llena todo de paredes
    for (int y = 0; y < ROOM_HEIGHT; y++) {
        for (int x = 0; x < ROOM_WIDTH; x++) {
            if (y == 0 || y == ROOM_HEIGHT - 1 || x == 0 || x == ROOM_WIDTH - 1)
                room->map[y][x] = '#'; // pared
            else
                room->map[y][x] = '.'; // piso
        }
    }

    // Puertas según conexiones
    if (north != -1) room->map[0][ROOM_WIDTH / 2] = ' ';
    if (south != -1) room->map[ROOM_HEIGHT - 1][ROOM_WIDTH / 2] = ' ';
    if (east  != -1) room->map[ROOM_HEIGHT / 2][ROOM_WIDTH - 1] = ' ';
    if (west  != -1) room->map[ROOM_HEIGHT / 2][0] = ' ';
}

void drawRoom(Room* room) {
    for (int y = 0; y < ROOM_HEIGHT; y++) {
        for (int x = 0; x < ROOM_WIDTH; x++) {
            std::cout << room->map[y][x];
        }
        std::cout << '\n';
    }
}
