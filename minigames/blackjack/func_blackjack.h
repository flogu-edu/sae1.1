#include <iostream>
#include <cstdlib>
#include <vector>
#include <random>
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

        if (aces > 0 && value_all < 21){

            value_all -= 10;
        }
    }

    return value_all;
}

// Vérifie si il y a Blackjack
bool isBlackjack(vector<Cards>& hand){

    return (handValue(hand) == 21);
}

// Vérifie si la main dépasse 21
bool exceeds21(vector<Cards>& hand){

    return (handValue(hand) < 21);
}

// Tour du joueur, jusqu'à ce qu'il stand
void playerTurn(vector<Cards>& hand){

    Cards new_card;

    bool play = 1;
    cout << "Wanna hit : 1" << endl << "Wanna stand : 0" << endl;
    cin >> play;

    while(play){

        new_card = deck[rand() % 52];
        hand.push_back(new_card);

        if (exceeds21(hand)){
            cout << "You've bust.." << endl;
            return;
        }

        cout << "Wanna hit : 1" << endl << "Wanna stand : 0" << endl;
        cin >> play;
    }
}

// Tour du dealer, après celui du joueur, jusqu'à atteindre 17
void dealerTurn(vector<Cards>& hand){
    
    Cards new_card;

    while(handValue(hand) < 17){
        new_card = deck[rand() % 52];
        hand.push_back(new_card);
    }
}

void displayBlackjack(){

    vector<Cards> dealer_hand = {deck[rand() % 52], deck[rand() % 52]};
    vector<Cards> player_hand = {deck[rand() % 52], deck[rand() % 52]};

    cout << "Your hand : " << player_hand[0].value << player_hand[0].suit << " | " << player_hand[1].value << player_hand[1].suit << endl;
    cout << "Dealer's hand : " << dealer_hand[0].value << dealer_hand[0].suit << " | ?" << endl;

    handValue(dealer_hand);
    handValue(player_hand);

    if (isBlackjack(dealer_hand)) cout << "Blackjack for the dealer !" << endl;
    else if (isBlackjack(player_hand)) cout << "Blackjack for you !" << endl;

    else {
        playerTurn(player_hand);
        dealerTurn(dealer_hand);
    }
}