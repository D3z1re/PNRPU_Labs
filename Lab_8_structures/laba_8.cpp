#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Film
{
	string name, director;
	int year, cost;

	void Fill()
	{
		cout << "\nВведите название фильма: ";
		getline(cin, name);
		while (name == "" || name[0] == ' ')
		{
			cout << "Строка не может быть пустой и не может начинаться с пробела.\n";
			cout << "Введите название фильма: ";
			getline(cin, name);
		}
		cout << "Введите имя режиссера: ";
		getline(cin, director);
		while (director == "" || director[0] == ' ')
		{
			cout << "Строка не может быть пустой и не может начинаться с пробела.\n";
			cout << "Введите имя режиссера: ";
			getline(cin, director);
		}
		cout << "Введите год: "; cin >> year;
		while (year > 2021 || year < 1895)
		{
			if (year < 1895)
			{
				cout << "Первый фильм был снят только в 1895 году.\n";
				cout << "Введите год: "; cin >> year;
			}
			else
			{
				cout << "Можно добавлять только уже вышедшие фильмы.\n";
				cout << "Введите год: "; cin >> year;
			}
		}
		cout << "Введите стоимость: "; cin >> cost;
		while (cost <= 0)
		{
			cout << "Стоимость введена некорректно.\n";
			cout << "Введите стоимость: "; cin >> cost;
		}
		cin.get();
	}

	void Print()
	{
		cout << "\n";
		cout << "Название:\t" << name << "\n";
		cout << "Режиссер:\t" << director << "\n";
		cout << "Год выпуска:\t" << year << "\n";
		cout << "Стоимость:\t" << cost << "\n";
	}
};

void AddToFile(ofstream& file, Film* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		file << "Название:\t" << arr[i].name << endl;
		file << "Режиссер:\t" << arr[i].director << endl;
		file << "Год выпуска:\t" << arr[i].year << endl;
		file << "Стоимость:\t" << arr[i].cost << endl << endl;
	}
}

void RemoveExcess(Film*& arr, int& size, int cost)
{
	int new_size = size;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].cost > cost) new_size--;
	}
	if (new_size == 0)
	{
		delete[] arr;
		arr = nullptr;
		size = 0;
	}
	else
	{
		Film* new_arr = new Film[new_size];
		new_size = 0;
		for (int i = 0; i < size; i++)
		{
			if (arr[i].cost <= cost)
			{
				new_arr[new_size] = arr[i];
				new_size++;
			}
		}
		delete[] arr;
		arr = new_arr;
		size = new_size;
		new_arr = nullptr;
	}
}

void AppendToList(Film*& arr, int& size)
{
	size++;
	Film* new_arr = new Film[size];
	new_arr[0].Fill();
	if (size > 1)
	{
		for (int i = 1; i < size; i++)
		{
			new_arr[i] = arr[i - 1];
		}
		delete[] arr;
		arr = new_arr;
		new_arr = nullptr;
	}
	else
	{
		arr = new_arr;
		new_arr = nullptr;
	}
}

void PrintList(Film* arr, int size)
{
	if (size == 0) cout << "Список пуст\n";
	else
	{
		for (int i = 0; i < size; i++)
		{
			arr[i].Print();
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251>nul");

	int num;
	int cost_del;
	string filename = "Filmoteka.txt";

	cout << "Введите количество фильмов: "; cin >> num;
	while (num <= 0)
	{
		cout << "Неверно введено количество фильмов.\n";
		cout << "Введите количество фильмов: "; cin >> num;
	}
	cin.get();
	Film* films_arr = new Film[num];
	for (int i = 0; i < num; i++)
	{
		films_arr[i].Fill();
	}
	cout << "\nИсходная фильмотека:\n";
	PrintList(films_arr, num);

	cout << "\nВведите предельную стоимость: ";
	cin >> cost_del;
	while (cost_del <= 0)
	{
		cout << "Введена некорректная стоимость.\n";
		cout << "\nВведите предельную стоимость: ";
		cin >> cost_del;
	}
	cin.get();
	cout << "\nВсе фильмы, превышающие стоймость " << cost_del << " будут удалены.";
	RemoveExcess(films_arr, num, cost_del);

	cout << "\nНовая фильмотека: \n";
	PrintList(films_arr, num);

	cout << "\nДобавление фильма в начало списка.\n";
	AppendToList(films_arr, num);

	cout << "\nНовая фильмотека:\n";
	PrintList(films_arr, num);

	ofstream output(filename);
	AddToFile(output, films_arr, num);

	output.close();
	delete[] films_arr;
	return 0;
}
