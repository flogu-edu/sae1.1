#include "./getInput.h"

#ifdef _WIN32
    #include <conio.h>
#endif

int getInput() {
    #ifdef _WIN32
        return _getch();
    #else
        return 0;
    #endif
}