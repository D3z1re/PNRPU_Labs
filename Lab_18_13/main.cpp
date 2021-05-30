#include <deque>
#include <iostream>
#include <algorithm>
#include <stack>
#include <set>
#include "Pair.h"
using namespace std;

deque<Pair> make_deque(int size)
{
	deque<Pair> tmp;

	for (int i = 0; i < size; i++)
	{
		Pair tmp_pair;
		cin >> tmp_pair;
		tmp.push_back(tmp_pair);
	}
	return tmp;
}
void print_deque(deque<Pair> tmp)
{
	for (int i = 0; i < tmp.size(); i++)
	{
		cout << tmp[i] << " ";
	}
	cout << endl;
}

stack<Pair> make_stack(int size)
{
	stack<Pair> tmp;

	for (int i = 0; i < size; i++)
	{
		Pair tmp_pair;
		cin >> tmp_pair;
		tmp.push(tmp_pair);
	}
	return tmp;
}
void print_stack(stack<Pair> a)
{
	stack<Pair> tmp = a;
	while (!tmp.empty())
	{
		cout << tmp.top() << " ";
		tmp.pop();
	}
	cout << endl;
}
stack<Pair> delete_task(stack<Pair> a, Pair left, Pair right)
{
	stack<Pair> tmp, tmp_2;
	int count = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a.top() < left || a.top() > right)
		{
			tmp.push(a.top());
			count++;
		}
		a.pop();
	}
	for (int i = 0; i < count; i++)
	{
		tmp_2.push(tmp.top());
		tmp.pop();
	}
	return tmp_2;
}

set<Pair> make_set(int size)
{
	set<Pair> tmp;
	for (int i = 0; i < size; i++)
	{
		Pair tmp_pair;
		cin >> tmp_pair;
		tmp.insert(tmp_pair);
	}
	return tmp;
}
void print_set(set<Pair> m)
{
	set<Pair>::iterator iter = m.begin();
	for (; iter != m.end(); iter++)
	{
		cout << *iter << endl;
	}
	cout << endl;
}
set<Pair> add_average(set<Pair> m)
{
	set<Pair>::iterator iter = m.begin();
	set<Pair> temp_set;
	int size = 0;
	Pair avg;
	while (iter != m.end())
	{
		avg += *iter;
		size++;
		iter++;
	}
	avg /= size;
	iter = m.begin();
	while (iter != m.end())
	{
		Pair tmp = avg + (*iter);
		iter++;
		temp_set.insert(tmp);
	}
	return temp_set;
}


void task1()
{
	deque<Pair> deq;
	int size;
	cout << "Введите размер двунаправленной очереди (1-100): "; cin >> size;
	while (size < 1 || size > 100)
	{
		cout << "Ввод некорректен!\n";
		cout << "Введите размер двунаправленной очереди (1-100): "; cin >> size;
	}
	deq = make_deque(size);
	cout << "\nВведенная очередь: \n";
	print_deque(deq);
	cout << "\nДобавление максимального элемента";
	deque<Pair>::iterator max;
	//deque<Pair>::iterator iter = deq.end();
	max = max_element(deq.begin(), deq.end());
	deq.insert(deq.end(), *max);
	cout << "\nОчередь после добавления: \n";
	print_deque(deq);
}

void task2()
{
	stack<Pair> st;
	int size;
	Pair left, right;
	cout << "Введите размер стека (1-100): "; cin >> size;
	while (size < 1 || size > 100)
	{
		cout << "Ввод некорректен!\n";
		cout << "Введите размер стека (1-100): "; cin >> size;
	}
	st = make_stack(size);
	cout << "\nВведенный стек:\n";
	print_stack(st);

	cout << "\nУдаление элементов в диапазоне";
	cout << "\nВведите левую границу диапазона: "; cin >> left;
	cout << "Введите правую границу диапазона: "; cin >> right;
	cout << "\nУдаление элементов в диапазоне [" << left << "; " << right << "]...\n";
	st = delete_task(st, left, right);
	cout << "\nСтек после удаления:\n";
	print_stack(st);
}

void task3()
{
	set<Pair> pset;
	int size;
	cout << "Введите размер set (1-100): "; cin >> size;
	while (size < 1 || size > 100)
	{
		cout << "Ввод некорректен!\n";
		cout << "Введите размер set (1-100): "; cin >> size;
	}
	pset = make_set(size);
	cout << "\nВведенный set:\n";
	print_set(pset);
	cout << "\nДобавление среднего арифметического к каждому элементу set:\n";
	pset = add_average(pset);
	cout << "\nSet после добавления: \n";
	print_set(pset);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Задание 1:\n";
	task1();
	cout << "\nЗадание 2:\n";
	task2();
	cout << "\nЗадание 3:\n";
	task3();
	return 0;
}