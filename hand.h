// filepath: /cardgame/cardgame/src/hand.h
#ifndef HAND_H
#define HAND_H

#include "cards.h"
#include "deck.h"
#include <algorithm>
#include <iostream>

class Hand {
private:
    Card* hand;
    int handSize;

public:
    Hand(Card** currentDeck, int& deckSize, int handSize);
    ~Hand();

    Card* drawHand(Card** currentDeck, int& deckSize, int handSize);
    void sortHand(Card* hand, int handSize);
    void show() const;
    int getScore() const;
    int getHandSize() const;
    bool isBusted();
};

#endif // HAND_H
