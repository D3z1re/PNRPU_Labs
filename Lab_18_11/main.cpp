#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include "Pair.h"
#include "List.h"
using namespace std;

template <typename T>
void Print_Deque(deque<T> tmp)
{
	for (int i = 0; i < tmp.size(); i++) cout << tmp[i] << " ";
	cout << endl;
}
template <typename T>
deque<T> Delete_Deque(deque<T> a, T left, T right)
{
	deque<T> temp;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] < left || a[i] > right) temp.push_back(a[i]);
	}
	return temp;
}
//template <typename T>
//List<T> Delete_List(List<T> a, T left, T right)
//{
//	int count = 0;
//	for (int i = 0; i < a(); i++)
//	{
//		if (a[i] > left || a[i] < right) {
//			a[i] = -1;
//			count++;
//		}
//	}
//	List<T> temp(size - count, 0);
//	int i = 0;
//	for (int j = 0; j < a(); j++)
//	{
//		if (a[j] != -1) {
//			temp[i] = a[j];
//			i++;
//		}
//	}
//	return temp;
//}
template <typename T>
deque<T> Add_Middle_Deque(deque<T> a)
{
	deque<T> tmp = a;
	T middle = a[0];
	for (int i = 1; i < tmp.size(); i++) middle += tmp[i];
	middle /= tmp.size();
	for (int i = 0; i < tmp.size(); i++) tmp[i] += middle;
	return tmp;
}
template<typename T> 
deque<T> Add_Max_Deque(deque<T> a)
{
	deque<T> tmp = a;
	T max = tmp[0];
	for (int i = 0; i < tmp.size(); i++)
	{
		if (tmp[i] > max) max = tmp[i];
	}
	tmp.push_back(max);
	return tmp;
}

template<typename T>
void Print_Stack(stack<T> a)
{
	stack<T> temp = a;
	while (!temp.empty())
	{
		cout << temp.top() << " ";
		temp.pop();
	}
	cout << endl;
}

void Task1()
{
	deque<double> temp;
	int size;
	cout << "Введите размер очереди (1-100): "; cin >> size;
	while (size < 1 || size > 100)
	{
		cout << "Ввод некорректен!\n";
		cout << "Введите размер очереди (1-100): "; cin >> size;
	}
	for (int i = 0; i < size; i++)
	{
		temp.push_back(rand() % 10000 / 100.0);
	}
	cout << "Сгенерированная очередь: \n";
	Print_Deque(temp);
	
	cout << "\nДобавление максимума в конец очереди\n";
	temp = Add_Max_Deque(temp);
	cout << "Очередь после добавления максимального числа в конец:\n";
	Print_Deque(temp);

	cout << "\nУдаление из очереди чисел в заданном диапазоне\n";
	double min, max;
	cout << "Введите левую границу диапазона: "; cin >> min;
	cout << "Введите правую границу диапазона: "; cin >> max;
	cout << "Удаление из очереди элементов в диапазоне [" << min << ";" << max << "]\n";
	temp = Delete_Deque(temp, min, max);
	cout << "Очередь после удаления:\n";
	Print_Deque(temp);
	cout << "\nДобавление среднего арифметического к каждому элементу очереди:\n";
	temp = Add_Middle_Deque(temp);
	cout << "Очередь после добавления:\n";
	Print_Deque(temp);
}

void Task2()
{
	Pair a;
	int size;
	deque<Pair> deq;
	cout << "Введите размер очереди (1-100): "; cin >> size;
	while (size < 1 || size > 100)
	{
		cout << "Ввод некорректен!\n";
		cout << "Введите размер очереди (1-100): "; cin >> size;
	}
	for (int i = 0; i < size; i++)
	{
		cout << "Пара " << i + 1 << ":\n";
		Pair tmp;
		cin >> tmp;
		deq.push_back(tmp);
	}
	cout << "Полученная очередь: \n";
	Print_Deque(deq);

	cout << "\nДобавление максимума в конец очереди\n";
	deq = Add_Max_Deque(deq);
	cout << "Очередь после добавления максимального числа в конец:\n";
	Print_Deque(deq);

	cout << "\nУдаление из очереди чисел в заданном диапазоне\n";
	Pair min, max;
	cout << "Введите левую границу диапазона: \n"; cin >> min;
	cout << "Введите правую границу диапазона: \n"; cin >> max;
	cout << "Удаление из очереди элементов в диапазоне [" << min << ";" << max << "]\n";
	deq = Delete_Deque(deq, min, max);
	cout << "Очередь после удаления:\n";
	Print_Deque(deq);

	cout << "\nДобавление среднего арифметического к каждому элементу очереди:\n";
	deq = Add_Middle_Deque(deq);
	cout << "Очередь после добавления:\n";
	Print_Deque(deq);
}

void Task3()
{
	int size;
	cout << "Введите размер списка (1-100): "; cin >> size;
	while (size < 1 || size > 100)
	{
		cout << "Ввод некорректен!\n";
		cout << "Введите размер списка (1-100): "; cin >> size;
	}

	List<double> lst(size, 0);
	for (int i = 0; i < size; i++) lst[i] = rand() % 10000 / 100.0;
	cout << "Сгенерированный список: \n";
	cout << lst << endl;

	cout << "\nДобавление максимума в конец списка\n";
	double max = lst[0];
	for (int i = 1; i < lst(); i++) if (lst[i] > max) max = lst[i];
	lst.push_back(max);
	cout << "Полученный список: \n";
	cout << lst << endl;

	cout << "\nУдаление из списка чисел в заданном диапазоне\n";
	double min;
	cout << "Введите левую границу диапазона: \n"; cin >> min;
	cout << "Введите правую границу диапазона: \n"; cin >> max;
	cout << "Удаление из очереди элементов в диапазоне [" << min << ";" << max << "]\n";
	/*for (int i = 0; i < lst(); i++)
	{
		if (lst[i] > min || lst[i] < max) lst.erase(i);
	}*/
	//lst = Delete_List(lst, min, max);
	int count = 0;
	for (int i = 0; i < lst(); i++)
	{
		if (lst[i] > min && lst[i] < max) {
			lst[i] = -1;
			count++;
		}
	}
	List<double> temp(lst() - count, 0);
	int i = 0;
	for (int j = 0; j < lst(); j++)
	{
		if (lst[j] != -1) {
			temp[i] = lst[j];
			i++;
		}
	}
	lst = temp;
	cout << "Полученный список: \n";
	cout << lst << endl;

	cout << "\nДобавление среднего арифметического к каждому элементу очереди:\n";
	double middle = 0;
	for (int i = 0; i < lst(); i++) middle += lst[i];
	middle /= lst();
	for (int i = 0; i < lst(); i++) lst[i] += middle;
	cout << "Полученный список: \n";
	cout << lst << endl;
}

//void Task41()
//{
//	int size;
//	cout << "Введите размер очереди (1-100): "; cin >> size;
//	while (size < 1 || size > 100)
//	{
//		cout << "Ввод некорректен!\n";
//		cout << "Введите размер очереди (1-100): "; cin >> size;
//	}
//	queue<double> qu;
//	queue<double> tmp;
//	for (int i = 0; i < size; i++) qu.push(rand() % 10000 / 100.0);
//	cout << "Сгенерированная очередь: \n";
//	Print_Queue(qu);
//
//	cout << "\nДобавление максимума в конец очереди\n";
//	tmp = qu;
//	double max = 0;
//	for (int i = 0; i < size; i++)
//	{
//		if (tmp.front() > max) max = tmp.front();
//		tmp.pop();
//	}
//	qu.push(max); size++;
//	cout << "Полученная очередь: \n";
//	Print_Queue(qu);
//
//	cout << "\nУдаление из очереди чисел в заданном диапазоне\n";
//	double min;
//	cout << "Введите левую границу диапазона: "; cin >> min;
//	cout << "Введите правую границу диапазона: "; cin >> max;
//	cout << "Удаление из очереди элементов в диапазоне [" << min << ";" << max << "]\n";
//	int count = 0;
//	for (int i = 0; i < size; i++)
//	{
//		if (qu.front() < min || qu.front() > max)
//		{
//			count++;
//			tmp.push(qu.front());
//		}
//		qu.pop();
//	}
//	size = count;
//	for (int i = 0; i < size; i++)
//	{
//		qu.push(tmp.front());
//		tmp.pop();
//	}
//	cout << "Полученная очередь: \n";
//	Print_Queue(qu);
//
//	cout << "\nДобавление среднего арифметического к каждому элементу очереди:\n";
//	double middle = 0;
//	for (int i = 0; i < size; i++)
//	{
//		middle += qu.front();
//		tmp.push(qu.front());
//		qu.pop();
//	}
//	middle /= size;
//	for (int i = 0; i < size; i++)
//	{
//		qu.push(tmp.front() + middle);
//		tmp.pop();
//	}
//	cout << "Полученная очередь: \n";
//	Print_Queue(qu);
//}

void Task4()
{
	int size;
	cout << "Введите размер стека (1-100): "; cin >> size;
	while (size < 1 || size > 100)
	{
		cout << "Ввод некорректен!\n";
		cout << "Введите размер стека (1-100): "; cin >> size;
	}
	stack<double> st;
	stack<double> tmp;
	for (int i = 0; i < size; i++) st.push(rand() % 10000 / 100.0);
	cout << "Сгенерированный стек: \n";
	Print_Stack(st);

	cout << "\nДобавление максимума в конец стека\n";
	tmp = st;
	double max = 0;
	for (int i = 0; i < size; i++)
	{
		if (tmp.top() > max) max = tmp.top();
		tmp.pop();
	}
	for (int i = 0; i < size; i++)
	{
		tmp.push(st.top());
		st.pop();
	}
	tmp.push(max);
	size++;
	for (int i = 0; i < size; i++)
	{
		st.push(tmp.top());
		tmp.pop();
	}
	cout << "Полученный стек:\n";
	Print_Stack(st);

	cout << "\nУдаление из списка чисел в заданном диапазоне\n";
	double min;
	cout << "Введите левую границу диапазона: "; cin >> min;
	cout << "Введите правую границу диапазона: "; cin >> max;
	cout << "Удаление из списка элементов в диапазоне [" << min << ";" << max << "]\n";
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (st.top() < min || st.top() > max)
		{
			tmp.push(st.top());
			count++;
		}
		st.pop();
	}
	size = count;
	for (int i = 0; i < size; i++)
	{
		st.push(tmp.top());
		tmp.pop();
	}
	cout << "Полученный стек:\n";
	Print_Stack(st);

	cout << "\nДобавление среднего арифметического к каждому элементу стека\n";
	double middle = 0;
	for (int i = 0; i < size; i++)
	{
		middle += st.top();
		tmp.push(st.top());
		st.pop();
	}
	middle /= size;
	for (int i = 0; i < size; i++)
	{
		st.push(tmp.top() + middle);
		tmp.pop();
	}
	cout << "Полученный стек:\n";
	Print_Stack(st);
}

void Task5()
{
	int size;
	cout << "Введите размер стека (1-100): "; cin >> size;
	while (size < 1 || size > 100)
	{
		cout << "Ввод некорректен!\n";
		cout << "Введите размер стека (1-100): "; cin >> size;
	}
	stack<double> st;
	stack<double> tmp;
	for (int i = 0; i < size; i++) st.push(rand() % 10000 / 100.0);
	cout << "Сгенерированный стек: \n";
	Print_Stack(st);

	cout << "\nДобавление максимума в конец стека\n";
	tmp = st;
	double max = 0;
	for (int i = 0; i < size; i++)
	{
		if (tmp.top() > max) max = tmp.top();
		tmp.pop();
	}
	for (int i = 0; i < size; i++)
	{
		tmp.push(st.top());
		st.pop();
	}
	tmp.push(max);
	size++;
	for (int i = 0; i < size; i++)
	{
		st.push(tmp.top());
		tmp.pop();
	}
	cout << "Полученный стек:\n";
	Print_Stack(st);

	cout << "\nУдаление из списка чисел в заданном диапазоне\n";
	double min;
	cout << "Введите левую границу диапазона: "; cin >> min;
	cout << "Введите правую границу диапазона: "; cin >> max;
	cout << "Удаление из списка элементов в диапазоне [" << min << ";" << max << "]\n";
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (st.top() < min || st.top() > max)
		{
			tmp.push(st.top());
			count++;
		}
		st.pop();
	}
	size = count;
	for (int i = 0; i < size; i++)
	{
		st.push(tmp.top());
		tmp.pop();
	}
	cout << "Полученный стек:\n";
	Print_Stack(st);

	cout << "\nДобавление среднего арифметического к каждому элементу стека\n";
	double middle = 0;
	for (int i = 0; i < size; i++)
	{
		middle += st.top();
		tmp.push(st.top());
		st.pop();
	}
	middle /= size;
	for (int i = 0; i < size; i++)
	{
		st.push(tmp.top() + middle);
		tmp.pop();
	}
	cout << "Полученный стек:\n";
	Print_Stack(st);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	cout << "=========================| Двунаправленная очередь |=========================\n";
	Task1();
	cout << "\n=========================|       Пара чисел        |=========================\n";
	Task2();
	cout << "\n=========================|         Список          |=========================\n";
	Task3();
	cout << "\n=========================|          Стек           |=========================\n";
	Task4();

	return 0;
}