
#include <iostream>
#include <string>
#include "2afficherGrille.h"
#include "TabPosCroix.h"
#include "TabPosCercle.h"
#include "structGrille.h"
#include "structpos.h"
 
#ifndef JOUERPION_H
#define JOUERPION_H
 
// Pose un pion (croix / cercle) sur le plateau.

//  - pos       : case choisie (colonne / ligne)
//  - taille    : taille de la grille et taille d'une case
//  - taillePion: taille du pion (1 = Croix nv 1)
//  - joueur    : "croix" / "cercle" (valeur de debutPartie)
//  - partie    : tableau d'AFFICHAGE (X, O, -, |, +, *)
//  - tab       : tableau LOGIQUE (mémorise les coups pour la victoire)
void jouerPion(position pos, grille taille, int taillePion, std::string joueur, std::string partie[][100], std::string tab[][100]){
 
    int posfinalX ;
    int posfinalY ;
    int pas = taille.tailleCase + 1 ;   // distance entre le début de deux cases (séparateur compris)
 
    // 1) Vérifications
 
    // La case choisie doit être dans la grille
    if (pos.colonne < 1 || pos.colonne > taille.tailleGrille || pos.ligne < 1 || pos.ligne > taille.tailleGrille){
        std::cout << "Case invalide" << std::endl;
        return;
    }
    // Le pion doit tenir dans la case
    if (taillePion < 1 || 2 * taillePion - 1 > taille.tailleCase){
        std::cout << "Taille de pion invalide" << std::endl;
        return;
    }
 
    // 2) Calcul du centre de la case dans le tableau d'affichage
 
    if (taille.tailleCase % 2 == 1) {
        // Case de taille impaire : le centre est exactement au milieu
        posfinalX = (pos.colonne - 1) * pas + taille.tailleCase / 2;
        posfinalY = (pos.ligne - 1) * pas + taille.tailleCase / 2;
    }
    else {
        // Case de taille paire : pas de milieu exact, on prend le caractère juste avant
        posfinalX = (pos.colonne - 1) * pas + (taille.tailleCase - 1) / 2;
        posfinalY = (pos.ligne - 1) * pas + (taille.tailleCase - 1) / 2;
    }
 
    int posdecalX = posfinalX;
    int posdecalY = posfinalY;
 
    // 3) Dessin du pion 
 
    if (joueur == "croix"){
 
        // Le centre
        partie[posfinalY][posfinalX] = 'X';
 
        // Diagonale vers le bas à droite
        for (int j = 0; j < (taillePion - 1); j++){
            posdecalX = posdecalX + 1 ;
            posdecalY = posdecalY + 1 ;
            partie[posdecalY][posdecalX] = 'X';
        }
        // On repart du centre : diagonale vers le haut à gauche
        posdecalX = posfinalX ;
        posdecalY = posfinalY ;
        for (int j = 0; j < (taillePion - 1); j++){
            posdecalX = posdecalX - 1 ;
            posdecalY = posdecalY - 1 ;
            partie[posdecalY][posdecalX] = 'X';
        }
        
        // Diagonale vers le bas à gauche
        posdecalX = posfinalX ;
        posdecalY = posfinalY ;

        for (int j = 0; j < (taillePion - 1); j++){
            posdecalX = posdecalX + 1 ;
            posdecalY = posdecalY - 1 ;
            partie[posdecalY][posdecalX] = 'X';
        }
        // Diagonale vers le haut à droite
        posdecalX = posfinalX ;
        posdecalY = posfinalY ;
        for (int j = 0; j < (taillePion - 1); j++){
            posdecalX = posdecalX - 1 ;
            posdecalY = posdecalY + 1 ;
            partie[posdecalY][posdecalX] = 'X';
        }
 
        // Mise à jour du tableau logique pour la croix
        TabPosCroix(tab, pos, taillePion);
    }
    else {
        int x = taillePion - 1 ;   // distance entre le centre et un côté du carré
 
        if (taillePion == 1){
            // Cercle de taille 1 : un seul caractère
            partie[posfinalY][posfinalX] = 'O';
        }
        else {
            // Côté "bas" du carré
            for (int j = 0 - x; j <= x; j++){
                posdecalX = posfinalX + j ;
                posdecalY = posfinalY + x ;
                partie[posdecalY][posdecalX] = 'O';
            }
            // Côté "haut"
            for (int j = 0 - x; j <= x; j++){
                posdecalX = posfinalX + j ;
                posdecalY = posfinalY - x ;
                partie[posdecalY][posdecalX] = 'O';
            }
            // Côté "gauche"
            for (int j = 0 - x; j <= x; j++){
                posdecalX = posfinalX - x ;
                posdecalY = posfinalY + j ;
                partie[posdecalY][posdecalX] = 'O';
            }
            // Côté "droit"
            for (int j = 0 - x; j <= x; j++){
                posdecalX = posfinalX + x ;
                posdecalY = posfinalY + j ;
                partie[posdecalY][posdecalX] = 'O';
            }
        }
 
        // Mise à jour du tableau logique pour le cercle
        TabPosCercle(tab, pos, taillePion);
    }
 
    // 4) Affichage du plateau après le coup
    afficherGrille(taille, partie);
}
 
#endif //JOUERPION_H
 