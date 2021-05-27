#pragma once
#include "Pair.h"
#include <iostream>
using namespace std;

template <class T>
class List
{
	T* data = nullptr;
	int size;
public:
	List()
	{
		data = nullptr;
		size = 0;
	}
	List(int s)
	{
		size = s;
		data = new T[size];
	}
	List(List<T>& tmp)
	{
		if (tmp.get_size() == 0) List();
		else
		{
			size = tmp.get_size();
			data = new T[size];
			for (int i = 0; i < size; i++)
			{
				data[i] = tmp[i];
			}
		}
	}
	~List()
	{
		delete[] data;
		data = nullptr;
		size = 0;
	}
	
	int get_size() { return size; }

	bool empty() { return size == 0; }

	void push_back(T elem)
	{
		T* tmp = new T[size + 1];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = data[i];
		}
		tmp[size] = elem;
		size++;
		delete[] data;
		data = tmp;
		tmp = nullptr;
	}
	void pop_back()
	{
		if (empty()) return;
		T* tmp = new T[size - 1];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = data[i];
		}
		delete[] data;
		data = tmp;
		size--;
		tmp = nullptr;
	}
	void erase(int index)
	{
		if (empty()) return;
		T* tmp = new T[size - 1];
		for (int i = 0; i < index; i++)
		{
			tmp[i] = data[i];
		}
		for (int i = index; i < size - 1; i++)
		{
			tmp[i] = data[i + 1];
		}
		delete[] data;
		data = tmp;
		size--;
		tmp = nullptr;
	}

	T& operator[](int index) { return data[index]; }

	List<T>& operator=(List<T>& tmp)
	{
		delete[] data;
		size = tmp.get_size();
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = tmp[i];
		}
		return *this;
	}

	List<T>& operator+(List<T>& tmp)
	{
		if (empty() || tmp.empty()) return *this;
		if (size > tmp.get_size())
		{
			for (int i = 0; i < tmp.get_size(); i++)
			{
				data[i] = data[i] + tmp[i];
			}
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				data[i] = data[i] + tmp[i];
			}
		}
		return *this;
	}
	List<T>& operator+(T tmp)
	{
		if (empty()) return *this;
		for (int i = 0; i < size; i++)
		{
			data[i] = data[i] + tmp;
		}
		return *this;
	}

	friend istream& operator>> <>(istream& in, List<T>& tmp);
	friend ostream& operator<< <>(ostream& out, List<T>& tmp);
};

template <class T>
istream& operator>>(istream& in, List<T>& tmp)
{
	for (int i = 0; i < tmp.get_size(); i++)
	{
		cout << "Введите " << i + 1 << " элемент спика: ";
		in >> tmp.data[i];
	}
	return in;
}

template <class T>
ostream& operator<<(ostream& out, List<T>& tmp)
{
	for (int i = 0; i < tmp.get_size(); i++) out << tmp.data[i] << "\n";
	return out;
}