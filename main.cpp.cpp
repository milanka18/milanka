#include <iostream>
#include "Header.h"
using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");
	Qaternion q1,q4,q5;
	q4 = Qaternion(9, 8, 7, 6);
	q5 = Qaternion(14, 4, 10, 12);
	q1.print();
	Qaternion q2=Qaternion(1,2,3,4);
	q2.print();
	Qaternion q3 = Qaternion(q2);
	q3.print();
	cout << "Параметры после изменения: " << endl;
	q3.set_Qaternion(5, 2, 6, 4);
	q3.print();
	cout << "Извлечение с помощью get значения " << endl;
	double a1, b1, c1, d1;
	q3.get_Qaternion(a1, b1, c1, d1);
	cout << "a1" << " " << a1 << endl;
	cout << "b1" << " " << b1 << endl;
	cout << "c1" << " " << c1 << endl;
	cout << "d1"<< " " << d1 << endl;
	double norma;
	norma = q3.norma();
	cout << "Норма кватерниона:";
	cout << norma << endl;
	cout << "Сопряженный кватернион:";
	q3.sopr();
	cout << "Нормализация кватерниона:";
	q3.normal();
	cout << "Инверсия кватерниона:";
	q3.invers();
	cout << "q4 + q5: ";
	summa(q4, q5).print();
	cout << "q4 - q5: ";
	razn(q4, q5).print();
	cout << "q4 * q5: ";
	umn(q4, q5).print();
	cout << "q1 x q2: ";
	cout << scalar(q4, q5) << endl;
	cout << "Евклидово расстояние:";
	cout << evklid(q4, q5) << endl;
	cout << "Норма Чебышева:";
	cout << normic(q4, q5) << endl;
}