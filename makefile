all: BlackJack

BlackJack:  Main.cpp Card.cpp Deck.cpp Hand.cpp Player.cpp Dealer.cpp UserControlledPlayer.cpp
	g++ Main.cpp Card.cpp Deck.cpp Hand.cpp Player.cpp Dealer.cpp UserControlledPlayer.cpp -std=c++11 -o HW1
