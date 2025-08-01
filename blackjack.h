#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "hand.h"

class BlackJack
{
private:
    Deck deck;
    Hand playerHand;
    Hand dealerHand;
    bool playable;

public:
    void hit();
    void stand();
    void playRound();
    void playerTurn();
    void dealerTurn();
    int quit();
    void status() const;
    void victor() const;
    BlackJack(int numDecks = 1, int handSize = 2);
    void setPlay();
    void stopPlay();
};

#endif // BLACKJACK_H
