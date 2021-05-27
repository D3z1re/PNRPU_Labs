#include "Abiturient.h"

Abiturient::Abiturient(void)
{
	speciality = "";
	exams = 0;
}
Abiturient::Abiturient(string n, int a, string s, int e) :Person(n, a)
{
	speciality = s;
	exams = e;
}
Abiturient::Abiturient(const Abiturient& a)
{
	name = a.name;
	age = a.age;
	speciality = a.speciality;
	exams = a.exams;
}
Abiturient::~Abiturient(void)
{}
void Abiturient::Set_Speciality(string s)
{
	speciality = s;
}
void Abiturient::Set_Exams(int e)
{
	exams = e;
}
Abiturient& Abiturient::operator=(const Abiturient& a)
{
	if (&a == this) return *this;
	name = a.name;
	age = a.age;
	speciality = a.speciality;
	exams = a.exams;
	return *this;
}
void Abiturient::Show()
{
	cout << "\nName: " << name;
	cout << "\nAge: " << age;
	cout << "\nSpeciality: " << speciality;
	cout << "\nExams: " << exams << endl;
}
void Abiturient::Input()
{
	cout << "\nEnter name: "; cin.ignore(); getline(cin, name);
	cout << "Enter age: "; cin >> age;
	cout << "Enter speciality: "; cin.ignore(); getline(cin, speciality);
	cout << "Enter exams: "; cin >> exams;
	cin.get();
}
