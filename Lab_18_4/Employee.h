#pragma once
#include <iostream>
#include "Person.h"
using namespace std;

class Employee : public Person
{
	string position;
	double salary;
public:
	Employee() :Person(), position("None"), salary(0) {}
	Employee(string pos, double sal) :Person(), position(pos), salary(sal) {}
	Employee(string pos) :Person(), position(pos), salary(0) {}
	Employee(string name, int age, string pos, double sal) :Person(name, age), position(pos), salary(sal) {}
	Employee(double sal) :Person(), salary(sal) {}
	Employee(Person p, string pos, double sal) :Person(p), position(pos), salary(sal) {}

	void SetPosition(string pos) { this->position = pos; }
	void SetSalary(double sal) { this->salary = sal; }
	string GetPosition() { return position; }
	double GetSalary() { return salary; }

	double GetPay() { return salary * 1.25; }

	void All_Info()
	{
		this->Show();
		cout << "Должность: " << position << endl;
		cout << "Оклад: " << salary << endl;
		cout << "Оклад + премия: " << GetPay() << endl;
	}

	~Employee() {}

	Employee& operator=(Person& p)
	{
		this->SetName(p.GetName());
		this->SetAge(p.GetAge());
		return *this;
	}
};