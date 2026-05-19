#include "game.h"
#include <iostream>
#include <conio.h>

int main() {
    Game game;
    initGame(&game);

    while (game.running) {
        renderGame(&game);
        char input = _getch(); // captura tecla sin Enter
        updateGame(&game, input);
    }

    renderGame(&game);
    if (game.won)
        std::cout << "\n*** GANASTE! Escapaste del dungeon! ***\n";
    else
        std::cout << "\n*** PERDISTE! El dungeon te venció... ***\n";

    return 0;
}
