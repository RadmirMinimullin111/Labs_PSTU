#include <iostream>

using namespace std;

class TIME
{
public:
	friend ostream& operator<< (ostream& out, const TIME&);
	friend istream& operator>> (istream& in, TIME&);
	TIME(void);
	TIME(const TIME&);
	TIME(int, int);
	TIME&operator=(const TIME&);
	TIME operator+(TIME k);
	
	virtual ~TIME(void){};
private:
	int min,sec;
};
