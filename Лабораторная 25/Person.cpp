#include "Person.h"
#include "Event.h"
using namespace std;

Person::Person(void)
{
    name = "";
    age = 0;
}
Person::~Person(void)
{
}

Person::Person(string M,int C)
{
    name = M; age = C;
}
Person::Person(const Person& a)
{
    name = a.name; age = a.age;
}
void Person::Set_age(int C)
{
    age = C;
}
void Person::Set_name(string M)
{
    name = M;
}
Person& Person::operator=(const Person& c)
{
    if (&c == this)return *this; 
    name = c.name; 
    age = c.age; 
    return *this;
}
void Person::Show()
{
    cout << "\n��� : " << name;
    cout << "\n������� : " << age;
    cout << "\n";
}
void Person::Input()
{
    cout << "\n��� : "; cin >> name;
    cout << "\n������� : "; cin >> age;
}
void Person::HandleEvent(const TEvent& e)
{
    if (e.what == evMessage)
    {
        switch (e.command)
        {
        case cmGet:cout << "��� : " << Get_name() << endl; break;
        }
    }
}
