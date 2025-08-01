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
    void cardStatus() const;
    void victor() const;
    BlackJack(int numDecks = 1, int handSize = 2);
    void setPlay();
    void stopPlay();
    string getPlayer() const;
    string getDealer() const;
    bool status() const;
    void reset();
    bool playerBust() const;
    bool dealerBust() const;
    int scorePlayer() const;
    int scoreDealer() const;
};

#endif // BLACKJACK_H
