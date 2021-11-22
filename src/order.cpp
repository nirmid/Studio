//
// Created by spl211 on 16/11/2021.
//
#ifndef ORDER_CPP_
#define ORDER_CPP_
using namespace std;
#include <../include/Action.h>
#include <vector>
#include <iostream>
#include <../include/Trainer.h>
#include <../include/Studio.h>

Order :: Order(int id): trainerId(id)  {}

void Order :: act (Studio& studio) {
    if (trainerId > studio.getNumOfTrainers() | !(studio.getTrainer(trainerId))->isOpen())
        error("Trainer does not exist or not open");
    else{
        Trainer *cur = studio.getTrainer(trainerId);
        for(auto i = ((*cur).getCustomers()).begin() ; i != ((*cur).getCustomers()).end(); i++){
            (*cur).order((*i)->getId(), (*i)->order(studio.getWorkoutOptions()), studio.getWorkoutOptions());
        }
    }
}

std::string Order::toString() const {
    stringstream ss;
    ss<<trainerId;
    string output = "order " + ss.str()+string(" ");
    if(this->getStatus()== ERROR)
        output = output+string("Error:Trainer does not exist or not open");
    else
        output = output+string("COMPLETED");
    return output;

}












#endif