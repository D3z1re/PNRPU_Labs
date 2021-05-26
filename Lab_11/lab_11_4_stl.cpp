#include <iostream>
#include <ctime>
#include <queue>
using namespace std;

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

void print(queue<char*> qu, char**& arr)
{
	int n = qu.size();
	for (int i = 0; i < n; i++)
	{
		arr[i] = qu.front();
		cout << i + 1 << ".\t" << qu.front() << "\n";
		qu.pop();
	}
	for (int i = 0; i < n; i++)
	{
		qu.push(arr[i]);
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, pos;
	cout << "Введите количество элементов очереди (1-100): ";
	cin >> n;
	while (n < 1 || n > 99)
	{
		cout << "\nКоличество введено некорректно.\n";
		cout << "Введите количество элементов (1-100): ";
		cin >> n;
	}

	char** arr = new char* [n];

	queue<char*> qu;
	for (int i = 0; i < n; i++)
	{
		qu.push(generate_string());
	}
	print(qu, arr);

	cout << "Введите номер, после которого нужно добавить элемент (1-" << n << "): ";
	cin >> pos;
	while (pos < 1 || pos > n)
	{
		cout << "\nНомер введен некорректно.\n";
		cout << "Введите номер, после которого нужно добавить элемент (1-" << n << "): ";
		cin >> pos;
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = qu.front();
		qu.pop();
	}
	for (int i = 0; i < pos; i++)
	{
		qu.push(arr[i]);
	}
	qu.push(generate_string());

	for (int i = pos; i < n; i++)
	{
		qu.push(arr[i]);
	}
	cout << "\nОчередь после добавления: \n";
	print(qu, arr);
	n++;
	for (int i = 0; i < n; i++)
	{
		qu.pop();
	}

	for (int i = 0; i < n; i++)
	{
		delete[] arr[i];
	}
}