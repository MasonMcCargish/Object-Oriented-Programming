#include "card.hpp"

int Card::getValue() const
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

std::ostream& operator<<(std::ostream& o, const Card& card)
{
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