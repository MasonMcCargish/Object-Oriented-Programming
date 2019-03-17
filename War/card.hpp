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
	// Card()
	// {}

	enum cardType {
		Standard,
		Joker,
	};

	Card(cardType newType) : type(newType) {}

	int getValue() const;
	Rank getRank() const;
	Suit getSuit() const;
	bool isJoker() const;
	Color getColor() const;
	

	// Card(Color c) //Joker Constructor
	// : data(0b1000000 | static_cast<unsigned>(c))
	// {}

	// Card(Rank r, Suit s) //playing card constructor
	// : data(static_cast<unsigned>(s) << 4 | static_cast<unsigned>(r))
	// {}

	//bool isJoker() const;

private:
	// int data;
	cardType type;
};


// Somehow conenct these using virtual functions and overrides
class StandardCard : public Card {
public:
	StandardCard(Rank r, Suit s)
	: Card(Standard), data(static_cast<unsigned>(s) << 4 | static_cast<unsigned>(r))
	{}

	int getValue() const;
	Rank getRank() const;
	Suit getSuit() const;

private:
	int data;
};

class JokerCard : Card {
public:
	JokerCard(Color c)
	: Card(Joker), data(static_cast<unsigned>(c))
	{}

	Color getColor() const;
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