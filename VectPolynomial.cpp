#include "Header.h"
#include "Header1.h"
#include <iostream>
using namespace std;
void set_num_elements(int& a) {
    do {
        cout << "Input #elements: ";
        cin >> a;
    } while (a <= 0);
}
VectPolynomial::VectPolynomial()
{
    this->s = 0;
    this->d = 0;
    this->vector = nullptr;
}
VectPolynomial::VectPolynomial(int new_a)
{
    this->s = new_a;
    this->d = 0;
    this->vector = new Polynomial[new_a];
}

VectPolynomial::VectPolynomial(const VectPolynomial& p)
{
    this->s = p.s;
    this->d = p.d;
    this->vector = p.vector;
}
VectPolynomial::~VectPolynomial() {}

void VectPolynomial::setS(int a) {
    if (this->vector != nullptr) {
        delete[] this->vector;
    }

    this->s = a;
    this->vector = new Polynomial[a];
}
int VectPolynomial::find_degree() {
    int max = 0;

    for (int i = 0; i < this->s; i++) {
        int expo = this->vector[i].getPe();

        if (expo > max) {
            max = expo;
        }
    }
    return max;
}

int VectPolynomial::getS() {
    return this->s;
}
void VectPolynomial::setv() {
    double c, e;

    for (int i = 0; i < this->getS(); i++) {
        cout << "Elements" << i + 1 << ":" << endl;
        cout << "Coeff: ";
        cin >> c;
        cout << "Exponents: ";
        cin >> e;
        this->vector[i] = Polynomial(c, e);
    }
}

void VectPolynomial::print_vector() {
    for (int i = 0; i < getS(); i++) {
        cout << i + 1 << ": ";
        vector[i].print();
    }
}
void VectPolynomial::evaluatep(double x) {
    for (int i = 0; i < this->s; i++) {
        cout << "Polynomial " << i + 1 << ": ";
        this->vector[i].print();
        cout << "Evaluated at x = " << x << " : " << this->vector[i].evaluate(x) << endl;
    }
}
VectPolynomial VectPolynomial::operatev(VectPolynomial& v1, VectPolynomial& v2, char out) {
    VectPolynomial result(v1.getS());

    for (int i = 0; i < v1.getS(); i++) {
        int j = (i % 2 == 0) ? i + 1 : i - 1;

        if (out == '+') {
            result.vector[i] = v1.vector[i] + v2.vector[j];
        }
        else {
            result.vector[i] = v1.vector[i] - v2.vector[j];
        }
    }

    return result;
}