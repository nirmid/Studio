//
// Created by nir on 12/11/2021.
//
#ifndef SWEATYCUSTOMER_CPP_
#define SWEATYCUSTOMER_CPP_
#include <../include/Customer.h>
#include <string>
using namespace std;
Customer::Customer(std::string c_name, int c_id): name(c_name),id(c_id) {}
int Customer::getId() const {return id;}
string Customer::getName() const {return name;}
string Customer::toString() const {}   // implementation is needed
vector<int> Customer::order(const std::vector<Workout> &workout_options) {
    vector<Workout> v1;  // reference or values ?
    for (int i=0;i<workout_options.size(); i=i+1){

    }
}
vector<Workout> sort(const vector<Workout> &workout_options){
    vector<Workout> v1;
    int low=0;
    int high=workout_options.size();

}



#endif