#pragma once

#include "room.h"
#include "player.h"
#include "enemy.h"
#include "item.h"

const int MAX_ROOMS = 6;

struct Game {
    Room rooms[MAX_ROOMS];
    Player player;
    Enemy enemies[MAX_ENEMIES];
    Item items[MAX_ITEMS];
    int currentRoom;
    bool running;
    bool won;
};

void initGame(Game* game);
void updateGame(Game* game, char input);
void renderGame(Game* game);
void checkWinLose(Game* game);
