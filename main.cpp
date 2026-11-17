#include <iostream>
#include <stdlib.h>

#include "./index.h"

int main() {
    const int nbGame = 6;
    std::string games[] = {
        "Exit",
        "Pow n",
        "Tic Tac Stack",
        "Wordle",
        "Pendu",
        "Snake"
    };

    bool continueMenu = true;

    while (continueMenu) {
        int chosenGame = menuInput(games, nbGame);
        continueMenu = chooseGame(chosenGame);
    }
}