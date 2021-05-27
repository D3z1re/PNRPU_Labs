#pragma once
#include <iostream>
using namespace std;

template <class T>
class List
{
	int size;
	T* data;
public:
	List(int s, T k);
	List(const List<T>& a);
	~List();

	List& operator = (const List<T>& a);
	T& operator [] (int index);
	List operator + (const T k);
	List operator + (const List<T>& a);
	void push_back(T a);
	void erase(int pos);
	int operator () ();
	friend ostream& operator << <>(ostream& out, const List<T>& a);
	friend istream& operator >> <>(istream& in, List<T>& a);
};

template <class T>
List<T>::List(int s, T k)
{
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++) data[i] = k;
}
template <class T>
List<T>::List(const List& a)
{
	size = a.size;
	data = new T[size];
	for (int i = 0; i < size; i++) data[i] = a.data[i];
}
template <class T>
List<T>::~List()
{
	delete[] data;
	data = 0;
}
template <class T>
void List<T>::push_back(T a)
{
	T* old_data = data;
	data = new T[size + 1];
	for (int i = 0; i < size; i++) data[i] = old_data[i];
	data[size] = a;
	delete[] old_data;
	size++;
}
template <class T>
void List<T>::erase(int pos)
{
	T* old_data = data;
	delete data;
	data = new int[size - 1];
	for (int i = 0; i < pos; i++) data[i] = old_data[i];
	size--;
	for (int i = pos; i < size; i++) data[i] = old_data[i + 1];
	delete[] old_data;
}
template<class T>
List<T>& List<T>::operator=(const List<T>& a)
{
	if (this == &a) return *this;
	size = a.size;
	if (data != 0) delete[] data;
	data = new T[size];
	for (int i = 0; i < size; i++) data[i] = a.data[i];
	return *this;
}
template<class T>
T& List<T>::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "\nError! Index out of range.";
}
template<class T>
List<T> List<T>::operator+(const T k)
{
	List<T> temp(size, k);
	for (int i = 0; i < size; ++i) temp.data[i] = data[i] + k;
	return temp;
}
template<class T>
List<T> List<T>::operator+(const List<T>& a)
{
	int min = size < a.size ? size : a.size;
	List<T> temp(min, 0);
	for (int i = 0; i < min; i++) temp.data[i] = data[i] + a.data[i];
	return temp;
}
template<class T>
int List<T>::operator () ()
{
	return size;
}
template<class T>
ostream& operator << (ostream& out, const List<T>& a)
{
	for (int i = 0; i < a.size; ++i) out << a.data[i] << " ";
	return out;
}
template<class T>
istream& operator >> (istream& in, List<T>& a)
{
	for (int i = 0; i < a.size; ++i) in >> a.data[i];
	return in;
}
