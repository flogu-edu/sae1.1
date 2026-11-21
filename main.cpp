#include <iostream>
#include <stdlib.h>

#include "./index.h"

int main() {
    const int nbGame = 7;
    std::string games[] = {
        "Exit",
        "Pow n",
        "Tic Tac Stack",
        "Wordle",
        "Pendu",
        "Snake",
        "BlackJack"
    };

    bool continueMenu = true;

    while (continueMenu) {
        int chosenGame = menuInput(games, nbGame);
        continueMenu = chooseGame(chosenGame);
    }
}