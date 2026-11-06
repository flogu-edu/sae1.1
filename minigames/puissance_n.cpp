#include "func_puissance_n.cpp"
#include <iostream>
#include <vector>

int main() {

    int n = 6;

    std::vector<std::vector<char>> grille(n, std::vector<char>(n, '.'));

    int colonne;
    int joueur = 1;
    int tours = 0;

    while (tours < n * n) {

        displayPuissance_n(n, grille);

        std::cout << "Tour du joueur " << joueur << std::endl;
        std::cout << "Dans quelle colonne voulez-vous jouer ? ";
        std::cin >> colonne;

        if (colonne < 1 || colonne > n) {
            std::cout << "Colonne invalide !" << std::endl;
            continue;
        }

        colonne--;

        int ligne = n - 1;

        while (ligne >= 0 && grille[ligne][colonne] != '.') {
            ligne--;
        }

        if (ligne < 0) {
            std::cout << "Cette colonne est pleine !" << std::endl;
            continue;
        }

        char pion = (joueur == 1) ? 'X' : 'O';

        grille[ligne][colonne] = pion;

        tours++;

        if (verifierVictoire(n, grille, pion)) {

            displayPuissance_n(n, grille);

            std::cout << "Le joueur " << joueur << " a gagne !" << std::endl;

            return 0;
        }

        if (joueur == 1) {
            joueur = 2;
        }
        else {
            joueur = 1;
        }
    }

    std::cout << "Match nul !" << std::endl;

    return 0;
}