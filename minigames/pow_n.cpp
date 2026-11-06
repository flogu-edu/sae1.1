#include "func_pow_n.cpp"
#include <iostream>
#include <vector>

int main() {

    int n = 6;

    std::vector<std::vector<char>> grid(n, std::vector<char>(n, '.'));

    int column;
    int player = 1;
    int rounds = 0;

    while (rounds < n * n) {

        displayPow_n(n, grid);

        std::cout << "Tour du joueur " << player << std::endl;
        std::cout << "Dans quelle colonne voulez-vous jouer ? ";
        std::cin >> column;

        if (column < 1 || column > n) {
            std::cout << "Colonne invalide !" << std::endl;
            continue;
        }

        column--;

        int line = n - 1;

        while (line >= 0 && grid[line][column] != '.') {
            line--;
        }

        if (line < 0) {
            std::cout << "Cette colonne est pleine !" << std::endl;
            continue;
        }

        char pawn = (player == 1) ? 'X' : 'O';

        grid[line][column] = pawn;

        rounds++;

        if (checkVictory(n, grid, pawn)) {

            displayPow_n(n, grid);

            std::cout << "Le joueur " << player << " a gagne !" << std::endl;

            return 0;
        }

        if (player == 1) {
            player = 2;
        }
        else {
            player = 1;
        }
    }

    std::cout << "Match nul !" << std::endl;

    return 0;
}