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

	cout << "���������� ������ ��� ������� ��� �: ";
	e1.arc_apexX();
	cout << "���������� ������ ��� ������� ��� Y: ";
	e1.arc_apexY();
	cout << "���������� ������� ��� ������� ��� �: ";
	e1.focus_X();
	cout << "���������� ������� ��� ������� ��� Y: ";
	e1.focus_Y();

	cout << "����� ��������� �����: " << e1.focal_chord_len() << endl;

	cout << "��������������: " << e1.calculate_e() << endl;

	cout << "��������� ������� �� ��������� ��������: " << endl;
	e2.print();
	cout << "��������� ������� ����� ��������� ��������:" << endl;
	e2.set_all(15, 5, -5, 0);
	e2.print();

	double a1, b1, h1, k1;
	e2.get_all(a1, b1, h1, k1);
	cout << "����������� � ������� get ��������: " << endl;
	cout << "a: " << a1 << endl;
	cout << "b: " << b1 << endl;
	cout << "h: " << h1 << endl;
	cout << "k: " << k1 << endl;

	cout << endl << "����� ����������: " << endl;
	e1.equation();

	cout << "������� ���������� �����: " << endl;
	double x, y;
	cin >> x >> y;
	e1.check_point(x, y);
	cout << "��������������� �������� ������� ����� " << e1.perimeter() << endl;
	cout << "������� ������� ����� " << e1.area() << endl;
	cout << "������� ������ ���������� ��� �����" << endl;
	double x0;
	cin >> x0;
	e1.second_coordinate(x0);
	return 0;
}