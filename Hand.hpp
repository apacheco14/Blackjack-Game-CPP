#ifndef HAND_HPP
#define HAND_HPP

#include "Card.hpp"
#include <vector>

class Hand
{
	private:
		std::vector<Card*> cards;
		int totalValue;

	public:
		Hand();
		void clear();
		int getTotalValue();
		void addCard(Card* newCard);
};

#endif