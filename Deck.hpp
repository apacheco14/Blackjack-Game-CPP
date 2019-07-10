#ifndef DECK_HPP
#define DECK_HPP

#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include "Card.hpp"

class Deck
{
private:
	std::vector<Card*> cards;
	void shuffle();
	static const int DECK_SIZE = 52;

public:
	Deck(int numDecks);
	Card* getNextCard();
	bool isEmpty();
	bool isLow();
};

#endif