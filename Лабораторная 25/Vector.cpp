#include "Vector.h"
#include "Programmer.h"
#include "Person.h"
#include "Object.h"
#include <iostream>
using namespace std;
Vector::~Vector(void)
{
    if (beg != 0)
        delete[] beg; 
    beg = 0;
}
Vector::Vector(void) {
    size = 0;
    cur = 0;
}
Vector::Vector(int n)
{
    beg = new Object * [n];
    cur = 0;
    size = n;
}
void Vector::Add()
{
    Object* p;
    cout<<"1.�������"<<endl;
    cout<<"2.�����������"<<endl;
    int y; 
    cin >> y;
    if (y == 1)
    {
        Person* a = new (Person);
        a->Input(); 
        p=a;
        if (cur < size)
        {
            beg[cur] = p;
            cur++;
        }
    }
    else
    if (y == 2) 
    {
        Programmer* b = new Programmer;
        b->Input();
        p = b;
        if (cur < size)
        {
            beg[cur] = p;
            cur++;
        }
    }
    else return;
}
void Vector::Show()
{
    if (cur == 0) cout << "������" << endl;
    Object** p = beg;
    for(int i=0;i<cur;i++)
    {
        (*p)->Show();
        p++;
    }
} 
int Vector::operator ()()
{
    return cur;
}
void Vector::Del()
{
    if (cur == 0)return; 
    cur--;
}
void Vector::HandleEvent(const TEvent& e)
{
    int o;
    cout << "������� ����� �������� ��� �������� ����� �������: ";
    cin >> o;
    if (e.what == evMessage)
    {
        Object** p = beg;
        for (int i = 1; i < o; i++)
            p++;
        (*p)->HandleEvent(e);
    }
}

