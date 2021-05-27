#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Pair.h"
using namespace std;

void Delete_Pairs(char* file, int f, double s)
{
	ifstream input;
	input.open(file);
	ofstream output;
	output.open("temp.txt");

	while (!input.eof())
	{
		Pair a;
		input >> a;
		if (a != Pair())
		{
			if (a.GetFirst() != f || a.GetSecond() != s)
			{
				output << a;
			}
		}
	}
	input.close();
	output.close();
	remove(file);
	rename("temp.txt", file);
}
void Decrease_Pairs(char* file, int f, double s, int L)
{
	ifstream input;
	input.open(file);
	ofstream output;
	output.open("temp.txt");

	while (!input.eof())
	{
		Pair a;
		input >> a;
		if (a != Pair())
		{
			if (a.GetFirst() == f && a.GetSecond() == s)
			{
				a.SetFirst(a.GetFirst() - L);
				a.SetSecond(a.GetSecond() - L);
			}
			output << a;
		}
	}
	input.close();
	output.close();
	remove(file);
	rename("temp.txt", file);
}
void Add_Pairs(char* file, vector<Pair> pairs_to_add, int f, double s)
{
	ifstream input;
	input.open(file);
	ofstream output;
	output.open("temp.txt");

	int flag = 0;

	while (!input.eof())
	{
		Pair a;
		input >> a;
		if (a != Pair())
		{
			output << a;
			if (a.GetFirst() == f && a.GetSecond() == s && !flag)
			{
				for (int i = 0; i < pairs_to_add.size(); i++)
				{
					output << pairs_to_add[i];
				}
				flag = 1;
			}
		}
	}
	input.close();
	output.close();
	remove(file);
	rename("temp.txt", file);
}
vector<Pair> Read_to_Vector(string file)
{
	vector<Pair> tmp;

	ifstream input;
	input.open(file);

	while (!input.eof())
	{
		Pair a;
		input >> a;
		if (a != Pair())
		{
			tmp.push_back(a);
		}
	}
	input.close();
	return tmp;
}
void Show(vector<Pair> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << "Pair " << i + 1 << ": " << endl;
		cout << a[i].GetFirst() << ":" << a[i].GetSecond() << endl;
	}
}

void GetMenu()
{
	cout << "========================| ���� |========================\n";
	cout << "| 1 - ������ �����\n";
	cout << "| 2 - ������ � �������� ��� � �������� ���������\n";
	cout << "| 3 - ������ � ���������� ��� � �������� ���������\n";
	cout << "| 4 - ������ � ���������� ����� ���� � �������� ���������\n";
	cout << "| 0 - �����\n";
	cout << "========================================================\n";
	cout << "�����: ";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char file[] = "input.txt";
	vector<Pair> pairs;

	int n = -1;
	while (n != 0)
	{
		GetMenu();
		cin >> n;

		switch (n)
		{
		case 1: {
			cout << "������ �����\n";
			pairs = Read_to_Vector(file);
			Show(pairs);
			break;
		}
		case 2: {
			cout << "������ ����� � ���������\n";
			int tmp1; double tmp2;
			cout << "������� ������������� ������� ����: ";
			cin >> tmp1;
			cout << "������� ������������ ������� ����: ";
			cin >> tmp2;
			cout << "�������� �� ����� ��� �� ��������� " << tmp1 << ":" << tmp2 << "\n";
			Delete_Pairs(file, tmp1, tmp2);
			pairs = Read_to_Vector(file);
			Show(pairs);
			break;
		}
		case 3: {
			cout << "������ ����� � �����������\n";
			int tmp1, L; double tmp2;
			cout << "������� ������������� ������� ����: ";
			cin >> tmp1;
			cout << "������� ������������ ������� ����: ";
			cin >> tmp2;
			cout << "������� �����, �� ������� ����� ��������� ����: ";
			cin >> L;
			cout << "���������� ��� �� ��������� " << tmp1 << ":" << tmp2 << " �� " << L;
			Decrease_Pairs(file, tmp1, tmp2, L);
			pairs = Read_to_Vector(file);
			Show(pairs);
			break;
		}
		case 4: {
			cout << "������ ����� � �����������\n";
			vector<Pair> tmp;
			int tmp1, k; double tmp2;
			cout << "\n������� ��� ����� �������� (1-10): ";
			cin >> k;
			while (k < 1 || k > 10)
			{
				cout << "���� �����������! ����� �������� �� 1 �� 10 ���.\n";
				cout << "������� ��� ����� �������� (1-10) ";
				cin >> k;
			}
			cout << "\n������� �������� ��� ��� ����������.\n";
			for (int i = 0; i < k; i++)
			{
				cout << "���� " << i + 1 << ":\n";
				cout << "������� ������������� ������� ����: ";
				cin >> tmp1;
				cout << "������� ������������ ������� ����: ";
				cin >> tmp2;
				tmp.push_back(Pair(tmp1, tmp2));
			}
			cout << "\n������� �������� ����, ����� ������� ����� ������� " << k << " ��������� ���\n";
			cout << "������� ������������� ������� ����: ";
			cin >> tmp1;
			cout << "������� ������������ ������� ����: ";
			cin >> tmp2;
			cout << "���������� " << k << " ��� ����� ���� �� ��������� " << tmp1 << ":" << tmp2 << endl;
			Add_Pairs(file, tmp, tmp1, tmp2);
			pairs = Read_to_Vector(file);
			Show(pairs);
			break;
		}
		}
	}
	Show(pairs);

	return 0;
}
