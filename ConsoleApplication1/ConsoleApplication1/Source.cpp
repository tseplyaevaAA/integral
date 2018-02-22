#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

double func_1(double x){
	x = x*x + 4;
	return x;
}

double gauss(double a, double b){

	if (a > b){ swap(a, b); }
	double s = (b - a) / 2 * (
		func_1((a + b) / 2 - (b - a) / (2 * sqrt(3))) +
		func_1((a + b) / 2 + (b - a) / (2 * sqrt(3)))
		);
	return s;
}

//метод прямоугольников
double rectangles(float a, float b, int step){
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
		sum += func_1(x);
	}

	sum = dx*sum;
	return sum;
}

//метод трапеций 
double I(double a, double b, int n, double y) { return (b - a) / (2 * n)*y; }
double trapeze(float a, float b, int step) {
	double sum=0;
	double g;
	double dx;
	if (b >= a){ dx = (b - a) * 1.0 / step; }
	else{
		swap(a, b);
		dx = (b - a) * 1.0 / step;
	}
	sum += func_1(a) + func_1(b);
	for (int i = 1; i<step; i++) { sum += 2 * (func_1(a + dx*i)); }
	g = I(a, b, step, sum);
	
	return g;
}

//метод симпсона 
double simpson(double a, double b, int step) {

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
		sum += func_1(x0) + 4 * func_1(x0 + h / 2) + func_1(x1);

		x0 += h;
		x1 += h;
	} 

	return (h / 6)*sum;
}

double chebishev(double a, double b,int step){
	if (a>b){
		swap(a, b);
	}
	double s = 0;
	double h = (b - a) * 1.0 / step;

	for (unsigned i = 0; i < step - 1; i++) {
		s += func_1(a + h*i);
	}
	s = s * (b-a) / step;
		return s;
}

int main(){

	//double s = rectangles(2, 10, 1000);
	//cout << s << endl;

	//double s1 = trapeze(2, 10, 1000);
	//cout << s1<<endl;

	//double s2 = simpson(2, 10, 1000);
	//cout << s2 << endl;

	//double s3 = gauss(2, 10);
	//cout << s3 << endl;

	//double s4 = chebishev(2, 10, 1000);
	//cout << s4 << endl;

	_getch();
	return 0;
}