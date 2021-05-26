#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <ctime>
#include <cmath>
using namespace std;

struct Date
{
	int day, mon, yr;
};

struct Human
{
	string name;
	Date birth;
	string phone;

	void Print()
	{
		cout << "ФИО: " << name;
		cout << "\nДата рождения: " << birth.day << "/" << birth.mon << "/" << birth.yr;
		cout << "\nНомер телефона: " << phone;
		cout << "\n--------------------------------------------------------\n";
	}

	string GeneratePhone()
	{
		string res = "+79";
		for (int i = 0; i < 9; i++)
		{
			res += to_string(rand() % 10);
		}
		return res;
	}

	void Generate()
	{
		string names[] = { "Марк", "Егор", "Руслан", "Андрей", "Дмитрий", "Павел", "Юрий", "Сергей", "Никита", "Кирилл" };
		string snames[] = { "Терехов", "Латышев", "Адрианов", "Титов", "Логинов", "Тихонов", "Беликов", "Поздняков", "Блинов", "Исаков" };
		string fnames[] = { "Маркович", "Егорович", "Русланович", "Андреевич", "Дмитриевич", "Павлович", "Юрьевич", "Сергеевич", "Никитович", "Кириллович" };

		name = snames[rand() % 10] + " " + names[rand() % 10] + " " + fnames[rand() % 10];
		birth.mon = rand() % 12 + 1;
		if (birth.mon == 2) birth.day = rand() % 28 + 1;
		else birth.day = rand() % 30 + 1;
		birth.yr = 1900 + (rand() % 120 + 1);
		phone = GeneratePhone();
	}
};

struct HashTable
{
	int key;
	vector<Human> list;
	void HashFunc(string name, int size)
	{
		int sum = 0;
		for (int i = 0; i < name.length(); i++)
		{
			sum += abs(int(name[i]));
		}
		key = sum % size;
	}
	void Add(Human a)
	{
		list.push_back(a);
	}
};

vector<Human> CreateArr(int size = 100)
{
	vector<Human> lst;
	for (int i = 0; i < size; i++)
	{
		Human elem;
		elem.Generate();
		lst.push_back(elem);
	}
	return lst;
}

void Sort(vector<HashTable>& lst)
{
	for (int st = lst.size() / 2; st > 0; st /= 2)
	{
		for (int i = st; i < lst.size(); i++)
		{
			for (int j = i; j >= st; j -= st)
			{
				if (lst[j].key < lst[j - st].key) swap(lst[j].key, lst[j - st].key);
			}
		}
	}
}

void PrintArr(vector<Human> lst)
{
	if (lst.empty())
	{
		cout << "Список пуст.\n";
		return;
	}
	cout << "\n--------------------------------------------------------\n";
	for (int i = 0; i < lst.size(); i++)
	{
		cout << "Номер: " << i + 1 << endl;
		lst[i].Print();
	}
}

void PrintHashTable(vector<HashTable> hash_lst)
{
	for (int i = 0; i < hash_lst.size(); i++)
	{
		cout << "===========================================================\n";
		cout << "Хеш " << i + 1 << ":\t" << hash_lst[i].key << endl;
		cout << "Элементы с этим хешем: \t" << hash_lst[i].list.size() << endl;
		for (int j = 0; j < hash_lst[i].list.size(); j++)
		{
			cout << "Номер " << j + 1 << endl;
			cout << "ФИО:\t" << hash_lst[i].list[j].name << endl;
			cout << "Дата рождения:\t" << hash_lst[i].list[j].birth.day << "/" << hash_lst[i].list[j].birth.mon << "/" << hash_lst[i].list[j].birth.yr << endl;
			cout << "Номер телефона:\t" << hash_lst[i].list[j].phone << endl;
			cout << "Hash:\t" << hash_lst[i].key << endl;
			cout << endl;
		}
	}
}

void FillHashTable(vector<Human> lst, vector<HashTable>& hash_lst)
{
	for (int i = 0; i < lst.size(); i++)
	{
		HashTable tmp;
		tmp.HashFunc(lst[i].name, lst.size());
		tmp.Add(lst[i]);
		hash_lst.push_back(tmp);
	}
	Sort(hash_lst);
	int len = hash_lst.size();
	for (int i = 0; i < len - 1;)
	{
		if (hash_lst[i].key == hash_lst[i + 1].key)
		{
			hash_lst[i].list.push_back(hash_lst[i + 1].list[0]);
			hash_lst.erase(hash_lst.begin() + i + 1);
			len--;
		}
		else i++;
	}
}

void FindByName(vector<HashTable> hash_lst, string key, int size)
{
	int sum = 0;
	for (int i = 0; i < key.length(); i++)
	{
		sum += abs(int(key[i]));
	}
	int key_hash = sum % size;

	for (int i = 0; i < hash_lst.size(); i++)
	{
		if (hash_lst[i].key == key_hash)
		{
			for (int j = 0; j < hash_lst[i].list.size(); j++)
			{
				if (key == hash_lst[i].list[j].name)
				{
					cout << "Элемент найден!\n";
					cout << "ФИО:\t" << hash_lst[i].list[j].name << endl;
					cout << "Дата рождения:\t" << hash_lst[i].list[j].birth.day << "/" << hash_lst[i].list[j].birth.mon << "/" << hash_lst[i].list[j].birth.yr << endl;
					cout << "Номер телефона:\t" << hash_lst[i].list[j].phone;
					cout << "Hash:\t" << hash_lst[i].key << endl;
					return;
				}
			}
			cout << "===========================================================\n";
		}
	}
	cout << "Элементов не найдено.\n";
}

void FindByHash(vector<HashTable> hash_lst, int key)
{
	for (int i = 0; i < hash_lst.size(); i++)
	{
		if (key == hash_lst[i].key)
		{
			cout << "Элемент(ы) с таким хешем найден(ы):\n";
			PrintArr(hash_lst[i].list);
			cout << "===========================================================\n";
			return;
		}
	}
	cout << "Элементов не найдено.\n";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int n;
	vector<Human> list = CreateArr();
	vector<HashTable> hash_list;
	PrintArr(list);

	FillHashTable(list, hash_list);

	cout << "===========================================================\n\n";
	cout << "Таблица хешей:\n";
	PrintHashTable(hash_list);
	cout << "===========================================================\n\n";
	cout << "===========================================================\n\n";
	cout << "Методы поиска:\n";
	cout << "| 1. Поиск по имени.\n";
	cout << "| 2. Поиск по хешу.\n";
	cout << "Выберите метод поиска (1-2): ";
	cin >> n;
	cin.get();
	switch (n)
	{
	case 1:
	{
		string key;
		cout << "Введите ФИО для поиска: ";
		getline(cin, key);
		while (key == "" || key[0] == ' ')
		{
			cout << "\nФИО введено некорректно.\n";
			cout << "Введите ФИО для поиска: ";
			getline(cin, key);
		}
		cout << "===========================================================\n\n";
		FindByName(hash_list, key, list.size());
		break;
	}
	case 2:
	{
		int key;
		cout << "Введите хеш для поиска: ";
		cin >> key;
		cout << "===========================================================\n\n";
		FindByHash(hash_list, key);
		break;
	}
	default:
	{
		cout << "Ввод некорректен. Завершение работы...\n";
	}
	}
}
