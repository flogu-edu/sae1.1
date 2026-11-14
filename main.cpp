#include <iostream>
#include <stdlib.h>

#include "./index.h"

int main() {
    const int nbGame = 4;
    std::string games[] = {
        "Pow n",
        "Tic Tac Stack",
        "Wordle",
        "Pendu"
    };

    while (true) {
        int chosenGame = menuInput(games, nbGame);
        chooseGame(chosenGame);
    }
}