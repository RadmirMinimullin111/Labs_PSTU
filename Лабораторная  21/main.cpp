//���������� ������, ���. 20, ������ � �������
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
				
		cout << "1.�������� ���������� first � second" << endl;
		cout << "2.��������� ������������ ���� �����" << endl;
		cout << "3.��������� ������� � �������� �������������� � ����� �� ���������" << endl;
		cout << "4.�����" << endl;
	
		cin >> k;																							
		switch(k){	
			case 1:
				method.change();	//�������� ����� change ������ method
				break;
			case 2:
				proiz = method.composition(method.first, method.second);	//�������������� ���������� ��� ��������� ����������� ������ composition
				cout <<"������������ = "<< proiz << endl;																
				break;
			case 3: 
					area = gh.Area(method.first, method.second);
					Per = gh.perimetr(method.first, method.second);
					cout << "�������: " << area << endl;
					cout << "��������: " << Per << endl;
					break;
		}
	}while(k != 4);
}

