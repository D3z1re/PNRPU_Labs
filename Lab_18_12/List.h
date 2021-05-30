#pragma once
#include <iostream>
#include <set>
using namespace std;

template <class T>
class List
{
	int size;
	set<T> data;

public:
	List(int s);
	List(const List<T>& a);
	~List();

	List& operator = (const List<T>& a);
	T& operator [] (int index);
	List operator + (const T k);
	List operator + (const List<T>& a);
	void push_back(T a);
	void erase(int pos);
	int operator () ();
	void Fill();
	void Show();
	void Delete_task(T left, T right);
	void Add_Average();
	//friend ostream& operator << <>(ostream& out, const List<T>& a);
	//friend istream& operator >> <>(istream& in, List<T>& a);
};

template <class T>
List<T>::List(int s)
{
	size = s;
}
template <class T>
List<T>::List(const List& a)
{
	size = a.size;
	data = a.data;
}
template <class T>
List<T>::~List()
{
}
template <class T>
void List<T>::push_back(T a)
{
	data.insert(a);
	size++;
}
template <class T>
void List<T>::erase(int pos)
{
	set<double>::iterator iter = data.begin();
	//iterator iter = data.begin();
	for (int i; i < pos; i++) iter++;
	data.erase(iter);
	size--;
}
template<class T>
List<T>& List<T>::operator=(const List<T>& a)
{
	if (this == &a) return *this;
	size = a.size;
	data = a.data;
	return *this;
}
template<class T>
T& List<T>::operator[](int index)
{
	
	if (index < size) {
		set<double>::iterator iter = data.begin();
		//iterator iter = data.begin();
		for (int i = 0; i < index; i++) iter++;
		double tmp = *iter;
		return tmp;
	}
	else cout << "\nError! Index out of range.";
}
template<class T>
List<T> List<T>::operator+(const T k)
{
	List<T> temp(size);
	set<T> temp_set;
	for (int i = 0; i < size; ++i) temp_set.insert((*this)[i] + k);
	temp.data = temp_set;
	return temp;
}
template<class T>
List<T> List<T>::operator+(const List<T>& a)
{
	int min = size < a.size ? size : a.size;
	List<T> temp(min, 0);
	set<T> temp_set;
	for (int i = 0; i < min; i++) temp_set.insert(data[i] + a.data[i]);
	temp.data = temp_set;
	return temp;
}
template<class T>
int List<T>::operator () ()
{
	return size;
}
template<class T>
void List<T>::Show()
{
	set<double>::iterator iter = data.begin();
	while (iter != data.end())
	{
		cout << (*iter) << " ";
		iter++;
	}
	//for (; iter != data.end(); iter++) cout << (*iter) << " ";
}
template<class T>
void List<T>::Fill()
{
	data.clear();
	T tmp;
	for (int i = 0; i < size; ++i) { cin >> tmp; data.insert(tmp); }
}
template<class T>
void List<T>::Delete_task(T left, T right)
{
	set<double>::iterator iter = data.begin();
	vector<set<double>::iterator> iters;
	int count = 0;
	while (iter != data.end())
	{
		if (*iter <= right && *iter >= left) { count++; iters.push_back(iter); }
		iter++;
	}
	cout << "Ёлементов к удалению: " << count << endl;
	for (int i = 0; i < count; i++)
	{
		data.erase(iters[i]);
		size--;
	}
}
template<class T>
void List<T>::Add_Average()
{
	double avg = 0;
	for (int i = 0; i < size; i++)
	{
		avg += (*this)[i];
	}
	avg /= size;
	set<T> tmp;
	for (int i = 0; i < size; i++)
	{
		tmp.insert(((*this)[i] + avg));
	}
	data = tmp;
}