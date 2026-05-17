#include "player.h"
#include <cstring>

void initPlayer(Player* player, int startX, int startY) {
    player->x = startX;
    player->y = startY;
    player->health = 3;
    player->hasItem = false;
    strcpy(player->itemName, "");
}

void movePlayer(Player* player, int dx, int dy, char map[][20]) {
    int newX = player->x + dx;
    int newY = player->y + dy;

    // Solo mueve si no es pared
    if (map[newY][newX] != '#') {
        player->x = newX;
        player->y = newY;
    }
}
