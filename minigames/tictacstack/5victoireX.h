#include <iostream>
#include <string>
#include "structGrille.h"
#include "estAuSommet.h"

#ifndef VICTOIREX_H
#define VICTOIREX_H

bool victoireX(std::string tabX[][100], std::string tabO[][100], grille & taille){
    int untilVictoireX = 0 ;
    
    for(int i = 1 ; i <= taille.tailleGrille ; i++){
        for(int j = 1 ; j <= taille.tailleGrille ; j++){
            if (estAuSommet(tabX, tabO, i, j)){
                untilVictoireX++ ;
            }
        }
        if(untilVictoireX == taille.tailleGrille){
                return true ;
        }
        untilVictoireX = 0 ;
    }
    
    untilVictoireX = 0 ;
    
    for(int i = 1 ; i <= taille.tailleGrille ; i++){
        for(int j = 1 ; j <= taille.tailleGrille ; j++){
            if (estAuSommet(tabX, tabO, j, i)){
                untilVictoireX++ ;
            }
        }
        if(untilVictoireX == taille.tailleGrille){
                return true ;
        }
        untilVictoireX = 0 ;
    }

    for(int i = 1 ; i <= taille.tailleGrille ; i ++){
        if (estAuSommet(tabX, tabO, i, i)){
                untilVictoireX++ ;
            }
        }
    if(untilVictoireX == taille.tailleGrille){
            return true ;
    }
    untilVictoireX = 0 ;
    
    for(int i = taille.tailleGrille ; i >= 1 ; i --){
        if (estAuSommet(tabX, tabO, (taille.tailleGrille + 1)- i, i)){
                untilVictoireX++ ;
            }
        }
    if(untilVictoireX == taille.tailleGrille){
            return true ;
    }
    return false ;

}
#endif //VICTOIREX_H