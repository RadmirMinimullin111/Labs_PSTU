//Минимуллин Радмир , лаб 28, Последовательные контейнеры библиотеки STL
#include <iostream>
#include <queue>
#include "1.cpp"
#include "2.cpp"
#include "4.h"
#include "5.cpp"
using namespace std;
void print_deque1(priority_queue<int> p_q);
int min_element4(priority_queue<int> p_q);
int max_element4(priority_queue<int> p_q);
void add_average4(priority_queue<int> p_q, int n);
void delete_max_element4(priority_queue<int> p_q, int n);
void add_min_element4(priority_queue<int> p_q, 	int* array_queue4, int n);

int main() {
	
	setlocale(LC_ALL, "rus");
	two_deque QUEUE;
	
	
	cout << "Задача 1: " << endl;
	cout << "Задание 1: " << endl;
	cout << "\t" << "Элементы очереди: ";
	QUEUE.print_deque(QUEUE.q);
	cout << endl;
	cout << "\t" << "Минимальный элемент очереди: " << QUEUE.min_element(QUEUE.q) << endl;
	cout << "\t" << "На какую позицию добавить минимальный элемент?";
	QUEUE.add_min_element(QUEUE.q, QUEUE.array_deque, QUEUE.n);
	cout << endl;
	cout << "Задание 2: " << endl;
	cout << "\t" << "Максимальный элемент в очереди: " << QUEUE.max_element(QUEUE.q) << endl;
	cout << "\t" << "Очередь после удаления максимального элемента: "; 
	QUEUE.delete_max_element(QUEUE.q, QUEUE.n);
	cout << "Задание 3: " << endl;
	QUEUE.add_average(QUEUE.q, QUEUE.n);
	cout << endl;
	
	cout << "Задача 2: " << endl;
	Times<int> TIME;
	cout << "Задание 1: " << endl;
	cout << "\t" << "Элементы очереди: ";
	TIME.print_deque1(TIME.d);
	cout << endl << "\t" << "Минимальный элемент: " << TIME.min_Element(TIME.d) << endl;
	cout << "\t" << "Максимальный элемент: " << TIME.max_Element(TIME.d) << endl;
	cout << "\t" << "На какую позицию добавить минимальный элемент?";
	TIME.add_min_element1(TIME.d, TIME.array_deque1, TIME.n);
	cout << endl;
	cout << "\t" << "Очередь после удаления максимального элемента: "; 
	TIME.delete_max_element1(TIME.d, TIME.n);
	cout << "Задание 3: " << endl;
	TIME.add_average1(TIME.d, TIME.n);
	cout << endl;
	
	
	cout << "Задача 4: " << endl;
	priority_queue<int> p_q;
	int n;
		cout << "Количество элементов: ";
		cin >> n;
		int* array_queue4 = new int[n];
		cout << "Введите элементы очереди: " << endl;
		for(int i = 0; i < n; i++){
			cout << "->";
			int p;
			cin >> p;
			array_queue4[i] = p;
			p_q.push(p);
		}
	cout << "Задание 1: " << endl;
	cout << "\t" << "Элементы очереди: ";
	print_deque1(p_q);
	cout << endl << "\t" << "Минимальный элемент: " << min_element4(p_q) << endl;
	cout << "\t" << "Максимальный элемент: " << max_element4(p_q) << endl;
	cout << "Задание 2: " << endl;
	cout << "\t" << "На какую позицию добавить минимальный элемент?";
	add_min_element4(p_q, array_queue4, n);
	cout << endl;
	cout << "\t" << "Очередь после удаления максимального элемента: "; 
	delete_max_element4(p_q, n);
	cout << "Задание 3: " << endl;
	add_average4(p_q, n);
	cout << endl;
	
	cout << "Задача 5:" << endl;
	cout << "Задание 1: " << endl;
	vector_stl Vector;
	
	cout << "\t" << "Элементы очереди: ";
	Vector.print_deque5(Vector.io);
	cout << endl << "\t" << "Минимальный элемент: " << Vector.min_element5(Vector.io) << endl;
	cout << "\t" << "Максимальный элемент: " << Vector.max_element5(Vector.io) << endl;
	cout << "\t" << "На какую позицию добавить минимальный элемент?";
	Vector.add_min_element5(Vector.io, Vector.array_deque5, Vector.n);
	cout << endl;
	cout << "Задание 2: " << endl;
	cout << "\t" << "Очередь после удаления максимального элемента: "; 
	Vector.delete_max_element5(Vector.io, Vector.n);
	cout << "Задание 3: " << endl;
	Vector.add_average5(Vector.io, Vector.n);
	cout << endl;
	return 0;
}
