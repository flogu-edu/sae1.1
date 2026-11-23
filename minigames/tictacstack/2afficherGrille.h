#include <iostream>
#include <string>
#include "structGrille.h"

#ifndef AFFICHERGRILLE_H
#define AFFICHERGRILLE_H

void afficherGrille(grille taille, std::string tab[][100]){
    int Morpion = (taille.tailleGrille * taille.tailleCase) + (taille.tailleGrille - 1);
    for (int i = 0; i < Morpion; i++){
        for (int j = 0; j < Morpion; j++){
            std::cout<<tab[i][j];
        }
        std::cout<<std::endl;
    }
}

#endif //AFFICHERGRILLE_H