#include <cstdlib>

int getRandomNb(int max) {
    int randomNb = rand() % max;
    return randomNb;
}