#include <iostream>
#include "Pair.h"

using namespace std;

Pair::Pair()
{
	First = 1;
	Second = 1;
}

Pair::Pair(int First, double Second)
{
	this->First = First;
	this->Second = Second;
}

Pair::Pair(const Pair& p)
{
	this->First = p.First;
	this->Second = p.Second;
}

Pair::~Pair() {}

Pair& Pair::operator=(const Pair& pair)
{
	if (this == &pair)
	{
		return *this;
	}
	this->First = pair.First;
	this->Second = pair.Second;
	return *this;
}

istream& operator>>(istream& in, Pair& pair)
{
	cout << "¬ведите пару чисел через пробел: " << endl;
	in >> pair.First >> pair.Second;
	return in;
}

ostream& operator<<(ostream& out, const Pair& pair)
{
	out << pair.First << " : " << pair.Second << endl;
	return out;
}