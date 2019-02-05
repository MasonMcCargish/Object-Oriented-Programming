#pragma once

#include "card.hpp"
#include "deck.hpp"

class User
{
public:
	User(){loss = false;}

	Card playCard();
	void give(Deck);

	Deck hand;
	Deck nextHand;
	bool loss;
};