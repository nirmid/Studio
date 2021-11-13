//
// Created by nir on 13/11/2021.
//
#ifndef HEAVYMYSCLECUSTOMER_CPP_
#define HEAVYMYSCLECUSTOMER_CPP_
#include <../include/Customer.h>
#include <string>
using namespace std;
Customer::Customer(std::string c_name, int c_id): name(c_name),id(c_id) {}
int Customer::getId() const {return id;}
string Customer::getName() const {return name;}
string Customer::toString() const {}   // implementation is needed
#endif
