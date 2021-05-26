#include <iostream>
#include "classes.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251>nul");

	//первая лаба

	double n, res;
	Fraction number;
	number.init();
	cout << "\nВведите число, на которое нужно умножить: ";
	cin >> n;
	res = number.multiply(n);
	cout << (int)number.first + number.second << " * " << n << " = " << res << endl << endl;
	number.init(res);
	cin.get();
	cout << endl;

	//вторая лаба

	Enrollee obj1, obj2("Фролов Кирилл Михайлович", "Разработка программно-информационных систем", 252);
	Enrollee obj3(obj2);
	obj1.init();

	cout << "\nФИО: " << obj1.GetName() << endl;
	cout << "Специальность: " << obj1.GetSpeciality() << endl;
	cout << "Баллы ЕГЭ: " << obj1.GetExams() << endl;

	vector<Enrollee> lst{ obj1, obj2, obj3 };

	cout << "\n---------------------------------------------------\n";
	for (int i = 0; i < lst.size(); i++)
	{
		cout << "Элемент " << i + 1 << ":\n";
		lst[i].Print();
	}
}
