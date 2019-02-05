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
	Deck& operator=(const Deck&);
	Deck& operator+(const Deck&);
	Deck& operator+(const Card&);

	std::vector<Card> deck;
};
