#include <iostream>
#include "snake.h"

struct position {
    int x;
    int y;
};

struct maillon {
    maillon *next;
    maillon *prev;
    position position;
    char direction;
};

struct snake {
    maillon *head;
    maillon *tail;
};

void init(snake *body) {
    maillon *newPart =  new maillon;
    newPart->next = nullptr;
    newPart->prev = nullptr;
    newPart->position = { 50, 50 };
    newPart->direction = 'E';

    body->head = newPart;
    body->tail = newPart;
}

void addTail(snake *body) {
    maillon *newTail = new maillon;
    newTail->next = body->tail;
    newTail->prev = nullptr;
    newTail->direction = body->tail->direction;

    
    switch (body->tail->direction) {
        case 'E':
            newTail->position.x = body->tail->position.x - 1;
            newTail->position.y = body->tail->position.y;
            break;
        
        case 'W':
            newTail->position.x = body->tail->position.x + 1;
            newTail->position.y = body->tail->position.y;
            break;
        
        case 'N':
            newTail->position.x = body->tail->position.x;
            newTail->position.y = body->tail->position.y - 1;
            break;
        
        case 'S':
            newTail->position.x = body->tail->position.x;
            newTail->position.y = body->tail->position.y + 1;
            break;
    }

    body->tail->prev = newTail;
    body->tail = newTail;
}

void displaySnake(snake *body) {
    maillon *currentMaillon = body->head;

    while(currentMaillon != nullptr) {
        std::cout<<"X : "<<currentMaillon->position.x;
        std::cout<<" Y : "<<currentMaillon->position.y<<std::endl;

        std::cout<<"Direction : "<<currentMaillon->direction<<std::endl;
        std::cout<<"Maillon actuel : "<<currentMaillon<<std::endl;
        std::cout<<"Maillon precedent : "<<currentMaillon->next<<std::endl;
        std::cout<<"Maillon suivant : "<<currentMaillon->prev<<std::endl;

        currentMaillon = currentMaillon->prev;
    }
}

void snakeGame() {
    snake *testBody = new snake;
    init(testBody);
    addTail(testBody);
    addTail(testBody);
    displaySnake(testBody);
}

int main() {
    snakeGame();
}