#pragma once

#include "card.hpp"
#include <vector>

class Deck
{
public:
	void fill();
	Card getCard(size_t);
	void shuffle();
	Card draw();
	bool empty();
	Deck cut();
	Deck clear();
	void addCard(Card &);
	void addDeck(Deck &);
	Deck& operator=(const Deck&);

	std::vector<Card> deck;
};
