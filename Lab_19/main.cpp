#include <iostream>
#include "Stack.h"
#include "Stack.cpp"
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	int n;
	Stack<double> stk;
	cout << "������� ������ ����� (1-100): "; cin >> n;
	while (n < 1 || n > 100)
	{
		cout << "\n���� �����������!";
		cout << "\n������� ������ ����� (1-100): "; cin >> n;
	}
	for (int i = 0; i < n; i++)
	{
		double a = rand() % 10000 / 100.0;
		stk.push(a);
	}
	cout << "\n����� ���������������� �����: " << stk.size();
	for (int i = 0; i < stk.size(); i++)
	{
		cout << "������� " << i + 1 << ": " << stk.top() << endl;
		stk.pop();
	}

	return 0;
}
