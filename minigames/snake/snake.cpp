#include <iostream>
#include <thread>
#include <chrono>
#include "snake.h"
#include "../../utils/clearScreen.h"
#include "../../utils/backToMenu.h"
#include "../../utils/getRandomNb.h"


#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <sys/select.h>
#endif

struct position {
    int x;
    int y;
};

struct maillon {
    maillon *next;
    maillon *prev;
    position pos;
    char direction;
};

struct snake {
    maillon *head;
    maillon *tail;
};

struct fruit {
    int x;
    int y;
};


void init(snake *body, int gridSize) {
    maillon *newPart =  new maillon;
    newPart->next = nullptr;
    newPart->prev = nullptr;
    newPart->pos = { gridSize/2, gridSize/4 };
    newPart->direction = 'E';

    body->head = newPart;
    body->tail = newPart;
}

void addTail(snake *body, int gridSize) {
    maillon *newTail = new maillon;
    newTail->next = body->tail;
    newTail->prev = nullptr;
    newTail->direction = body->tail->direction;

    
    switch (body->tail->direction) {
        case 'E':
            newTail->pos.x = (body->tail->pos.x - 1 + gridSize) % gridSize;
            newTail->pos.y = (body->tail->pos.y) % (gridSize / 2);
            break;
        
        case 'W':
            newTail->pos.x = (body->tail->pos.x + 1) % gridSize;
            newTail->pos.y = (body->tail->pos.y) % (gridSize / 2);
            break;
        
        case 'N':
            newTail->pos.x = (body->tail->pos.x) % gridSize;
            newTail->pos.y = (body->tail->pos.y - 1 + (gridSize / 2)) % (gridSize / 2);
            break;
        
        case 'S':
            newTail->pos.x = (body->tail->pos.x) % gridSize;
            newTail->pos.y = (body->tail->pos.y + 1) % (gridSize / 2);
            break;
    }

    body->tail->prev = newTail;
    body->tail = newTail;
}


void draw(int x, int y, char symbole) {
    std::cout<< "\033[" << y + 1 << ";" << x + 1<< "H" << symbole;
}

void setCursor(int x, int y) {
    std::cout<< "\033[" << y + 1 << ";" << x + 1 << "H";
}

void displaySnake(snake *body) {
    maillon *currentMaillon = body->head;

    while (currentMaillon != nullptr) {
        if(currentMaillon->next == nullptr) {
            draw(currentMaillon->pos.x + 1, currentMaillon->pos.y + 1, 'O');
        } else {
            draw(currentMaillon->pos.x + 1, currentMaillon->pos.y + 1, 'o');
        }

        currentMaillon = currentMaillon->prev;
    }
}

void displayGrid(int gridSize) {
    for(int x = 0; x <= gridSize; x++) {
        draw(x, 0, '-');
    }

    for (int x = 0; x <= gridSize; x++) {
        draw(x, gridSize/2 + 1, '-');
    }

    for(int y = 0; y <= gridSize / 2; y++) {
        draw(0, y, '|');
    }

    for(int y = 0; y <= gridSize / 2; y++) {
        draw(gridSize + 1, y, '|');
    }

    draw(0, 0, '+');
    draw(gridSize + 1, 0, '+');
    draw(0, gridSize / 2 + 1, '+');
    draw(gridSize + 1, gridSize / 2 + 1, '+');
}

void forwardSnake(snake *body, int gridSize) {
    maillon *currentMaillon = body->tail;
    while(currentMaillon->next != nullptr) {
        currentMaillon->pos.x = currentMaillon->next->pos.x;
        currentMaillon->pos.y = currentMaillon->next->pos.y;

        currentMaillon->direction = currentMaillon->next->direction;

        currentMaillon = currentMaillon->next;
    }
    
    switch (body->head->direction) {
        case 'S':
            body->head->pos.x = body->head->pos.x;
            body->head->pos.y = (body->head->pos.y + 1) % (gridSize / 2);
            break;
        
        case 'N':
            body->head->pos.x = body->head->pos.x;
            body->head->pos.y = (body->head->pos.y - 1 + (gridSize / 2)) % (gridSize / 2);
            break;
        
        case 'E':
            body->head->pos.x = (body->head->pos.x + 1) % gridSize; 
            body->head->pos.y = body->head->pos.y;
            break;
        
        case 'W':
            body->head->pos.x = (body->head->pos.x - 1 + gridSize) % gridSize; 
            body->head->pos.y = body->head->pos.y;
            break;
    }
    
}

void changeDirection(snake *body, char newDirection) {
    body->head->direction = newDirection;
}

char chooseDirection(char actual) {

    #ifdef _WIN32

        static bool waitingForArrowCode = false;
        char newDirection = actual;

        while (_kbhit()) {
            int input = _getch();

            if (input == 0 || input == 224) {
                waitingForArrowCode = true;
                continue;
            }

            if (waitingForArrowCode) {
                waitingForArrowCode = false;

                switch (input) {
                    case 72: newDirection = 'N'; break;
                    case 80: newDirection = 'S'; break;
                    case 75: newDirection = 'W'; break;
                    case 77: newDirection = 'E'; break;
                }
            }
        }

        return newDirection;

    #else

        static bool initialized = false;
        static termios oldTermios;

        if (!initialized) {
            tcgetattr(STDIN_FILENO, &oldTermios);

            termios newTermios = oldTermios;
            newTermios.c_lflag &= ~(ICANON | ECHO);
            newTermios.c_cc[VMIN] = 0;
            newTermios.c_cc[VTIME] = 0;

            tcsetattr(STDIN_FILENO, TCSANOW, &newTermios);
            initialized = true;
        }

        char newDirection = actual;

        unsigned char input;

        while (read(STDIN_FILENO, &input, 1) > 0) {

            if (input == 27) {
                unsigned char sequence[2];

                if (read(STDIN_FILENO, &sequence[0], 1) <= 0)
                    continue;

                if (read(STDIN_FILENO, &sequence[1], 1) <= 0)
                    continue;

                if (sequence[0] == '[') {
                    switch (sequence[1]) {
                        case 'A': newDirection = 'N'; break;
                        case 'B': newDirection = 'S'; break;
                        case 'D': newDirection = 'W'; break;
                        case 'C': newDirection = 'E'; break;
                    }
                }
            }
        }

        return newDirection;

    #endif
}

char getCurrentDirection(snake * body) {
    return body->head->direction;
}

fruit * createFruit(int gridSize){
    fruit *newFruit = new fruit;
    newFruit->x = getRandomNb(gridSize);
    newFruit->y = getRandomNb(gridSize/2);
    return newFruit;
}

void displayFruit(fruit * fruit) {
    draw(fruit->x, fruit->y, '#');
}

fruit * eatFruit(fruit * oldFruit, int & score, int gridSize) {
    delete oldFruit;
    fruit *newFruit = new fruit;
    newFruit->x = getRandomNb(gridSize);
    newFruit->y = getRandomNb(gridSize);
    score++;
    return newFruit;
}

void snakeGame() {
    clearScreen();
    
    int gridSize = 50;
    
    snake *testBody = new snake;
    init(testBody, gridSize);
    addTail(testBody, gridSize);
    addTail(testBody, gridSize);
    addTail(testBody, gridSize);
    addTail(testBody, gridSize);
    addTail(testBody, gridSize);
    
    char direction = 'E';

    for(int i = 0; i < 1000; i++) {
        clearScreen();
        displayGrid(gridSize);
        displaySnake(testBody);

        setCursor(0, gridSize / 2 + 2);
        std::cout << std::flush;
        
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        forwardSnake(testBody, gridSize);


        direction = chooseDirection(getCurrentDirection(testBody));

        changeDirection(testBody, direction);
    }

    backToMenu();
}