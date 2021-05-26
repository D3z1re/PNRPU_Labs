#include <iostream>
#include "Pair.h"
using namespace std;

int main()
{
	Pair a(8, 3.14);
	Pair b(9, 2.45);

	cout << "a: ";
	a.Show();

	cout << "b: ";
	a.Show();

	cout << "\n--a: ";
	(--a).Show();

	cout << "a--: ";
	(a--).Show();

	cout << endl << "a > b: " << (a > b) << endl;
	cout << "a >= b: " << (a >= b) << endl;
	cout << "a < b: " << (a < b) << endl;
	cout << "a <= b: " << (a <= b) << endl;
}
