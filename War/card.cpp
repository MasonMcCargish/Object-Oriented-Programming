#include "card.hpp"
#include <cassert>

bool Card::isJoker() const
{
	return false;
}
Color Card::getColor() const
{
	assert(isJoker());
	return RED;
}

Rank StandardCard::getRank() const
{
	//assert(!isJoker());
	return static_cast<Rank>(data & 0b1111);
}

Suit StandardCard::getSuit() const
{
	//assert(!isJoker());
	return static_cast<Suit>(data >> 4);
}

int StandardCard::getValue() const
{
	switch(getRank())
	{
		case TWO: return 2;
		case THREE: return 3;
		case FOUR: return 4;
		case FIVE: return 5;
		case SIX: return 6;
		case SEVEN: return 7;
		case EIGHT: return 8;
		case NINE: return 9;
		case TEN: return 10;
		case JACK: return 11;
		case QUEEN: return 12;
		case KING: return 13;
		case ACE: return 14;
	}
}

Color JokerCard::getColor() const
{
	//assert(isJoker());
	return static_cast<Color>(data & 0b1111);
}

bool JokerCard::isJoker() const
{
	return((data & 0b1000000) == 0b1000000);
}

std::ostream& operator<<(std::ostream& o, const Rank& rank)
{
	switch(rank)
	{
		case TWO: return o << "2";
		case THREE: return o << "3";
		case FOUR: return o << "4";
		case FIVE: return o << "5";
		case SIX: return o << "6";
		case SEVEN: return o << "7";
		case EIGHT: return o << "8";
		case NINE: return o << "9";
		case TEN: return o << "T";
		case JACK: return o << "J";
		case QUEEN: return o << "Q";
		case KING: return o << "K";
		case ACE: return o << "A";
	}
}

std::ostream& operator<<(std::ostream& o, const Suit& suit)
{
	switch(suit)
	{
		case CLUBS: return o << "C";
		case DIAMONDS: return o << "D";
		case HEARTS: return o << "H";
		case SPADES: return o << "S";
	}
}

std::ostream& operator<<(std::ostream& o, const Color& c)
{
	switch(c)
	{
		case RED: return o << "R";
		case BLACK: return o << "B";
	}
}

std::ostream& operator<<(std::ostream& o, const Card& card)
{
	if(card.isJoker())
		return o << card.getColor() << "J";
	else
		return o << card.getRank() << card.getSuit();
}

bool operator<(const Card& C1, const Card& C2)
{
	if(C1.getValue() < C2.getValue())
		return true;
	else
		return false;
}

bool operator>(const Card& C1, const Card& C2)
{
	if(C1.getValue() > C2.getValue())
		return true;
	else
		return false;
}