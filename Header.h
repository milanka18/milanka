#pragma once
class Qaternion {
public:
	double a;
	double b;
	double c;
	double d;
public:
	Qaternion(double a = 1, double b = 0, double c = 0, double d = 0);
	Qaternion(const Qaternion& q);
	~Qaternion();
public:
	void set_Qaternion(double a, double b, double c, double d);
	void get_Qaternion(double& a, double& b, double& c, double& d);
public:
	void print();
public:
	double norma();

public:
	void sopr();
public:
	void normal();
public:
	void invers();
};
Qaternion summa(Qaternion q4, Qaternion q5);
Qaternion razn(Qaternion q4, Qaternion q5);
Qaternion umn(Qaternion q4, Qaternion q5);
double scalar(Qaternion q4, Qaternion q5);
double evklid(Qaternion q4, Qaternion q5);
double normic(Qaternion q4, Qaternion q5);
