// filepath: /cardgame/cardgame/src/hand.h
#ifndef HAND_H
#define HAND_H

#include "deck.h"

class Hand {

private:

    Card* hand;
    int handSize;

public:

    int getHandSize() const {
        return handSize; // Return the size of the hand
    };
    void setHandSize(int size) {
        handSize = size; // Set the size of the hand
    };
    Card* getHand() const {
        return hand; // Return the hand
    };
    void sortHand();
    Hand(Deck& deck, int size);
    ~Hand() {
        delete[] hand; // Clean up memory
    };
    void drawCard(Deck& deck, int draws = 1);
    void show() const;
    void showSplit() const;
    void showSize() const;
    int getScore() const;
    void showScore() const;
    bool isBusted() const;
};
#endif // HAND_H
