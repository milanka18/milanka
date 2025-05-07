#pragma once
#include "Product.h"
enum TYPE{center, 
	west, 
	east};
class Warehouse {
public:
	static int id;
	char ID[4];
	TYPE type;
	double longitude;
	double latitude;
	int max;
	int common;
	Product* list;
public:
	Warehouse();
	Warehouse(int ID, TYPE type, double longitude, double latitude, int max, int common, Product* list, int n);
	Warehouse(const Warehouse& w);
	~Warehouse();
	void gen_ID();
	double m_distance(Product& p);
	void add_prod(Product& p);
	void menu(Warehouse& w);
	void insert_prod();
	void print_list();
	void search_prod(char user[50]);
	void delete_prod(int x);
};