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
string Customer::toString() const {return to_string(getId())+" "+getName();}   // implementation is needed
vector<int> Customer::order(const std::vector<Workout> &workout_options) {
    vector<int> v1;  // reference or values ?
    for (int i=0;i<workout_options.size(); i=i+1){
        if(workout_options[i].getType()==ANAEROBIC){
            v1.push_back(workout_options[i].getId());
        }
    }
    return v1;
}

#endif
