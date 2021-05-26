#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

string file = "database.txt";

string names[] = { "Марк", "Егор", "Руслан", "Андрей", "Дмитрий", "Павел", "Юрий", "Сергей", "Никита", "Кирилл" };
string snames[] = { "Терехов", "Латышев", "Адрианов", "Титов", "Логинов", "Тихонов", "Беликов", "Поздняков", "Блинов", "Исаков" };
string fnames[] = { "Маркович", "Егорович", "Русланович", "Андреевич", "Дмитриевич", "Павлович", "Юрьевич", "Сергеевич", "Никитович", "Кириллович" };

struct Human;

vector<Human> DelList;

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
		name = snames[rand() % 10] + " " + names[rand() % 10] + " " + fnames[rand() % 10];
		birth.mon = rand() % 12 + 1;
		if (birth.mon == 2) birth.day = rand() % 28 + 1;
		else birth.day = rand() % 30 + 1;
		birth.yr = 1900 + (rand() % 120 + 1);
		phone = GeneratePhone();
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

void OutputToFile(vector<Human>& lst)
{
	ofstream output(file);
	for (int i = 0; i < lst.size(); i++)
	{
		output << lst[i].name << endl;
		output << lst[i].birth.day << endl;
		output << lst[i].birth.mon << endl;
		output << lst[i].birth.yr << endl;
		output << lst[i].phone << endl;
	}
	output.close();
	cout << "База данных сохранена в файл " << file << endl;
}

void InputFromFile(vector<Human>& lst)
{
	ifstream input(file);
	if (input.is_open())
	{
		cout << "Чтение базы данных из файла " << file << endl;
		lst.clear();
		while (!input.eof())
		{
			Human elem = Human();
			getline(input, elem.name);
			input >> elem.birth.day;
			input >> elem.birth.mon;
			input >> elem.birth.yr;
			input >> elem.phone;
			input.ignore();
			lst.push_back(elem);
		}
		lst.erase(lst.end() - 1);
		cout << "База данных из файла " << file << " загружена.\n";
	}
	else
	{
		cout << "Не удалось открыть файл " << file << endl;
		return;
	}
	input.close();
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

void GetMenu()
{
	cout << "\n========================================================\n";
	cout << "| Меню управления программой\n";
	cout << "--------------------------------------------------------\n";
	cout << "| 1 - генерация массива\n";
	cout << "| 2 - поиск элемента в массиве\n";
	cout << "| 3 - добавление элемента\n";
	cout << "| 4 - удаление элемента по номеру\n";
	cout << "| 5 - удаление элемента по ФИО\n";
	cout << "| 6 - восстановление последнего удаленного элемента\n";
	cout << "| 7 - ввод из файла\n";
	cout << "| 8 - сохранение в файл\n";
	cout << "| 9 - вывод в консоль\n";
	cout << "| 0 - выход\n";
	cout << "========================================================\n";
}

int LineSearch(vector<Human> lst, string key)
{
	for (int i = 0; i < lst.size(); i++)
	{
		if (lst[i].name == key) return i;
	}
	return -1;
}

bool SubStringSearch(vector<Human> lst, string key)
{
	string names = "";

	for (int i = 0; i < lst.size(); i++)
	{
		names += lst[i].name;
	}

	for (int i = 0; i <= names.size() - key.size(); i++)
	{
		int j = 0;
		while (names[i + j] == key[j] && j < key.size()) j++;
		if (j == key.size()) return true;
	}
	return false;
}

bool BoyerMoorSearch(vector<Human> lst, string key)
{
	int stl, ctl;
	string st = "";
	for (int i = 0; i < lst.size(); i++)
	{
		st += lst[i].name;
	}
	stl = st.size();
	ctl = key.size();
	if (stl != 0 && ctl != 0 && stl >= ctl)
	{
		int i, p;
		int b[256];
		for (i = 0; i < 256; i++)
		{
			b[i] = ctl;
		}
		for (i = ctl - 2; i >= 0; i--)
		{
			if (b[int(unsigned char(key[i]))] == ctl)
			{
				b[int(unsigned char(key[i]))] = ctl - i - 1;
			}
		}
		p = ctl - 1;
		while (p < stl)
		{
			if (key[ctl - 1] != st[p])
			{
				p += b[int((unsigned char)st[p])];
			}
			else
			{
				for (i = ctl - 1; i >= 0; i--)
				{
					if (key[i] != st[p - ctl + i + 1])
					{
						p += b[int((unsigned char)st[p])];
						break;
					}
					else if (i == 0)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool KMPSearch(vector<Human> lst, string key)
{
	string names = "";
	for (int i = 0; i < lst.size(); i++)
	{
		names += lst[i].name;
	}

	vector<int> a(key.length());
	for (int j = 0, i = 1; i < key.length(); i++)
	{
		while (j > 0 && key[i] != key[j]) j = a[j - 1];
		if (key[i] == key[j]) j++;
		a[i] = j;
	}
	for (int j = 0, i = 0; i < names.length(); ++i)
	{
		while (j > 0 && key[j] != names[i]) j = a[j - 1];
		j++;
		if (j == key.length()) return true;
	}
	return false;
}

bool InterpolationSearch(vector<Human> lst, string key)
{
	vector<string> names(lst.size());
	int n;
	for (int i = 0; i < lst.size(); i++)
	{
		names[i] = lst[i].name;
	}
	for (int i = 0; i < names.size(); i++)
	{
		for (int j = i; j > 0 && names[j - 1] > names[j]; j--)
		{
			swap(names[j - 1], names[j]);
		}
	}
	int mid, left = 0, right = names.size() - 1;
	while (names[left] < key && names[right] > key)
	{
		mid = left + (key[0] - names[left][0]) * (right - left) / (names[right][0] - names[left][0]);
		if (names[mid] < key) left = mid + 1;
		else if (names[mid] > key) right = mid - 1;
	}
	if (names[left] == key)
	{
		n = left;
		return true;
	}
	if (names[right] == key)
	{
		n = right;
		return true;
	}
	return false;
}

void Search(vector<Human> lst)
{
	if (lst.empty())
	{
		cout << "Список пуст, поиск невозможен.\n";
		return;
	}

	string key;
	bool f;
	int res;

	cout << "Введите ФИО для поиска: ";
	getline(cin, key);

	cout << "Поиск элемента с именем: " << key << endl;

	cout << "\nМетод прямого поиска:\n";
	res = LineSearch(lst, key);
	if (res != -1) cout << "\tЭлемент найден. Его номер: " << res + 1 << endl;
	else cout << "\tЭлемент не найден.\n";

	cout << "\nМетод интерполяционного поиска:\n";
	f = InterpolationSearch(lst, key);
	if (f) cout << "\tЭлемент найден.\n";
	else cout << "\tЭлемент не найден.\n";

	cout << "\nМетод поиска подстроки в строке:\n";
	f = SubStringSearch(lst, key);
	if (f) cout << "\tЭлемент найден.\n";
	else cout << "\tЭлемент не найден.\n";

	cout << "\nМетод Боера Мура\n";
	f = BoyerMoorSearch(lst, key);
	if (f) cout << "\tЭлемент найден.\n";
	else cout << "\tЭлемент не найден.\n";

	cout << "\nМетод Кнутта-Морриса-Пратта\n";
	f = KMPSearch(lst, key);
	if (f) cout << "\tЭлемент найден.\n";
	else cout << "\tЭлемент не найден.\n";
}

void AddByNum(vector<Human>& lst)
{
	int n = 0;

	cout << "Добавление элемента в список... \n";
	if (!lst.empty())
	{
		cout << "Введите номер нового элемента (1-" << lst.size() + 1 << "): ";
		cin >> n;
		while (n < 1 || n > lst.size() + 1)
		{
			cout << "\nНомер введен некорректно.\n";
			cout << "Введите номер нового элемента (1-" << lst.size() + 1 << "): ";
			cin >> n;
		}
		cin.get();
		n--;
	}
	Human elem;
	cout << "Введите ФИО: ";
	getline(cin, elem.name);
	cout << "Введите дату рождения (дд мм гггг): ";
	cin >> elem.birth.day >> elem.birth.mon >> elem.birth.yr;
	cout << "Введите номер телефона (11 цифр, начиная с 7): ";
	cin >> elem.phone;
	while (elem.phone < "70000000000" || elem.phone > "79999999999")
	{
		cout << "\nНомер телефона введен некорректно.\n";
		cout << "Введите номер телефона (11 цифр, начиная с 7): ";
		cin >> elem.phone;
	}
	lst.insert(lst.begin() + n, elem);
	cout << "Добавление выполнено успешно.\n";
}

void DelByNum(vector<Human>& lst)
{
	if (lst.empty())
	{
		cout << "Список пуст. Удаление невозможно.\n";
		return;
	}

	int n;

	cout << "Удаление элемента по номеру... \n";
	cout << "Введите номер элемента для удаления (1-" << lst.size() << "): ";
	cin >> n;
	while (n < 1 || n > lst.size())
	{
		cout << "\nНомер введен некорректно.\n";
		cout << "Введите номер нового элемента (1-" << lst.size() << "): ";
		cin >> n;
	}
	n--;
	DelList.push_back(lst[n]);
	lst.erase(lst.begin() + n);
	cout << "Элемент успешно удален.\n";
}

void DelByKey(vector<Human>& lst)
{
	if (lst.empty())
	{
		cout << "Список пуст. Удаление невозможно.\n";
		return;
	}

	string dname;
	cout << "Введите ФИО элемента, который нужно удалить: ";
	getline(cin, dname);
	int n = LineSearch(lst, dname);
	if (n == -1) cout << "Элемент с таким ФИО не найден.\n";
	else
	{
		DelList.push_back(lst[n]);
		lst.erase(lst.begin() + n);
		cout << "Элемент успешно удален.\n";
	}
}

void RecoveryLast(vector<Human>& lst)
{
	if (DelList.empty())
	{
		cout << "Список на удаление пуст, восстановление невозможно.";
	}
	else
	{
		Human elem = DelList[DelList.size() - 1];
		DelList.erase(DelList.end() - 1);
		lst.push_back(elem);
		cout << "Последний удаленный элемент восстановлен.";
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251>nul");
	srand(time(NULL));

	vector<Human> data;
	int input;

	do {
		GetMenu();
		cout << "\nВыберите действие: ";
		cin >> input;
		cin.get();

		switch (input)
		{
		case 1: data = CreateArr(); cout << "\nМассив сгенерирован.\n"; break;
		case 2: Search(data); break;
		case 3: AddByNum(data); break;
		case 4: DelByNum(data); break;
		case 5: DelByKey(data); break;
		case 6: RecoveryLast(data); break;
		case 7: InputFromFile(data); break;
		case 8: OutputToFile(data); break;
		case 9: PrintArr(data); break;
		case 0: break;
		default: cout << "Ввод некорректен.\n";
		}
	} while (input != 0);
	cout << "Завершеие работы.\n";
	return 0;
}
