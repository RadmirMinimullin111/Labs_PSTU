#include <iostream>
#include <cassert>
using namespace std;
class VECTOR 
{
	protected: 
		int *ad;		
		int size;	
		
	public: 
		VECTOR(): size(0), ad(NULL){}
		
	
		VECTOR(int _size):size(_size){
			assert(_size >= 0);
			
			if(_size > 0) ad = new int[_size];
			else ad = NULL;
		}
		
		int getLength() { return size; }
	
		int& operator[](int index);
    
    	int operator()(int ad);
	
		int* operator * (int h);
		int* operator - (int n);
		
		void ins(int value, int index);
	
	
		
		~VECTOR(){
			delete[] ad;						
		}	
};


class Integer
{
protected:
	int num;

public:
	Integer() {};
	Integer(int _num) : num(_num) {};

	friend istream& operator >> (istream&, Integer&);
	friend ostream& operator << (ostream&, const Integer&);

};

istream& operator >> (istream& in, Integer& a)
{
	in >> (a.num);
	return in;
}

ostream& operator << (ostream& out, const Integer& a)
{
	out << (a.num);
	return out;
}
