#include "Deck.hpp"

//Blackjack rules state that between 1 and 8 decks can be used
//it is typical for 6 decks to be used at once shuffled together
Deck::Deck(int numDecks)
{
	//correct if numDecks requested in constructor
	//is outside allowable range
	if(numDecks > 8)
	{
		numDecks = 8;
	}
	else if(numDecks < 1)
	{
		numDecks = 1;
	}

	//for each requested deck
	for(int n = 0; n < numDecks; n++)
	{
		//instantiate all cards in a typical 52-card deck
		for(int j = 0; j < Deck::DECK_SIZE; j++)
		{
			//assign suit
			std::string suit = "";
			switch(j % 4)
			{
				case 0:
				suit = "spades";
				break;

				case 1:
				suit = "hearts";
				break;

				case 2:
				suit = "clubs";
				break;

				case 3:
				suit = "diamonds";
				break;
			}

			//instantiate card with value and suit
			this->cards.push_back(new Card((j % 13 + 1), suit));

			// j -> value suit
			// 0 -> A spades
			// 1 -> 2 hearts
			// 13 -> A hearts
			// 38 -> K clubs
			// 39 -> A diamonds
			// 51 -> K diamonds
		}
	}

	//once all decks have been created, shuffle them together
	shuffle();
}

void Deck::shuffle()
{
	//seed random function
	srand(time(NULL));

	//switch card places 100000 (a bunch of) times
	for(int m = 0; m < 100000; m++)
	{
		//pick random card to be switched
		int index = rand() % cards.size();

		//save the card
		Card* c = this->cards.at(index);

		//erase the card from the deck
		this->cards.erase(this->cards.begin()+index);

		//put card back in deck at the end
		this->cards.push_back(c);
	}

	//PROOF OF SHUFFLED DECK
	/*
	std::cout << std::endl;

	for(Card* c : this->cards)
	{
		std::cout << c->getName() << " " << c->getSuit() << std::endl;
	}

	std::cout << std::endl;
	*/
}

Card* Deck::getNextCard()
{
	if(this->isEmpty())
	{
		return NULL;
	}
	else
	{
		Card* c = this->cards.back();
		this->cards.pop_back();
		return c;
	}
}

bool Deck::isEmpty()
{
	return cards.empty();
}

bool Deck::isLow()
{
	return (cards.size() < 20);
}
