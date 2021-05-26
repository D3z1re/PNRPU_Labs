#pragma once
#include <iostream>
using namespace std;

class Person
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
	Person(const Person& obj)
	{
		name = obj.name;
		age = obj.age;
	}

	~Person() {}

	void SetName(string a)
	{
		this->name = a;
	}
	void SetAge(int n)
	{
		this->age = n;
	}

	string GetName() { return name; }
	int GetAge() { return age; }

	void Show()
	{
		cout << "ФИО: " << name << endl;
		cout << "Возраст: " << age << endl;
	}

	Person& operator=(Person& obj);
	friend istream& operator >> (istream& cin, Person& obj);
	friend ostream& operator << (ostream& cin, Person& obj);
};

Person& Person::operator=(Person& obj)
{
	if (this == &obj) return *this;
	name = obj.name;
	age = obj.age;
	return *this;
}
istream& operator>> (istream& cin, Person& obj)
{
	cout << "Введите ФИО: ";
	getline(cin, obj.name);
	cout << "Введите возраст: ";
	cin >> obj.age;
	return cin;
}
ostream& operator<< (ostream& cout, Person& obj)
{
	return (cout << "Имя: " << obj.name << endl << "Возраст: " << obj.age << endl);
}