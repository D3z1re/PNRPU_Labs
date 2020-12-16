#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

void insert_sorting(int* a, int n) {
    int tmp;
    int j;
    for (int i = 0; i < n; i++) {
        tmp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > tmp) {
            a[j + 1] = a[j];
            a[j] = tmp;
            j--;
        }
    }
}

void selection_sorting(int* a, int n) {
    int tmp; int m;

    for (int i = 0; i < n; i++) {
        m = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[m]) m = j;
        }
        tmp = a[i];
        a[i] = a[m];
        a[m] = tmp;
    }
}

void bubble_sorting(int* a, int n) {
    int tmp;
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= (i + 1); j--) {
            if (a[j] < a[j - 1]) {
                tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    srand(time(NULL));
    int num;

    cout << "\nВведите длину массива: ";
    cin >> num; // получение от пользователя размера массива
    while (num <= 0) {
        cout << "\nДлина массива должна быть больше 0";
        cout << "\nВведите длину массива: ";
        cin >> num;
    }
    int* arr = new int[num]; // Выделение памяти для массива
    int* p_arr = arr;

    cout << "\nСортировка методом вставки";
    cout << "\nСгенерированный массив: \n\t";
    for (; p_arr != (arr + num); p_arr++) {
        // Заполнение массива и вывод значений его элементов
        *p_arr = rand() % 100;
        cout << *p_arr << " ";
    }

    insert_sorting(arr, num);

    cout << "\nОтсортированный массив: \n\t";
    for (p_arr = arr; p_arr != (arr + num); p_arr++) {
        // Заполнение массива и вывод значений его элементов
        cout << *p_arr << " ";
    }

    cout << "\n\nСортировка методом выбора";
    cout << "\nСгенерированный массив: \n\t";
    for (p_arr = arr; p_arr != (arr + num); p_arr++) {
        // Заполнение массива и вывод значений его элементов
        *p_arr = rand() % 100;
        cout << *p_arr << " ";
    }

    selection_sorting(arr, num);

    cout << "\nОтсортированный массив: \n\t";
    for (p_arr = arr; p_arr != (arr + num); p_arr++) {
        // Заполнение массива и вывод значений его элементов
        cout << *p_arr << " ";
    }

    cout << "\n\nСортировка методом обмена";
    cout << "\nСгенерированный массив: \n\t";
    for (p_arr = arr; p_arr != (arr + num); p_arr++) {
        // Заполнение массива и вывод значений его элементов
        *p_arr = rand() % 100;
        cout << *p_arr << " ";
    }

    bubble_sorting(arr, num);

    cout << "\nОтсортированный массив: \n\t";
    for (p_arr = arr; p_arr != (arr + num); p_arr++) {
        // Заполнение массива и вывод значений его элементов
        cout << *p_arr << " ";
    }
    cout << "\n\n";

    delete[] arr;

    system("pause");

    return 0;
}
