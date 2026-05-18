#include "enemy.h"

void initEnemy(Enemy* enemy, int x, int y, EnemyType type) {
    enemy->x = x;
    enemy->y = y;
    enemy->health = 2;
    enemy->alive = true;
    enemy->type = type;
    enemy->direction = 1;
}

void updateEnemy(Enemy* enemy, int playerX, int playerY, char map[][20]) {
    if (!enemy->alive) return;

    if (enemy->type == CHASER) {
        // Se mueve hacia el jugador
        int dx = 0, dy = 0;
        if (playerX > enemy->x) dx = 1;
        else if (playerX < enemy->x) dx = -1;
        else if (playerY > enemy->y) dy = 1;
        else if (playerY < enemy->y) dy = -1;

        int newX = enemy->x + dx;
        int newY = enemy->y + dy;
        if (map[newY][newX] != '#') {
            enemy->x = newX;
            enemy->y = newY;
        }

    } else if (enemy->type == PATROL) {
        // Patrulla horizontalmente
        int newX = enemy->x + enemy->direction;
        if (map[enemy->y][newX] == '#') {
            enemy->direction *= -1; // cambia dirección
        } else {
            enemy->x = newX;
        }
    }
}
