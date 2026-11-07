#include <iostream>
#include <stdlib.h>

#include "minigames/pow_n/pow_n.hpp"
#include "minigames/ticktackstack.hpp"
#include "minigames/wordle/wordle.h"

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
       pow_n();
       break;
    
    case 1:
        tictacstack();
        break;

    case 2:
        wordle();
        break;
    
    default:
        break;
    }
}