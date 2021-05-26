#include <iostream>
#include <ctime>
using namespace std;

struct ListOfInt
{
	int data;
	ListOfInt* next;
};

void print_list(ListOfInt* first)
{
	if (first == NULL) cout << "Список пустой.\n";
	else
	{
		ListOfInt* p = first;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << '\n';
	}

}

ListOfInt* make(int size)
{
	ListOfInt* first, * p;
	first = NULL;
	p = new ListOfInt;
	p->data = rand() % 100 + 1;
	first = p;
	for (int i = 1; i < size; i++)
	{
		ListOfInt* h = new ListOfInt;
		p->next = h;
		p = p->next;
		p->data = rand() % 100 + 1;
		p->next = NULL;
	}
	return first;
}

void delete_even(ListOfInt*& first)
{
	ListOfInt* p = first;
	while (p->data % 2 == 0)
	{
		ListOfInt* q = p;
		p = p->next;
		delete q;
		first = p;
	}
	while (p->next != NULL)
	{
		if (p->next->data % 2 == 0)
		{
			ListOfInt* q = p->next;
			p->next = p->next->next;
			delete q;
		}
		else p = p->next;
	}
}

void delete_list(ListOfInt* head)
{
	if (head != NULL)
	{
		delete_list(head->next);
		delete head;
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

	ListOfInt* list = make(n);
	cout << "Сгенерированный список: \n";
	print_list(list);
	cout << "\nУдаление из списка всех четных элементов...\n\n";
	delete_even(list);
	cout << "Новый список: \n";
	print_list(list);

	delete_list(list);

	return 0;
}