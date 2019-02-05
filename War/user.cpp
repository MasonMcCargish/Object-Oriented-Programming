#include "user.hpp"

Card User::playCard()
{
	return hand.draw();
}

void User::give(Deck cards)
{
	nextHand = nextHand + cards;
}