#include "hand.h"

void Hand::sortHand() {
    //easy sort lmao
    sort(hand, hand + handSize, [](const Card& a, const Card& b) {
        return a.sort < b.sort;
    });
};

Hand::Hand(Deck& deck, int size) : handSize(size) {
    hand = new Card[handSize]; // Initialize hand with the specified size
    for (int i = 0; i < handSize; i++) {
        hand[i] = deck.drawCard(); // Draw a card from the deck
    }
    sortHand(); // Initialize hand with the specified size
};

void Hand::drawCard(Deck& deck, int draws) {
    Card* newHand = new Card[handSize + draws]; // Initialize hand with the specified size
    for (int i = 0; i < handSize; i++) {
        newHand[i] = hand[i]; // Copy existing cards to the new hand
    }
    // Draw additional cards from the deck
    for (int i = handSize; i < handSize + draws; i++) {
        newHand[i] = deck.drawCard(); // Draw a card from the deck
    }
    delete[] hand; // Clean up memory for the old hand
    hand = newHand; // Update the hand to the new hand with the drawn cards
    handSize += draws; // Increase the size of the hand
    sortHand(); // Initialize hand with the specified size
};


void Hand::show() const {
    for (int i = 0; i < handSize; i++) {
        cout << hand[i].rank << hand[i].suit << " ";
    }
    cout << endl;
};

void Hand::showSplit() const {
    for (int i = 0; i < handSize; i++) {
        cout << hand[i].rank << hand[i].suit << " ";
        if (i < handSize - 1 && hand[i].suit != hand[i + 1].suit) {
            cout << endl; // Print a new line if the suit changes
        }
    }
    cout << endl;
};

void Hand::showSize() const {
    cout << "Hand size: " << handSize << endl; // Show the size of the deck
};

int Hand::getScore() const {
    int score = 0;
    for (int i = 0; i < handSize; i++) {
        score += hand[i].points; // Sum the points of each card in the hand
    }
    return score;
};

void Hand::showScore() const {
    int score = 0;
    for (int i = 0; i < handSize; i++) {
        score += hand[i].points; // Sum the points of each card in the hand
    }
    cout << "Player score is: " << score << endl;
};

bool Hand::isBusted() const {
    return getScore() > 21; // Check if the hand is busted
};
