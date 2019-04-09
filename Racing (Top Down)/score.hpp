#pragma once

class Score 
{
public:
	Score () {
		s = 0;
	}

	void add(int);
	void print();

private:
	int s;
};