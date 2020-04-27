#include <iostream>

using namespace std;

template <class T> 
class VECTOR
{
	public:
		VECTOR(int s,T k);
		VECTOR(const VECTOR<T>&a);
		
		~VECTOR();
		
		VECTOR&operator=(const VECTOR<T>&a);
		T&operator[](int index);
		VECTOR operator+(VECTOR<T>&B);
		
		int operator()();
		

		int size;
		T*data;
};


template <class T> 
VECTOR<T>::VECTOR(int s,T k)
{
	size=s;
	data=new T[size];
	for(int i=0;i<size;i++)
		data[i]=k;
}


template <class T> 
VECTOR<T>::VECTOR(const VECTOR&a)
{
	size=a.size;
	data=new T[size];
	for(int i=0;i<size;i++)
		data[i]=a.data[i];
}


template <class T> 
VECTOR<T>::~VECTOR()

{
	delete[]data;
	data = 0;
}


template <class T> 
VECTOR<T>&VECTOR<T>::operator=(const VECTOR<T>&a)
{
	if(this==&a)return *this;
	size=a.size;
	if (data!=0) delete[]data;
	data=new T[size];
	for(int i=0;i<size;i++)
		data[i]=a.data[i];
	return *this;
}


template <class T> 
T&VECTOR<T>::operator[](int index)
{
	if (index<size) return data[index]; 
	else cout << "\nError! Index>size"; 
}


template <class T> 
VECTOR<T> VECTOR<T>::operator+(VECTOR<T>&b)
{
	
	VECTOR<T> temp(size,0);
	for (int i=0;i<size;++i)
		temp.data[i]=data[i]+b.data[i];
	return temp;
}


template <class T> 
int VECTOR<T>::operator ()()
{
	return size;
}


template <class T> 
ostream&operator<< (ostream&out,const VECTOR<T>&a)
{
	for(int i=0;i<a.size;++i)
		out<<a.data[i]<<" ";
	return out;
}


template <class T> 
istream&operator>> (istream&in,VECTOR<T>&a)
{
	for(int i=0;i<a.size;++i)
		in>>a.data[i];
	return in;
}


