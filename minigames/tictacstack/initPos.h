#include <iostream>
#include <string>
#include <limits>
#include "structpos.h"

#ifndef INITPOS_H
#define INITPOS_H

position initPos(int tailleGrille){
    position posXY;
    posXY.colonne = 0;
    posXY.ligne = 0;
    
    bool colonneInvalide = false;
    bool ligneInvalide = false;

    do{
        std::cout<<"Quelle colonne ?"<<std::endl;
        std::cin>>posXY.colonne;
        colonneInvalide = (posXY.colonne > tailleGrille || posXY.colonne <= 0);
        if (std::cin.fail()) {
            std::cin.clear();
        }   
        if(colonneInvalide){
            std::cout<<"Impossible !"<<std::endl;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while(colonneInvalide);
    do{
        std::cout<<"Quelle ligne ?"<<std::endl;
        std::cin>>posXY.ligne;
        ligneInvalide = (posXY.ligne > tailleGrille || posXY.ligne <= 0);
        if (std::cin.fail()) {
            std::cin.clear();
        }   
        if(ligneInvalide){
            std::cout<<"Impossible !"<<std::endl;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while(ligneInvalide);

   return posXY ;
}

#endif //INITPOS_H