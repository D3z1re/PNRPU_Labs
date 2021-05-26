#pragma once
#include <iostream>
#include "Object.h"
using namespace std;

class Vector
{
	Object** begin_p = nullptr;
	int len = 0;
public:
	Vector(int size)
	{
		begin_p = new Object * [size];
		len = size;
	}
	Vector(Vector& tmp)
	{
		if (begin_p != nullptr) delete[] begin_p;
		else
		{
			int size = tmp.size();
			begin_p = new Object * [size];
			for (int i = 0; i < size; i++)
			{
				begin_p[i] = tmp.begin_p[i];
			}
		}
	}

	~Vector()
	{
		if (begin_p != nullprt)
		{
			delete[] begin_p;
			begin_p = nullptr;
		}
	}

	int size() { return len; }
	void push_back(Object* a)
	{
		Object** tmp = new Object * [len + 1];
		for (int i = 0; i < len; i++)
		{
			tmp[i] = begin_p[i];
		}
		tmp[len] = a;
		delete[] begin_p;
		begin_p = tmp;
		len++;

		tmp = nullptr;
	}

	friend ostream& operator << (osream& out, Vector& lst);
};

osream& operator << (ostream& out, Vecotor& lst)
{
	if (lst.len == 0) return out << "Список пуст\n";
	Object** tmp = lst.begin_p;
	for (int i = 0; i < lst.len; i++)
	{
		out << "Элемент " << (i + 1) << endl;
		(*tmp)->Show();
		tmp++;
	}
	return out;
}