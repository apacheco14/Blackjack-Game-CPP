#ifndef DEALER_HPP
#define DEALER_HPP

#include "Player.hpp"

class Dealer : public Player
{
public:
	Dealer(std::string name);
	void addCardToHand(Card* c);
	bool hit();
};

#endif