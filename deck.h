// filepath: /cardgame/cardgame/src/card.h
#ifndef CARDS_H
#define CARDS_H
#include <string>

struct Card {
    std::string rank;
    std::string suit;
    int points; // Points for blackjack
    int sort;
};

// class Cards {

//private:
//    struct Card;
//};

#endif
