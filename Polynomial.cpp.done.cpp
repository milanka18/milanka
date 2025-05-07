#include <iostream>

#include "Header1.h"
#include <cmath>
using namespace std;
Polynomial::Polynomial(double c, double e) {
	this->c = c;
	this->e = e;
}
Polynomial::Polynomial(const Polynomial& q) {
	this->c = q.c;
	this->e = q.e;
}
Polynomial ::~Polynomial() {}
void Polynomial::setPc(double c) {
	this->c = c;
}

void Polynomial::setPe(double e) {
	this->e = e;
}

double Polynomial::getPc() {
	return this->c;
}

double Polynomial::getPe() {
	return this->e;
}

void Polynomial::print() {
	cout << this->c << "x^" << this->e << endl;
}
double Polynomial::evaluate(double x) {
	return this->c * pow(x, this->e);
}

Polynomial Polynomial::operator+(const Polynomial& q) {
	return Polynomial(this->c + q.c, this->e);
}

Polynomial Polynomial::operator-(const Polynomial& q) {
	return Polynomial(this->c - q.c, this->e);
}
