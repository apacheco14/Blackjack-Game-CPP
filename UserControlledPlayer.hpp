#ifndef USERCONTROLLEDPLAYER_HPP
#define USERCONTROLLEDPLAYER_HPP

#include "Player.hpp"

class UserControlledPlayer : public Player
{
private:
	int chips;

public:
	UserControlledPlayer(std::string name, int chips);
	void addCardToHand(Card* c);
	int getChips();
	void addChips(int chips);
	int bet();
	bool hit();
};

#endif
