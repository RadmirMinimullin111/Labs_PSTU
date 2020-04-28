#pragma once
#include "Person.h"

class Programmer:
public Person{
public:
	Programmer(void);
public:
	~Programmer(void);
	Programmer(string, int, float, string);
	Programmer(const Programmer&);
	void Show();
	void Input();
	float Get_Money() { return money; }
	string Get_Pos() { return pos; }
	void Set_Money(float);
	void Set_Pos(string);
	Programmer& operator=(const Programmer&);
protected:
	float money;
	string pos;
};