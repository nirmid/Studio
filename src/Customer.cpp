
#ifndef CUSTOMER_CPP_
#define CUSTOMER_CPP_
#include <../include/Action.h>
#include <../include/Studio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
Customer::Customer(std::string c_name, int c_id): name(c_name), id(c_id){}
Customer::Customer(Customer &other): name(other.name), id(other.id) {}
string_type Customer::getType() {
    return t;
}
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

//FullBodyCustomer
FullBodyCustomer::FullBodyCustomer(std::string name, int id): Customer(std::move(name), id) {}
FullBodyCustomer::FullBodyCustomer(FullBodyCustomer &other): Customer(other.getName(), other.getId()){}
string FullBodyCustomer::toString() const {return string(getName()+string(",fbd"));}
vector<int> FullBodyCustomer::order(const std::vector<Workout> &workout_options) {
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

//HeavyMuscleCustomer
HeavyMuscleCustomer::HeavyMuscleCustomer(std::string name, int id): Customer(std::move(name), id) {}
HeavyMuscleCustomer::HeavyMuscleCustomer(HeavyMuscleCustomer &other): Customer(other.getName(), other.getId()){}
string HeavyMuscleCustomer::toString() const {return string(getName()+string (",mcl"));}
vector<int> HeavyMuscleCustomer::order(const std::vector<Workout> &workout_options) {
    vector<Workout> temp;
    for(int i=0;i<workout_options.size();i=i+1)
        temp.push_back(workout_options[i]);
    vector<int> v1;
    sort(temp.begin(),temp.end());
    for (int i=workout_options.size()-1;i>=0; i=i-1){
        if(workout_options[i].getType()==ANAEROBIC){
            v1.push_back(workout_options[i].getId());
        }
    }
    return v1;
}

//SweatyCustomer

SweatyCustomer::SweatyCustomer(std::string name, int id): Customer(std::move(name),id) {}
SweatyCustomer::SweatyCustomer(SweatyCustomer &other): Customer(other.getName(), other.getId()){}
string SweatyCustomer::toString() const {return string(getName()+string(",swt"));}
vector<int> SweatyCustomer::order(const std::vector<Workout> &workout_options) {
    vector<int> v1;
    for (int i=0;i<workout_options.size(); i=i+1){
        if(workout_options[i].getType()==CARDIO)
            v1.push_back(workout_options[i].getId());
    }
    return v1;
}

//CheapCustomer
CheapCustomer::CheapCustomer(std::string name, int id): Customer(std::move(name),id)  {}
CheapCustomer::CheapCustomer(CheapCustomer &other): Customer(other.getName(), other.getId()){}
string CheapCustomer::toString() const {return string(getName()+string(",chp"));}

vector<int> CheapCustomer::order(const std::vector<Workout> &workout_options) {
    vector<Workout> temp;
    for(int i=0;i<workout_options.size();i=i+1)
        temp.push_back(workout_options[i]);
    vector<int> v1;
    sort(temp.begin(),temp.end());
    for(int i=0;i<workout_options.size();i=i+1)
        v1.push_back(workout_options[i].getId());
    return v1;
}






#endif