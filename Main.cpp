/*
	Alex Pacheco
	COMP 340 - Homework 1
*/

#include "UserControlledPlayer.hpp"
#include "Dealer.hpp"
#include "Deck.hpp"

#include <iostream>

//DECLARE VARIABLES AND FUNCTIONS USED IN Main.cpp
std::vector<UserControlledPlayer*> players;
Dealer* dealer;
Deck* deck;
bool continuePlaying;
void playRound();

int main()
{

//VARIABLES USED TO STORE USER INPUT
	std::string str_numPlayers = "";
	std::string str_numChips = "";

//INITIAL WELCOME MESSAGE
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "                  BLACKJACK!                  " << std::endl;
	std::cout << "Beat the Dealer to win chips" << std::endl;
	std::cout << "Get 21 for an extra payout" << std::endl;
	std::cout << "Ace         -  1 or 11" << std::endl;
	std::cout << "Face cards  -  10" << std::endl;
	std::cout << "All others  -  Pip value";
	std::cout << std::endl;

//GAME SET UP
	std::cout << "Enter number of user-controlled players: ";
	getline(std::cin, str_numPlayers);

	//convert str_numPlayers input into integer value
	//then create number of players requested by user
	//and add it to the vector of players
	for(int i = 0; i < std::stoi(str_numPlayers); i++)
	{
		std::cout <<
			"Enter number of starting chips for Player " << i+1 << ": ";
		getline(std::cin, str_numChips);

		players.push_back(new UserControlledPlayer(
			"Player " + std::to_string(i+1), std::stoi(str_numChips)));
	}

	//create a Dealer and a Deck
	dealer = new Dealer("Dealer");
	deck = new Deck(6);

//PLAY GAME
	do
	{
		for(int x = 0; x < players.size(); x++)
		{
			//any players with no chips left are removed from the game
			players.erase((players.begin() + x));
		}

		//if there are few cards remaining, a new deck is created
		if(deck->isLow())
		{
			deck = new Deck(6);
			std::cout << "Resetting Deck" << std::endl;
		}

		//play one round of Blackjack
		playRound();
		
		//check if game should continue
		continuePlaying = false;
		for(int x = 0; x < players.size(); x++)
		{
			//if any players still have chips available, game continues
			if((players.at(x))->getChips() > 0)
			{
				continuePlaying = true;
			}
			else
			{
				//any players with no chips left are removed from the game
				players.erase((players.begin() + x));
			}
		}

	} while(continuePlaying);

	//loop is broken when there are no players remaining
	//that have chips available, meaning the game is over
	std::cout << "GAME OVER" << std::endl;
}

//FUNCTION EXECUTES ALL STEPS REQUIRED IN
//ONE ROUND OF BASIC BLACKJACK GAMEPLAY
void playRound()
{
	//vector stores player wagers for the current round only
	std::vector<int> bets;

	std::cout << std::endl << "--- --- --- ROUND START --- --- ---" << std::endl;

//ROUND SET UP
	//collect bets from all players
	for(int x = 0; x < players.size(); x++)
	{
		UserControlledPlayer* p = players.at(x);
		std::cout << std::endl;

		int bet = p->bet();
		bets.push_back(bet);
		std::cout <<
			p->getName() << " has wagered " << bet << " chips." << std::endl;
	}

	//cards are distributed to dealer
	Card* dealerCard1 = deck->getNextCard();
	Card* dealerCard2 = deck->getNextCard();
	dealer->addCardToHand(dealerCard1);
	dealer->addCardToHand(dealerCard2);

//USER CONTROLLED PLAYERS TAKE TURNS PLAYING
	for(int x = 0; x < players.size(); x++)
	{
		UserControlledPlayer* p = players.at(x);

		std::cout << std::endl << p->getName() << " Turn Start" << std::endl;

		//player gets their cards
		p->addCardToHand(deck->getNextCard());
		p->addCardToHand(deck->getNextCard());
		
		//while a player continues to hit, they receive another card
		while(p->hit())
		{
			p->addCardToHand(deck->getNextCard());
		}

		//when player no longer wants cards, they stand and their turn ends
	}

//END OF ROUND
	//dealer hole card is displayed
	std::cout << std::endl << "Dealer Hole Card: " <<
		dealerCard2->getName() << " " << dealerCard2->getSuit() << std::endl;

	//dealer takes turn hitting/standing
	while(dealer->hit())
	{
		Card* nextCard = deck->getNextCard();
		std::cout << "Dealer hits. "
			<< nextCard->getName() << " " << nextCard->getSuit() << std::endl;
		dealer->addCardToHand(nextCard);
	}

	std::cout << "Dealer Hand Value: " << dealer->getHandValue() << std::endl;
	std::cout << std::endl;

	//each player is paid out any potential winnings
	for(int x = 0; x < players.size(); x++)
	{
		//store current player, bet, and player's hand value
		UserControlledPlayer* p = players.at(x);
		int bet = bets.at(x);
		int hv = p->getHandValue();

		//player loses chips if they bust or get less than dealer
		if(hv > 21 || hv < dealer->getHandValue())
		{
			p->addChips(-bet);
			std::cout <<
				p->getName() << " lost " << bet << " chips." << std::endl;
		}
		//player wins extra chips for getting 21
		else if(hv == 21)
		{
			p->addChips(3*bet/2);
			std::cout <<
				p->getName() << " won " << 3*bet/2 << " chips." << std::endl;
		}
		//bet is pushed if player matches dealer
		else if(hv == dealer->getHandValue())
		{
			std::cout <<
				p->getName() << " does not win or lose chips." << std::endl;
		}
		//player wins chips for beating dealer and staying under 21
		else
		{
			p->addChips(bet);
			std::cout <<
				p->getName() << " won " << bet << " chips." << std::endl;
		}

		std::cout << std::endl;

		//player's hand is cleared for next round
		p->clearHand();
	}

	//dealer's hand is cleared for next round
	dealer->clearHand();
}