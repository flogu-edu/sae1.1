#include <iostream>
#include <string>
#include <limits>
#include "structGrille.h"

#ifndef INITGRILLE_H
#define INITGRILLE_H

grille initGrille(grille & taille){
    int x = 0;
    int tailleGrilleInvalide = 0 ;
    int tailleCaseInvalide = 0 ;
        
    do{    
        do{
            std::cout<<"Taille de la grille ?" <<std::endl;
            std::cin>>taille.tailleGrille;
            tailleGrilleInvalide = (taille.tailleGrille <= 2) ;
            if (std::cin.fail()) {
                    std::cin.clear();
            }   
            if(tailleGrilleInvalide){
                std::cout<<"Impossible !"<<std::endl;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }while(tailleGrilleInvalide);

        do{
            std::cout<<"Taille de chaque case ?" <<std::endl;
            std::cin>>taille.tailleCase;
            tailleCaseInvalide = (taille.tailleCase <= 0) ;
            if (std::cin.fail()) {
                    std::cin.clear();
            }   
            if(tailleCaseInvalide){
                std::cout<<"Impossible !"<<std::endl;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }while(tailleCaseInvalide);
        x = (taille.tailleGrille * taille.tailleCase + (taille.tailleGrille - 1));
    }while(x > 100);
    return taille ;
}
#endif //INITGRILLE_H