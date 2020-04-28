#include "Programmer.h"
#include <string>
using namespace std;

Programmer::Programmer(void) :Person(){
	money = 0;
	pos = "";
}
Programmer::~Programmer(void) {};
Programmer::Programmer(string M, int C, float F, string K) :Person(M, C) {
	money = F;
	pos = K;
}
Programmer::Programmer(const Programmer& P) {
	name = P.name;
	age = P.age;
	money = P.money;
	pos = P.pos;
}
void Programmer::Set_Money(float F) {
	money = F;
}
void Programmer::Set_Pos(string K) {
	pos = K;
}
Programmer& Programmer::operator=(const Programmer& p) {
	if (&p == this) return *this;
	name = p.name;
	age = p.age;
	money = p.money;
	pos = p.pos;
}
void Programmer::Show()
{
	cout << "\nИмя : " << name;
	cout << "\nВозраст : " << age;
	cout << "\nЗарплата(руб) : " << money;
	cout << "\nДолжность : " << pos;
	cout << "\n";
}
void Programmer::Input()
{
	cout << "\nИмя : "; cin >> name;
	cout << "\nВозраст : "; cin >> age;
	cout << "\nЗарплата(руб) : "; cin >> money;
	cout << "\nДожность : "; cin >> pos;
}
