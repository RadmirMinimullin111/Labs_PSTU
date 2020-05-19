#include <iostream>
using namespace std;

int& operator [] (int index){
	if (index<size) return data[index]; 
	else cout << "\nError! Index>size"; 
}
