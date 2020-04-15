//Минимуллин Радмир, лаб. 20, Классы и объекты
#include <iostream>
#include "point.cpp"
using namespace std;

point make(long O, long T){
	point t;
	t.qwe(O, T);
	return t;
}

int main(){
	point A;
	point B;
	B.read();
	B.print();
	cout <<  "B.summa(" << B.first << "," << B.second << ") = " << B.summa() << endl;
	point *X = new point;
	X->read();
	X->print();
	X->summa();
	cout << "X.summa(" << X->first << "," << X->second << ") = " << X->summa() << endl;
	point mass[3];
	for(int i = 0; i < 3; i++){
		mass[i].read();
	}
	for(int i = 0; i < 3; i++){
		mass[i].print();
	}
	for(int i = 0; i < 3; i++){
		mass[i].summa();
		cout << "mass[" << i << "].summa(" << mass[i].first << "," << mass[i].second << ") = " << mass[i].summa() << endl;
	}
	
	int c, b;
	cout << "first: " << endl;
	cin >> c;
	cout << "second: " << endl;
	cin >> b;
	
	point F = make(c, b);
	F.print();
	return 0;
}
