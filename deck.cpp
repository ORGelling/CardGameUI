#include "deck.h"

void Deck::setRand() {
    srand(time(NULL));
}

Card* Deck::createDeck(int numDecks = 1) {
    const char* ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    const char* suits[] = { "C", "D", "H", "S" };
    int points[] = { 2,3,4,5,6,7,8,9,10,10,10,10,10 }; // Points for blackjack

    Card* newDeck = new Card[totalCards];

    int index = 0; // Index to fill the new deck
    for (int d = 0; d < numDecks; ++d) {
        int sortindex = 0;
        for (int s = 0; s < 4; ++s) {
            for (int p = 0; p < 13; ++p) {
                newDeck[index].rank = ranks[p];
                newDeck[index].suit = suits[s];
                newDeck[index].points = points[p];
                newDeck[index].sort = sortindex; // Assign sort value
                ++index;
                ++sortindex;
            }
        }
    }
    return newDeck;
};

Card Deck::drawCard() {
    if (deckSize == 0) throw std::runtime_error("Deck is empty!");
    int cardPick = rand() % deckSize; // Randomly pick a card from the deck
    Card pickedCard = deck[cardPick]; // Get the picked card

    Card* newDeck = new Card[deckSize - 1]; // Create a new deck without the picked card
    for (int j = 0, k = 0; j < deckSize; j++) {
        if (j != cardPick) { // Skip the picked card
            newDeck[k++] = (deck)[j]; // Copy the remaining cards to the new deck
        }
    }
    delete[] deck; // Clean up memory for the old deck
    deck = newDeck; // Update the deck to the new deck without the picked card
    deckSize--; // Decrease deck size after picking a card
    return pickedCard;
};

Deck::Deck(int numDecks) : numDecks(numDecks), totalCards(52 * numDecks), deckSize(52 * numDecks) {
    setRand();
    deck = createDeck(numDecks);
};

void Deck::showDeck() const {
    for (int i = 0; i < deckSize; i++) {
        cout << deck[i].rank << deck[i].suit << " ";
    }
    cout << endl;
};

void Deck::showDeckSplit() {
    sortDeck(); // Sort the deck before showing it
    for (int i = 0; i < deckSize; i++) {
        cout << deck[i].rank << deck[i].suit << " ";
        if (i < deckSize - 1 && deck[i].suit != deck[i + 1].suit) {
            cout << endl; // Print a new line if the suit changes
        }
    }
    cout << endl;
};

void Deck::showSize() const {
    cout << "Deck size: " << deckSize << endl; // Show the size of the deck
};

void Deck::sortDeck() {
    //easy sort lmao
    sort(deck, deck + deckSize, [](const Card& a, const Card& b) {
        return a.sort < b.sort;
    });
};
