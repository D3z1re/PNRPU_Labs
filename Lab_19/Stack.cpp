#include "Stack.h"

template <typename T>
Stack<T>::Stack(int size)
{
	for (int i = 0; i < size; i++)
	{
		values.push_back(0);
	}
}

template <typename T>
T Stack<T>::top()
{
	if (values.size() == 0) throw ("Stack is empty");
	return values[values.size() - 1];
}

template <typename T>
void Stack<T>::push(T& elem)
{
	values.push_back(elem);
}

template <typename T>
void Stack<T>::pop()
{
	if (values.size() == 0) throw ("Stack is empty");
	values.pop_back();
}

template <typename T>
int Stack<T>::size()
{
	return values.size();
}
