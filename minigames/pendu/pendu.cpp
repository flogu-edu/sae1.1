#include <cctype>
#include <cmath>
#include <iostream>
#include "pendu.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include "../../utils/getRandomWord.h"
#include "../../utils/clearScreen.h"
#include "../../utils/backToMenu.h"

void displayPendu(std::string userWord) {
    for(unsigned int i = 0; i < userWord.length(); i++) {
        std::cout<< userWord[i] <<" ";
    }
    std::cout<<std::endl;
}

std::string init(std::string word) {
    std::string userWord = "";
    for(unsigned int i = 0; i < word.length(); i++) {
        userWord.push_back('_');
    }
    return userWord;
}

char getUserInput() {
    char userInput;

    std::cout<<"Please enter a letter : ";
    std::cin>>userInput;

    userInput = std::toupper(userInput);

    return userInput;
}

void check(char userInput, std::string word, std::string & userWord, int & failsNb, std::string & fails) {
    bool isCorrect = false;
    for(int i = 0; i < word.length(); i++) {
        if(userInput == word[i]) {
            userWord[i] = userInput;
            isCorrect = true;
        }
    }
    if(!isCorrect) {
        failsNb++;
        fails.push_back(userInput);
    }
}

bool checkSuccess(std::string userWord) {
    for(int i = 0; i < userWord.length(); i++) {
        if(userWord[i] == '_') {
            return false;
        }
    }
    return true;
}

void displayFailures(std::string failures) {
    std::string failureStates[] =  {
    R"(
        +---+
        |   |
            |
            |
            |
            |
        =========)", 
    R"(
        +---+
        |   |
        O   |
            |
            |
            |
        =========)", 
    R"(
        +---+
        |   |
        O   |
        |   |
            |
            |
        =========)", 
    R"(
        +---+
        |   |
        O   |
       /|   |
            |
            |
        =========)", 
    R"(
        +---+
        |   |
        O   |
       /|\  |
            |
            |
        =========)", 
    R"(
        +---+
        |   |
        O   |
       /|\  |
       /    |
            |
        =========)", 
    R"(
        +---+
        |   |
        O   |
       /|\  |
       / \  |
            |
        =========)"
    };

    std::cout<<failureStates[failures.length()]<<std::endl;
    std::cout<<"Errors : ";
    for(unsigned int i = 0; i < failures.length(); i++) {
        std::cout<<failures[i]<<" ";
    }
    std::cout<<std::endl;
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
    std::string userWord = init(word);
    int failsNb = 0;
    char userInput;
    std::string fails = "";

    bool isSuccess = false;

    while (!checkSuccess(userWord) && failsNb < 7) {
        clearScreen();
        displayFailures(fails);
        displayPendu(userWord);
        userInput = getUserInput();
        check(userInput, word, userWord, failsNb, fails);
    }

    if(checkSuccess(userWord)) {
        std::cout<<"You won, the word was : "<<word<<std::endl;
    } else {
        std::cout<<"You loose, the word was : "<<word<<std::endl;
    }
    
    backToMenu();
}