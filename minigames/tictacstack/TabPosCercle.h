#include <iostream>
#include <string>

#include "structpos.h"

#ifndef TABCERCLE_H
#define TABCERCLE_H

void TabPosCercle(std::string tab[][100],position position, int taillePion){
    std::string taillePionTexte = std::to_string(taillePion) ;
    tab[position.ligne][position.colonne] = "O" + taillePionTexte;
}

#endif //TABCERCLE_H