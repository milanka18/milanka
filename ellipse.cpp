#include <iostream>
#include "ellipse.h"
#include <cmath>
using namespace std;

Ellipse::Ellipse(double a, double b, double h, double k) {
	this-> a = a;
	this->b = b;
	this->h = h;
	this->k = k;
	normalize();
}

Ellipse::Ellipse(const Ellipse& e) {
	this->a = e.a;
	this->b = e.b;
	this->h = e.h;
	this->k = e.k;
	normalize();
}
Ellipse::~Ellipse() {};
double Ellipse::calculate_c() {
	double c = sqrt((a * a) - (b * b));
	return c;
}
void Ellipse::print() {
	cout << "Центр эллипса C (" << h << ", " << k << ")" << endl;
	cout << "Большая полуось: " << a << endl;
	cout << "Малая полуось: " << b << endl;
}
void Ellipse::normalize() {
	int aux;
	if (b > a) {
		aux = b;
		b = a;
		a = aux;
	}
}
void Ellipse::arc_apexX(){
	cout << "V1(" << h - a << ", " << k << "); "<<endl;
	cout << "V2(" << h + a << ", " << k << ")"<<endl;
}
void Ellipse::arc_apexY() {
	cout << "V1(" << h << ", " << k - a << "); " << endl;
	cout << "V2(" << h << ", " << k + a << ")" << endl;
}
void Ellipse::focus_X() {
	cout << "F1(" << h - calculate_c() << ", " << k << "); " << endl;
	cout << "F2(" << h + calculate_c() << ", " << k << ")" << endl;
}
void Ellipse::focus_Y() {
	cout << "F1(" << h << ", " << k - calculate_c() << "); " << endl;
	cout << "F2(" << h << ", " << k + calculate_c() << ")" << endl;
}
double Ellipse::focal_chord_len() {
	double LR = 2 * b * b / a;
	return LR;
}
double Ellipse::calculate_e() {
	double e = calculate_c() / a;
	return e;
}
void Ellipse::get_all(double &a, double &b, double &h, double &k) {
	a = this->a;
	b = this->b;
	h = this->h;
	k = this->k;
	
}
void Ellipse::set_all(double a, double b, double h, double k) {
	this->a = a;
	this->b = b;
	this->h = h;
	this->k = k;
}
void Ellipse::equation() {
	if (a > b) {
		cout <<"Уравнение эллипса: "<<"(x-" << h << ")^2 / " << a * a << "+ (y-" << k << ")^2 / " << b * b << " = 1" << endl;
	}
	else {
		cout << "Уравнение эллипса: " << "(x-" << h << ")^2 / " << b * b << " + (y-" << k << ")^2 / " << b * b << " = 1" << endl;
	}
	cout << "Центр: С (" << h << ", " << k << ")" << endl;
	cout << "Координаты вершин: " << endl;
	cout << "F1(" << h - calculate_c() << ", " << k << "); " << endl;
	cout << "F2(" << h + calculate_c() << ", " << k << ")" << endl;
	cout << "Координаты фокусов: " << endl;
	cout << "F1(" << h - calculate_c() << ", " << k << "); " << endl;
	cout << "F2(" << h + calculate_c() << ", " << k << ")" << endl;
}
void Ellipse::check_point(double x, double y) {
	double eq = (pow((x - h), 2) / (a * a) + (pow((y - k), 2) / (b * b)));
	if (eq < 1){
		cout<<"Точка лежит внутри эллипса"<<endl;
	}
	if (eq == 1) {
		cout << "Точка лежит на эллипсе" << endl;
	}
	if (eq > 1) {
		cout << "Точка лежит вне эллипса" << endl;
	}
}
double Ellipse::perimeter() {
	double P = 3.14 * (3*(a+b) - sqrt((3*a + b)*(a + 3*b)));
	return P;
}
double Ellipse::area() {
	double S = 3.14 * a * b;
	return S;
}
void Ellipse::second_coordinate(double x) {
	if (pow((x - h), 2) / a * a > 1) {
		cout << "Точка вне эллипса" << endl;
	}
	else {
		double v = b * sqrt(1 - pow((x - h), 2) / a * a);
		double y1 = k + v;
		double y2 = k - v;
		cout << "Вторая координата имеет значения " << y1 << " и " << y2 << endl;
	}
}