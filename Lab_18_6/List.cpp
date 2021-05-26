#pragma once
#include "List.h"

List::List(int s, int k)
{
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++) data[i] = k;
	_begin.elem = &data[0];
	_end.elem = &data[size];
}

List::List(const List& a)
{
	size = a.size;
	data = new int[size];
	for (int i = 0; i < size; i++) data[i] = a.data[i];
	_begin.elem = &data[0];
	_end.elem = &data[size];
}

List::~List()
{
	delete[] data;
	data = 0;
}

List& List::operator=(const List& a)
{
	if (this == &a) return *this;
	size = a.size;
	if (data != 0) delete[] data;
	data = new int[size];
	for (int i = 0; i < size; i++) data[i] = a.data[i];
	_begin.elem = &data[0];
	_end.elem = &data[size];
	return *this;
}

int& List::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "\nError! Index out of range.";
}

List List::operator+(const int k)
{
	List temp(size);
	for (int i = 0; i < size; ++i) temp.data[i] += data[i] + k;
	return temp;
}

List List::operator+(const List& a)
{
	int min = size < a.size ? size : a.size;
	List temp(min);
	for (int i = 0; i < min; i++) temp.data[i] = data[i] + a.data[i];
	return temp;
}

int List::operator () ()
{
	return size;
}

ostream& operator<<(ostream& out, List& a)
{
	for (int i = 0; i < a(); ++i) out << a.data[i] << " ";
	return out;
}

istream& operator>>(istream& in, List& a)
{
	for (int i = 0; i < a(); ++i) in >> a.data[i];
	return in;
}