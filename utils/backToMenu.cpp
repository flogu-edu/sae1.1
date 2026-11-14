#include <iostream>
#include <string>
#include "./backToMenu.h"
#include "clearScreen.h"
#include <limits>

void backToMenu() {
    // Efface le buffer de cin pour ignorer le \n du jeu  
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string dummy;
    std::cout<<"Press enter to get back to menu ";
    // permet de seulement presser enter
    std::getline(std::cin, dummy);
    clearScreen();
}