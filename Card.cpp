#include "Card.hpp"

Card::Card(int value, std::string suit)
{
	//Ace can be 1 or 11, here it is assigned 1
	//face cards (J, Q, K) are 10
	//all other cards are pip value
	switch(value)
	{
		case 1:
		this->name = "A";
		this->value = 1;
		break;
		
		case 11:
		this->name = "J";
		this->value = 10;
		break;

		case 12:
		this->name = "Q";
		this->value = 10;
		break;

		case 13:
		this->name = "K";
		this->value = 10;
		break;

		default:
		this->name = std::to_string(value);
		this->value = value;
		break;
	}

	this->suit = suit;
}

std::string Card::getName()
{
	return name;
}

std::string Card::getSuit()
{
	return suit;
}

int Card::getValue()
{
	return value;
}