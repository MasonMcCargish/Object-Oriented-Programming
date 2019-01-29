#include <iostream>
#include <vector>

enum suit
{
	C,
	D,
	H,
	S,
};

enum rank
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
	J,
	Q,
	K,
	A,
};

struct Card
{
	suit S;
	rank R;

	Card()
	{
		S = suit.C;
		R = rank.TWO;
	}
	Card(suit newSuit,rank newRank)
	{
		S = newSuit;
		R = newRank;
	}
	Card operator=(const Card* toCopy)
	{
		S = toCopy->S;
		R = toCopy->R;
	}
	friend std::ostream& operator<<(std::ostream& o, Card showCard)
	{
		if(S == suit.C)
			o << "C\n";
		o << "end";
		return o;
	}
};

struct Deck
{
	std::vector<Card> deck = std::vector<Card>(52);

	Deck()
	{
		size_t counter = 0;
	
		for (size_t i = 0; i < 13; ++i)
		{
			for (size_t j = 0; j < 4; ++j)
			{
				deck[counter] = new Card(suit(j),rank(i));
				++counter;
			}
		}
	}
};

int main()
{
	Deck newDeck();



	/*
	std::vector<Card> deck (52);
	size_t counter = 0;
	
	for (size_t i = 0; i < 13; ++i)
	{
		for (size_t j = 0; j < 4; ++j)
		{
			deck[counter] = new Card(suit(j),rank(i));
			++counter;
		}
	}
	*/
}