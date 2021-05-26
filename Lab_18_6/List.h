#pragma once
#include <iostream>
using namespace std;

class Iterator
{
	friend class List;
	int* elem;
public:
	Iterator() { elem = 0; }
	Iterator(const Iterator& a) { elem = a.elem; }

	bool operator == (const Iterator& a) { return elem == a.elem; }
	bool operator != (const Iterator& a) { return elem != a.elem; }
	void operator ++ () { ++elem; }
	void operator ++ (int) { elem++; }
	void operator -- () { --elem; }
	void operator -- (int) { elem--; }
	void operator + (const int k) { elem += k; }
	void operator - (const int k) { elem -= k; }
	int& operator * () { return *elem; }
};

class List
{
	int* data;
	int size;
	Iterator _begin;
	Iterator _end;
public:
	List(int s, int k = 0);
	List(const List& a);
	~List();

	List& operator = (const List& a);
	int& operator [] (int index);
	List operator + (const int k);
	List operator + (const List& a);
	int operator () ();

	friend ostream& operator << (ostream& out, List& a);
	friend istream& operator >> (istream& in, List& a);

	Iterator first() { return _begin; }
	Iterator last() { return _end; }
};