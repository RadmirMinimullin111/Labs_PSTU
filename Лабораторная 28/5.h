#include <iostream>
#include <queue>
using namespace std;

class vector_stl {
public:
	priority_queue<int> io;
	int* array_deque5;
	int n;
	vector_stl() {
		cout << "Количество элементов:" << endl;
		
		cin >> n;
		array_deque5 = new int[n];
		cout << "Введите элементы очереди" << endl;
		for (int i = 0; i < n; i++) {
			cout << "=";
			int qu;
			cin >> qu;
			array_deque5[i] = qu;
			io.push(qu);
		}
	};

	int min_element5(priority_queue<int> io);
	int max_element5(priority_queue<int> io);
	void add_average5(priority_queue<int> io, int n);
	void delete_max_element5(priority_queue<int> io, int n);
	void add_min_element5(priority_queue<int> io, int* array_deque5, int n);
	void print_deque5(priority_queue<int> io);
};
