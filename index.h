#include <iostream>
#include <stdlib.h>

#include "minigames/test.h"

void displayMenu(std::string games[], int nbGames);
int menuInput(std::string games[], int nbGames);

int menuInput(std::string games[], int nbGames) {
    int chosenGame;
    bool validEntry = false;

    while(!validEntry) {
        displayMenu(games, nbGames);
        std::cin>>chosenGame;

        if(chosenGame < 0 || chosenGame > nbGames - 1) {
            validEntry = false;
            std::cout<<"Please enter a valid number"<<std::endl;
        } else {
            validEntry = true;
        }
    }

    return chosenGame;
}

void displayMenu(std::string games[], int nbGames) {
    std::cout<<"Choose a game : "<<std::endl;
    for(int i = 0; i < nbGames; i++) {
        std::cout<<i<<" "<<games[i]<<std::endl;
    }
    std::cout<<"Enter a number ";
}

void chooseGame(int gameNb) {
    switch (gameNb)
    {
    case 0:
        // fonction jeu 1
        std::cout<<"Le jeu choisi est le 0"<<std::endl;
        break;
    
    default:
        break;
    }
}