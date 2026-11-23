#include <iostream>
#include <string>
#include <algorithm>

#include "structpos.h"
#include "tailleDansCase.h"

#ifndef JOUERPOSSIBLE_H
#define JOUERPOSSIBLE_H

// Un pion de taille taillePion peut être posé sur la case pos si et seulement si sa taille vaut (taille déjà présente + 1).
// Case vide : taille présente = 0, donc on ne peut poser qu'un pion de taille 1.

bool jouerPossible(position pos, int taillePion, std::string tabX[][100], std::string tabO[][100]){

    // Taille du pion de chaque joueur sur cette case (0 s'il n'y en a pas)
    int tailleX = tailleDansCase(tabX[pos.ligne][pos.colonne]) ;
    int tailleO = tailleDansCase(tabO[pos.ligne][pos.colonne]) ;

    // Le pion au sommet est le plus grand des deux
    int taillePresente = std::max(tailleX, tailleO) ;

    return (taillePion == taillePresente + 1) ;
}

#endif //JOUERPOSSIBLE_H
