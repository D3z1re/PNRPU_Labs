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
	cout << "���������� set: \n";
	copy(m.begin(), m.end(), ostream_iterator<double>(cout, " "));
	cout << endl;
}
void print_set(pset m)
{
	cout << "���������� set: \n";
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
	cout << "��������� � ��������: " << count << endl;
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
	cout << "��������� � ��������: " << count << endl;
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
	cout << "������� ������ ���������� (1-100): "; cin >> n;
	while (n < 1 || n > 100)
	{
		cout << "\n���� �����������!";
		cout << "\n������� ������ ���������� (1-100): "; cin >> n;
	}
	tset m = make_set(n);
	print_set(m);

	cout << "\n������������ ������� ����������: ";
	set<double>::iterator iter = m.end(); iter--;
	double tmp = *iter;
	cout << tmp << endl;

	cout << "\n�������� ��������� � ���������";
	cout << "\n������� ����� ������� ���������: "; cin >> left;
	cout << "������� ������ ������� ���������: "; cin >> right;
	cout << "\n�������� ��������� � ��������� [" << left << "; " << right << "]...\n";
	delete_set(m, left, right);
	cout << "\n��������� ����� ��������:\n";
	print_set(m);
	cout << "\n���������� �������� ��������������� � ������� �������� ����������...";
	add_average(m);
	cout << "\n��������� ����� ����������:\n";
	print_set(m);
}
void task2()
{
	int n; Pair left, right;
	cout << "������� ������ ���������� (1-100): "; cin >> n;
	while (n < 1 || n > 100)
	{
		cout << "\n���� �����������!";
		cout << "\n������� ������ ���������� (1-100): "; cin >> n;
	}
	pset m = make_pair_set(n);
	print_set(m);

	cout << "������������ ������� ����������: ";
	set<Pair>::iterator iter = m.end(); iter--;
	Pair tmp = *iter;
	cout << tmp << endl;
	cout << "\n�������� ��������� � ���������";
	cout << "\n������� ����� ������� ���������: \n"; cin >> left;
	cout << "������� ������ ������� ���������: \n"; cin >> right;
	cout << "\n�������� ��������� � ��������� [" << left << "; " << right << "]...\n";
	delete_set(m, left, right);
	cout << "\n��������� ����� ��������:\n";
	print_set(m);
	cout << "���������� �������� ��������������� � ������� �������� ����������...\n";
	add_average(m);
	cout << "\n��������� ����� ����������:\n";
	print_set(m);
}
void task3()
{
	int n; double left, right;
	cout << "������� ������ ���������� (1-100): "; cin >> n;
	while (n < 1 || n > 100)
	{
		cout << "\n���� �����������!";
		cout << "\n������� ������ ���������� (1-100): "; cin >> n;
	}
	List<double> task_set(n);
	task_set.Fill();
	cout << "\n���������� ����������: \n";
	task_set.Show();
	cout << endl;
	cout << "������������ ������� ����������: " << task_set[n-1];
	cout << "\n�������� ��������� � ���������";
	cout << "\n������� ����� ������� ���������: \n"; cin >> left;
	cout << "������� ������ ������� ���������: \n"; cin >> right;
	cout << "\n�������� ��������� � ��������� [" << left << "; " << right << "]...\n";
	task_set.Delete_task(left, right);
	cout << "\n��������� ����� ��������:\n";
	task_set.Show();
	cout << endl;
	cout << "���������� �������� ��������������� � ������� �������� ����������...\n";
	//add_average(task_set);
	task_set.Add_Average();
	cout << "\n��������� ����� ����������:\n";
	task_set.Show();
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "������ 1:\n";
	task1();
	cout << "\n������ 2:\n";
	task2();
	cout << "\n������ 3:\n";
	task3();

	return 0;
}
