#include "Player.hpp"

Player::Player(std::string name)
{
	this->name = name;
	this->hand = new Hand();
}

std::string Player::getName()
{
	return this->name;
}

void Player::clearHand()
{
	this->hand->clear();
}

int Player::getHandValue()
{
	return this->hand->getTotalValue();
}