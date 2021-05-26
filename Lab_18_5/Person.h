#pragma once
#include <iostream>
#include "Object.h"
using namespace std;

class Person : public Object
{
	string name;
	int age;
public:
	Person()
	{
		name = "None";
		age = 0;
	}
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	Person(const Person& p)
	{
		this->name = p.name;
		this->age = p.age;
	}

	~Person() {}

	void SetName(string name)
	{
		this->name = name;
	}
	void SetAge(int age)
	{
		this->age = age;
	}
	string GetName() { return name; }
	int GetAge() { return age; }

	void Show() override
	{
		cout << "���: " << name << endl;
		cout << "�������: " << age << endl;
	}

	Person& operator=(Person& p)
	{
		if (this == &p) return *this;
		this->name = p.name;
		this->age = p.age;
		return *this;
	}

	friend istream& operator >> (istream& in, Person& p);
	friend ostream& operator << (ostream& out, Person& p);
};

istream& operator >> (istream& in, Person& p)
{
	cout << "������� ���: ";
	getline(in, p.name);
	cout << "������� �������: ";
	in >> p.age;
	return in;
}

ostream& operator << (osteam& out, Person& p)
{
	return out << "���: " << p.name << endl << "�������: " << p.age << endl;
}
