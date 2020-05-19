#include "5.h"
#include <iostream>
using namespace std;

int vector_stl::min_element5(priority_queue<int> io)
{
	int min;
	
	min = io.top();
	io.pop();
	
	int first = io.top();
	while (!io.empty()) {
			if (first < min) {
			min = first;
			io.pop();
			first = io.top();
		}
		else
		{
			io.pop();
			first = io.top();
		}
	}
	return min;
}

int vector_stl::max_element5(priority_queue<int> io)
{
	int max;
	
	max = io.top();
	io.pop();
	
	int first = io.top();
	while (!io.empty()) {
			if (first > max) {
			max = first;
			io.pop();
			first = io.top();
		}
		else
		{
			io.pop();
			first = io.top();
		}
	}
	return max;
}

void vector_stl::print_deque5(priority_queue<int> io){
	while(!io.empty()){
		cout << io.top()<< ' ';
		io.pop();
	}
}

void vector_stl::add_min_element5(priority_queue<int> io, int* array_deque5, int n){
cout << "С данным видом контейнера нереализуемо" << endl;
}

void vector_stl::delete_max_element5(priority_queue<int> io, int n){
	int max = max_element5(io);
	for(int i = 0; i < n; i++){
		if(io.top() == max){
			cout << "delete" << " ";
			io.pop();
		}
		else{
			cout << io.top() << " ";
			io.pop();
		}
	}
	cout << endl;
}

void vector_stl::add_average5(priority_queue<int> io, int n){
	int average = 0;
	
	for(int i = 0; i < n; i++){
		average += io.top();
		io.pop();
		cout << average << " ";
	}
	cout << endl << average/n << endl;
	cout << "\t" << "Очередь после добавления среднеарифметического: ";
	for(int i = 0; i < n; i++){
		io.push(io.top() + (average/n));
		cout << io.top() << " ";
		io.pop();
	}
}
