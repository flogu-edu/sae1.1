#include <iostream>
#include <stdlib.h>

#include "index.h"

int main() {
    std::string games[2] = {
        "Tic Tac Stack",
        "ceci est un exemple"
    };
    const int nbGame = 2;

    while (true) {
        int chosenGame = menuInput(games, nbGame);
        chooseGame(chosenGame);
    }
}