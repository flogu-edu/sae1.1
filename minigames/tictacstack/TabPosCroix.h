#include <iostream>
#include <string>

#include "structpos.h"

#ifndef TABCROIX_H
#define TABCROIX_H

void TabPosCroix(std::string tab[][100],position position, int taillePion){
    std::string taillePionTexte = std::to_string(taillePion) ;
    tab[position.ligne][position.colonne] = "X" + taillePionTexte;
}

#endif //TABCROIX_H
