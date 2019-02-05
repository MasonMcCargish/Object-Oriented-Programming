#pragma once

#include <iostream>

enum Suit
{
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES,
};

enum Rank
{
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE,
};

class Card
{
public:
	int getValue() const;

	Rank rank;
	Suit suit;
};

std::ostream& operator<<(std::ostream&, const Rank &);
std::ostream& operator<<(std::ostream&, const Suit &);
std::ostream& operator<<(std::ostream&, const Card &);

bool operator<(const Card&, const Card&);
bool operator>(const Card&, const Card&);