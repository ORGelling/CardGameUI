// filepath:
#ifndef DECK_H
#define DECK_H

#include "cards.h"
// #include <algorithm>
#include <cstdlib>

class Deck {
private:
    int numDecks;
    int deckSize;
    int totalCards;
    Card* deck;

public:
    Deck(int numDecks = 1);
    ~Deck();

    Card* createDeck(int numDecks);
    Card* getDeck();
    int getTotalCards();
    int getDeckSize();
    void shuffle();
    Card drawCard();
    int getDeckSize() const;
};

#endif // DECK_H
