#include <cstdlib>
#include "./getRandomWord.h"

std::string getRandomWord(std::string wordList[], int size) {
    int randomNb = rand() % size;
    return wordList[randomNb];
}