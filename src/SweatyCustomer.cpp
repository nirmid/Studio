//
// Created by nir on 12/11/2021.
//
#ifndef SWEATYCUSTOMER_CPP_
#define SWEATYCUSTOMER_CPP_
#include <../include/Customer.h>
#include <string>
using namespace std;
SweatyCustomer::SweatyCustomer(std::string name, int id): Customer(std::move(name),id) {}
SweatyCustomer::SweatyCustomer(SweatyCustomer &other): Customer(other.getName(), other.getId()){}
int Customer::getId() const {return id;}
string Customer::getName() const {return name;}
string Customer::toString() const {return string(name+",swt");}
vector<int> Customer::order(const std::vector<Workout> &workout_options) {
    vector<int> v1;
    for (int i=0;i<workout_options.size(); i=i+1){
        if(workout_options[i].getType()==CARDIO)
            v1.push_back(workout_options[i].getId());
    }
    return v1;
}




#endif