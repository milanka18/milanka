#pragma once
#include "Header1.h"
#include <iostream>



class VectPolynomial {

public:
    Polynomial* vector;
    int s;
    int d;
    VectPolynomial();
    VectPolynomial(int a);
    VectPolynomial(const VectPolynomial& p);
    ~VectPolynomial();
    int find_degree();
    void setS(int a);
    int getS();
    void setv();
    void print_vector();
    void evaluatep(double x);
    VectPolynomial operatev(VectPolynomial& v1, VectPolynomial& v2, char out);

};
void set_num_elements(int& a);
