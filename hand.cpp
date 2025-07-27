#include "hand.h"
#include "deck.h"
#include <algorithm>
#include <iostream>

Hand::Hand(Card** currentDeck, int& deckSize, int size) : handSize(size) {
    hand = drawHand(currentDeck, deckSize, size); // Initialize hand with the specified size
}

Hand::~Hand() {
    delete[] hand; // Clean up memory
}

void Hand::sortHand(Card *hand, int handSize) {
    std::sort(hand, hand + handSize, [](const Card& a, const Card& b) {
        return a.sort < b.sort;
    });
}

Card* drawHand(Card** currentDeck, int& deckSize, int handSize) {

    Card* hand = new Card[handSize]; // Initialize hand with the specified size

    for (int i = 0; i < handSize; i++) {
        int cardPick = rand() % deckSize; // Randomly pick a card from the deck
        hand[i] = (*currentDeck)[cardPick]; // Add the picked card to the hand

        Card* newDeck = new Card[deckSize-1]; // Create a new deck without the picked card
        for (int j = 0, k = 0; j < deckSize; j++) {
            if (j != cardPick) { // Skip the picked card
                newDeck[k++] = (*currentDeck)[j]; // Copy the remaining cards to the new deck
            }
        }
        delete[] *currentDeck; // Clean up memory for the old deck
        *currentDeck = newDeck; // Update the deck to the new deck without the picked card
        deckSize--; // Decrease deck size after picking a card
    }
    // sortHand(hand, handSize); // Sort the hand after drawing cards
    return hand;
}

void Hand::show() const {
    for (int i = 0; i < handSize; i++) {
        std::cout << hand[i].rank << hand[i].suit << " ";
    }
    std::cout << std::endl;
}

int Hand::getScore() const {
    int score = 0;
    for (int i = 0; i < handSize; i++) {
        score += hand[i].points; // Sum the points of each card in the hand
    }
    return score;
}

int Hand::getHandSize() const {
    return handSize; // Return the size of the hand
}

bool Hand::isBusted() {
    return getScore() > 21; // Check if the hand is busted
}
