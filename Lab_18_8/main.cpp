#include "Object.h"
#include "Person.h"
#include "Abiturient.h"
#include "List.h"
#include "Dialog.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Commands: \n";
	cout << "| m [size] - make List\n";
	cout << "| + - add element\n";
	cout << "| - - remove element\n";
	cout << "| s - show List\n";
	cout << "| z - show middle age\n";
	cout << "| q - quit\n";
	cout << "----------------------------------\n";
	Dialog D;
	D.Execute();

	return 0;
}
