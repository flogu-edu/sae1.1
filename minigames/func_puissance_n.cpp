#include <iostream>
#include <vector>

void displayPuissance_n(int n, std::vector<std::vector<char>>& grille) {

    std::cout << std::endl;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << grille[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}

bool verifierVictoire(int n, std::vector<std::vector<char>>& grille, char pion) {

    // Vérification horizontale et verticale
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {

            // Horizontal
            if (j + 3 < n &&
                grille[i][j] == pion &&
                grille[i][j+1] == pion &&
                grille[i][j+2] == pion &&
                grille[i][j+3] == pion) {
                return true;
            }

            // Vertical
            if (i + 3 < n &&
                grille[i][j] == pion &&
                grille[i+1][j] == pion &&
                grille[i+2][j] == pion &&
                grille[i+3][j] == pion) {
                return true;
            }

            // Diagonale descendante
            if (i + 3 < n && j + 3 < n &&
                grille[i][j] == pion &&
                grille[i+1][j+1] == pion &&
                grille[i+2][j+2] == pion &&
                grille[i+3][j+3] == pion) {
                return true;
            }

            // Diagonale montante
            if (i >= 3 && j + 3 < n &&
                grille[i][j] == pion &&
                grille[i-1][j+1] == pion &&
                grille[i-2][j+2] == pion &&
                grille[i-3][j+3] == pion) {
                return true;
            }
        }
    }

    return false;
}