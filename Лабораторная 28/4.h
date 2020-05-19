#include <iostream>
#include <queue>
using namespace std;

void print_deque1(priority_queue<int> p_q){
	while(!p_q.empty()){
		cout << p_q.top()<< ' ';
		p_q.pop();
	}
}


int min_element4(priority_queue<int> p_q)
{
	int min;
	
	min = p_q.top();
	p_q.pop();
	
	int first = p_q.top();
	while (!p_q.empty()) {
			if (first < min) {
			min = first;
			p_q.pop();
			first = p_q.top();
		}
		else
		{
			p_q.pop();
			first = p_q.top();
		}
	}
	return min;
}

int max_element4(priority_queue<int> p_q)
{
	int max;
	
	max = p_q.top();
	p_q.pop();
	
	int first = p_q.top();
	while (!p_q.empty()) {
			if (first > max) {
			max = first;
			p_q.pop();
			first = p_q.top();
		}
		else
		{
			p_q.pop();
			first = p_q.top();
		}
	}
	return max;
}

void add_min_element4(priority_queue<int> p_q, int* array_queue4, int n){
	cout << "С данным видом контейнера не реализуемо" << endl;
}

void delete_max_element4(priority_queue<int> p_q, int n){
	int max = max_element4(p_q);
	for(int i = 0; i < n; i++){
		if(p_q.top() == max){
			cout << "delete" << " ";
			p_q.pop();
		}
		else{
			cout << p_q.top() << " ";
			p_q.pop();
		}
	}
	cout << endl;
}

void add_average4(priority_queue<int> p_q, int n){
	int average = 0;
	
	for(int i = 0; i < n; i++){
		average += p_q.top();
		p_q.pop();
		cout << average << " ";
	}
	cout << endl << average/n << endl;
	cout << "\t" << "Очередь после добавления среднеарифметического: ";
	for(int i = 0; i < n; i++){
		p_q.push(p_q.top() + (average/n));
		cout << p_q.top() << " ";
		p_q.pop();
	}
}
