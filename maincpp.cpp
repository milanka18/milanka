#include "ellipse.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Ellipse e1, e2;
	e1 = Ellipse(4, 5, 12, 11);
	e1.print();
	e2 = Ellipse();

	cout << "c1 = " << e1.calculate_c() << endl;

	cout << "Координаты вершин для большой оси Х: ";
	e1.arc_apexX();
	cout << "Координаты вершин для большой оси Y: ";
	e1.arc_apexY();
	cout << "Координаты фокусов для большой оси Х: ";
	e1.focus_X();
	cout << "Координаты фокусов для большой оси Y: ";
	e1.focus_Y();

	cout << "Длина фокальной хорды: " << e1.focal_chord_len() << endl;

	cout << "Эксцентриситет: " << e1.calculate_e() << endl;

	cout << "Параметры эллипса до изменения значений: " << endl;
	e2.print();
	cout << "Параметры эллипса после изменения значений:" << endl;
	e2.set_all(15, 5, -5, 0);
	e2.print();

	double a1, b1, h1, k1;
	e2.get_all(a1, b1, h1, k1);
	cout << "Извлеченные с помощью get значения: " << endl;
	cout << "a: " << a1 << endl;
	cout << "b: " << b1 << endl;
	cout << "h: " << h1 << endl;
	cout << "k: " << k1 << endl;

	cout << endl << "Общая информация: " << endl;
	e1.equation();

	cout << "Введите координаты точек: " << endl;
	double x, y;
	cin >> x >> y;
	e1.check_point(x, y);
	cout << "Приблизительный периметр эллипса равен " << e1.perimeter() << endl;
	cout << "Площадь эллипса равна " << e1.area() << endl;
	cout << "Введите первую координату для точки" << endl;
	double x0;
	cin >> x0;
	e1.second_coordinate(x0);
	return 0;
}