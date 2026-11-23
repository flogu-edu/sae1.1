#include <iostream>
#include <string>

#include "tailleDansCase.h"

#ifndef ESTAUSOMMET_H
#define ESTAUSOMMET_H

bool estAuSommet(std::string tabJoueur[][100], std::string tabAdverse[][100], int ligne, int colonne){
    return tailleDansCase(tabJoueur[ligne][colonne]) > tailleDansCase(tabAdverse[ligne][colonne]) ;
}

#endif //ESTAUSOMMET_H
