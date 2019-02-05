#include "card.hpp"
#include "deck.hpp"
#include "user.hpp"

#include <iostream>

int main()
{
	Deck deck;
	User p1;
	User p2;

	deck.fill();
	deck.shuffle();

	p1.hand = deck.cut();
	p2.hand = deck;

	Deck pot;
	Card p1Card;
	Card p2Card;
	while(true)
	{
		// p1Card = p1.playCard();
		// p2Card = p2.playCard();
		// pot = pot + p1Card;
		// pot = pot + p1Card;

		if(p1Card > p2Card)
		{
			std::cout << p1Card << " || " << p2Card << "  P1" << std::endl;
			p1.give(pot);
		}
		else if(p1Card < p2Card)
		{
			std::cout << p1Card << " || " << p2Card << "  P2" << std::endl;
			p2.give(pot);
		}
		else
		{
			std::cout << p1Card << " || " << p2Card << "  TIE" << std::endl;
		}
	}	
}