#include <iostream>
#include "Object.h"
#include "Person.h"
#include "Employee.h"
#include "Vector.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251>nul");

	Person pers;
	cin >> pers;
	cout << pers;
	cout << "\n------------------------------------------------\n";
	Employee emp;
	cin >> emp;
	cout << emp;
	cout << "\n------------------------------------------------\n";
	Object* p1 = &pers;
	Person* p2 = &emp;

	Vector list;
	list.push_back(p1);
	list.push_back(p2);
	cout << list << endl;
	cout << "\n------------------------------------------------\n";
}