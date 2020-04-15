#include <iostream>

using namespace std;

class users_class{
	public: 
		int first;				//Первая переменная
		int second;				//Вторая переменна
	
	users_class(){		    	//Конструктор без параметров
		first = 1;
		second = 2;
	}
	
	parametr(int first, int second){    //Конструктор с параметрами
		int new_first = first;
		int new_second = second;
	}
	
	kopir(users_class& b){			//Конструктор копирования
		int new_first = b.first;
		int new_second = b.second;
	}
	

	void change(){									//Инициализация метода для изменения полей
		cout << "Введите новые значения first и second: ";
		cin >> first >> second;
	}
	
	void print(){
		cout << "first: " << first << endl;
		cout << "second: " << second << endl;
	}
	
	int composition(int F, int S){					//Произведения двух чисел
		return F*S;
	}
	
	double composition(double F, double S){			//Перегрузка операции умножения
		return F*S;
	}
	
	
	~users_class(){};								//Деструктор класса
};
