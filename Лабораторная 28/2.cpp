#include "2.h"

template <class Time>
Time Times<Time>::min_Element(deque<Time> q)
{
	Time min;
	
	min = q.front();
	q.pop_front();
	
	Time first = q[0];
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

template <class Time>
Time Times<Time>::max_Element(deque<Time> q)
{
	Time max;
	
	max = q.front();
	q.pop_front();
	
	Time first = q[0];
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


template <class Time>
void Times<Time>::print_deque1(deque<Time> q){
	while(!q.empty()){
		cout << q.front()<< ' ';
		q.pop_front();
	}
}




template <class Time>
void Times<Time>::add_min_element1(deque<Time> q, Time* array_deque, Time n){
	int position;
	int minimal_element = min_Element(q);
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

template <class Time>
void Times<Time>::delete_max_element1(deque<Time> q, Time n){
	int max = max_Element(q);
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

template <class Time>
void Times<Time>::add_average1(deque<Time> q, Time n){
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
