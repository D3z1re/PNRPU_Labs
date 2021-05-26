#include <iostream>
#include <string>
#include "Person.h"
#include "Employee.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251>nul");

	Person a("Кондратьев Артём Иванович", 23);
	Person b(a);
	a.Show(); b.Show();
	cout << "----------------------------------\n";

	Employee c(a, "Тестировщик", 55000);
	c.All_Info();
	cout << "----------------------------------\n";

	Person Empty;
	Employee d("Смирнов Сергей Георгиевич", 20, "Системный аналитик", 80000);
	Empty.Show();
	Empty = b;
	Empty.Show();
	cout << "----------------------------------\n";

	cout << "Демонстрация перегрузки '<<' и '>>':\n";
	cout << "Ввод (>>):\n";
	Person obj;
	cin >> obj;
	cout << "Вывод (<<):\n";
	cout << obj;
	obj.Show();
}