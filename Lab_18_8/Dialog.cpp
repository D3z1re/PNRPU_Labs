#include "Dialog.h"
#include "Event.h"
#include <iostream>
#include <string>
using namespace std;

Dialog::Dialog(void):List()
{
	EndState = 0;
}
Dialog::~Dialog(void)
{}
void Dialog::GetEvent(TEvent& event)
{
	string OpInt = "+-/mszq";
	string s;
	cout << ">";
	getline(cin, s);

	if (OpInt.find(s[0]) != -1)
	{
		event.what = evMessage;
		switch (s[0])
		{
		case 'm': event.command = cmMake; break;
		case '+': event.command = cmAdd; break;
		case '-': event.command = cmDel; break;
		case 's': event.command = cmShow; break;
		case '/': event.command = cmName; break;
		case 'z': event.command = cmAge; break;
		case 'q': event.command = cmQuit; break;
		}
		if (s.length() > 1)
		{
			string param = s.substr(1, s.length() - 1);
			event.a = atoi(param.c_str());
		}
	}
	else event.what = evNothing;
}

void Dialog::Execute()
{
	TEvent event;
	do {
		GetEvent(event);
		HandleEvent(event);
		if (event.what != evNothing) ClearEvent(event);
	} while (EndState == 0);
}

void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;
}

void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake: {
			size = event.a;
			beg = new Object * [size];
			cur = 0;
			ClearEvent(event);
			break;
		}
		case cmAdd: {
			Add();
			ClearEvent(event);
			break;
		}
		case cmDel: {
			Del();
			ClearEvent(event);
			break;
		}
		case cmShow: {
			Show();
			ClearEvent(event);
			break;
		}
		case cmAge: {
			ShowMidAge();
			break;
		}
		case cmQuit: {
			EndState = 1;
			ClearEvent(event);
			break;
		}
		default: List::HandleEvent(event);
		}
	}
}