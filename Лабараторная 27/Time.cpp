#include <fstream>
#include <iostream>
#include "Time.h"
using namespace std;

//Запись в файл
void Time::write_to_file(int* min, int* sec){
	ofstream fout("Time\\time.txt");
	char jk = ':';
	char ko = '\n';
	if(fout.is_open()){
		for(int i = 0; i < 10; i++){
			fout << min[i];
			fout << jk;
			fout << sec[i];
			fout << ko;
		}
		cout << "Данные записаны в файл!" << endl;
	}
	else{
		cout << "Ошибка, файл не открылся!" << endl;
	}
	fout << ko;
	
}

//Чтение из файла
void read_to_file(){
	ifstream fin("Time\\time.txt");
	
	if(fin.is_open()){
		string strInput;
		fin >> strInput;
		cout << strInput << endl;
	}
	else
	{
		cout << "Ошибка, файл не открылся!" << endl;
	}
}
//Удаление (Удаление) интервала
void delete_interval(int* min, int* sec, int delete_min, int delete_sec){
	for(int i = 0; i < 10; i++){
		if(min[i] != delete_min | sec[i] != delete_sec){
			 min[i] = 0;
			 sec[i] = 0;
		}
	}
}
//Вычитание интервала
void decrease_the_interval(int* min, int* sec, int decrease_min, int decrease_sec){
	for(int i = 0; i < 10; i++){
		if(min[i] == decrease_min, sec[i] == decrease_sec){
			if(min[i] > 1 && sec[i] > 30){
				min[i] = min[i] - 1;
				sec[i] = sec[i] - 30;
			}
			else if(min[i] > 1 && sec[i] < 30){
				min[i] = min[i] - 1;
				sec[i] = (sec[i]+60)-30;
			}
			else{
				cout << "Не подходит" << endl;
			}
		}
	}
	cout << "Операция выполнена!" << endl;
}
//Добавлние минут
int* add_k_element_sec(int k, int* sec){
	int *new_sec = new int[k+10];
	for(int i = 0; i < k; i++){
		cin >> new_sec[i];
	}
	for(int i = k; i < (k+10); i++){
		new_sec[i] = sec[i];
	}
	
	for(int i = 0; i < (k+10); i++){
		sec[i] = new_sec[i];
	}
	return sec;
}
//Добавление секунд
int* add_k_element_min(int k, int* min){
	int *new_min = new int[k+10];
	for(int i = 0; i < k; i++){
		cin >> new_min[i];
	}
	for(int i = k; i < (k+10); i++){
		new_min[i] = min[i];
	}
	
	for(int i = 0; i < (k+10); i++){
		min[i] = new_min[i];
	}
	return min;
}
