//
// Created by spl211 on 22/11/2021.
//
#ifndef CUSTOMER_CPP_
#define CUSTOMER_CPP_
#include <../include/Action.h>
#include <../include/Studio.h>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
Customer::Customer(std::string c_name, int c_id): name(c_name), id(c_id){}
Customer::Customer(Customer &other): name(other.name), id(other.id) {}
string Customer::getName() const {
    return name;
}
int Customer::getId() const {
    return id;
}
 std::vector<int> Customer:: order(const std::vector<Workout> &workout_options){
     vector<int> fake;
     return fake;
}
 std::string Customer:: toString() const {
    return "";
}





#endif