#include <iostream>
#include <string>
#include <limits>

#ifndef INITPION_H
#define INITPION_H

int initPion(int tailleCase){
    int taillepion = 0;
    bool tailleInvalide = false;
    do{
        std::cout<<"Taille du pion ?"<<std::endl;
        std::cin>>taillepion;
        tailleInvalide = (taillepion > ((tailleCase + 1)/2)  || taillepion <= 0);
        if (std::cin.fail()) {
            std::cin.clear();
        }   
        if(tailleInvalide){
            std::cout<<"Impossible !"<<std::endl;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while(tailleInvalide); 
    return taillepion ;
}

#endif //INITPION_H