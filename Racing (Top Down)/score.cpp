#include "score.hpp"

#include <iostream>

void Score::add(int i) {
	s += i;
}

void Score::print() {
	std::cout << s << '\n';
}