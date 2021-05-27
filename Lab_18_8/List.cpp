#include "List.h"
#include "Person.h"
#include "Abiturient.h"
#include <iostream>
using namespace std;

List::~List(void)
{
	if (beg != 0) delete[] beg;
	beg = 0;
}
List::List()
{
	beg = 0;
	size = 0;
	cur = 0;
}
List::List(int n)
{
	size = n;
	beg = new Object * [size];
	cur = 0;
}
void List::Add()
{
	if (size == 0)
	{
		cout << "Please make a List First\n";
		return;
	}
	if (size == cur)
	{
		cout << "List is full\n";
		return;
	}
	Object* p;

	cout << "1. Person" << endl;
	cout << "2. Abiturient" << endl;
	int y;
	cout << "Choice: "; cin >> y;
	if (y == 1)
	{
		Person* a = new Person;
		a->Input();
		p = a;

		if (cur < size)
		{
			beg[cur] = p;
			cur++;
		}
	}
	else if (y == 2)
	{
		Abiturient* b = new Abiturient;
		b->Input();
		p = b;
		if (cur < size)
		{
			beg[cur] = p;
			cur++;
		}
	}
	else return;
}
void List::Show()
{
	if (cur == 0) cout << "Empty" << endl;
	else
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->Show();
			p++;
		}
	}
	
}
void List::ShowMidAge()
{
	if (cur == 0) 
	{ 
		cout << "List is empty" << endl; 
		return; 
	}
	else
	{
		int res = 0;
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			res = res + (*p)->Get_Age();
			p++;
		}
		res /= cur;
		cout << "Middle age: " << res << endl;
		return;
	}
}
int List::operator() ()
{
	return cur;
}
void List::Del()
{
	if (cur == 0) 
	{
		cout << "List is empty already.\n";
		return;
	} 
	cur--;
}
void List::HandleEvent(TEvent& event)
{
	if (event.what = evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(event);
			p++;
		}
	}
}