// filepath: /cardgame/cardgame/src/hand.h
#ifndef HAND_H
#define HAND_H

#include "deck.h"

class Hand {

private:

    Card* hand;
    int handSize;
    int startHandSize;

public:

    int getHandSize() const {
        return handSize; // Return the size of the hand
    };
    void setHandSize(int size) {
        handSize = size; // Set the size of the hand
    };
    Card* getHandFull() const {
        return hand; // Return the hand
    };
    void sortHand();
    Hand(Deck& deck, int size);
    ~Hand() {
        delete[] hand; // Clean up memory
    };
    void drawCard(Deck& deck, int draws = 1);
    void show() const;
    string getHand() const;
    void showSplit() const;
    void showSize() const;
    int getScore() const;
    void showScore() const;
    bool isBusted() const;
    void redraw(Deck& deck);
};
#endif // HAND_H
