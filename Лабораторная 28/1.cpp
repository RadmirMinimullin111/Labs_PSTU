#include "1.h"

int two_deque::min_element(deque<double> q)
{
	int min;
	
	min = q.front();
	q.pop_front();
	
	int first = q[0];
	while (!q.empty()) {
			if (first < min) {
			min = first;
			q.pop_front();
			first = q.front();
		}
		else
		{
			q.pop_front();
			first = q.front();
		}
	}
	return min;
}

int two_deque::max_element(deque<double> q)
{
	int max;
	
	max = q.front();
	q.pop_front();
	
	int first = q[0];
	while (!q.empty()) {
			if (first > max) {
			max = first;
			q.pop_front();
			first = q.front();
		}
		else
		{
			q.pop_front();
			first = q.front();
		}
	}
	return max;
}

void two_deque::print_deque(deque<double> q){
	while(!q.empty()){
		cout << q.front()<< ' ';
		q.pop_front();
	}
}

void two_deque::add_min_element(deque<double> q, double* array_deque, int n){
	int position;
	int minimal_element = min_element(q);
	cout << minimal_element << endl;
	cin >> position;
	position--;
	cout << endl;
	for(int i = 0, j = 0; i < n + 1; i++, j++){
	
		if(i == position){
			q[i] = minimal_element;
			i++;
			q[i] = array_deque[j];
		}
		else{
			q[i] = array_deque[j];
		}
	}
	cout << "Результат: ";
	for(int i = 0; i < n+1; i++){
		cout << q[i] << ' ';
	}
}

void two_deque::delete_max_element(deque<double> q, int n){
	int max = max_element(q);
	for(int i = 0; i < n; i++){
		if(q[i] == max){
			cout << "delete" << " ";
		}
		else{
			cout << q[i] << " ";
		}
	}
	cout << endl;
}

void two_deque::add_average(deque<double> q, int n){
	int average = 0;
	
	for(int i = 0; i < n; i++){
		average += q[i];
		cout << average << " ";
	}
	cout << endl << average/n << endl;
	cout << "\t" << "Очередь после добавления среднеарифметического: ";
	for(int i = 0; i < n; i++){
		q[i] = q[i] + (average/n);
		cout << q[i] << " ";
	}
}
