#include <iostream>
#include <string>
#include "structGrille.h"
#include "estAuSommet.h"

#ifndef VICTOIREO_H
#define VICTOIREO_H

bool victoireO(std::string tabX[][100], std::string tabO[][100], grille & taille){
    int untilVictoireO = 0 ;
    
    for(int i = 1 ; i <= taille.tailleGrille ; i++){
        for(int j = 1 ; j <= taille.tailleGrille ; j++){
            if (estAuSommet(tabO, tabX, i, j)){
                untilVictoireO++ ;
            }
        }
        if(untilVictoireO == taille.tailleGrille){
                return true ;
        }
        untilVictoireO = 0 ;
    }
    
    untilVictoireO = 0 ;
    
    for(int i = 1 ; i <= taille.tailleGrille ; i++){
        for(int j = 1 ; j <= taille.tailleGrille ; j++){
            if (estAuSommet(tabO, tabX, j, i)){
                untilVictoireO++ ;
            }
        }
        if(untilVictoireO == taille.tailleGrille){
                return true ;
        }
        untilVictoireO = 0 ;
    }

    for(int i = 1 ; i <= taille.tailleGrille ; i ++){
        if (estAuSommet(tabO, tabX, i, i)){
                untilVictoireO++ ;
            }
        }
    if(untilVictoireO == taille.tailleGrille){
            return true ;
    }
    untilVictoireO = 0 ;
    
    for(int i = taille.tailleGrille ; i >= 1 ; i --){
        if (estAuSommet(tabO, tabX, (taille.tailleGrille + 1)- i, i)){
                untilVictoireO++ ;
            }
        }
    if(untilVictoireO == taille.tailleGrille){
            return true ;
    }
    return false ;
   
}

#endif //VICTOIREO_H 
