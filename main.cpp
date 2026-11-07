#include <iostream>
#include <stdlib.h>

#include "./index.h"

int main() {
    const int nbGame = 3;
    std::string games[] = {
        "Pow n",
        "Tic Tac Stack",
        "Wordle"
    };

    while (true) {
        int chosenGame = menuInput(games, nbGame);
        chooseGame(chosenGame);
    }
}