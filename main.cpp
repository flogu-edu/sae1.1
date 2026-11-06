#include <iostream>
#include <stdlib.h>

#include "index.h"

int main() {
    std::string games[2] = {
        "Le jeu",
        "ceci est un exemple"
    };
    const int nbGame = 2;

    while (true) {
        int chosenGame = menuInput(games, nbGame);
        chooseGame(chosenGame);
    }
}