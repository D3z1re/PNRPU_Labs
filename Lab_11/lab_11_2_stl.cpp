#include <iostream>
#include <ctime>
#include <iterator>
#include <list>
using namespace std;

list<char*> charlist;

char* generate_string()
{
	int len = rand() % 30 + 1;
	char* a = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		a[i] = rand() % 57 + 65;
	}
	a[len] = '\0';

	return a;
}

void make(int size)
{
	for (int i = 0; i < size; i++)
	{
		charlist.push_back(generate_string());
	}
}

void add(int size)
{
	int pos;
	cout << "Введите номер строки для добавления (1-" << size + 1 << "): ";
	cin >> pos;
	while (pos < 1 || pos >(size + 1))
	{
		cout << "Номер введен некорректно.\n";
		cout << "\nВведите номер строки для добавления (1-" << size + 1 << "): ";
		cin >> pos;
	}
	list<char*> ::iterator it;
	it = charlist.begin();
	advance(it, pos - 1);
	list<char*> additlist;
	additlist.push_back(generate_string());
	charlist.insert(it, additlist.begin(), additlist.end());
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int n;

	cout << "Введите количество элементов списка (3-100): ";
	cin >> n;
	while (n < 3 || n > 99) {
		cout << "Количество введено некорректно.\n";
		cout << "\nВведите количество элементов списка (3-100): ";
		cin >> n;
	}
	make(n);
	cout << "\nСгенерированный список: \n";
	copy(charlist.begin(), charlist.end(), ostream_iterator<char*>(cout, "\n"));
	cout << endl;
	add(n);
	cout << "\nНовый список: \n";
	copy(charlist.begin(), charlist.end(), ostream_iterator<char*>(cout, "\n"));
	return 0;
}
