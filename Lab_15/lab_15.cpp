#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Time
{
	int hr = -1, min = -1;
};

struct Station
{
	string name;
	Time arr_time;

	void InputData()
	{
		cout << "\nВведите название станции: ";
		getline(cin, name);
		while (name == "")
		{
			cout << "\nВведена пустая строка.";
			cout << "\nВведите название станции: ";
			getline(cin, name);
		}

		cout << "\nВведите время прибытия (чч мм): ";
		cin >> arr_time.hr >> arr_time.min;
		while (arr_time.hr < 0 || arr_time.hr > 23 || 
			arr_time.min < 0 || arr_time.min > 59)
		{
			cout << "\nВремя прибытия введено некорректно. ";
			cout << "\nВведите время прибытия (чч мм): ";
			cin >> arr_time.hr >> arr_time.min;
		}
		cin.get();
	}

	void Print()
	{
		cout << "Название станции: " << name;
		cout << "\nВремя прибытия: " << arr_time.hr << ":" << arr_time.min;
		cout << "\n--------------------------------------------------------\n";
	}
};

void PrintArr(vector<Station> lst)
{
	cout << "\n--------------------------------------------------------\n";
	for (int i = 0; i < lst.size(); i++)
	{
		lst[i].Print();
	}
}

void ShellSort(vector<Station>& lst)
{
	int j;
	string tmpname;
	Time tmptime;
	for (int step = lst.size() / 2; step > 0; step /= 2)
	{
		for (int i = step; i < lst.size(); i++)
		{
			tmpname = lst[i].name;
			tmptime = lst[i].arr_time;
			for (j = i; j >= step; j -= step)
			{
				if (tmpname < lst[j - step].name)
				{
					lst[j].name = lst[j - step].name;
					lst[j].arr_time = lst[j - step].arr_time;
				}
				else break;
			}
			lst[j].name = tmpname;
			lst[j].arr_time = tmptime;
		}
	}
}

void QuickSort(vector<Station>& lst, int first, int last)
{
	int i = first, j = last;
	string tmpname = lst[(first + last) / 2].name;
	Time tmptime = lst[(first + last) / 2].arr_time;

	do
	{
		while (lst[i].name < tmpname) i++;
		while (lst[j].name > tmpname) j--;
		if (i <= j)
		{
			if (lst[i].name > lst[j].name) swap(lst[i], lst[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last) QuickSort(lst, i, last);
	if (first < j) QuickSort(lst, first, j);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251>nul");
	int n;
	cout << "Введите количество элементов списка (1-100): ";
	cin >> n;
	while (n < 1 || n > 100)
	{
		cout << "\nКоличество введено некорректно.\n";
		cout << "Введите количество элементов списка (1-100): ";
		cin >> n;
	}
	cin.get();
	vector<Station> arr(n);
	for (int i = 0; i < n; i++)
	{
		arr[i].InputData();
	}
	cout << "\n--------------------------------------------------------\n";
	cout << "| Выберите метод сортировки\n";
	cout << "| 1 - Сортировка Шелла\n";
	cout << "| 2 - Сортировка Хоара\n";
	cout << "Введите число (1-2): ";
	cin >> n;
	while (n < 1 || n > 2)
	{
		cout << "\nВвод некорректен.\n";
		cout << "Введите число (1-2): ";
		cin >> n;
	}
	switch (n) {
	case 1: ShellSort(arr); break;
	case 2: QuickSort(arr, 0, (arr.size() - 1)); break;
	}
	cout << "\nОтсортированный массив: ";
	PrintArr(arr);

	return 0;
}