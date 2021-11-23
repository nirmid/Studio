//
// Created by nir on 14/11/2021.
//
#ifndef OPENTRAINER_CPP_
#define OPENTRAINER_CPP_
#include <../include/Action.h>
#include <../include/Studio.h>
#include <../include/Customer.h>
#include <../src/Customer.cpp>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
OpenTrainer::OpenTrainer(int id, std::vector<Customer *> &customersList): trainerId(id)  {
    customers = customersList;
}
OpenTrainer::OpenTrainer(OpenTrainer &other): trainerId(other.trainerId) {
    for (int i = 0; i < other.customers.size(); i ++){
        Customer temp((other.customers[i]));
        customers.push_back(other.customers[i]);
    }
}

void OpenTrainer::act(Studio &studio) {
    if( studio.getTrainer(trainerId) != nullptr && studio.getTrainer(trainerId)->isOpen() ){
        Trainer* t=studio.getTrainer(trainerId);
        int i=0;
        while(i<t->getCapacity() && i<customers.size()){
            t->addCustomer(customers[i]);
            i=i+1;
        }
    }
    else {
        BaseAction::error("Workout session does not exist or is already open");
        cout << getErrorMsg();
    }
}

std::string OpenTrainer::toString() const {
    stringstream ss;
    ss<<trainerId;
    string output = string("open")+string(" ")+ss.str()+string(" ");
    for(int i=0; i<customers.size();i=i+1){
        Customer& c = *customers[i];
        output = output+c.toString()+string(" ");
    }
    if(this->getStatus()==ERROR)
        output = output+string("Error: Trainer does not exist or is already open");
    else
        output=output+string("COMPLETE");
    return output;


}

#endif