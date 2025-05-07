#include <iostream>
#include "Header.h"
#include "Header1.h"

using namespace std;

int main() {

    int a;
    set_num_elements(a);

    VectPolynomial v1(a), v2(a);
    cout << "Enter elements for V1:\n";
    v1.setv();
    cout << "Enter elements for V2:\n";
    v2.setv();

    VectPolynomial v3 = v3.operatev(v1, v2, '+');

    cout << "Resulting vector Vout:\n";
    v3.print_vector();

    double x;
    cout << "Enter value of x for evaluation: ";
    cin >> x;
    v3.evaluatep(x);

    return 0;
}