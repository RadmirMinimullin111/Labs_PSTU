//Минимуллин Радмир, лаб. 20, Классы и объекты
#include <iostream>
#include "point.h"
using namespace std;


void point::qwe(int O, int T){
	int first = O;
	int second = T;
}

void point::read(){
	cout << "first:" << endl;
	cin >> first;
	cout << "second:" << endl;
	cin >> second;
}

void point::print(){
	cout << "first: " << first << endl;
	cout << "second: " << second << endl;
}

int point::summa(){
	return first*second;
}
