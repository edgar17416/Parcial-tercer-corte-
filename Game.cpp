#include "game.h"
#include <iostream>
#include <cstring>

void initGame(Game* game) {
    game->currentRoom = 0;
    game->running = true;
    game->won = false;

    // Conectar 6 habitaciones:
    // 0-Norte->1, 1-Sur->0, 1-Este->2, 2-Oeste->1
    // 2-Norte->3, 3-Sur->2, 3-Oeste->4, 4-Este->3, 4-Norte->5
    initRoom(&game->rooms[0], 1, -1, -1, -1);
    initRoom(&game->rooms[1], -1, 0, 2, -1);
    initRoom(&game->rooms[2], 3, -1, -1, 1);
    initRoom(&game->rooms[3], -1, 2, -1, 4);
    initRoom(&game->rooms[4], 5, -1, 3, -1);
    initRoom(&game->rooms[5], -1, 4, -1, -1);

    initPlayer(&game->player, 10, 5);

    // 2 chasers y 2 patrulleros
    initEnemy(&game->enemies[0], 5, 3, CHASER);
    initEnemy(&game->enemies[1], 15, 7, CHASER);
    initEnemy(&game->enemies[2], 8, 5, PATROL);
    initEnemy(&game->enemies[3], 12, 5, PATROL);

    // Desactiva enemigos restantes
    for (int i = 4; i < MAX_ENEMIES; i++) {
        game->enemies[i].alive = false;
    }

    // Items: una llave para ganar
    initItem(&game->items[0], 5, 5, "Llave", true);
    initItem(&game->items[1], 8, 3, "Pocion", false);

    // Desactiva items restantes
    for (int i = 2; i < MAX_ITEMS; i++) {
        game->items[i].active = false;
    }
}

void updateGame(Game* game, char input) {
    Player* p = &game->player;
    char* map = &game->rooms[game->currentRoom].map[0][0];

    int dx = 0, dy = 0;
    if (input == 'w') dy = -1;
    else if (input == 's') dy = 1;
    else if (input == 'a') dx = -1;
    else if (input == 'd') dx = 1;
    else if (input == 'q') { game->running = false; return; }

    movePlayer(p, dx, dy, game->rooms[game->currentRoom].map);

    // Recoger o soltar item con 'e'
    if (input == 'e') {
        for (int i = 0; i < MAX_ITEMS; i++) {
            Item* item = &game->items[i];
            if (item->active && item->x == p->x && item->y == p->y) {
                if (!p->hasItem) {
                    p->hasItem = true;
                    strcpy(p->itemName, item->name);
                    item->active = false;
                } else {
                    // Suelta el item actual
                    item->active = true;
                    item->x = p->x;
                    item->y = p->y;
                    p->hasItem = false;
                    strcpy(p->itemName, "");
                }
            }
        }
    }

    // Actualizar enemigos
    for (int i = 0; i < MAX_ENEMIES; i++) {
        updateEnemy(&game->enemies[i], p->x, p->y,
                    game->rooms[game->currentRoom].map);
    }

    // Cambio de habitación por puertas
    Room* r = &game->rooms[game->currentRoom];
    if (p->y == 0 && r->northRoom != -1) {
        game->currentRoom = r->northRoom;
        p->y = ROOM_HEIGHT - 2;
    } else if (p->y == ROOM_HEIGHT - 1 && r->southRoom != -1) {
        game->currentRoom = r->southRoom;
        p->y = 1;
    } else if (p->x == ROOM_WIDTH - 1 && r->eastRoom != -1) {
        game->currentRoom = r->eastRoom;
        p->x = 1;
    } else if (p->x == 0 && r->westRoom != -1) {
        game->currentRoom = r->westRoom;
        p->x = ROOM_WIDTH - 2;
    }

    checkWinLose(game);
}

void renderGame(Game* game) {
    // Copia el mapa para dibujar encima
    Room* r = &game->rooms[game->currentRoom];
    char display[ROOM_HEIGHT][ROOM_WIDTH];
    for (int y = 0; y < ROOM_HEIGHT; y++)
        for (int x = 0; x < ROOM_WIDTH; x++)
            display[y][x] = r->map[y][x];

    // Dibuja items
    for (int i = 0; i < MAX_ITEMS; i++) {
        Item* item = &game->items[i];
        if (item->active)
            display[item->y][item->x] = item->isKey ? 'K' : 'P';
    }

    // Dibuja enemigos
    for (int i = 0; i < MAX_ENEMIES; i++) {
        Enemy* e = &game->enemies[i];
        if (e->alive)
            display[e->y][e->x] = e->type == CHASER ? 'E' : 'G';
    }

    // Dibuja jugador
    display[game->player.y][game->player.x] = '@';

    // Imprime
    system("cls");
    for (int y = 0; y < ROOM_HEIGHT; y++) {
        for (int x = 0; x < ROOM_WIDTH; x++)
            std::cout << display[y][x];
        std::cout << '\n';
    }

    // HUD
    std::cout << "\nVida: " << game->player.health;
    std::cout << "  Inventario: ";
    if (game->player.hasItem)
        std::cout << game->player.itemName;
    else
        std::cout << "[vacio]";
    std::cout << "\nHabitacion: " << game->currentRoom + 1 << "/6";
    std::cout << "\nControles: WASD=mover  E=recoger/soltar  Q=salir\n";
}

void checkWinLose(Game* game) {
    Player* p = &game->player;

    // Derrota: enemigo toca al jugador
    for (int i = 0; i < MAX_ENEMIES; i++) {
        Enemy* e = &game->enemies[i];
        if (e->alive && e->x == p->x && e->y == p->y) {
            p->health--;
            if (p->health <= 0) {
                game->running = false;
                game->won = false;
            }
        }
    }

    // Victoria: jugador tiene la llave y llega a habitación 5
    if (p->hasItem && strcmp(p->itemName, "Llave") == 0
        && game->currentRoom == 5) {
        game->running = false;
        game->won = true;
    }
}
