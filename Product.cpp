#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "Product.h"
using namespace std;
Product::Product() {
	srand(static_cast<unsigned int>(time(nullptr)));
	strncpy_s(this->code, "460", sizeof(code));
	int random = (rand() % 9 + 1) * 1000;
	char random_str[5];
	snprintf(random_str, sizeof(random_str), "%04d", random);
	strncat_s(this->code, random_str, sizeof(code) - strlen(code) - 1);
	int rand6 = rand() % 1000000;
	char rand_6_str[7];
	strncat_s(this->code, rand_6_str, sizeof(code) - strlen(code) - 1);
	this->description[0] = '\0';
	this->price = 0;
	this->quantity = 0;
	this->pl_longitude = 41.0 + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (82,0 - 41,0)));
	this->pl_latitude = 19.0 + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (169.0 - 19.0)));
}
Product::Product(char code[14], char description[50], double price, int quantity, double pl_longitude,
	double pl_latitude) {
	strncpy_s(this->code, code, sizeof(code)-1);
	strncpy_s(this->description, description, sizeof(description) - 1);
	this->price = price;
	this->quantity = quantity;
	this->pl_longitude = pl_longitude;
	this->pl_latitude = pl_latitude;
}
Product::Product(const Product& p) {
	strncpy_s(this->code, p.code, sizeof(code)- 1);
	strncpy_s(this->description, p.description, sizeof(description) - 1);
	this->price = p.price;
	this->quantity = p.quantity;
	this->pl_longitude = p.pl_longitude;
	this->pl_latitude = p.pl_latitude;
}
Product::~Product() {}
void Product::set_all() {
	strncpy_s(this->code, code, sizeof(code) - 1);
	strncpy_s(this->description, description, sizeof(description) - 1);
	this->price = price;
	this->quantity = quantity;
	this->pl_longitude = pl_longitude;
	this->pl_latitude = pl_latitude;
}
const char* Product::get_code() {
	return this->code;
}
const char* Product::get_description() {
	return this->description;
}
double Product::get_price() {
	return this->price;
}
int Product::get_quantity() {
	return this->quantity;
}
double Product::get_pl_longitude() {
	return this->pl_longitude;
}
double Product::get_pl_latitude() {
	return this->pl_latitude;
}
void Product::print_prod() {
	cout << setw(12) << this->code <<
		setw(15) << this->description <<
		setw(10) << this->price <<
		setw(10) << this->quantity <<
		setw(10) << this->pl_longitude <<
		setw(10) << this->pl_latitude << endl;
}