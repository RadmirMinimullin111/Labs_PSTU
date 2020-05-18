#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

class Time{
	public:
		int* min;
		int* sec;
		//Прототипы функций
		void write_to_file(int* min, int* sec);													
		void read_to_file();																		
		void delete_interval(int* min, int* sec, int delete_min, int delete_sec);					
		void decrease_the_interval(int* min, int* sec, int decrease_min, int decrease_sec);			
		int* add_k_element_min(int k, int* min);												
		int* add_k_element_sec(int k, int* sec);												
		
																								
		Time(){																						
			min = new int[10];
			sec = new int[10];
			for(int i = 0; i < 10; i++){														
				min[i] = rand()%59+1;
				sec[i] = rand()%59+1;
			}
		}
		
};
