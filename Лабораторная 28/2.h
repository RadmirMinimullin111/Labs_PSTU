#include <deque>
#include <iostream>
using namespace std;
template <class Time>
class Times{
public:
	deque<Time> d;
	Time n;
	Time* array_deque1;
	Times(){
		cout << "Количество элементов: ";
		cin >> n;
		
		array_deque1 = new Time[n];
		cout << "Введите элементы очереди: " << endl;
		for(int i = 0; i < n; i++){
			cout << "=";
			int du;
			cin >> du;
			array_deque1[i] = du;
			d.push_back(du);
		}
	}
	
	Time min_Element(deque<Time> d);
	Time max_Element(deque<Time> d);
	void add_average1(deque<Time> d, Time n);
	void delete_max_element1(deque<Time> d, Time n);
	void add_min_element1(deque<Time> d, Time* array_deque1, Time n);
	void print_deque1(deque<Time> d);

	
};


