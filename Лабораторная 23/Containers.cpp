#include <iostream>
#include "Met.h"
using namespace std;

		int& VECTOR::operator[](int index)
    	{
        	assert(index >= 0 && index < size);
        	return ad[index];
    	}

    	int VECTOR::operator()(int arr){
    		int size_of = 0;
    		for(int i = 0; i < size; i++){
    			size_of++;
			}
    		return size_of;
		}

		int* VECTOR::operator * (int h){
			for(int i = 0; i < size; i++){
				ad[i] = ad[i]*h;
			}
			return ad;
		}
		
		int* VECTOR::operator - (int n){
			int* ad1 = new int[n];
			for(int i = 0; i < n; i++){
				ad1[i] = ad[i];
			}
			return ad1;
		}
		
		
		void VECTOR::ins(int value, int index){
			assert(index >= 0 && index <= size);
			
			int *data = new int[size + 1];
			
			for(int before = 0; before < index; before++){
				data[before] = ad[before];
			}
			
			data[index] = value;
			
			for (int after=index; after < size; ++after)
            data[after+1] = ad[after];
            
            delete[] ad;
       	 	ad = data;
        	++size;
		}
