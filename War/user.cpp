#include "user.hpp"

Card User::playCard()
{
	if(hand.deck.size() <= 0)
	{
		hand = nextHand;
		nextHand.clear();
		hand.shuffle();
	}
	return hand.draw();
}

void User::give(Deck cards)
{
	nextHand.addDeck(cards);
}