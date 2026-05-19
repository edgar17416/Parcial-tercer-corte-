#pragma once

const int MAX_ENEMIES = 10;

enum EnemyType {
    CHASER,   // persigue directo al jugador
    PATROL    // patrulla de lado a lado
};

struct Enemy {
    int x, y;
    int health;
    bool alive;
    EnemyType type;
    int direction; // para el patrullero
};

void initEnemy(Enemy* enemy, int x, int y, EnemyType type);
void updateEnemy(Enemy* enemy, int playerX, int playerY, char map[][20]);
