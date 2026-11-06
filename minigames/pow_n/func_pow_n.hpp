#include <iostream>
#include <vector>

void displayPow_n(int n, std::vector<std::vector<char>>& grid) {

    std::cout << std::endl;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}

bool checkVictory(int n, std::vector<std::vector<char>>& grid, char pawn) {

    // Vérification horizontale et verticale
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {

            // Horizontal
            if (j + 3 < n &&
                grid[i][j] == pawn &&
                grid[i][j+1] == pawn &&
                grid[i][j+2] == pawn &&
                grid[i][j+3] == pawn) {
                return true;
            }

            // Vertical
            if (i + 3 < n &&
                grid[i][j] == pawn &&
                grid[i+1][j] == pawn &&
                grid[i+2][j] == pawn &&
                grid[i+3][j] == pawn) {
                return true;
            }

            // Diagonale descendante
            if (i + 3 < n && j + 3 < n &&
                grid[i][j] == pawn &&
                grid[i+1][j+1] == pawn &&
                grid[i+2][j+2] == pawn &&
                grid[i+3][j+3] == pawn) {
                return true;
            }

            // Diagonale montante
            if (i >= 3 && j + 3 < n &&
                grid[i][j] == pawn &&
                grid[i-1][j+1] == pawn &&
                grid[i-2][j+2] == pawn &&
                grid[i-3][j+3] == pawn) {
                return true;
            }
        }
    }

    return false;
}