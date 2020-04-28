///Minimullin Radmir. Lab 26. Obrabotka iskl. (3)
#include "List.h"
#include "Error.h"
#include <iostream>
using namespace std;

int main()
{
	try
	{
		cout << "List A(5, 10)\n";
		List A(5, 10); 
		cout << A; 

		cout << "\n\nList B\n";
		List B; 
		cout << B;

		int i, j, k, n;
		cout << "\nElement index of List A: ";
		cin >> i;
		
		cout << A[i] << endl;

		cout << "\n\nList C (3, 0)\n";
		List C(3, 0);
		cout << C;
		cout << "\nElements of List C: ";
		cin >> C;

		
		cout << "\n...Multiplication of List elements (A[i] * C[i])...\n";
		cout << "Index of first element: "; cin >> j;
		cout << "Index of second element: "; cin >> k;
		cout << "Result: " << A[j] * C[k] << "\n";


		cout << "\nTransition to the right to the element with number n (for List C)\n";
		cout << "Enter n: "; cin >> n;
		cout << C + n;
	}
	catch (Error & e)
	{
		e.what();
	}
	return 0;
}

