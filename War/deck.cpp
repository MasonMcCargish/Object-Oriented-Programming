#include "deck.hpp"

#include <algorithm>

// Used for RNG
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

void Deck::fill()
{
	size_t counter = 0;

	for (size_t i = 0; i < 13; ++i)
	{
		for (size_t j = 0; j < 4; ++j)
		{
			// deck.push_back(Card(static_cast<Rank>(i),static_cast<Suit>(j)));
			deck.push_back(Card(Rank(i),Suit(j)));
			++counter;
		}
	}
}

Card Deck::getCard(size_t pos)
{
	return deck[pos];
}

void Deck::shuffle()
{
	srand(time(NULL));
	std::random_shuffle(deck.begin(), deck.end());
}

Card Deck::draw()
{
	Card card = deck.back();
	deck.pop_back();
	return card;
}

bool Deck::empty()
{
	return (deck.size() <= 0);
}

Deck Deck::cut()
{
	Deck newDeck;

	std::vector<Card> newDeckVec(deck.begin() + deck.size() / 2, deck.end());
	deck.resize(deck.size() / 2);
	newDeck.deck = newDeckVec;
	return newDeck;
}

Deck Deck::clear()
{
	Deck newDeck;
	newDeck = *this;
	deck.clear();

	return newDeck;
}

void Deck::addCard(Card& newCard)
{
	deck.push_back(newCard);
}

void Deck::addDeck(Deck& newDeck)
{
	for(Card c: newDeck.deck)
		addCard(c);
}

Deck& Deck::operator=(const Deck& toCopy)
{
	this->deck = toCopy.deck;
	return *this;
}
