////Минимуллин Радмир, лаб. 22, Перегрузка операций.
#include <iostream>
#include "dot.cpp"
#include "windows.h"
using namespace std;

int main(){
	setlocale(LC_ALL, "rus");
	time users_method;
    int add_second; 
	int add_interval_min;
	int add_interval_sec;
	int interval_min;
	int interval_sec;
   
	int p, min;
	do{
		cout << "1.Enter Interval" << endl;
		cout << "2.Add seconds" << endl;
		cout << "3.Compare two time intervals" << endl;
		cout << "4.Exit" << endl;
		cin >> p;
		switch(p){
			case 1: 
				cout << "Minutes and seconds in timer : " << endl;	
				cout << "Minutes: "; cin >> interval_min;
				cout << "Seconds: "; cin >> interval_sec;
				
					break;
			case 2: "Enter the number of seconds you want to add: "; cin >> add_second;
							min = (add_second + interval_sec)/60;
							if(min < 1){
								
								interval_sec = add_second + interval_sec;
								cout << interval_min << ":" << interval_sec << endl;
							}
							else{
								interval_min = interval_min + min;
								int sec = min * 60;
								sec = add_second + interval_sec - sec;
								cout << interval_min << ":" << sec << endl;
					}
					break;
			case 3: cout << "Enter a new interval " << endl;
					cout << "Minutes: "; cin >> add_interval_min;
					cout << "Seconds: "; cin >> add_interval_sec;
					if(interval_min > add_interval_min){
						if(interval_sec > add_interval_sec){
							cout << "First interval longer" << endl;
						}
						else if(interval_sec == add_interval_sec){
							cout << "Intervals are equal" << endl;
						}
						else{
							cout << "The first interval is less" << endl;
						}
					}
					else if(interval_min <= add_interval_min){
						cout << "The first interval is less than or equal to the second" << endl;
					}
					break;
		}
	}while(p != 4);
	return 0;
}
