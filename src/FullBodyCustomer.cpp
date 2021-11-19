//
// Created by nir on 13/11/2021.
//
#ifndef FULLBODYCUSTOMER_CPP_
#define FULLBODYCUSTOMER_CPP_
#include <../include/Customer.h>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
FullBodyCustomer::FullBodyCustomer(std::string name, int id): Customer(std::move(name), id) {}
int Customer::getId() const {return id;}
string Customer::getName() const {return name;}
string Customer::toString() const {return to_string(getId())+" "+getName();}
vector<int> Customer::order(const std::vector<Workout> &workout_options) {
    vector<Workout> temp;
    for(int i=0;i<workout_options.size();i=i+1)
        temp.push_back(workout_options[i]);
    vector<int> v1;
    sort(temp.begin(),temp.end());
    v1.push_back(temp[0].getId());
    v1.push_back(temp[temp.size()-1].getId());
    bool found=false;
    for(int i=1; i<temp.size()-1 && !found;i=i+1)
        if(temp[i].getType()==MIXED) {
            v1.push_back(workout_options[i].getId());
            found = true;
        }
    return v1;
}
#endif
