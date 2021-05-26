#include <iostream>
#include <ctime>
using namespace std;

struct Queue
{
	char* data;
	Queue* next;
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

Queue* make(int n, Queue*& first, Queue*& last)
{
	if (n == 0) return NULL;
	Queue* p = new Queue;
	p->data = generate_string();
	p->next = NULL;
	first = p;
	last = p;
	for (int i = 1; i < n; i++)
	{
		Queue* h = new Queue;
		h->data = generate_string();
		h->next = p;
		last = h;
		p = last;
	}
	return first;
}

void print_queue(Queue* last, int size)
{
	Queue* p = last;
	int k = size;
	while (p != NULL)
	{
		int i = 0;
		cout << k << ".\t";
		while (p->data[i])
		{
			cout << p->data[i];
			i++;
		}
		cout << endl;
		k--;
		p = p->next;
	}
	cout << endl;
}

char* pop(Queue*& first, Queue*& last)
{
	Queue* p = last;
	int k = 0;
	while (p != NULL)
	{
		p = p->next;
		k++;
	}
	p = last;
	if (k == 1)
	{
		char* str = last->data;
		delete p;
		last = NULL;
		first = NULL;
		return str;
	}
	else
	{
		while (p->next->next != NULL)
		{
			p = p->next;
		}
		Queue* t = p;
		char* str = p->next->data;
		p = p->next;
		t->next = NULL;
		first = t;
		delete p;
		return str;
	}
}

Queue* push(char* n, Queue*& last)
{
	Queue* p = new Queue;
	p->data = n;
	p->next = last;
	last = p;
	return last;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, pos;
	Queue* first, * last;
	cout << "Введите количество элементов очереди (1-100): ";
	cin >> n;
	while (n < 1 || n > 99)
	{
		cout << "\nКоличество введено некорректно.\n";
		cout << "Введите количество элементов (1-100): ";
		cin >> n;
	}
	make(n, first, last);
	cout << "\nСгенерированная очередь:\n";
	print_queue(last, n);

	cout << "Введите номер, после которого нужно добавить элемент (1-" << n << "): ";
	cin >> pos;
	while (pos < 1 || pos > n)
	{
		cout << "\nНомер введен некорректно.\n";
		cout << "Введите номер, после которого нужно добавить элемент (1-" << n << "): ";
		cin >> pos;
	}
	char** mas = new char* [n];

	for (int i = 0; i < n; i++)
	{
		mas[i] = pop(first, last);
	}
	for (int i = 0; i < pos; i++)
	{
		push(mas[i], last);
	}
	char* tmp = generate_string();
	push(tmp, last);
	for (int i = pos; i < n; i++)
	{
		push(mas[i], last);
	}
	n++;
	cout << "\nОчередь после добавления:\n";
	print_queue(last, n);

	return 0;
}
