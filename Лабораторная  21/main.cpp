//Минимуллин Радмир, лаб. 21, Наследование.Полиморфизм.Абстрактные классы.Виртуальные методы.
#include <iostream>
#include "methods.cpp"
using namespace std;

int main(){
	setlocale(LC_ALL, "rus");
	int proiz, area, Per;																			
	int k;																									
	users_class method;																					
	RECTANGLE gh;
	do{
				
		cout << "1.Значение переменных first и second" << endl;
		cout << "2.Вычислить произведение двух чисел" << endl;
		cout << "3.Вычислить площадь и перимерт прямоугольника с этими же сторонами" << endl;
		cout << "4.Выход" << endl;
	
		cin >> k;																							
		switch(k){	
			case 1:
				method.change();	//вызываем метод change класса method
				break;
			case 2:
				proiz = method.composition(method.first, method.second);	//инициализируем переменную как результат возвращения метода composition
				cout <<"Произведение = "<< proiz << endl;																
				break;
			case 3: 
					area = gh.Area(method.first, method.second);
					Per = gh.perimetr(method.first, method.second);
					cout << "Площадь: " << area << endl;
					cout << "Периметр: " << Per << endl;
					break;
		}
	}while(k != 4);
}

