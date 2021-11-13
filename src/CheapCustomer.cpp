//
// Created by nir on 13/11/2021.
//
#ifndef CHEAPCUSTOMER_CPP_
#define CHEAPCUSTOMER_CPP_
#include <../include/Customer.h>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
CheapCustomer::CheapCustomer(std::string name, int id): Customer(std::move(name),id)  {}
int Customer::getId() const {return id;}
string Customer::getName() const {return name;}
string Customer::toString() const {return to_string(getId())+" "+getName();}

vector<int> Customer::order(const std::vector<Workout> &workout_options) {
    vector<Workout> temp;
    for(int i=0;i<workout_options.size();i=i+1)
        temp.push_back(workout_options[i]);
    vector<int> v1;
    sort(temp.begin(),temp.end());
    for(int i=0;i<workout_options.size();i=i+1)
        v1.push_back(workout_options[i].getId());
    temp.clear();
    temp.shrink_to_fit();
    return v1;
}

#endif