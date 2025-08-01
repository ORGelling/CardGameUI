#include "blackjack.h"

void BlackJack::hit() {
    playerHand.drawCard(deck); // Draw a card for the player
    //playerHand.show();
    if (playerHand.isBusted()) {
        ;
    } else {
        ;
    }
};

void BlackJack::stand() {
    cout << "Player stands with score: " << playerHand.getScore() << endl;
    dealerTurn(); // Proceed to dealer's turn
};

void BlackJack::playRound() {
    // Implement the logic for playing a round of blackjack
};

void BlackJack::playerTurn() {
    // Implement the player's turn logic
};

void BlackJack::dealerTurn() {
    cout << "Dealer's turn.\n Dealer has hand:" << endl;
    dealerHand.show();
    cout << " Dealer's score: " << dealerHand.getScore() << endl;
    while (dealerHand.getScore() < 17) { // Dealer hits until score is 17 or higher
        cout << "Dealer hits." << endl;
        dealerHand.drawCard(deck);
        dealerHand.show();
        cout << "Dealer's new score: " << dealerHand.getScore() << endl;
    }
    if (!dealerHand.isBusted()) {
        cout << "Dealer stands" << endl;
    }
    //if (dealerHand.isBusted()) {
    //	cout << "Dealer busted" << endl;
    //} else {
    //	cout << "Dealer stands" << endl;
    //}
};

int BlackJack::quit() {
    cout << "Quitting the game." << endl;
    return 0; // Exit the game
};

void BlackJack::cardStatus() const {
    cout << "Player's hand: ";
    playerHand.show();
    cout << "Player's score: " << playerHand.getScore() << endl;
    cout << "Dealer's hand: ";
    dealerHand.show();
    cout << "Dealer's score: " << dealerHand.getScore() << endl;
};

void BlackJack::victor() const {
    if (playerHand.isBusted()) {
        cout << "Player busted. Dealer wins!" << endl;
    } else if (dealerHand.isBusted()) {
        cout << "Dealer busted. Player wins!" << endl;
    } else if (playerHand.getScore() > dealerHand.getScore()) {
        cout << "Player wins with score: " << playerHand.getScore() << endl;
    } else if (dealerHand.getScore() > playerHand.getScore()) {
        cout << "Dealer wins with score: " << dealerHand.getScore() << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
};

BlackJack::BlackJack(int numDecks, int handSize) :		deck(numDecks), playerHand(deck, handSize), dealerHand(deck, handSize) {
    playable = true;
};

void BlackJack::reset() {
    deck.reset();
    playerHand.redraw(deck);
    dealerHand.redraw(deck);
    playable = true;
};

/*
BlackJack::BlackJackFunction(int numDecks, int handSize) :		deck(numDecks), playerHand(deck, handSize), dealerHand(deck, handSize) {
    // Initialize the game with a deck and player hand
    //cout << "Player's hand: ";
    //playerHand.show();
    //playerHand.showScore();
    int choice;
    playable = true;
    while (playable) {
        cout << "What do you wish to do? \n1: hit\n2: stand\n3: quit\n4: status" << endl;
        cin >> choice;
        switch (choice) {
        case 1: // Assuming 1 is for "hit"
            hit();
            if (playerHand.isBusted()) {
                playable = false; // Exit the loop if player busts
            }
            break;
        case 2: // Assuming 2 is for "stand"
            playable = false; // Exit the loop if player stands
            stand();
            break;
        case 3: // Assuming 3 is for "quit"
            playable = false; // Exit the loop if player quits
            quit();
            break;
        case 4: // Assuming 4 is for "status"
            status();
            break;
        default:
            cout << "Invalid choice. Please enter 1 for hit, 2 for stand, 3 for quit, or 4 for status." << endl;
            break;
        };
        //if (choice == 3) break; // Exit the loop if the player chooses to quit
        //if (choice == 2) break; // If player stands, proceed to dealer's turn
    };
    //if (choice == 2) {
    //	dealerTurn(); // Proceed to dealer's turn if player stands
    //}
    victor(); // Determine the winner after the game ends
    cout << "Game over." << endl;
};
*/

void BlackJack::setPlay() {
    playable = true;
}

void BlackJack::stopPlay() {
    playable = false;
}

string BlackJack::getPlayer() const {
    return playerHand.getHand();
};

string BlackJack::getDealer() const {
    return dealerHand.getHand();
};

bool BlackJack::status() const {
    return playable;
};

bool BlackJack::playerBust() const{
    return playerHand.isBusted();
};

bool BlackJack::dealerBust() const{
    return dealerHand.isBusted();
};

int BlackJack::scorePlayer() const{
    return playerHand.getScore();
};

int BlackJack::scoreDealer() const{
    return dealerHand.getScore();
};
