#pragma once
#include <iostream>
#include "MyForm.h"
using namespace std;







class Calc {
public:
	int numerator_1, numerator_2, denominator_1, denominator_2;

	Calc() {
	};											
												



	int Addition_numerator(int numerator_1, int numerator_2, int denominator_1, int denominator_2);		
	int Addition_denominator(int denominator_1, int denominator_2);
	int Subtraction_numerator(int numerator_1, int numerator_2, int denominator_1, int denominator_2);			
	int Subtraction_denominator(int denominator_1, int denominator_2);
	int Multiplication_numerator(int numerator_1, int numerator_2);			
	int Multiplication_denominator(int denominator_1, int denominator_2);
	int Division_numerator(int numerator_1, int denominator_2);				
	int Division_denominator(int numerator_2, int denominator_1);
	double Plain(double numerator_1, double denominator_1);															

	int return_lenght_string(int number);
	double return_lenght_string_double(double number);
	
	~Calc();
};


int Calc::Addition_numerator(int numerator_1, int numerator_2, int denominator_1, int denominator_2){
	return (numerator_1 * denominator_2) + (denominator_1 * numerator_2);
}

int Calc::Addition_denominator(int denominator_1, int denominator_2) {
	return denominator_1 * denominator_2;
}

int Calc::Subtraction_numerator(int numerator_1, int numerator_2, int denominator_1, int denominator_2) {
	return (numerator_1 * denominator_2) - (denominator_1 * numerator_2);
}
int Calc::Subtraction_denominator(int denominator_1, int denominator_2) {
	return denominator_1 * denominator_2;
}

int Calc::Multiplication_numerator(int numerator_1, int numerator_2) {
	return numerator_1 * numerator_2;
}

int Calc::Multiplication_denominator(int denominator_1, int denominator_2) {
	return denominator_1 * denominator_2;
}

int Calc::Division_numerator(int numerator_1, int denominator_2) {
	return numerator_1 * denominator_2;
}
int Calc::Division_denominator(int numerator_2, int denominator_1) {
	return numerator_2 * denominator_1;
}

double Calc::Plain(double numerator_1, double denominator_1) {
	return numerator_1 / denominator_1;
}

int Calc::return_lenght_string(int number) {
	int count = 0;
	while (number > 1) {
		number /= 10;
		count++;
	}
	return count;
}

inline Calc::~Calc()
{
}







