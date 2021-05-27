#pragma once
#include "Object.h"
#include "Event.h"
class List
{
protected:
	Object** beg;
	int size;
	int cur;
public:
	List();
	List(int);
	~List(void);
	void Add();
	void Del();
	void Show();
	void ShowMidAge();
	void HandleEvent(TEvent& event);
	int operator() ();
};
