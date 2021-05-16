#pragma once
#include <iostream>

using namespace std;

class Pair
{
	int First;
	double Second;
public:
	Pair();
	Pair(int First, double Second);
	Pair(const Pair& p);
	~Pair();
	
	Pair& operator=(const Pair& pair);

	friend istream& operator>>(istream& in, Pair& pair);
	friend ostream& operator<<(ostream& out, const Pair& pair);
};