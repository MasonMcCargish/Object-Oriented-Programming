#include "war.hpp"
#include "card.hpp"
#include "deck.hpp"
#include "user.hpp"

#include <iostream>

void War::startGame()
{
	Deck deck;
	User p1;
	User p2;

	deck.fill();
	deck.shuffle();

	for (Card c: deck.deck)
		std::cout << c << " ";

	p1.hand = deck.cut();
	p2.hand = deck;

	Deck pot;
	Card p1Card;
	Card p2Card;
	while(true)
	{
		p1Card = p1.playCard();
		p2Card = p2.playCard();
		pot.addCard(p1Card);
		pot.addCard(p2Card);

		if(p1Card > p2Card)
		{
			std::cout << p1Card << " || " << p2Card << "  P1" << std::endl;
			p1.give(pot);
			pot.clear();
		}
		else if(p1Card < p2Card)
		{
			std::cout << p1Card << " || " << p2Card << "  P2" << std::endl; 
			p2.give(pot);
			pot.clear();
		}
		else
		{
			std::cout << p1Card << " || " << p2Card << "  TIE" << std::endl;
		}

		if(p1.hand.deck.size() == 0 && p1.nextHand.deck.size() == 0)
		{
			std:: cout << "Player 2 Wins!" << std::endl;
			break;
		}
		if(p2.hand.deck.size() == 0 && p2.nextHand.deck.size() == 0)
		{	
			std:: cout << "Player 1 Wins!" << std::endl;
			break;
		}
	}
}