//Минимуллин Радмир, лаб. 25, Программы, управляемые событиями.
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
	cout << "m - создать группу\n";
	cout << "+ - добавить элемент в группу\n";
	cout << "- - удалить элемент из группы\n";
	cout << "s - информация об элементах группы\n";
	cout << "z - вывести имя заданного элемента\n";
	cout << "q - конец работы\n";
	Dialog D;
	D.Execute();

}
