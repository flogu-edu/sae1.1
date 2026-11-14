#include <iostream>
#include <stdlib.h>
#include "utils/clearScreen.h"

#include "minigames/pow_n/pow_n.hpp"
#include "minigames/ticktackstack.hpp"
#include "minigames/wordle/wordle.h"
#include "minigames/pendu/pendu.h"

void displayMenu(std::string games[], int nbGames);
int menuInput(std::string games[], int nbGames);

int menuInput(std::string games[], int nbGames) {
    int chosenGame;
    bool validEntry = false;

    while(!validEntry) {
        displayMenu(games, nbGames);
        std::cout<<"Enter a number ";
        std::cin>>chosenGame;

        if(chosenGame < 0 || chosenGame > nbGames - 1) {
            validEntry = false;
            std::cout<<"Please enter a valid number"<<std::endl;
        } else {
            validEntry = true;
        }
    }

    clearScreen();
    return chosenGame;
}

void displayMenu(std::string games[], int nbGames) {
    clearScreen();
    std::cout<<"Choose a game : "<<std::endl;
    for(int i = 0; i < nbGames; i++) {
        std::cout<<i<<" "<<games[i]<<std::endl;
    }
}

bool chooseGame(int gameNb) {
    switch (gameNb) {
    case 0:
        return false;
        break;
    
    case 1:
        pow_n();
        return true;
        break;
       
    case 2:
        tictacstack();
        return true;
        break;
       
    case 3:
        wordle();
        return true;
        break;

    case 4:
        pendu();
        return true;
        break;
    
    default:
        return true;
        break;
    }
}