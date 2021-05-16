#include <iostream>
#include "List.h"
#include "Pair.h"
 
using namespace std;

int main()
{
	system("color F0");
	setlocale(LC_ALL, "rus");
	List<Pair> list_a(5);
	List<Pair> list_b(list_a);
	List<Pair> list = list_b;
	cout << list << endl;
	cout << "Item[2]: " << endl << list[2] << endl;
	cout << "Size: " << list() << endl;

	return 0;
}
