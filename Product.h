#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <Vector>
#include <Random>
#include <ctime>
#include <sstream>

using namespace std;


class Product {
public:
    char code[13];
    char description[50];
    double price;
    int quantity;
    double pl_longitude;
    double pl_latitude;


public:
    Product();
    Product(char code[13], char description[50], double price, int quantity, double pl_longitude,
        double pl_latitude);
    Product(const Product& p);
    ~Product();
    void set_all();
    const char* get_code();
    const char* get_description();
    double get_price();
    int get_quantity();
    double get_pl_longitude();
    double get_pl_latitude();
    void print_prod();
};
