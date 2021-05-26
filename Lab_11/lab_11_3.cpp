#include <iostream>
#include <ctime>
using namespace std;

struct Stack
{
	int data;
	Stack* prev;
};

Stack* make(int n)
{
	if (n == 0) return NULL;
	Stack* top, * p;
	top = NULL;
	p = new Stack;
	p->data = rand() % 100 + 1;
	p->prev = NULL;
	top = p;
	for (int i = 1; i < n; i++)
	{
		Stack* h = new Stack;
		h->data = rand() % 100 + 1;
		h->prev = top;
		top = h;
	}
	return top;
}

void print_stack(Stack* top)
{
	if (top == NULL)
	{
		cout << "Стек пуст\n";
	}
	else
	{
		Stack* p = top;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->prev;
		}
	}
	cout << endl;
}

int pop(Stack*& top)
{
	Stack* p = top;
	int k = 0;
	while (p != NULL)
	{
		k++;
		p = p->prev;
	}
	p = top;
	if (k == 1)
	{
		int x = top->data;
		delete p;
		top = NULL;
		return x;
	}
	else
	{
		Stack* t = p->prev;
		int x = p->data;
		top = t;
		delete p;
		return x;
	}
}

Stack* push(Stack*& top, int value)
{
	Stack* p = new Stack;
	p->data = value;
	p->prev = top;
	top = p;
	return top;
}

void delete_even(Stack*& top, int& size)
{
	int k = 0;
	Stack* new_stack = make(0);
	for (int i = 0; i < size; i++)
	{
		int tmp = pop(top);
		if (tmp % 2 != 0) push(new_stack, tmp);
		else k++;
	}
	size = size - k;
	for (int i = 0; i < size; i++)
	{
		int tmp = pop(new_stack);
		push(top, tmp);
	}
}

void clear_stack(Stack*& top)
{
	Stack* p = top;
	while (p != NULL)
	{
		p = top->prev;
		delete top;
		top = p;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int n, k = 0;
	cout << "Введите количество элементов стека (1-100): ";
	cin >> n;
	while (n < 1 || n > 99)
	{
		cout << "\nКоличество введено неверно.\n";
		cout << "Введите количество элементов стека (1-100): ";
		cin >> n;
	}
	Stack* a = make(n);
	cout << "\nСгенерированный стек: \n";
	print_stack(a);
	cout << "\nУдаление четных элементов из стека...\n";
	delete_even(a, n);
	cout << "\nСтек после удаления: \n";
	print_stack(a);
	clear_stack(a);
	delete a;
}
