//Minimullin Radmir, лаб. 27. Сохранение данных в файле 
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Time.cpp"
using namespace std;
int main(){
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	Time time;
	int p, k, delete_minut, delete_secund, decrease_minut, decrease_secund;
	cout << "Начальные интервалы: " << endl;
	for(int i = 0; i < 10; i++){
		cout << i+1 << " - " << time.min[i] << ":" << time.sec[i] << endl;
	}
	
	do{
		
		cout << "1.Записать данные в файл                                                                                                     " << endl;
		cout << "2.Вывести на экран содержимое файла                                                                                          " << endl;
		cout << "3.Удалить все записи не равные заданному значению                                                                            " << endl;
		cout << "4.Уменьшить все записи с заданным значением на 1 минуту 30 секунд. Значение интервала не должно быть меньше 0 минут 0 секунд." << endl;
		cout << "5.Добавить K записей в начало файла                                                                                          " << endl;
		cout << "6.Выход                                                                                                                      " << endl;
	
		cin >> p;
		switch(p){
			case 1: time.write_to_file(time.min, time.sec);
					break;
			case 2: read_to_file();
					break;
			case 3: 
					cout << "Введите значение: " << endl;
					cout << "Минуты: "; cin >>  delete_minut;
					cout << "Секунды: "; cin >> delete_secund;
				
					delete_interval(time.min, time.sec, delete_minut, delete_secund);
					break;
			case 4: 
					cout << "Введите значение: " << endl;
					cout << "Минуты: "; cin >>  decrease_minut;
					cout << "Секунды: "; cin >> decrease_secund;
				
					decrease_the_interval(time.min, time.sec, decrease_minut, decrease_secund);
					break;
			case 5:
					cout << "Введите K: "; cin >> k;
					cout << "Введите последовательно К значений  " << endl;
					cout << "Введите минуты: " << endl;
					add_k_element_min(k, time.min);
					cout << "Введите секунды: " << endl;
					add_k_element_sec(k, time.sec);
					
					break;
			
		}
	}while(p != 6);
}
