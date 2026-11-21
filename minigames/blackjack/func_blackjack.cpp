#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <ctime>

#include "blackjack.h"
#include "../../utils/backToMenu.h"
using namespace std;

struct Cards {
    int value;
    char suit;
};

vector<Cards> createCards(){

    char suit[] = {'H', 'D', 'C', 'S'};

    vector<Cards> cards;
    int val;

    for (int j = 0; j < 4; ++j){
        for (int i = 1; i <= 13; ++i){

            if (i > 10) val = 10;
            else if (i == 1) val = 11;
            else val = i;

            cards.push_back({val, suit[j]});
        }
    }

    return cards;
}

vector<Cards> deck = createCards();

// Vérifie et choisi la valeur de l'As
int handValue(vector<Cards>& hand){

    int value_all = 0;
    int aces = 0;

    for (int i = 0; i < hand.size(); ++i){

        if (hand[i].value == 11) ++aces;
        value_all += hand[i].value;
    }

    while (aces > 0){

        if (aces > 0 && value_all > 21) value_all -= 10;
        aces -= 1;
    }

    return value_all;
}

// Vérifie si il y a Blackjack
bool isBlackjack(vector<Cards>& hand){

    return (handValue(hand) == 21 && hand.size() == 2);
}

// Vérifie si la main dépasse 21
bool exceeds21(vector<Cards>& hand){

    return (handValue(hand) > 21);
}

// Affiche la main avec sa valeur
void printHand(const string& name, vector<Cards>& hand){

    cout << name << " : ";
    for (int i = 0; i < hand.size(); ++i){
        if (i > 0) cout << " | ";
        cout << hand[i].value << hand[i].suit;
    }
    cout << " (" << handValue(hand) << ")" << endl;
}

// Demande si le joueur veut tirer une carte ou pas
int askHitOrStand(){

    string choice;
    while (true){
        
        cout << "Wanna hit : 1" << endl << "Wanna stand : 0" << endl;
        cin >> choice;

        if (choice == "1") return 1;
        if (choice == "0") return 0;

        cout << "Invalid input" << endl;
    }
}

// Tour du joueur, jusqu'à ce qu'il stand ou qu'il bust
int playerTurn(vector<Cards>& hand){

    while (!exceeds21(hand) && askHitOrStand() == 1){

        hand.push_back(deck[rand() % 52]);
        printHand("Your hand", hand);
    }

    return handValue(hand);
}

// Tour du dealer, après celui du joueur, jusqu'à atteindre 17
int dealerTurn(vector<Cards>& hand){
    
    while (handValue(hand) < 17){

        hand.push_back(deck[rand() % 52]);
    }

    return handValue(hand);
}

// Redemande si le joueur veut rejouer avant de revenir au menu principal
bool askReplay(){

    string choice;

    while (true){

        cout << "Play again ? (y/n)" << endl;
        cin >> choice;

        if (choice == "y") return true;
        if (choice == "n") return false;

        cout << "Invalid input" << endl;
    }
}

// Fonction de jeu
void displayBlackjack(){

    vector<Cards> dealer_hand = {deck[rand() % 52], deck[rand() % 52]};
    vector<Cards> player_hand = {deck[rand() % 52], deck[rand() % 52]};

    printHand("Your hand", player_hand);
    cout << "Dealer's hand : " << dealer_hand[0].value << dealer_hand[0].suit << " | ?" << endl;

    if (isBlackjack(dealer_hand)) cout << "Blackjack for the dealer !" << endl;
    else if (isBlackjack(player_hand)) cout << "Blackjack for you !" << endl;
    else {

        int player_value = playerTurn(player_hand);
        if (exceeds21(player_hand)){

            cout << "You've bust !.." << endl;
            return;
        }

        int dealer_value = dealerTurn(dealer_hand);
        printHand("Dealer's hand", dealer_hand);

        if (exceeds21(dealer_hand)) cout << "Dealer bust, you win !" << endl;
        else if (player_value > dealer_value) cout << "You win !" << endl;
        else if (player_value == dealer_value) cout << "Tie !" << endl;
        else cout << "Dealer win !" << endl;
    }
}

// Fait jouer au moins une fois, puis demande si on veut rejouer
void blackjack(){

    srand(time(NULL));

    do {
        displayBlackjack();
    } while (askReplay());

    backToMenu();
}