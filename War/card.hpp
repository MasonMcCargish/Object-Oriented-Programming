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
	Card()
	{}

	Card(Rank r, Suit s)
	: data(static_cast<unsigned>(s) << 4 | static_cast<unsigned>(r))
	{}

	Rank getRank() const {return static_cast<Rank>(data & 0b1111);}

	Suit getSuit() const {return static_cast<Suit>(data >> 4);}

	int getValue() const;

private:
	int data;
	// Rank rank;
	// Suit suit;
};

std::ostream& operator<<(std::ostream&, const Rank &);
std::ostream& operator<<(std::ostream&, const Suit &);
std::ostream& operator<<(std::ostream&, const Card &);

bool operator<(const Card&, const Card&);
bool operator>(const Card&, const Card&);