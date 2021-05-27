#pragma once
#include "Object.h"
#include <iostream>
#include <string>
using namespace std;

class Person :
    public Object
{
protected:
    string name;
    int age;

public:
    Person(void);
public:
    virtual ~Person(void);
    void Show();
    void Input();
    Person(string, int);
    Person(const Person&);

    string Get_Name() { return name; }
    int Get_Age() { return age; }

    void Set_Name(string);
    void Set_Age(int);

    void HandleEvent(TEvent& event);

    Person& operator=(const Person&);
};
