#pragma once
class Polynomial {
public:
	double c;
	double e;
	Polynomial(double c = 0.0, double e = 0.0);
	Polynomial(const Polynomial& q);
	~Polynomial();
	void setPc(double c);
	void setPe(double e);
	double getPc();
	double getPe();
	void print();
	double evaluate(double x);

	Polynomial operator + (const Polynomial& q);
	Polynomial operator - (const Polynomial& q);



};
