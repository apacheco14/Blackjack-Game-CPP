#include "UserControlledPlayer.hpp"

UserControlledPlayer::UserControlledPlayer(std::string name, int chips) : Player(name)
{
	this->chips = chips;
}

void UserControlledPlayer::addCardToHand(Card* c)
{
	std::cout << c->getName() << " " << c->getSuit() << std::endl;
	this->hand->addCard(c);
}

int UserControlledPlayer::getChips()
{
	return this->chips;
}

void UserControlledPlayer::addChips(int chips)
{
	this->chips += chips;
}

int UserControlledPlayer::bet()
{
	std::string str_numChips = "";
	int numChips = 0;

	//do not let player wager 0 chips or more chips than they have available
	while(numChips == 0 || numChips > this->chips)
	{
		std::cout << getName() << ", enter amount to bet ("
			<< this->chips << " chips available): ";
		getline(std::cin, str_numChips);

		numChips = std::stoi(str_numChips);
	}

	return numChips;
}

bool UserControlledPlayer::hit()
{
	std::string userInput = "";

	//if the user already has 21, do not let them hit
	if(this->hand->getTotalValue() == 21)
	{
		std::cout << "Blackjack!" << std::endl;
		return false;
	}
	//if the user has busted, do not let them hit
	else if(this->hand->getTotalValue() > 21)
	{
		std::cout << "Bust!" << std::endl;
		return false;
	}
	//let the user hit if they choose to
	else
	{
		std::cout << "Enter '1' to Hit, any key to Stand: ";
		getline(std::cin, userInput);

		if(userInput == "1")
			return true;
		else
			return false;
	}
}