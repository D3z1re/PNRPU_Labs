﻿#include <iostream>
#include "List.h"
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	List a(5);
	cout << a << endl;
	cin >> a;
	cout << a << endl;
	a[2] = 100;
	cout << a << endl;
	List b(10);
	cout << b << endl;
	b = a;
	cout << b << endl;
	List c(10);
	c = b + 100;
	cout << c << endl;
	cout << "\nThe length of a = " << a() << endl;

	cout << *(a.first()) << endl;
	Iterator i = a.first();
	i++;
	cout << *i << endl;

	for (i = a.first(); i != a.last(); i++) cout << *i << endl;

	return 0;
}