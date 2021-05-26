#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

vector<int> Generate(int size = 100)
{
	vector<int> lst;
	for (int i = 0; i < size; i++)
	{
		lst.push_back(rand() % 100 + 1);
	}
	return lst;
}

void Fibb(int k, int& len1, int& len2)
{
	len1 = 0, len2 = 1;
	while (len1 + len2 < k)
	{
		int tmp = len2;
		len2 += len1;
		len1 = tmp;
	}
}

void DeleteEmpty(vector<int>& lst)
{
	while (lst[0] == 0)
	{
		lst.erase(lst.begin());
	}
}

void Print(vector<int> lst)
{
	for (int i = 0; i < lst.size(); i++)
	{
		cout << lst[i] << " ";
	}
	cout << endl;
}

void PrintSeries(vector<vector<int>> series_lst)
{
	for (int i = 0; i < series_lst.size(); i++)
	{
		cout << "Серия " << i + 1 << endl;
		for (int j = 0; j < series_lst[i].size(); j++)
		{
			cout << series_lst[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void PrintFiles(vector<vector<int>> f1, vector<vector<int>> f2, vector<vector<int>> f3)
{
	cout << "F1:\n";
	PrintSeries(f1);
	cout << "=============================================\n";
	cout << "F2:\n";
	PrintSeries(f2);
	cout << "=============================================\n";
	cout << "F3:\n";
	PrintSeries(f3);
	cout << "=============================================\n";
}

vector<int> Merge(vector<int> l1, vector<int> l2)
{
	int i = 0, j = 0;
	vector<int> tmp;
	while (i < l1.size() && j < l2.size())
	{
		if (l1[i] <= l2[j])
		{
			tmp.push_back(l1[i]);
			i++;
		}
		else
		{
			tmp.push_back(l2[j]);
			j++;
		}
	}
	while (i < l1.size())
	{
		tmp.push_back(l1[i]);
		i++;
	}
	while (j < l2.size())
	{
		tmp.push_back(l2[j]);
		j++;
	}
	//Print(tmp);
	//cout << "-------------------------------------------\n";
	return tmp;
}

void MergeSort(vector<int>& lst)
{
	if (lst.size() < 2) return;
	vector<int> left, right;
	int mid = lst.size() / 2;
	for (int i = 0; i < mid; i++) left.push_back(lst[i]);
	for (int i = mid; i < lst.size(); i++) right.push_back(lst[i]);
	MergeSort(left); MergeSort(right);
	lst = Merge(left, right);
}

vector<int> MergeSeries(vector<int> l1, vector<int>l2)
{
	int i = 0, j = 0;

	vector<int> tmp;
	while (i < l1.size())
	{
		tmp.push_back(l1[i]);
		i++;
	}
	while (j < l2.size())
	{
		tmp.push_back(l2[j]);
		j++;
	}
	return tmp;
}

vector<vector<int>> MergeFiles(vector<vector<int>>& f1, vector<vector<int>>& f2)
{
	vector<vector<int>> tmp;
	int min;
	if (f1.size() < f2.size()) min = f1.size();
	else min = f2.size();
	for (int i = 0; i < min; i++)
	{
		tmp.push_back(MergeSeries(f1[i], f2[i]));
	}
	f1.erase(f1.begin(), f1.begin() + min);
	f2.erase(f2.begin(), f2.begin() + min);
	return tmp;
}

void SplitSeries(vector<int> lst, vector<vector<int>>& series_lst)
{
	int i = 0;
	while (i < lst.size())
	{
		vector<int> tmp;
		tmp.push_back(lst[i]);
		i++;

		while (i < lst.size() && (lst[i - 1] < lst[i]))
		{
			tmp.push_back(lst[i]);
			i++;
		}
		series_lst.push_back(tmp);
	}
}

vector<vector<int>> SplitSeries_Phase(vector<int> lst)
{
	vector<vector<int>> res;
	int k;

	if (lst.size() < 8) k = 1;
	else
	{
		k = lst.size() / 8;
		while (lst.size() % k != 0) k--;
	}

	for (int i = 0; i < lst.size() / k; i++)
	{
		vector <int> tmp;
		for (int j = 0; j < k; j++)
		{
			tmp.push_back(lst[i * k + j]);
		}
		res.push_back(tmp);
	}
	return res;
}

vector <int> NaturalMerge(vector<int> lst)
{
	vector<vector<int>> series_lst;
	SplitSeries(lst, series_lst);
	//PrintSeries(series_lst);

	while (series_lst.size() >= 2)
	{
		vector<int> tmp = MergeSeries(series_lst[0], series_lst[1]);
		series_lst.push_back(tmp);
		series_lst.erase(series_lst.begin());
		series_lst.erase(series_lst.begin());
	}
	return series_lst[0];
}

vector<int> PhaseMerge(vector<int>& lst)
{
	vector<vector<int>> series_lst = SplitSeries_Phase(lst);
	int l1, l2;

	vector<vector<int>> f1, f2, f3;
	Fibb(series_lst.size(), l1, l2);

	for (int i = 0; i < l1; i++)
	{
		f1.push_back(series_lst[i]);
	}
	if (l1 + l2 == series_lst.size())
	{
		for (int i = l1; i < series_lst.size(); i++)
		{
			f2.push_back(series_lst[i]);
		}
	}
	else
	{
		int i = l1;
		for (i; i < series_lst.size(); i++)
		{
			f2.push_back(series_lst[i]);
		}

		for (i; i < l1 + l2; i++)
		{
			vector<int> tmp;
			for (int j = 0; j < f2[0].size(); j++)
			{
				tmp.push_back(0);
			}
			f2.push_back(tmp);
		}
	}
	//PrintFiles(f1, f2, f3);

	for (int i = 0; i < f1.size(); i++) sort(f1[i].begin(), f1[i].end());
	for (int i = 0; i < f2.size(); i++) sort(f2[i].begin(), f2[i].end());

	cout << "Отсортированные файлы:\n";
	PrintFiles(f1, f2, f3);

	int k = 1;
	while (k != 2)
	{
		int k_i = 3;
		if (f1.empty()) k_i = 1;
		if (f2.empty()) k_i = 2;
		switch (k_i)
		{
		case 1: f1 = MergeFiles(f2, f3); break;
		case 2: f2 = MergeFiles(f1, f3); break;
		case 3: f3 = MergeFiles(f1, f2); break;
		}
		k = 0;
		if (f1.empty()) k++;
		if (f2.empty()) k++;
		if (f3.empty()) k++;
		//PrintFiles(f1, f2, f3);
	}
	if (!f1.empty()) 
	{
		DeleteEmpty(f1[0]);
		return f1[0];
	}
	if (!f2.empty()) 
	{
		DeleteEmpty(f2[0]);
		return f2[0];
	}
	if (!f3.empty()) 
	{
		DeleteEmpty(f3[0]);
		return f3[0];
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int n;
	vector<int> list = Generate();

	cout << "Исходный массив:\n\n";
	Print(list);
	cout << "===============================================================\n";
	cout << "Методы сортировки: \n";
	cout << "| 1. Естественное слияние\n";
	cout << "| 2. Сбалансированние слияние\n";
	cout << "| 3. Многофазное слияние\n";

	cout << "\nВыберите метод сортировки (1-3): ";
	cin >> n;

	switch (n) {
	case 1: list = NaturalMerge(list); break;
	case 2: MergeSort(list); break;
	case 3: list = PhaseMerge(list); break;
	}

	cout << "Отсортированный массив: \n";
	Print(list);
}