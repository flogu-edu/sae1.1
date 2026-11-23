#include <iostream>
#include <string>

#ifndef TAILLEDANSCASE_H
#define TAILLEDANSCASE_H

// Renvoie la taille du pion mémorisée dans une case du tableau logique.
//  - une case jamais jouée vaut "0" : taille 0
//  - une case jouée vaut "X3", "O12", ... : on lit tout ce qui suit la 1re lettre
int tailleDansCase(const std::string & contenu){
    if (contenu.size() < 2){
        return 0 ;
    }
    return std::stoi(contenu.substr(1)) ;
}
#endif //TAILLEDANSCASE_H
