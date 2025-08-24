#include "blackjack.h"

void BlackJack::hit() {
    playerHand.drawCard(deck); // Draw a card for the player
    //playerHand.show();
    // if (playerHand.isBusted()) {
    //     ;
    // } else {
    //     ;
    // }
};

void BlackJack::stand() {
    // dealerHand.show();
    stopPlay();
    while (dealerHand.getScore() < 17) { // Dealer hits until score is 17 or higher
        dealerHand.drawCard(deck);
        // dealerHand.show();
        // cout << "Dealer's new score: " << dealerHand.getScore() << endl;
    }
    if (!dealerHand.isBusted()) {
        // cout << "Dealer stands" << endl;
    }
};

void BlackJack::playRound() {
    // Implement the logic for playing a round of blackjack
};

void BlackJack::playerTurn() {
    // Implement the player's turn logic
};

void BlackJack::dealerTurn() {
    cout << "Dealer's turn.\n Dealer has hand:" << endl;
    dealerHand.show();
    cout << " Dealer's score: " << dealerHand.getScore() << endl;
    while (dealerHand.getScore() < 17) { // Dealer hits until score is 17 or higher
        cout << "Dealer hits." << endl;
        dealerHand.drawCard(deck);
        dealerHand.show();
        cout << "Dealer's new score: " << dealerHand.getScore() << endl;
    }
    if (!dealerHand.isBusted()) {
        cout << "Dealer stands" << endl;
    }
    //if (dealerHand.isBusted()) {
    //	cout << "Dealer busted" << endl;
    //} else {
    //	cout << "Dealer stands" << endl;
    //}
};

int BlackJack::quit() {
    cout << "Quitting the game." << endl;
    return 0; // Exit the game
};

void BlackJack::cardStatus() const {
    cout << "Player's hand: ";
    playerHand.show();
    cout << "Player's score: " << playerHand.getScore() << endl;
    cout << "Dealer's hand: ";
    dealerHand.show();
    cout << "Dealer's score: " << dealerHand.getScore() << endl;
};

void BlackJack::victor() const {
    if (playerHand.isBusted()) {
        cout << "Player busted. Dealer wins!" << endl;
    } else if (dealerHand.isBusted()) {
        cout << "Dealer busted. Player wins!" << endl;
    } else if (playerHand.getScore() > dealerHand.getScore()) {
        cout << "Player wins with score: " << playerHand.getScore() << endl;
    } else if (dealerHand.getScore() > playerHand.getScore()) {
        cout << "Dealer wins with score: " << dealerHand.getScore() << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
};

BlackJack::BlackJack(int numDecks, int handSize) :		deck(numDecks), playerHand(deck, handSize), dealerHand(deck, handSize) {
    playable = true;
};

void BlackJack::reset() {
    deck.reset();
    playerHand.redraw(deck);
    dealerHand.redraw(deck);
    playable = true;
};

void BlackJack::setPlay() {
    playable = true;
}

void BlackJack::stopPlay() {
    playable = false;
}

string BlackJack::getPlayer() const {
    return playerHand.getHand();
};

string BlackJack::getDealer() const {
    return dealerHand.getHand();
};

bool BlackJack::status() const {
    return playable;
};

bool BlackJack::playerBust() const{
    return playerHand.isBusted();
};

bool BlackJack::dealerBust() const{
    return dealerHand.isBusted();
};

int BlackJack::scorePlayer() const{
    return playerHand.getScore();
};

int BlackJack::scoreDealer() const{
    return dealerHand.getScore();
};
