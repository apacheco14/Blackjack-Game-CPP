#ifndef CARD_HPP
#define CARD_HPP

#include <string>

class Card
{
private:
	std::string name;
	std::string suit;
	int value;

public:
	Card(int value, std::string suit);
	std::string getName();
	std::string getSuit();
	int getValue();
};

#endif