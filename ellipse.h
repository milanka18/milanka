#pragma once
class Ellipse {
public:
	int a, b, h, k;
public:
	Ellipse(double a = 0, double b = 0, double h = 0, double k = 0);
	Ellipse(const Ellipse& e);
	~Ellipse();
	void print();
	double calculate_c();
	void normalize();
	void arc_apexX();
	void arc_apexY();
	void focus_X();
	void focus_Y();
	double focal_chord_len();
	double calculate_e();
	void set_all(double a, double b, double h, double k);
	void get_all(double& a, double& b, double& h, double& k);
	void equation();
	void check_point(double x, double y);
	double perimeter();
	double area();
	void second_coordinate(double x);
};