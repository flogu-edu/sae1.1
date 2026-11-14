#include <iostream>
#include <stdlib.h>

#include "./index.h"

int main() {
    const int nbGame = 5;
    std::string games[] = {
        "Exit",
        "Pow n",
        "Tic Tac Stack",
        "Wordle",
        "Pendu"
    };

    bool continueMenu = true;

    while (continueMenu) {
        int chosenGame = menuInput(games, nbGame);
        continueMenu = chooseGame(chosenGame);
    }
}