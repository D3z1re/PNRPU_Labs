#include <iostream>
#include <map>
#include <vector>
#include <set>
#include "Pair.h"
#include "List.h"
using namespace std;

typedef set<double> tset;
typedef set<Pair> pset;

tset make_set(int n)
{
	tset m;
	double a;
	for (int i = 0; i < n; i++)
	{
		cout << "?";
		cin >> a;
		m.insert(a);
	}
	return m;
}
pset make_pair_set(int n)
{
	pset m;
	Pair a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		m.insert(a);
	}
	return m;
}

void print_set(tset m)
{
	cout << "Содержимое set: \n";
	copy(m.begin(), m.end(), ostream_iterator<double>(cout, " "));
	cout << endl;
}
void print_set(pset m)
{
	cout << "Содержимое set: \n";
	set<Pair>::iterator iter = m.begin();
	for (; iter != m.end(); iter++)
	{
		cout << *iter << endl;
	}
	//copy(m.begin(), m.end(), ostream_iterator<Pair>(cout, " "));
	cout << endl;
}

void delete_set(tset& m, double left, double right)
{
	set<double>::iterator iter = m.begin();
	vector<set<double>::iterator> iters;
	int count = 0;
	while (iter != m.end())
	{
		if (*iter <= right && *iter >= left) { count++; iters.push_back(iter); }
		iter++;
	}
	cout << "Элементов к удалению: " << count << endl;
	for (int i = 0; i < count; i++)
	{
		m.erase(iters[i]);
	}
}
void delete_set(pset& m, Pair left, Pair right)
{
	set<Pair>::iterator iter = m.begin();
	vector<set<Pair>::iterator> iters;
	int count = 0;
	while (iter != m.end())
	{
		if (*iter <= right && *iter >= left) { count++; iters.push_back(iter); }
		iter++;
	}
	cout << "Элементов к удалению: " << count << endl;
	for (int i = 0; i < count; i++)
	{
		m.erase(iters[i]);
	}
}

void add_average(tset& m)
{
	set<double>::iterator iter = m.begin();
	tset temp_set;
	int size = 0;
	double avg = 0;
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
		double tmp = (*iter) + avg;
		iter++;
		temp_set.insert(tmp);
	}
	m = temp_set;
}
void add_average(pset& m)
{
	set<Pair>::iterator iter = m.begin();
	pset temp_set;
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
	m = temp_set;
}
void add_average(List<double>& m)
{
	double avg = 0;
	for (int i = 0; i < m(); i++)
	{
		avg += m[i];
	}
	avg /= m();
	List<double> tmp = m + avg;
	m = tmp;
}

void task1()
{
	int n; double left, right;
	cout << "Введите размер контейнера (1-100): "; cin >> n;
	while (n < 1 || n > 100)
	{
		cout << "\nВвод некорректен!";
		cout << "\nВведите размер контейнера (1-100): "; cin >> n;
	}
	tset m = make_set(n);
	print_set(m);

	cout << "\nМаксимальный элемент контейнера: ";
	set<double>::iterator iter = m.end(); iter--;
	double tmp = *iter;
	cout << tmp << endl;

	cout << "\nУдаление элементов в диапазоне";
	cout << "\nВведите левую границу диапазона: "; cin >> left;
	cout << "Введите правую границу диапазона: "; cin >> right;
	cout << "\nУдаление элементов в диапазоне [" << left << "; " << right << "]...\n";
	delete_set(m, left, right);
	cout << "\nКонтейнер после удаления:\n";
	print_set(m);
	cout << "\nДобавление среднего арифметического к каждому элементу контейнера...";
	add_average(m);
	cout << "\nКонтейнер после добавления:\n";
	print_set(m);
}
void task2()
{
	int n; Pair left, right;
	cout << "Введите размер контейнера (1-100): "; cin >> n;
	while (n < 1 || n > 100)
	{
		cout << "\nВвод некорректен!";
		cout << "\nВведите размер контейнера (1-100): "; cin >> n;
	}
	pset m = make_pair_set(n);
	print_set(m);

	cout << "Максимальный элемент контейнера: ";
	set<Pair>::iterator iter = m.end(); iter--;
	Pair tmp = *iter;
	cout << tmp << endl;
	cout << "\nУдаление элементов в диапазоне";
	cout << "\nВведите левую границу диапазона: \n"; cin >> left;
	cout << "Введите правую границу диапазона: \n"; cin >> right;
	cout << "\nУдаление элементов в диапазоне [" << left << "; " << right << "]...\n";
	delete_set(m, left, right);
	cout << "\nКонтейнер после удаления:\n";
	print_set(m);
	cout << "Добавление среднего арифметического к каждому элементу контейнера...\n";
	add_average(m);
	cout << "\nКонтейнер после добавления:\n";
	print_set(m);
}
void task3()
{
	int n; double left, right;
	cout << "Введите размер контейнера (1-100): "; cin >> n;
	while (n < 1 || n > 100)
	{
		cout << "\nВвод некорректен!";
		cout << "\nВведите размер контейнера (1-100): "; cin >> n;
	}
	List<double> task_set(n);
	task_set.Fill();
	cout << "\nСодержимое контейнера: \n";
	task_set.Show();
	cout << endl;
	cout << "Максимальный элемент контейнера: " << task_set[n-1];
	cout << "\nУдаление элементов в диапазоне";
	cout << "\nВведите левую границу диапазона: \n"; cin >> left;
	cout << "Введите правую границу диапазона: \n"; cin >> right;
	cout << "\nУдаление элементов в диапазоне [" << left << "; " << right << "]...\n";
	task_set.Delete_task(left, right);
	cout << "\nКонтейнер после удаления:\n";
	task_set.Show();
	cout << endl;
	cout << "Добавление среднего арифметического к каждому элементу контейнера...\n";
	//add_average(task_set);
	task_set.Add_Average();
	cout << "\nКонтейнер после добавления:\n";
	task_set.Show();
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Задача 1:\n";
	task1();
	cout << "\nЗадача 2:\n";
	task2();
	cout << "\nЗадача 3:\n";
	task3();

	return 0;
}
