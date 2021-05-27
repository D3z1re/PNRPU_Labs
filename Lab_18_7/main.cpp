#include <iostream>
#include <ctime>
#include "List.h"
#include "Pair.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));

    List<int> lst_1(10);
    cout << "Ввод списка 1: \n";
    cin >> lst_1;
    cout << "Вывод списка 1: \n";
    cout << lst_1;
    List<int> lst_2;
    lst_2 = lst_1 + 5;
    cout << "Вывод списка 2(список 1 + 5): \n";
    cout << lst_2;
    List<int> lst_3;
    lst_3 = lst_1 + lst_2;
    cout << "Вывод списка 3(список 1 + список 2): \n";
    cout << lst_3;

    List<Pair> lst_4(3);
    cout << "Ввод списка Pair: \n";
    cin >> lst_4;
    cout << "Вывод списка Pair: \n";
    cout << lst_4;
}