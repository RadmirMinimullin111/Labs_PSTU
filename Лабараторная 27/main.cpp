//Minimullin Radmir, ���. 27. ���������� ������ � ����� 
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
	cout << "��������� ���������: " << endl;
	for(int i = 0; i < 10; i++){
		cout << i+1 << " - " << time.min[i] << ":" << time.sec[i] << endl;
	}
	
	do{
		
		cout << "1.�������� ������ � ����                                                                                                     " << endl;
		cout << "2.������� �� ����� ���������� �����                                                                                          " << endl;
		cout << "3.������� ��� ������ �� ������ ��������� ��������                                                                            " << endl;
		cout << "4.��������� ��� ������ � �������� ��������� �� 1 ������ 30 ������. �������� ��������� �� ������ ���� ������ 0 ����� 0 ������." << endl;
		cout << "5.�������� K ������� � ������ �����                                                                                          " << endl;
		cout << "6.�����                                                                                                                      " << endl;
	
		cin >> p;
		switch(p){
			case 1: time.write_to_file(time.min, time.sec);
					break;
			case 2: read_to_file();
					break;
			case 3: 
					cout << "������� ��������: " << endl;
					cout << "������: "; cin >>  delete_minut;
					cout << "�������: "; cin >> delete_secund;
				
					delete_interval(time.min, time.sec, delete_minut, delete_secund);
					break;
			case 4: 
					cout << "������� ��������: " << endl;
					cout << "������: "; cin >>  decrease_minut;
					cout << "�������: "; cin >> decrease_secund;
				
					decrease_the_interval(time.min, time.sec, decrease_minut, decrease_secund);
					break;
			case 5:
					cout << "������� K: "; cin >> k;
					cout << "������� ��������������� � ��������  " << endl;
					cout << "������� ������: " << endl;
					add_k_element_min(k, time.min);
					cout << "������� �������: " << endl;
					add_k_element_sec(k, time.sec);
					
					break;
			
		}
	}while(p != 6);
}
