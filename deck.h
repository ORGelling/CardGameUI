// filepath: /cardgame/cardgame/src/card.h
#ifndef Deck_H
#define Deck_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>

using namespace std;

struct Card {
    string rank;
    string suit;
    int points; // Points for blackjack
    int sort;
};

class Deck {

private:
    int numDecks;
    int totalCards;
    int deckSize;
    Card* deck;

public:
    Card* createDeck(int numDecks);
    Card drawCard();

    void showDeck() const;
    void showDeckSplit();
    void showSize() const;
    void sortDeck();
    void setRand();
    Deck(int numDecks = 1);
    ~Deck() {
        delete[] deck; // Clean up memory
    }
    Card* getDeck() {
        return deck;
    }
    void setDeck(Card* newDeck) {
        deck = newDeck; // Set the deck to a new deck
    }
    void setDeckSize(int size) {
        deckSize = size; // Set the size of the deck
    }
    int getDeckSize() {
        return deckSize; // Return the size of the deck
    }
    int getTotalCards() {
        return totalCards;
    }
    void reset();
};

#endif
