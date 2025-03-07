
#include "Header.h"
#include<cmath>
#include <iostream>
using namespace std;
Qaternion::Qaternion(double a, double b, double c, double d) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;

}
Qaternion::Qaternion(const Qaternion& q) {
    this->a = q.a;
    this->b = q.b;
    this->c = q.c;
    this->d = q.d;
}
Qaternion::~Qaternion() {}
void Qaternion::set_Qaternion(double a, double b, double c, double d) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
}
void Qaternion::get_Qaternion(double& a, double& b, double& c, double& d) {
    a =this-> a;
    b = this->b;
    c = this->c;
    d = this->d;
    
}
void Qaternion::print() {
    cout << "q=" << a << "+" << b << "i+" << c << "j+" << d << "k" << endl;

}
double Qaternion::norma() {
    return sqrt(a*a+b*b+c*c+d*d);

}
void Qaternion::sopr() {
    cout << "q=" << a << "-" << b << "i-" << c << "j-" << d << "k" << endl;

}
void Qaternion::normal() {
    double x = sqrt(a * a + b + b + c * c + d * d);
    a = a / x;
    b = b / x;
    c = c / x;
    d = d / x;
    cout << "q=" << a << "+" << b << "i+" << c << "j+" << d << "k" << endl;

}
void Qaternion::invers() {
    double x = pow(sqrt(a * a + b * b + c * c + d + d), 2);
    a = a / x;
    b = b / x;
    c = c / x;
    d = d / x;
    cout<< "q="<< a <<"-" << b << "i-" << c << "j-" << d << "k" << endl;
}

Qaternion summa(Qaternion q4, Qaternion q5) {
    return Qaternion(q4.a + q5.a, q4.b + q5.b, q4.c + q5.c, q4.d + q5.d);
}
Qaternion razn(Qaternion q4, Qaternion q5) {
    return Qaternion(q4.a - q5.a, q4.b - q5.b, q4.c - q5.c, q4.d - q4.d);
}
Qaternion umn(Qaternion q4, Qaternion q5) {
    return Qaternion(q4.a * q5.a - q4.b * q5.b - q4.c * q5.c - q4.d * q5.d, q4.a * q5.b + q4.b * q5.a + q4.c * q5.d - q4.d * q5.c, q4.a * q5.c + q4.c * q5.a + q4.d * q5.b - q4.b * q5.d, q4.a * q5.d + q4.d * q5.a + q4.b * q5.c - q4.c * q5.b);
}
double scalar(Qaternion q4, Qaternion q5) {
    return (q4.a * q5.a + q4.b * q5.b + q4.c * q5.c + q4.d * q5.d);   
}
double evklid(Qaternion q4, Qaternion q5) {
    return sqrt(pow(q4.a - q5.a, 2) + pow(q4.b - q5.b, 2) + pow(q4.c - q5.c, 2) + pow(q4.d - q5.d, 2));
}
int max(double a, double b, double c, double d) {
    double max = a; 

    if (b > max) {
        max = b; 
    }
    if (c > max) {
        max = c; 
    }
    if (d > max) {
        max = d; 
    }

    return max; 
}
double normic(Qaternion q4, Qaternion q5) {
    double l = max(abs(q4.a - q5.a), abs(q4.b - q5.b), abs(q4.c - q5.c), abs(q4.d - q5.d));
    return l;
}