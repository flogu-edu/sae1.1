#include <iostream>
#include <string>

#include "3debutPartie.h"
#include "2afficherGrille.h"
#include "jouerPossible.h"
#include "jouerPion.h"
#include "5victoireX.h"
#include "5victoireO.h"
#include "initTabPosCroix.h"
#include "initTabPosCercle.h"
#include "4Partie.h"

void tictacstack(){
    grille taille ;
    std::string tab[100][100];
    std::string partie[100][100];
    std::string tabX[100][100];
    std::string tabO[100][100];


    Partie(taille, partie,tabX,tabO);
}
