#include <iostream>
#include <stdio.h>
#include <cmath>
#include <conio.h>
using namespace std;

double func_1(double x){
		x = x*x + 4;
	return x;
}

double pow1(double l, double y){
	int res = l;
	for (int i = 1; i < y; i++)
	{res *= l;}
	return res;
}

double func_2(double x){
	x = x*x*exp(-x);
	return x;
}

double func_3(double x){
	x = 1 / ((1 - x)*(2 - x*x));
	return x;
}

double gauss(double(*f)(double x), double a, double b){

	if (a > b){ swap(a, b); }
	double s = (b - a) / 2 * (
		f((a + b) / 2 - (b - a) / (2 * sqrt(3))) +
		f((a + b) / 2 + (b - a) / (2 * sqrt(3)))
		);
	return s;
}

//метод прямоугольников
double rectangles(double(*f)(double x),float a, float b, int step){
	double dx;
	int i;
	double sum;

	if (b >= a){ dx = (b - a) * 1.0 / step; }
	else{
		swap(a, b);
		dx = (b - a) * 1.0 / step;
	}

	sum = 0;
	for (int i = 0; i < step - 1; i++){
		double x = a + dx*i;
		sum += f(x);
	}

	sum = dx*sum;
	return sum;
}

//метод трапеций 
double I(double a, double b, int n, double y) { return (b - a) / (2 * n)*y; }
double trapeze(double(*f)(double x), float a, float b, int step) {
	double sum=0;
	double g;
	double dx;
	if (b >= a){ dx = (b - a) * 1.0 / step; }
	else{
		swap(a, b);
		dx = (b - a) * 1.0 / step;
	}
	sum += f(a) + f(b);
	for (int i = 1; i<step; i++) { sum += 2 * (f(a + dx*i)); }
	g = I(a, b, step, sum);
	
	return g;
}

//метод симпсона 
double simpson(double(*f)(double x), double a, double b, int step) {

	double h;
	if (b >= a){ h = (b - a) * 1.0 / step; }
	else{
		swap(a, b);
		h = (b - a) * 1.0 / step;
	}
	double sum = 0;

	double x0 = a;
	double x1 = a + h;

	for (unsigned i = 0; i < step - 1; i++) {
		sum += f(x0) + 4 * f(x0 + h / 2) + f(x1);

		x0 += h;
		x1 += h;
	} 

	return (h / 6)*sum;
}

double chebishev(double(*f)(double x),double a, double b, int step){
	if (a>b){
		swap(a, b);
	}
	double s = 0;
	double h = (b - a) * 1.0 / step;

	for (unsigned i = 0; i < step - 1; i++) {
		s += f(a + h*i);
	}
	s = s * (b-a) / step;
		return s;
}

int main(){
	int n;
	double a, b;
	double s, s1, s2, s3, s4;
	cout << "Choose a function: " << endl;

	cout << "1. f(x) = x^2+4 " << endl;
	cout << "2. f(x) = x^2 * e^(-x) " << endl;
	cout << "3. f(x) =  1 / ((1 - x)*(2 - x*x));" << endl;
	
	cin >> n;
	cout << "Input limits of integration: ";
	cin >> a >> b;

	

	if (n > 0){
		switch (n){
		case 1:  s = rectangles(func_1, a,b, 1000);
				 s1 = trapeze(func_1,a, b, 1000);
				 s2 = simpson(func_1, a, b, 1000);
				 s3 = gauss(func_1,a, b);
				 s4 = chebishev(func_1, a,b, 1000);


				break;
		case 2:  s = rectangles(func_2, a, b, 1000);
				 s1 = trapeze(func_2, a, b, 1000);
				 s2 = simpson(func_2, a, b, 1000);
				 s3 = gauss(func_2, a, b);
				 s4 = chebishev(func_2, a, b, 1000);
				break;
		case 3:  s = rectangles(func_3,a, b, 1000);
				 s1 = trapeze(func_3, a, b, 1000);
				 s2 = simpson(func_3, a, b, 1000);
				 s3 = gauss(func_3, a, b);
				 s4 = chebishev(func_3,a, b, 1000);
				break;
		default: cout << "Неверное значение"<<endl;
		}
	}
	

	cout << s  << endl;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;

	_getch();
	return 0;
}