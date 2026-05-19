#pragma once

struct Player {
    int x, y;
    int health;
    bool hasItem;
    char itemName[20];
};

void initPlayer(Player* player, int startX, int startY);
void movePlayer(Player* player, int dx, int dy, char map[][20]);
