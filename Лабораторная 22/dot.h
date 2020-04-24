#include <iostream>
#include "windows.h"
using namespace std;

class time{
	public:	
	    int add_second(int Seconds);
		int add_minutes(int Minutes);
		int Minutes;
		int Seconds;
 Time(){
			Minutes = 0;
			Seconds = 0;
		}
		~time(){};
};

