#include "Person.h"
#include "Programmer.h"
#include "Vector.h"
#include "Object.h"
#include "Dialog.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "m - ������� ������\n";
	cout << "+ - �������� ������� � ������\n";
	cout << "- - ������� ������� �� ������\n";
	cout << "s - ���������� �� ��������� ������\n";
	cout << "z - ������� ��� ��������� ��������\n";
	cout << "q - ����� ������\n";
	Dialog D;
	D.Execute();

}
