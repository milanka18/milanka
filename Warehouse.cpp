#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Warehouse.h"
#include "Product.h"

using namespace std;
int Warehouse::id = 100;
void Warehouse::gen_ID() {
	ID[0] = 'W';
	ID[1] = (id / 100) + '0';
	ID[2] = ((id % 100) / 100) + '0';
	ID[3] = (((id % 100) % 100) / 100) + '0';
}
Warehouse::Warehouse() {
	gen_ID();
	this->type = west;
	this->longitude = 0;
	this->latitude;
	this->max = 0;
	this->common = 0;
	this->list;
}
Warehouse::Warehouse(int ID, TYPE type, double longitude, double latitude, int max, int common, Product* list, int n) {
	gen_ID();
	this->type = type;
	this->longitude = longitude;
	this->latitude = latitude;
	this->max = max;
	this->common = common;
	this->list = new Product[n];
}
Warehouse::Warehouse(const Warehouse& w) {
	gen_ID();
	this->type = w.type;
	this->longitude = w.longitude;
	this->latitude = w.latitude;
	this->max = w.max;
	this->common = w.common;
}
Warehouse::~Warehouse(){
}
double Warehouse::m_distance(Product& p) {
	double dist = abs(latitude - p.pl_latitude) + abs(longitude - p.pl_longitude);
	return dist;
}
void Warehouse::add_prod(Product& p) {
	if ((common += p.get_quantity()) > max) {
		cout << "Warehouse is full" << endl;
		return;
	}
	else {
		common += p.get_quantity();
	}
}
void Warehouse::insert_prod() {
	char code[13];
	char description[50];
	double price;
	int quantity;
	double longetude;
	double latitude;
	cout << "Enter code" << endl;
	cin >> code;
	cout << "Enter description: " << endl;
	cin >> description;
	cout << "Enter price" << endl;
	cin >> price;
	cout << "Enter quantity" << endl;
	cin >> quantity;
	cout << "Enter lognetude" << endl;
	cin >> longetude;
	cout << "Enter latitude" << endl;
	cin >> latitude;
	Product p(code, description, price, quantity, longetude, latitude);
	add_prod(p);
}
void Warehouse::print_list() {
	for (int i = 0; i < this->common; i++) {
		this->list[i].print_prod();
	}
}
void Warehouse::search_prod(char user[50]) {
	int x;
	for (int i = 0; i < this->common; i++) {
		if (strcmp(this->list[i].description, user) == 0) {
			x = i;
			cout << "Description corresponds to product ¹" << x << endl;
		}
		else {
			cout << "There is no such product" << endl;
		}
	}
}

void Warehouse::delete_prod(int x) {
	this->common = this->common - this->list[x].quantity;
	for (int i = x; i < (sizeof(this->list) / sizeof(this->list[0])); i++){
		this->list[i] = this->list[i+1];
	}
}
void Warehouse::menu(Warehouse& w) {
	int choice;
	cout << "MENU" << endl;
	cout << "|1| ADD PRODUCT |" << endl;
	cout << "|2| SHOW PRODUCT LIST |" << endl;
	cout << "|3| SEARCH PRODUCT BY DESCRIPTION |" << endl;
	cout << "|4| DELETE PRODUCTS |" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		w.insert_prod();
	case 2:
		w.print_list();
	case 3:
		cout << "Enter description" << endl;
		char user[50];
		cin >> user;
		w.search_prod(user);
	case 4:
		cout << "Enter product's number" << endl;
		int x;
		cin >> x;
		w.delete_prod(x);

	default:
		cout << "";
	}
}
