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

#ifndef PARTIE_H
#define PARTIE_H

void Partie(grille & taille, std::string partie[][100],std::string tabX[][100], std::string tabO[][100]){
    int taillePion ;
    position posXY ;
    bool coupPossible ;

    taille = initGrille(taille); //return un struct Grille (taille.tailleGrille et taille.tailleCase)
    
    std::string joueur = debutPartie(taille, partie); //return quel pion joue (Joueur)
    afficherGrille(taille,partie);

    int total = ((((taille.tailleCase - 1)/ 2 )+ 1) * (taille.tailleGrille* taille.tailleGrille));
    int totalJouer = 0 ;
    
    initTabPosCroix(taille,tabX);
    initTabPosCercle(taille,tabO);

    while(!(victoireX(tabX, tabO, taille)) && !(victoireO(tabX, tabO, taille)) && !(totalJouer >= total)){
        if(joueur == "croix"){
            do{
                taillePion = initPion(taille.tailleCase); //return taillePion
                posXY = initPos(taille.tailleGrille); //return un struct position (posXY.colonne / posXY.ligne)
                coupPossible = jouerPossible(posXY, taillePion, tabX, tabO);
                if(!coupPossible){
                    std::cout<<"Coup impossible !"<<std::endl;
                }
            }while(!coupPossible); //faire tant que ce c'est pas possible de jouer 

            jouerPion(posXY, taille, taillePion, joueur , partie, tabX); // affiche la grille avec le pion placé
            totalJouer++ ;

            joueur = "cercle";
        }
        else{
            do{
                taillePion = initPion(taille.tailleCase); //return taillePion
                posXY = initPos(taille.tailleGrille); //return un struct position (posXY.colonne / posXY.ligne)
                coupPossible = jouerPossible(posXY, taillePion, tabX, tabO);
                if(!coupPossible){
                    std::cout<<"Coup impossible !"<<std::endl;
                }
            }while(!coupPossible); //faire tant que ce c'est pas possible de jouer 

            jouerPion(posXY, taille, taillePion, joueur , partie, tabO); // affiche la grille avec le pion placé
            totalJouer++ ;
            
            joueur = "croix";
        }
    }
    if(victoireX(tabX, tabO, taille)){
        std::cout<<"les croix ont gagnees !"<<std::endl;
    }
    else if(victoireO(tabX, tabO, taille)){
        std::cout<<"les ronds ont gagnees !"<<std::endl;
    }
    else {
        std::cout<<"Match nul !"<<std::endl;
    }
}

#endif //PARTIE_H

