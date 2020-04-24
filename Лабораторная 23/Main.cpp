//Минимуллин Радмир, лаб. 23, АТД. Деревья.
#include <iostream>
#include "Containers.cpp"

using namespace std;

int main(){
	setlocale(LC_ALL, "rus");
	
	cout << "Enter the number of elements in the array: ";
	int size_ad;
	cin >> size_ad;
	VECTOR vector(size_ad);
	
	for(int i = 0; i < size_ad; i++){
		vector[i] = i+1;
	}
	cout << "Array after adding a number to a given section: ";
	vector.ins(5, 7);
	for (int j=0; j<vector.getLength(); j++) cout << vector[j] << " ";
	cout << endl;
	cout << "Array after multiplying all elements by 5: ";
	vector*5;
	for (int j=0; j<vector.getLength(); j++) cout << vector[j] << " ";
	cout << endl;
	cout << "Number of array elements" << endl;
	int size = (vector(size_ad-1));
	cout << size - 1 << endl;
	int n;
	cout << "Go left to item n: "; cin >> n;
	vector - n;
	for(int i = 0; i < n; i++){
		cout << vector[i] << " ";
	}
	cout << endl;
	
	system("pause");
	
	return 0;
}
