#include <iostream>
#include <string>

#include "structGrille.h"

#ifndef INITTABCERCLE_H
#define INITTABCERCLE_H

void initTabPosCercle(grille taille, std::string tab[][100]){
    for(int i = 1 ; i <= taille.tailleGrille ; i++){
        for(int j = 1 ; j <= taille.tailleGrille ; j++){
            tab[i][j] = "0" ;
        }
    }
}

#endif //INITTABCERCLE_H