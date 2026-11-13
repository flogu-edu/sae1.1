#include <iostream>
#include "pendu.h"
#include <ctime>
#include <cstdlib>
#include "../../utils/getRandomWord.h"

void displayPendu(std::string userWord) {
    for(unsigned int i = 0; i < userWord.length(); i++) {
        std::cout<< userWord[i] <<" ";
    }
    std::cout<<std::endl;
}

std::string getUserInput() {
    std::string userInput = "";
    bool isInputValid = false;

    while (isInputValid) {
        std::cout<<"Please enter a letter : ";
        std::cin>>userInput;

        if(userInput.length() > 1) {
            std::cout<<"Please enter only one letter"<<std::endl;
            isInputValid = false;
        } else if (userInput.length() < 1) {
            std::cout<<"Please enter at least one letter"<<std::endl;
        } else {
            isInputValid = true;
        }
    }

    return userInput;
}

void pendu() {
    srand(time(0));

    std::string wordList[] = {
        "POMME",
        "MAISON",
        "SOLEIL",
        "CHEVAL",
        "JARDIN",
        "NUAGE",
        "PIRATE",
        "FROMAGE",
        "CHOCOLAT",
        "MONTAGNE",
        "GIRAFE",
        "PARAPLUIE",
        "KANGOUROU",
        "ELEPHANT",
        "BROUILLARD",
        "ESCARGOT",
        "LABYRINTHE",
        "HELICOPTERE",
        "CITROUILLE",
        "DINOSAURE",
        "HIPPOPOTAME",
        "ACROBATIE",
        "PHENOMENE",
        "QUINCAILLERIE",
        "AVALANCHE",
        "SPHINX",
        "XYLOPHONE",
        "KRYPTONITE",
        "EXCENTRIQUE",
        "QUIPROQUO"
    };

    int wordCount = 30;

    std::string word = getRandomWord(wordList, wordCount);
    

}