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

enum Color
{
	RED,
	BLACK
};

class Card
{
public:
	Card()
	{}

	Card(Color c) //Joker Constructor
	: data(0b1000000 | static_cast<unsigned>(c))
	{}

	Card(Rank r, Suit s) //playing card constructor
	: data(static_cast<unsigned>(s) << 4 | static_cast<unsigned>(r))
	{}

	Rank getRank() const;
	Suit getSuit() const;
	Color getColor() const;
	int getValue() const;
	bool isJoker() const;

private:
	int data;
};

std::ostream& operator<<(std::ostream&, const Rank &);
std::ostream& operator<<(std::ostream&, const Suit &);
std::ostream& operator<<(std::ostream&, const Card &);
std::ostream& operator<<(std::ostream&, const Color &);

bool operator<(const Card&, const Card&);
bool operator>(const Card&, const Card&);