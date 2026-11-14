#include "./clearScreen.h"
#include <stdlib.h>

void clearScreen() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system ("clear");
    #endif
}