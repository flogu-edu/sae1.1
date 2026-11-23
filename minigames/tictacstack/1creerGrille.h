#include <iostream>
#include <string>
#include "structGrille.h"

#ifndef CREERGRILLE_H
#define CREERGRILLE_H

void creerGrille(grille taille, std::string tab[][100]){
    int Morpion = (taille.tailleGrille * taille.tailleCase) + (taille.tailleGrille - 1);
    int x = taille.tailleCase + 1 ;

    for (int i = 0; i < Morpion; i++){
        for (int j = 0; j < Morpion; j++){
            bool separationLigne = (i % x == taille.tailleCase); 
            bool separationColonne = (j % x == taille.tailleCase);

            if(separationLigne && !separationColonne){
                tab[i][j] = "-" ;
            }
            else if(separationColonne && !separationLigne){
                tab[i][j] = "|" ;
            }
            else if (separationColonne && separationLigne){
                tab[i][j] = "+" ;
            }
            else{
                tab[i][j] = "*"; 
            }
        }
    }
}

#endif //CREERGRILLE_H