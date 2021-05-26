#include <iostream>
#include <ctime>
#include <stack>
using namespace std;

void print(stack<int> st)
{
	int n = st.size();
	if (n == 0) cout << "Стек пуст";
	else
	{
		for (int i = 0; i < n; i++)
		{
			cout << st.top() << " ";
			st.pop();
		}
	}
	cout << endl;
}

void delete_even(stack<int>& st, int& n)
{
	stack<int> st2;
	for (int i = 0; i < n; i++)
	{
		if (st.top() % 2 != 0)
		{
			st2.push(st.top());
		}
		st.pop();
	}
	n = st2.size();
	for (int i = 0; i < n; i++)
	{
		st.push(st2.top());
		st2.pop();
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	stack<int> st;
	int n;
	cout << "Введите количество элементов стека (1-100): ";
	cin >> n;
	while (n < 1 || n > 99)
	{
		cout << "\nКоличество введено неверно.\n";
		cout << "Введите количество элементов стека (1-100): ";
		cin >> n;
	}
	for (int i = 0; i < n; i++)
	{
		st.push(rand() % 100 + 1);
	}
	cout << "\nСгенерированный стек: \n";
	print(st);
	delete_even(st, n);
	cout << "\nСтек после удаления: \n";
	print(st);
}
