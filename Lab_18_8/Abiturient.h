#pragma once
#include "Person.h"

class Abiturient :
    public Person
{
protected:
    string speciality;
    int exams;
public:
    Abiturient(void);
    Abiturient(string, int, string, int);
    Abiturient(const Abiturient&);
    ~Abiturient(void);
    void Show();
    void Input();
    string Get_Speciality() { return speciality; }
    int Get_Exams() { return exams; }
    void Set_Speciality(string);
    void Set_Exams(int);
    Abiturient& operator=(const Abiturient&);
};
