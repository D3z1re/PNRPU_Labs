#pragma once
#include <iostream>
using namespace std;

class Pair
{
    int first;
    double second;
public:
    Pair()
    {
        first = 0;
        second = 0;
    }

    Pair(int f, double s)
    {
        this->first = f;
        this->second = s;
    }
    Pair(const Pair& obj)
    {
        first = obj.first;
        second = obj.second;
    }

    void Show()
    {
        cout << first << ":" << second << endl;
    }
    void SetFirst(int n)
    {
        first = n;
    }
    void SetSecond(double n)
    {
        second = n;
    }
    int GetFirst() 
    { 
        return first; 
    }
    double GetSecond() 
    { 
        return second; 
    }

    friend bool operator>(const Pair& obj1, const Pair& obj2);
    friend bool operator>=(const Pair& obj1, const Pair& obj2);
    friend bool operator<(const Pair& obj1, const Pair& obj2);
    friend bool operator<=(const Pair& obj1, const Pair& obj2);
    friend bool operator==(const Pair& obj1, const Pair& obj2);
    friend bool operator!=(const Pair& obj1, const Pair& obj2);

    Pair& operator--() // префикс
    {
        first--;
        return *this;
    }
    Pair operator--(int) //постфикс
    {
        second--;
        return *this;
    }

    friend ostream& operator << (ostream& out, Pair& a)
    {
        out << a.first << endl << a.second << endl;
        return out;
    }

    friend istream& operator >> (istream& in, Pair& a)
    {
        in >> a.first;
        in >> a.second;
        return in;
    }

    ~Pair() {};
};

bool operator>(const Pair& obj1, const Pair& obj2)
{
    return (obj1.first > obj2.first && obj1.second > obj2.second);
}

bool operator>=(const Pair& obj1, const Pair& obj2)
{
    return (obj1.first >= obj2.first && obj1.second >= obj2.second);
}

bool operator<(const Pair& obj1, const Pair& obj2)
{
    return (obj1.first < obj2.first&& obj1.second < obj2.second);
}

bool operator<=(const Pair& obj1, const Pair& obj2)
{
    return (obj1.first <= obj2.first && obj1.second <= obj2.second);
}

bool operator==(const Pair& obj1, const Pair& obj2)
{
    return (obj1.first == obj2.first && obj1.second == obj2.second);
}

bool operator!=(const Pair& obj1, const Pair& obj2)
{
    return (obj1.first != obj2.first || obj1.second != obj2.second);
}
