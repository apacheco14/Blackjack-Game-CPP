#include "Dealer.hpp"

Dealer::Dealer(std::string name) : Player(name)
{
	
}

void Dealer::addCardToHand(Card* c)
{
	//if this is the first card in the dealer's hand
	if(this->hand->getTotalValue() == 0)
	{
		//display the card to the players
		std::cout << std::endl << "Dealer Face Up Card: " <<
			c->getName() << " " << c->getSuit() << std::endl;
	}

	this->hand->addCard(c);
}

bool Dealer::hit()
{
	/*

		From bicyclecards.com/how-to-play/blackjack/
		"The Dealer's Play"

		When the dealer has served every player,
		his face-down card is turned up. If the
		total is 17 or more, he must stand. If
		the total is 16 or under, he must take a
		card. He must continue to take cards
		until the total is 17 or more, at which
		point the dealer must stand. If the
		dealer has an ace, and counting it as 11
		would bring his total to 17 or more (but
		not over 21), he must count the ace as
		11 and stand. The dealer's decisions,
		then, are automatic on all plays,
		whereas the player always has the option
		of taking one or more cards.

	*/

	if(hand->getTotalValue() >= 17)
	{
		return false;
	}
	else
	{
		return true;
	}
}