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
    Pair operator + (int k)
    {
        return Pair(first + k, second);
    }
    Pair operator + (double k)
    {
        return Pair(first, second + k);
    }
    Pair operator + (const Pair& a)
    {
        return Pair(first + a.first, second + a.second);
    }
    Pair operator - (int k)
    {
        return Pair(first - k, second);
    }
    Pair operator - (double k)
    {
        return Pair(first, second - k);
    }
    Pair operator - (Pair& a)
    {
        return Pair(first - a.first, second - a.second);
    }
    Pair operator / (int k)
    {
        return Pair(first / k, second);
    }
    Pair operator / (double k)
    {
        return Pair(first, second / k);
    }
    Pair operator / (Pair& a)
    {
        return Pair(first / a.first, second / a.second);
    }

    void operator += (int k)
    {
        first += k;
    }
    void operator += (double k)
    {
        second += k;
    }
    void operator += (const Pair& a)
    {
        first += a.first;
        second += a.second;
    }

    void operator -= (int k)
    {
        first -= k;
    }
    void operator -= (double k)
    {
        second -= k;
    }
    void operator -= (const Pair& a)
    {
        first -= a.first;
        second -= a.second;
    }

    void operator /= (int k)
    {
        first /= k; second /= k;
    }
    void operator /= (Pair& a)
    {
        first /= a.first;
        second /= a.second;
    }

    friend ostream& operator << (ostream& out, const Pair& a)
    {
        out << a.first << ":" << a.second;
        return out;
    }

    friend istream& operator >> (istream& in, Pair& a)
    {
        cout << "¬ведите целое число пары: "; in >> a.first;
        cout << "¬ведите вещественное число пары: "; in >> a.second;
        return in;
    }

    ~Pair() {};
};

bool operator>(const Pair& obj1, const Pair& obj2)
{
    //return (obj1.first > obj2.first && obj1.second > obj2.second);
    return (((double)obj1.first + obj1.second) > ((double)obj2.first + obj2.second));
}

bool operator>=(const Pair& obj1, const Pair& obj2)
{
    //return (obj1.first >= obj2.first && obj1.second >= obj2.second);
    return (((double)obj1.first + obj1.second) >= ((double)obj2.first + obj2.second));
}

bool operator<(const Pair& obj1, const Pair& obj2)
{
    //return (obj1.first < obj2.first && obj1.second < obj2.second);
    return (((double)obj1.first + obj1.second) < ((double)obj2.first + obj2.second));
}

bool operator<=(const Pair& obj1, const Pair& obj2)
{
    //return (obj1.first <= obj2.first && obj1.second <= obj2.second);
    return (((double)obj1.first + obj1.second) <= ((double)obj2.first + obj2.second));
}

bool operator==(const Pair& obj1, const Pair& obj2)
{
    return (obj1.first == obj2.first && obj1.second == obj2.second);
}

bool operator!=(const Pair& obj1, const Pair& obj2)
{
    return (obj1.first != obj2.first || obj1.second != obj2.second);
}
