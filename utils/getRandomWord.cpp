#include <iostream>
#include <cstdlib>

std::string getRandomWord(std::string wordList[], int size) {
    int randomNb = rand() % size;
    return wordList[randomNb];
}