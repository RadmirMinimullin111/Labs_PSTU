#include <iostream>
#include "initialization.h"
using namespace std;
class RECTANGLE: public users_class{
	public:
		int Area(int first, int second){
			return first*second;
		}
		
		int perimetr(int first, int second){
			return (first + second)*2;
		}	
	};


