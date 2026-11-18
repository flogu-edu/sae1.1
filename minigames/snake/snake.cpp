#include <iostream>
#include <thread>
#include <chrono>
#include "snake.h"
#include "../../utils/clearScreen.h"
#include "../../utils/backToMenu.h"

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

void init(snake *body, int gridSize) {
    maillon *newPart =  new maillon;
    newPart->next = nullptr;
    newPart->prev = nullptr;
    newPart->pos = { gridSize/2, gridSize/2 };
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
            newTail->pos.y = (body->tail->pos.y) % gridSize;
            break;
        
        case 'W':
            newTail->pos.x = (body->tail->pos.x + 1) % gridSize;
            newTail->pos.y = (body->tail->pos.y) % gridSize;
            break;
        
        case 'N':
            newTail->pos.x = (body->tail->pos.x) % gridSize;
            newTail->pos.y = (body->tail->pos.y - 1 + gridSize) % gridSize;
            break;
        
        case 'S':
            newTail->pos.x = (body->tail->pos.x) % gridSize;
            newTail->pos.y = (body->tail->pos.y + 1) % gridSize;
            break;
    }

    body->tail->prev = newTail;
    body->tail = newTail;
}


void draw(int x, int y, char symbole) {
    std::cout<< "\033[" << y + 1 << ";" << x + 1<< "H" << symbole;
}

void displaySnake(snake *body) {
    maillon *currentMaillon = body->head;

    while (currentMaillon != nullptr) {
        if(currentMaillon->next == nullptr) {
            draw(currentMaillon->pos.x, currentMaillon->pos.y / 2, 'O');
        } else {
            draw(currentMaillon->pos.x, currentMaillon->pos.y / 2, 'o');
        }

        currentMaillon = currentMaillon->prev;
    }
}

void displayGrid(int gridSize) {
    for(int x = 0; x < gridSize; x++) {
        draw(x, 0, '-');
    }

    for (int x = 0; x < gridSize; x++) {
        draw(x, gridSize/2, '-');
    }

    for(int y = 0; y < gridSize / 2; y++) {
        draw(0, y, '|');
    }

    for(int y = 0; y < gridSize / 2; y++) {
        draw(gridSize, y, '|');
    }

    draw(0, 0, '+');
    draw(gridSize, 0, '+');
    draw(0, gridSize / 2, '+');
    draw(gridSize, gridSize / 2, '+');
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
            body->head->pos.y = (body->head->pos.y + 1) % gridSize;
            break;
        
        case 'N':
            body->head->pos.x = body->head->pos.x;
            body->head->pos.y = (body->head->pos.y - 1 + gridSize) % gridSize;
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
    
    
    for(int i = 0; i < 10; i++) {
        clearScreen();
        displayGrid(gridSize);
        displaySnake(testBody);
        draw(0, gridSize/2 + 1, ' ');
    
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        forwardSnake(testBody, gridSize);
    }
    changeDirection(testBody, 'N');
    for(int i = 0; i < 10; i++) {
        clearScreen();
        displayGrid(gridSize);
        displaySnake(testBody);
        draw(0, gridSize/2 + 1, ' ');
    
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        forwardSnake(testBody, gridSize);
    }

    backToMenu();
}