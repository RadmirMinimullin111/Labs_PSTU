#include <iostream>
#include <deque>
using namespace std;

class two_deque {
public:
	deque<double> q;
	double* array_deque;
	int n;
	two_deque() {
		cout << "Количество элементов:" << endl;
		
		cin >> n;
		array_deque = new double[n];
		cout << "Введите элементы очереди" << endl;
		for (int i = 0; i < n; i++) {
			cout << "=";
			int qu;
			cin >> qu;
			array_deque[i] = qu;
			q.push_back(qu);
		}
	};

	int min_element(deque<double> q);
	int max_element(deque<double> q);
	void add_average(deque<double> q, int n);
	void delete_max_element(deque<double> q, int n);
	void add_min_element(deque<double> q, double* array_deque, int n);
	void print_deque(deque<double> q);
};
