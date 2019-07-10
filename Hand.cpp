#include "Hand.hpp"

Hand::Hand()
{
	this->totalValue = 0;
}

int Hand::getTotalValue()
{
	//Aces can be 1 or 11

	this->totalValue = 0;
	int numAces = 0;

	//for every card in the hand
	for(Card* c : this->cards)
	{
		//if card is an Ace, keep track of it but do not add value
		if(c->getName() == "A")
		{
			numAces++;
		}
		//add value to total for all other cards
		else
		{
			this->totalValue += c->getValue();
		}
	}

	//checks how many Aces have to be added as 1
	//starts by assuming all Aces are 11, then removes
	//one at a time until all Aces are determined to
	//be 1 or 11
	for(int x = numAces; x > 0; x--)
	{
		//if making all remaining Aces count as 11 would keep
		//player under/equal 21, add them to total value as 11
		if(this->totalValue + 11*x <= 21)
		{
			this->totalValue += 11;
		}
		//if making all remaining Aces count as 11 would cause
		//player to bust, treat this one Ace as 1 and continue loop
		else
		{
			this->totalValue += 1;
		}
	}

	return this->totalValue;
}

void Hand::addCard(Card* newCard)
{
	this->cards.push_back(newCard);
	this->totalValue += newCard->getValue();
}

void Hand::clear()
{
	this->cards.clear();
	this->totalValue = 0;
}