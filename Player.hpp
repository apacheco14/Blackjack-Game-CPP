#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Hand.hpp"

#include <iostream>

class Player
{
protected:
	std::string name;
	Hand* hand;

public:
	Player(std::string name);
	std::string getName();
	void clearHand();
	int getHandValue();
	virtual void addCardToHand(Card* c) = 0;
	virtual bool hit() = 0;
};

#endif