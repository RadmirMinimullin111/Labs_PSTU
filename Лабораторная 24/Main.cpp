///Minimullin Radmir, lab24, shabloni classow.
#include <iostream>
#include "Vector.h"
#include "Time.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	VECTOR<int>A(5,0);
	cout << "Enter the first vector\n";
	cin>>A;
	cout << "first vector: ";
	cout<<A<<endl;
	VECTOR <int>B(5,0);
	cout << "Enter the second vector\n";
	cin >> B;
	cout << "second vector: ";
	cout<<B<<endl;
	cout << "Index Access: ";
	cout <<A[2]<<endl;
	cout << "The length of the first and second vector: ";
	cout<<A()<<endl;
	VECTOR<int> C(5, 0);
	C = B + A;
	cout << "Addition of two vectors: "; 
	cout << C << endl;
	return 0;
}
