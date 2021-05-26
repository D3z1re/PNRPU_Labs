#include <iostream>
#include <ctime>
using namespace std;

struct ListOfChar
{
	char* data;
	ListOfChar* next;
	ListOfChar* prev;
};

char* generate_string()
{
	int len = rand() % 30 + 1;
	char* a = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		a[i] = rand() % 57 + 65;
	}
	a[len] = '\0';

	return a;
}

ListOfChar* make(int size)
{
	ListOfChar* first, * p;
	first = NULL;
	p = new ListOfChar;
	p->data = generate_string();
	first = p;
	for (int i = 1; i < size; i++)
	{
		ListOfChar* h = new ListOfChar;
		ListOfChar* q = p;
		p->next = h;
		p = p->next;
		p->data = generate_string();
		p->next = NULL;
		p->prev = q;
	}
	return first;
}

void print_list(ListOfChar* first)
{
	if (first == NULL) cout << "Список пустой\n";
	else
	{
		ListOfChar* p = first;
		int row = 1;
		while (p != NULL)
		{
			int k = 0;
			cout << row << ".\t";
			while (p->data[k])
			{
				cout << p->data[k];
				k++;
			}
			row++;
			cout << '\n';
			p = p->next;
		}
		cout << '\n';
	}
}

void delete_list(ListOfChar* head)
{
	if (head != NULL)
	{
		delete_list(head->next);
		delete head;
	}
}

void append_to_list(ListOfChar*& first, int size)
{
	int pos, k = 1;
	ListOfChar* p = first;
	cout << "Введите номер строки для добавления (1-" << size + 1 << "): ";
	cin >> pos;
	while (pos < 1 || pos > (size + 1))
	{
		cout << "Номер введен некорректно.\n";
		cout << "\nВведите номер строки для добавления (1-" << size + 1 << "): ";
		cin >> pos;
	}
	if (pos == 1)
	{
		ListOfChar* h = new ListOfChar;
		h->data = generate_string();
		h->prev = NULL;
		h->next = p;
		first = h;
	}
	else
	{ 
		while (k < (pos - 1))
		{
			p = p->next;
			k++;
		}
		ListOfChar* h = new ListOfChar;
		h->data = generate_string();
		h->prev = p;
		if (p->next != NULL)
		{
			h->next = p->next;
			p->next = h;
		}
		else
		{
			p->next = h;
			h->next = NULL;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int n;

	cout << "Введите количество элементов списка (3-100): ";
	cin >> n;
	while (n < 3 || n > 99) {
		cout << "Количество введено некорректно.\n";
		cout << "\nВведите количество элементов списка (3-100): ";
		cin >> n;
	}

	ListOfChar* list = make(n);
	cout << "\nСгенерированный список: \n";
	print_list(list);

	append_to_list(list, n);

	cout << "\nНовый список: \n";
	print_list(list);

	delete_list(list);

	return 0;
}
