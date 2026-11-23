#include <iostream>
#include <string>

#include "structGrille.h"

#ifndef INITTABCROIX_H
#define INITTABCROIX_H

void initTabPosCroix(grille taille, std::string tab[][100]){
    for(int i = 1 ; i <= taille.tailleGrille ; i++){
        for(int j = 1 ; j <= taille.tailleGrille ; j++){
            tab[i][j] = "0" ;
        }
    }
}

#endif //INITTABCROIX_H
