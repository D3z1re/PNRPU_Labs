#pragma once
#include <vector>
using namespace std;

template<typename T>
class Stack
{
	vector<T> values;
public:
	Stack() {}
	Stack(int size);
	T top();
	void push(T& elem);
	void pop();
	bool empty();
	int size();
};
