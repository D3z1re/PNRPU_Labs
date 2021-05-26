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
		cout << "������� ������������ �����: ";
		cin >> second;
		second = modf(second, &tmp);
		first = int(tmp);
		cout << "����� ����� ���������� �����: " << first << endl;
		cout << "������� ����� ���������� �����: " << second << endl;
	}
	void init(double n)
	{
		double tmp;
		second = modf(n, &tmp);
		first = int(tmp);
		cout << "����� ����� ������ �����: " << first << endl;
		cout << "������� ����� ������ �����: " << second << endl;
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
	Enrollee() // ��� ����������
	{
		name = "";
		speciality = "";
		exams = 0;
	}

	Enrollee(string a, string b, int c) // � �����������
	{
		this->name = a;
		this->speciality = b;
		this->exams = c;
	}

	Enrollee(const Enrollee& obj) // �����
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

		cout << "������� ���: ";
		getline(cin, a);
		while (a == "" || a[0] == ' ')
		{
			cout << "\n��� ������� �����������.\n";
			cout << "������� ���: ";
			getline(cin, a);
		}
		this->name = a;
		cout << "\n������� �������������: ";
		getline(cin, a);
		while (a == "" || a[0] == ' ')
		{
			cout << "\n������������� ������� �����������.\n";
			cout << "������� �������������: ";
			getline(cin, a);
		}
		this->speciality = a;
		cout << "\n������� ����� ��� (1-300): ";
		cin >> n;
		while (n <= 0 || n > 300)
		{
			cout << "\n����� ��� ������� �����������.\n";
			cout << "������� ����� ��� (1-300: ";
			cin >> n;
		}
		this->exams = n;
	}

	string GetName() { return name; }
	string GetSpeciality() { return speciality; }
	int GetExams() { return exams; }

	void Print()
	{
		cout << "���: " << this->name << endl;
		cout << "�������������: " << this->speciality << endl;
		cout << "����� ���: " << this->exams << endl;
		cout << "---------------------------------------------------\n";
	}
};