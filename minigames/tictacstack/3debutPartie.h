#include <iostream>
#include <string>
#include <cctype>

#include "1creerGrille.h"
#include "initPion.h"
#include "initPos.h"
#include "2initGrille.h"
#include "structGrille.h"


#ifndef DEBUTPARTIE_H
#define DEBUTPARTIE_H

std::string debutPartie(grille & taille, std::string tab[][100]){
    
    std::string Joueur ;

    creerGrille(taille, tab);
        do{
        std::cout<<"Qui commence ?" <<std::endl;
        std::cin>>Joueur;
        for (char &c : Joueur){
            c = std::tolower(static_cast<unsigned char>(c));
        }
    } while( Joueur != "croix" && Joueur != "cercle");

    return Joueur ;

}

#endif //DEBUTPARTIE_H