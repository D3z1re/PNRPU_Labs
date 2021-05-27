#include "Person.h"

Person::Person(void)
{
	name = "";
	age = 0;
}
Person::Person(string n, int a)
{
	name = n;
	age = a;
}
Person::Person(const Person& a)
{
	name = a.name;
	age = a.age;
}
Person::~Person(void)
{}

void Person::Set_Name(string n)
{
	name = n;
}
void Person::Set_Age(int a)
{
	age = a;
}

Person& Person::operator=(const Person& a)
{
	if (&a == this) return *this;
	name = a.name;
	age = a.age;
	return *this;
}

void Person::Show()
{
	cout << "\nName: " << name;
	cout << "\nAge: " << age << endl;
}

void Person::Input()
{
	cout << "Enter name: "; cin.ignore(); getline(cin, name);
	cout << "Enter age: "; cin >> age;
	cin.get();
}

void Person::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmName:
		{
			cout << "Name: " << Get_Name() << endl;
			break;
		}
		}
	}
}
