#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Fraction
{
public:
	int first;
	double second;

	void init()
	{
		double tmp;
		cout << "Введите вещественное число: ";
		cin >> second;
		second = modf(second, &tmp);
		first = int(tmp);
		cout << "Целая часть введенного числа: " << first << endl;
		cout << "Дробная часть введенного числа: " << second << endl;
	}
	void init(double n)
	{
		double tmp;
		second = modf(n, &tmp);
		first = int(tmp);
		cout << "Целая часть нового числа: " << first << endl;
		cout << "Дробная часть нового числа: " << second << endl;
	}

	double multiply(double n)
	{
		double f, s, t;
		modf(first, &f);
		s = fabs(modf(second, &t));
		return ((s + f) * n);
	}
};

class Enrollee
{
	string name;
	string speciality;
	int exams;
public:
	Enrollee() // без аргументов
	{
		name = "";
		speciality = "";
		exams = 0;
	}

	Enrollee(string a, string b, int c) // с аргументами
	{
		this->name = a;
		this->speciality = b;
		this->exams = c;
	}

	Enrollee(const Enrollee& obj) // копия
	{
		name = obj.name;
		speciality = obj.speciality;
		exams = obj.exams;
	}

	~Enrollee() {}

	void init()
	{
		string a;
		int n;

		cout << "Введите ФИО: ";
		getline(cin, a);
		while (a == "" || a[0] == ' ')
		{
			cout << "\nФИО введено некорректно.\n";
			cout << "Введите ФИО: ";
			getline(cin, a);
		}
		this->name = a;
		cout << "\nВведите специальность: ";
		getline(cin, a);
		while (a == "" || a[0] == ' ')
		{
			cout << "\nСпециальность введена некорректно.\n";
			cout << "Введите специальность: ";
			getline(cin, a);
		}
		this->speciality = a;
		cout << "\nВведите баллы ЕГЭ (1-300): ";
		cin >> n;
		while (n <= 0 || n > 300)
		{
			cout << "\nБаллы ЕГЭ введены некорректно.\n";
			cout << "Введите баллы ЕГЭ (1-300: ";
			cin >> n;
		}
		this->exams = n;
	}

	string GetName() { return name; }
	string GetSpeciality() { return speciality; }
	int GetExams() { return exams; }

	void Print()
	{
		cout << "ФИО: " << this->name << endl;
		cout << "Специальность: " << this->speciality << endl;
		cout << "Баллы ЕГЭ: " << this->exams << endl;
		cout << "---------------------------------------------------\n";
	}
};